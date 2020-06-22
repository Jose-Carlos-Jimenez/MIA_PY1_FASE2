#ifndef LOGIN_H
#define LOGIN_H

#endif // LOGIN_H
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <parser.h>
#include <MOUNT.h>
#include <REP.h>

using namespace  std;

class LOGIN_
{
private:
    string usr;
    string pass;
    string id;
    bool correct;

public:
    LOGIN_():usr(""), pass(""), id(""),correct(true){}
    void setUsr(char* usr);
    void setPass(char* pass);
    void setId(char* id);
    void semantic();
    int log();
    void run();
    int verificarDatos(string direccion);
    char getLogicFit(string direccions);
};

extern bool loged;
extern QList<MOUNT_> *mounted;
extern Sesion sesion;

void LOGIN_::setUsr(char *usr)
{
    this->usr = usr;
    if(this->usr[0] == '\"')
    {
        this->usr = this->usr.substr(1,this->usr.length()-2);
    }
}

void LOGIN_::setPass(char *pass)
{
    this->pass = pass;
    if(this->pass[0] == '\"')
    {
        this->pass = this->pass.substr(1,this->pass.length()-2);
    }
}

void LOGIN_::setId(char *id)
{
    this->id = id;
    if(this->id[0] == '\"')
    {
        this->id = this->id.substr(1, this->usr.length()-2);
    }
}

void LOGIN_::semantic()
{
    if(this->id == "")
    {
        cout << "El parámetro id es obligatorio para loguearse." << endl;
        correct = false;
    }
    if(this->usr == "")
    {
        cout << "El parámetro usr es obligatorio para loguearse." << endl;
        correct = false;
    }
    if(this->pass == "")
    {
        cout << "El parámetro pass es obligatorio para loguearse." << endl;
        correct = false;
    }
}

int LOGIN_::log()
{
    int partIndex = -1;
    MOUNT_ disk;
    int aux = 0;
    QList<MOUNT_>::iterator i;
    for(i=mounted->begin(); i != mounted->end(); i++)
    {
        if(i->getId() == this->id)
        {
            partIndex = i->partIndex();//Obtengo el indice de la partición si es primaria o extendida.
            disk = mounted->at(aux);// Obtengo la referencia al disco montado.
            break;
        }
        aux++;
    }
    if(partIndex!= -1){
        MBR masterboot;
        SuperBloque super;
        InodoTable inodo;
        FILE *fp = fopen(disk.getPath().data(),"r+b");
        fread(&masterboot,sizeof(MBR),1,fp);
        fseek(fp,masterboot.mbr_partitions[partIndex].part_start,SEEK_SET);
        fread(&super,sizeof(SuperBloque),1,fp);
        fseek(fp,super.s_inode_start + static_cast<int>(sizeof(InodoTable)),SEEK_SET);
        fread(&inodo,sizeof(InodoTable),1,fp);
        fseek(fp,super.s_inode_start + static_cast<int>(sizeof(InodoTable)),SEEK_SET);
        inodo.i_atime = time(nullptr);
        fwrite(&inodo,sizeof(InodoTable),1,fp);
        fclose(fp);
        sesion.inicioSuper = masterboot.mbr_partitions[partIndex].part_start;
        sesion.fit = masterboot.mbr_partitions[partIndex].part_fit;
        sesion.inicioJournal = masterboot.mbr_partitions[partIndex].part_start + static_cast<int>(sizeof(SuperBloque));
        sesion.tipo_sistema = super.s_filesystem_type;
        return verificarDatos(disk.getPath());
    }else{
        partIndex = disk.LogicPartIndex();
        if(partIndex != -1){
            SuperBloque super;
            InodoTable inodo;
            FILE *fp = fopen(disk.getPath().data(),"r+b");
            fseek(fp,partIndex+ static_cast<int>(sizeof(EBR)),SEEK_SET);
            fread(&super,sizeof(SuperBloque),1,fp);
            fseek(fp,super.s_inode_start + static_cast<int>(sizeof(InodoTable)),SEEK_SET);
            fread(&inodo,sizeof(InodoTable),1,fp);
            fseek(fp,super.s_inode_start + static_cast<int>(sizeof(InodoTable)),SEEK_SET);
            inodo.i_atime = time(nullptr);
            fwrite(&inodo,sizeof(InodoTable),1,fp);
            fclose(fp);
            sesion.inicioSuper = partIndex + static_cast<int>(sizeof(EBR));
            sesion.fit = getLogicFit(disk.getPath());
            return verificarDatos(disk.getPath());
        }
    }
    return 0;
}

