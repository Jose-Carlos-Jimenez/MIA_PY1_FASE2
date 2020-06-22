#ifndef RMGRP_H
#define RMGRP_H

#endif // RMGRP_H

#include <iostream>
#include <string.h>
#include <structs.h>
#include <parser.h>

using namespace std;

class RMGRP_
{
private:
    string name;
    bool correct;
public:
    RMGRP_():name(""), correct(true){};
    void setName(char* name);
    void semantic();
    void run();
    int buscarGrupo();
    void eliminarGrupo();
};

extern bool loged;
extern Sesion sesion;

void RMGRP_::setName(char *name)
{
    this->name = name;
    if(name[0] == '\"')
    {
        this->name = this->name.substr(1, this->name.length() - 2);
    }
}

void RMGRP_::semantic()
{
    if(this->name == "")
    {
        correct = false;
        cout << "El parámetro name es obligatorio." << endl;
    }
}

void RMGRP_::run()
{
    semantic();
    if(correct)
    {
        if(loged){
            if(sesion.id_user == 1 && sesion.id_grp == 1){//Usuario root
                int grupo = buscarGrupo();
                if(grupo != -1)
                {
                    eliminarGrupo();
                }
                else cout << "El grupo no existe." << endl;
            }else
               cout << "Solo el usuario root puede ejecutar este comando." << endl;
        }else
            cout << "Necesita iniciar sesion para poder ejecutar este comando." << endl;
    }
}

int RMGRP_::buscarGrupo(){
    FILE *fp = fopen(sesion.direccion.data(),"r+b");
    char cadena[400] = "\0";
    InodoTable inodo;
    SuperBloque super;
    fseek(fp,sesion.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,fp);
    fseek(fp,super.s_inode_start + static_cast<int>(sizeof(InodoTable)), SEEK_SET);
    fread(&inodo,sizeof(InodoTable),1,fp);

    for(int i = 0; i < 15; i++)
    {
        if(inodo.i_block[i] != -1){
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
        char group[12];
        char *end_token;
        char *token2 = strtok_r(token,",",&end_token);
        strcpy(id,token2);
        if(strcmp(id,"0") != 0)
        {
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

void RMGRP_::eliminarGrupo(){
    FILE *fp = fopen(sesion.direccion.data(),"r+b");

    SuperBloque super;
    InodoTable inodo;
    BloqueArchivo archivo;

    int col = 1;
    char actual;
    int posicion = 0;
    int numBloque = 0;
    int id = -1;
    char tipo = '\0';
    string grupo = "";
    string palabra = "";
    bool flag = false;


    fseek(fp,sesion.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,fp);

    fseek(fp,super.s_inode_start + static_cast<int>(sizeof(InodoTable)),SEEK_SET);
    fread(&inodo,sizeof(InodoTable),1,fp);

    for (int i = 0; i < 12; i++) {
        if(inodo.i_block[i] != -1){
            fseek(fp,super.s_block_start + static_cast<int>(sizeof(BloqueArchivo))*inodo.i_block[i],SEEK_SET);
            fread(&archivo,sizeof(BloqueArchivo),1,fp);
            for(int j = 0; j < 63; j++){
                actual = archivo.b_content[j];
                if(actual=='\n'){
                    if(tipo == 'G'){
                        grupo = palabra;
                        if(strcmp(grupo.c_str(),this->name.data()) == 0){
                            fseek(fp,super.s_block_start+static_cast<int>(sizeof(BloqueArchivo))*numBloque,SEEK_SET);
                            fread(&archivo,sizeof(BloqueCarpeta),1,fp);
                            archivo.b_content[posicion] = '0';
                            fseek(fp,super.s_block_start+static_cast<int>(sizeof(BloqueArchivo))*numBloque,SEEK_SET);
                            fwrite(&archivo,sizeof(BloqueArchivo),1,fp);
                            cout << "Grupo eliminado con exito" << endl;
                            flag = true;
                            break;
                        }
                    }
                    col = 1;
                    palabra = "";
                }else if(actual != ','){
                    palabra += actual;
                    col++;
                }else if(actual == ','){
                    if(col == 2){
                        id = atoi(palabra.c_str());
                        posicion = j-1;
                        numBloque = inodo.i_block[i];
                    }
                    else if(col == 4)
                        tipo = palabra[0];
                    col++;
                    palabra = "";
                }
            }
            if(flag)
                break;
        }
    }

    fclose(fp);
}
