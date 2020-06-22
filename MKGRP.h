#ifndef MKGRP_H
#define MKGRP_H

#endif // MKGRP_H

#include <iostream>
#include <string.h>
#include <parser.h>
#include <structs.h>

using namespace std;

class MKGRP_
{
private:
    string name;
    bool correct;
public:
    MKGRP_():name(""), correct(false){}
    void setName(char* name);
    void semantic();
    void run();
    int buscarGrupo(string name);
    void agregarUsersTXT(string datos);
    int buscarBit(FILE *fp, char tipo, char fit);
    int getID_grp();
    void guardarJournal(char *operacion, int tipo, int permisos, char *nombre, char *content);
};

extern bool loged;
extern Sesion sesion;

void MKGRP_::setName(char *name)
{
    this->name = name;
    if(this->name[0] == '\"')
    {
        this->name = this->name.substr(1, this->name.length() - 2);
    }
}

void MKGRP_::semantic()
{
    if(this->name != "")
    {
        this->correct = true;
    }
    else
    {
        cout << "El parámetro name es obligatorio." << endl;
    }
}

void MKGRP_::run()
{
    semantic();
    if(this->correct)
    {
        if(loged){
            if(sesion.id_user == 1 && sesion.id_grp == 1)
            {
                if(name.length() <= 10)
                {
                    int grupo = buscarGrupo(name);
                    if(grupo == -1){
                        int idGrp = getID_grp();
                        string nuevoGrupo = to_string(idGrp)+",G,"+name+"\n";
                        agregarUsersTXT(nuevoGrupo);
                        cout << "Grupo creado con exito "<< endl;
                        if(sesion.tipo_sistema ==3){
                            char aux[64];
                            char operacion[10];
                            char content[2];
                            strcpy(aux,nuevoGrupo.data());
                            strcpy(operacion,"mkgrp");
                            memset(content,0,2);
                            guardarJournal(operacion,0  ,0,aux,content);
                        }
                    }else
                        cout << "Ya existe un grupo con ese nombre" << endl;
                }else
                    cout << "Nombre del grupo no puede exceder los 10 caracters" << endl;
            }else
                cout << "No cuenta con permisos suficientes para ejecutar esta acción." << endl;
        }else
            cout << "Inicie sesión para poder ejecutar este comando" << endl;

    }
}

int MKGRP_::buscarGrupo(string name)
{
    FILE *fp = fopen(sesion.direccion.data(),"r+b");

    char cadena[400] = "\0";
    SuperBloque super;
    InodoTable inodo;

    fseek(fp,sesion.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,fp);
    //Leemos el inodo del archivo users.txt
    fseek(fp,super.s_inode_start + static_cast<int>(sizeof(InodoTable)), SEEK_SET);
    fread(&inodo,sizeof(InodoTable),1,fp);

    for(int i = 0; i < 15; i++){
        if(inodo.i_block[i] != -1){
            BloqueArchivo archivo;
            fseek(fp,super.s_block_start,SEEK_SET);
            for(int j = 0; j <= inodo.i_block[i]; j++){
                fread(&archivo,sizeof(BloqueArchivo),1,fp);
            }
            strcat(cadena,archivo.b_content);
        }
    }

    fclose(fp);

    char *end_str;
    char *token = strtok_r(cadena,"\n",&end_str);
    while(token != nullptr){
        char id[2];
        char tipo[2];
        char group[12];
        char *end_token;
        char *token2 = strtok_r(token,",",&end_token);
        strcpy(id,token2);
        if(strcmp(id,"0") != 0){//Verificar que no sea un U/G eliminado
            token2 = strtok_r(nullptr,",",&end_token);
            strcpy(tipo,token2);
            if(strcmp(tipo,"G") == 0){
                strcpy(group,end_token);
                if(strcmp(group,name.data()) == 0)
                    return atoi(id);
            }
        }
        token = strtok_r(nullptr,"\n",&end_str);
    }

    return -1;
}