void LOGIN_::run()
{
    semantic();
    if(this->correct)
    {
        if(!loged)
        {
            int res = log();
            if(res==1)
            {
                loged = true;
                cout << "Se ha logueado con éxito" << endl;
            }
            else if(res==2)
            {
                cout << "Contraseña incorrecta." << endl;
            }
            else if(res == 0 )
            {
                cout << "Usuario incorrecto." << endl;
            }
            else
            {
                cout << "No se ha podido iniciar sesión." << endl;
            }
        }
        else
        {
            cout << "Ya se encuentra logueado." << endl;
        }
    }
}

int LOGIN_::verificarDatos(string direccion)
{
    FILE *file = fopen(direccion.data(),"r+b");

    char cadena[400] = "\0";
    SuperBloque super;
    InodoTable inodo;

    fseek(file,sesion.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,file);
    //Leemos el inodo del archivo users.txt
    fseek(file,super.s_inode_start + static_cast<int>(sizeof(InodoTable)),SEEK_SET);
    fread(&inodo,sizeof(InodoTable),1,file);

    for(int i = 0; i < 15; i++){
        if(inodo.i_block[i] != -1){
            BloqueArchivo archivo;
            fseek(file,super.s_block_start,SEEK_SET);
            for(int j = 0; j <= inodo.i_block[i]; j++){
                fread(&archivo,sizeof(BloqueArchivo),1,file);
            }
            strcat(cadena,archivo.b_content);
        }
    }

    fclose(file);

    char *end_str;
    char *token = strtok_r(cadena,"\n",&end_str);
    while(token != nullptr){
        char id[2];
        char tipo[2];
        string group;
        char user_[12];
        char password_[12];
        char *end_token;
        char *token2 = strtok_r(token,",",&end_token);
        strcpy(id,token2);
        if(strcmp(id,"0") != 0){
            token2=strtok_r(nullptr,",",&end_token);
            strcpy(tipo,token2);
            if(strcmp(tipo,"U") == 0){
                token2 = strtok_r(nullptr,",",&end_token);
                group = token2;
                token2 = strtok_r(nullptr,",",&end_token);
                strcpy(user_,token2);
                token2 = strtok_r(nullptr,",",&end_token);
                strcpy(password_,token2);
                if(strcmp(user_,this->usr.data()) == 0){
                    if(strcmp(password_,this->pass.data()) == 0){
                        sesion.direccion = direccion;
                        sesion.id_user = atoi(id);
                        REP_ *r = new REP_();
                        sesion.id_grp = r->buscarGrupo(group);
                        return 1;
                    }else
                        return 2;
                }
            }
        }
        token = strtok_r(nullptr,"\n",&end_str);
    }

    return 0;
}

char LOGIN_::getLogicFit(string direccion)
{
    FILE *fp;
    if((fp = fopen(direccion.data(),"r+b"))){
        int extendida = -1;
        MBR masterboot;
        fseek(fp,0,SEEK_SET);
        fread(&masterboot,sizeof(MBR),1,fp);
        for(int i = 0; i < 4; i++){
            if(masterboot.mbr_partitions[i].part_type == 'E'){
                extendida = i;
                break;
            }
        }
        if(extendida != -1){
            EBR extendedBoot;
            fseek(fp, masterboot.mbr_partitions[extendida].part_start,SEEK_SET);
            while(fread(&extendedBoot,sizeof(EBR),1,fp)!=0 && (ftell(fp) < masterboot.mbr_partitions[extendida].part_start + masterboot.mbr_partitions[extendida].part_size)){
                if(strcmp(extendedBoot.part_name, id.data()) == 0){
                    return extendedBoot.part_fit;
                }
            }
        }
        fclose(fp);
    }
    return -1;
}