void MKGRP_::agregarUsersTXT(string datos){
    FILE *fp = fopen(sesion.direccion.data(), "r+b");

    SuperBloque super;
    InodoTable inodo;
    BloqueArchivo archivo;
    int blockIndex = 0;

    fseek(fp,sesion.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,fp);
    //Leemos el inodo del archivo users.txt
    fseek(fp,super.s_inode_start + static_cast<int>(sizeof(InodoTable)), SEEK_SET);
    fread(&inodo,sizeof(InodoTable),1,fp);

    for(int i = 0; i < 12; i++){
        if(inodo.i_block[i] != -1)
            blockIndex = inodo.i_block[i];//Ultimo bloque utilizado del archivo
    }

    fseek(fp,super.s_block_start + static_cast<int>(sizeof(BloqueArchivo))*blockIndex,SEEK_SET);
    fread(&archivo,sizeof(BloqueArchivo),1,fp);
    int enUso = static_cast<int>(strlen(archivo.b_content));
    int libre = 63 - enUso;
    int tam = datos.size();


    if( tam <= libre)
    {
        strcat(archivo.b_content,datos.data());
        fseek(fp,super.s_block_start + static_cast<int>(sizeof(BloqueArchivo))*blockIndex,SEEK_SET);
        fwrite(&archivo,sizeof(BloqueArchivo),1,fp);
        fseek(fp,super.s_inode_start + static_cast<int>(sizeof(InodoTable)),SEEK_SET);
        fread(&inodo,sizeof(InodoTable),1,fp);
        inodo.i_size = inodo.i_size + datos.length();
        inodo.i_mtime = time(nullptr);
        fseek(fp,super.s_inode_start + static_cast<int>(sizeof(InodoTable)),SEEK_SET);
        fwrite(&inodo,sizeof(InodoTable),1,fp);
    }
    else
    {
        string aux = "";
        string aux2 = "";
        int i = 0;

        for(i = 0; i < libre; i++)
        {
            aux += datos.at(i);
        }
        for(; i < tam; i++)
        {
            aux2  += datos.at(i);
        }
        //Guardamos lo que cabe en el primer bloque
        strcat(archivo.b_content,aux.data());
        fseek(fp,super.s_block_start + static_cast<int>(sizeof(BloqueArchivo))*blockIndex,SEEK_SET);
        fwrite(&archivo,sizeof(BloqueArchivo),1,fp);
        BloqueArchivo auxArchivo;
        strcpy(auxArchivo.b_content,aux2.data());
        int bit = buscarBit(fp,'B',sesion.fit);
        /*Guardamos el bloque en el bitmap y en la tabla de bloques*/
        fseek(fp,super.s_bm_block_start + bit,SEEK_SET);
        fputc('2',fp);
        fseek(fp,super.s_block_start + (static_cast<int>(sizeof(BloqueArchivo))*bit),SEEK_SET);
        fwrite(&auxArchivo,sizeof(BloqueArchivo),1,fp);
        /*Guardamos el modificado del inodo*/
        fseek(fp,super.s_inode_start + static_cast<int>(sizeof(InodoTable)),SEEK_SET);
        fread(&inodo,sizeof(InodoTable),1,fp);
        inodo.i_size = inodo.i_size + datos.length();
        inodo.i_mtime = time(nullptr);
        inodo.i_block[blockIndex] = bit;
        fseek(fp,super.s_inode_start + static_cast<int>(sizeof(InodoTable)),SEEK_SET);
        fwrite(&inodo,sizeof(InodoTable),1,fp);
        /*Guardamos la nueva cantidad de bloques libres y el primer bloque libre*/
        super.s_first_blo = super.s_first_blo + 1;
        super.s_free_blocks_count = super.s_free_blocks_count - 1;
        fseek(fp,sesion.inicioSuper,SEEK_SET);
        fwrite(&super,sizeof(SuperBloque),1,fp);
    }
    fclose(fp);
}

int MKGRP_::buscarBit(FILE *fp, char tipo, char fit)
{
    SuperBloque super;
    int inicio_bm = 0;
    char tempBit = '0';
    int bit_libre = -1;
    int tam_bm = 0;

    fseek(fp,sesion.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,fp);

    if(tipo == 'I')
    {
        tam_bm = super.s_inodes_count;
        inicio_bm = super.s_bm_inode_start;
    }
    else if(tipo == 'B')
    {
        tam_bm = super.s_blocks_count;
        inicio_bm = super.s_bm_block_start;
    }

    if(fit == 'F')
    {
        for(int i = 0; i < tam_bm; i++){
            fseek(fp,inicio_bm + i,SEEK_SET);
            tempBit = static_cast<char>(fgetc(fp));
            if(tempBit == '0'){
                bit_libre = i;
                return bit_libre;
            }
        }

        if(bit_libre == -1)
            return -1;

    }else if(fit == 'B'){
        int libres = 0;
        int LIBRESCP = -1;

        for(int i = 0; i < tam_bm; i++){
            fseek(fp,inicio_bm + i,SEEK_SET);
            tempBit = static_cast<char>(fgetc(fp));
            if(tempBit == '0'){
                libres++;
                if(i+1 == tam_bm){
                    if(LIBRESCP == -1 || LIBRESCP == 0)
                        LIBRESCP = libres;
                    else{
                        if(LIBRESCP > libres)
                            LIBRESCP = libres;
                    }
                    libres = 0;
                }
            }else if(tempBit == '1'){
                if(LIBRESCP == -1 || LIBRESCP == 0)
                    LIBRESCP = libres;
                else{
                    if(LIBRESCP > libres)
                        LIBRESCP = libres;
                }
                libres = 0;
            }
        }

        for(int i = 0; i < tam_bm; i++){
            fseek(fp,inicio_bm + i, SEEK_SET);
            tempBit = static_cast<char>(fgetc(fp));
            if(tempBit == '0'){
                libres++;
                if(i+1 == tam_bm)
                    return ((i+1)-libres);
            }else if(tempBit == '1'){
                if(LIBRESCP == libres)
                    return ((i+1) - libres);
                libres = 0;
            }
        }

        return -1;

    }else if(fit == 'W')
    {
        int libres = 0;
        int auxLibres = -1;

        for (int i = 0; i < tam_bm; i++) {
            fseek(fp,inicio_bm + i, SEEK_SET);
            tempBit = static_cast<char>(fgetc(fp));
            if(tempBit == '0'){
                libres++;
                if(i+1 == tam_bm){
                    if(auxLibres == -1 || auxLibres == 0)
                        auxLibres = libres;
                    else {
                        if(auxLibres < libres)
                            auxLibres = libres;
                    }
                    libres = 0;
                }
            }else if(tempBit == '1'){
                if(auxLibres == -1 || auxLibres == 0)
                    auxLibres = libres;
                else{
                    if(auxLibres < libres)
                        auxLibres = libres;
                }
                libres = 0;
            }
        }

        for (int i = 0; i < tam_bm; i++) {
            fseek(fp,inicio_bm + i, SEEK_SET);
            tempBit = static_cast<char>(fgetc(fp));
            if(tempBit == '0'){
                libres++;
                if(i+1 == tam_bm)
                    return ((i+1) - libres);
            }else if(tempBit == '1'){
                if(auxLibres == libres)
                    return ((i+1) - libres);
                libres = 0;
            }
        }

        return -1;
    }

    return 0;
}

int MKGRP_::getID_grp(){
    FILE *fp = fopen(sesion.direccion.data(),"rb+");

    char cadena[400] = "\0";
    int aux_id = -1;
    SuperBloque super;
    InodoTable inodo;
    fseek(fp,sesion.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,fp);
    //Leemos el inodo del archivo users.txt
    fseek(fp,super.s_inode_start + static_cast<int>(sizeof(InodoTable)), SEEK_SET);
    fread(&inodo,sizeof(InodoTable),1,fp);

    for(int i = 0; i < 15; i++)
    {
        if(inodo.i_block[i] != -1)
        {
            BloqueArchivo archivo;
            fseek(fp,super.s_block_start,SEEK_SET);
            for(int j = 0; j <= inodo.i_block[i]; j++)
            {
                fread(&archivo,sizeof(BloqueArchivo),1,fp);
            }
            strcat(cadena,archivo.b_content);
        }
    }

    fclose(fp);

    char *end_str;
    char *token = strtok_r(cadena,"\n",&end_str);
    while(token != nullptr){
        char id[2];
        char tipo[2];
        char *end_token;
        char *token2 = strtok_r(token,",",&end_token);
        strcpy(id,token2);
        if(strcmp(id,"0") != 0){//Verificar que no sea un U/G eliminado
            token2 = strtok_r(nullptr,",",&end_token);
            strcpy(tipo,token2);
            if(strcmp(tipo,"G") == 0){
                aux_id = atoi(id);
            }

        }
        token = strtok_r(nullptr,"\n",&end_str);
    }
    return ++aux_id;
}

void MKGRP_::guardarJournal(char* operacion,int tipo,int permisos,char *nombre,char *content){
    SuperBloque super;
    Journal registro;
    strcpy(registro.journal_operation_type,operacion);
    registro.journal_type = tipo;
    strcpy(registro.journal_name,nombre);
    strcpy(registro.journal_content,content);
    registro.journal_date = time(nullptr);
    registro.journal_owner = sesion.id_user;
    registro.journal_permissions = permisos;
    FILE *fp = fopen(sesion.direccion.data(),"r+b");

    Journal registroAux;
    bool ultimo = false;
    fseek(fp,sesion.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,fp);
    int inicio_journal = sesion.inicioSuper + static_cast<int>(sizeof(SuperBloque));
    int final_journal = super.s_bm_inode_start;
    fseek(fp,inicio_journal,SEEK_SET);
    while((ftell(fp) < final_journal) && !ultimo){
        fread(&registroAux,sizeof(Journal),1,fp);
        if(registroAux.journal_type != 0 && registroAux.journal_type != 1)
            ultimo = true;
    }
    fseek(fp,ftell(fp)- static_cast<int>(sizeof(Journal)),SEEK_SET);
    fwrite(&registro,sizeof(Journal),1,fp);
    fclose(fp);
}
