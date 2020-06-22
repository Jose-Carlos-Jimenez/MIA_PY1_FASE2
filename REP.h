#pragma once
#ifndef REP_H
#define REP_H

#endif // REP_H

#include "MOUNT.h"

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <structs.h>
#include "parser.h"
#include <libgen.h>
#include <chrono>
#include <thread>

using namespace std;

class REP_
{
private:
    char *id; /// Identificador de la partición montada.
    char *ruta;/// Destino del reporte.
    string path;/// Ruta auxiliar del disco que se leera.
    string cont;
    char *name;/// Nombre que se le dará al reporte.
    bool correct;/// Semántica de la acción.
    bool isMounted;/// Indica si la partición que se desea está montada.
public:
    /**
     * Constructor
    */
    REP_():id(0),ruta(0),path(""),name(0),correct(false),isMounted(false){}
    /**
     * Configura el id de la partición montada a escribir.
     * @param id: identificador de la partición montada en el sistema.
    */
    void setId(char* id);

    /**
     * Configura la ruta en donde se guardará el reporte.
     * @param path: ruta que se pretende guardar el reporte.
    */
    void setPath(char* path);

    /**
     * Configura la ruta en la que se guardará
     * ya que se necesitan variantes para guardar el dot
     * y para la imagen.
    */
    void confRuta();

    /**
     * Guarda el valor de la ruta
     * @param ruta: dirección en la que se almacenará el reporte.
    */
    void setRuta(char* ruta)
    {
        this->ruta = ruta;
    }

    void setCont(char* cont)
    {
        this->cont = cont;
    }

    /**
     * Guarda el nombre de la partición montada que se reportará.
     * @param name: indica el nombre de la partición en el sistema de particiones montadas.
    */
    void setName(char* name)
    {
        this->name = name;
    }

    /*
     * Obtiene el id de la partición.
    */
    char* getId()
    {
        return this->id;
    }

    /*
     * Obtiene la ruta que se eligió como destino.
    */
    char* getRuta()
    {
        return  this->ruta;
    }

    /**
     * Obtiene el nombre que se le dará al rerporte.
    */
    char* getName()
    {
        return  this->name;
    }

    /**
     * Método para verificar semántica de la operación
    */
    void semantic();

    /**
     * Método para ejecutar
    */
    void run();

    /**
     * Método para convertir un string a minúsculas.
    */
    string toLowerString(string input);

    /**
     * Método que obtiene el directorio de un archivo.
    */
    string dirNam(string);

    /**
     * Método para generar el reporte de MBR
    */
    void reportMBR();

    /**
     * Método para generar el reporte del disco
    */
    void reportDISK();
    /**
     * Método para reportar los inodos.
    */
    void reportINODE();
    /**
     * Método para reportar el Journaling.
    */
    void reportJOURNAL();

    /**
     * Método para reportar el superbloque.
    */
    void reportBLOQUE();

    /**
     * Método para reportar el bitmap de los iNodos
    */
    void reportBMI();

    /**
     * Método para reportar el bitmap de los bloques
    */
    void reportBMB();

    /**
     * Método para reportar el árbol del EXT3
    */
    void reportTREE();

    /**
     * Método auxiliar para generar el dot del árbol.
     * @param ruta: Lugar en donde se guardará el repositorio
     * @param inicio: byte inicial en donde se debe leer el árbol.
    */
    void graficarTree(string ruta, int inicio);

    void reportFILE();
    void graphFILE(int,string, int);
    int findFile(FILE* fp, string path);
    int byteInodoBloque(FILE*,int, char);

    void reportSB();

    void reportLS();
    Usuario getUsuario(string direccion, int inicioSuper, int usuario);

    int buscarGrupo(string name);

};

extern QList<MOUNT_> *mounted;
extern struct Sesion sesion;

void REP_::setId(char *id)
{
    this->id = id;
    if(id[0] == '\"')
    {
        string aux = id;
        aux = aux.substr(1,aux.size()-2);
        strcpy(this->id, aux.c_str());
    }
}

void REP_::setPath(char *id)
{
    this->path = "";
    path.append(id);
    if(path[0]== '\"')
    {
        path=path.substr(1, path.size()-2);
    }
}

void REP_::confRuta()
{
    QList<MOUNT_>::iterator i;
    cout << "Buscando montada... " << endl;
    for(i=mounted->begin(); i != mounted->end(); i++)
    {
        cout << i->getId() << endl;
        if(i->getId() == this->getId())
        {
            char letras[255];
            strcpy(letras,i->getPath().c_str());
            this->ruta =letras;
            this->isMounted = true;
            break;
        }
    }
}

void REP_::semantic()
{
    if(this->getId() !=0 && this->getName() != 0 && this->path != "")
    {
        this->correct = true;
    }
}

void REP_::run()
{
    semantic();
    if(this->correct)
    {
        this->confRuta();
        if(isMounted)
        {
            string nameS(this->name);
            if(toLowerString(nameS) == "mbr")
            {
                reportMBR();
            }
            else if(toLowerString(nameS) == "inode")
            {
                reportINODE();
            }
            else if (toLowerString(nameS) == "block")
            {
                reportBLOQUE();
            }
            else if(toLowerString(nameS) == "disk")
            {
                reportDISK();
            }
            else if(toLowerString(nameS) == "journaling")
            {
                reportJOURNAL();
            }
            else if(toLowerString(nameS) == "bm_inode")
            {
                reportBMI();
            }
            else if(toLowerString(nameS) == "bm_block")
            {
                reportBMB();
            }
            else if(toLowerString(nameS) == "tree")
            {
                reportTREE();
            }
            else if(toLowerString(nameS) == "file")
            {
                reportFILE();
            }
            else if(toLowerString(nameS) == "sb")
            {
                reportSB();
            }
            else if(toLowerString(nameS) == "ls")
            {
                reportLS();
            }
        }
        else
        {
            cout << "La partición que deseas reportar no está montada." << endl;
        }
    }
    else
    {
        cout << "Faltan parámetros para generar el reporte." << endl;
    }
}

string REP_::toLowerString(string input)
{
    std::for_each(input.begin(), input.end(), [](char & c){
        c = ::tolower(c);
    });
    return input;
}

string REP_::dirNam(string val)
{
    string directory = "";
    const size_t last_slash_idx = val.rfind('/');
    if (std::string::npos != last_slash_idx)
    {
        directory = val.substr(0, last_slash_idx);
    }
    return directory;
}

void REP_::reportMBR()
{
    string dir = this->getRuta();//Debo cambiar esta ruta por la que encuentre de la partición montada
    FILE *f;
    if((f = fopen(dir.c_str(),"rb+")))
    {
        string dot = "digraph DISK_MBR{\n";
        dot+= "MBR[\n";
        dot+="shape=none;label=<<TABLE CELLSPACING='-1' CELLBORDER='1' WIDTH='800' HEIGHT= '1000'>\n";
        dot+= "<tr><td WIDTH='400'>NOMBRE</td><td WIDTH='400'>VALOR</td></tr>";
        MBR m;
        fseek(f,0,SEEK_SET);
        fread(&m,sizeof(MBR),1,f);
        dot += "<tr>  <td><b>mbr_tamaño</b></td><td>";
        dot += to_string(m.mbr_tamano);
        dot +=" bytes</td>  </tr>\n";
        struct tm *tm;
        char fecha[100];
        tm = localtime(&m.mbr_fecha_creacion);
        strftime(fecha,100,"%d/%m/%y %H:%S", tm);
        dot+= "<tr>  <td><b>mbr_fecha_creacion</b></td> <td>";
        dot+=fecha;
        dot+= "</td>  </tr>\n";
        dot+="<tr>  <td><b>mbr_disk_signature</b></td> <td>";
        dot+=to_string(m.mbr_disk_signature);
        dot+= "</td>  </tr>\n";
        dot+= "<tr>  <td><b>Disk_fit</b></td> <td>";
        dot.push_back(m.disk_fit);
        dot+= "</td>  </tr>\n";
        int ext = -1;
        for (int i = 0; i < 4; i++){
            if(m.mbr_partitions[i].part_start!=-1 && m.mbr_partitions[i].part_status!='1'){
                if(m.mbr_partitions[i].part_type == 'E')ext = i;
                char status[3];
                if(m.mbr_partitions[i].part_status == '0')strcpy(status,"0");
                else if(m.mbr_partitions[i].part_status == '2')strcpy(status,"2");
                dot+= "<tr>  <td><b>part_status_";
                dot+= to_string(i+1);
                dot+= "</b></td> <td>";
                dot.push_back(m.mbr_partitions[i].part_status);
                dot+= "</td>  </tr>\n";
                dot+= "<tr>  <td><b>part_type_";
                dot+= to_string(i+1);
                dot+="</b></td> <td>";
                dot.push_back(m.mbr_partitions[i].part_type);
                dot+= "</td>  </tr>\n";
                dot+= "<tr>  <td><b>part_fit_";
                dot+= to_string(i+1);
                dot+= "</b></td> <td>";
                dot.push_back(m.mbr_partitions[i].part_fit);
                dot+= "</td>  </tr>\n";
                dot+= "<tr>  <td><b>part_start_";
                dot+= to_string(i+1);
                dot+= "</b></td> <td>";
                dot+= to_string(m.mbr_partitions[i].part_start);
                dot+= "</td>  </tr>\n";
                dot+= "<tr>  <td><b>part_size_";
                dot+= to_string(i+1);
                dot+= "</b></td> <td>";
                dot+= to_string(m.mbr_partitions[i].part_size);
                dot+= "</td>  </tr>\n";
                dot+= "<tr>  <td><b>part_name_";
                dot+= to_string(i+1);
                dot+= "</b></td> <td>";
                dot+= m.mbr_partitions[i].part_name;
                dot+= "</td>  </tr>\n";
            }
        }
        dot += "</TABLE>\n>];\n";

        if(ext != -1){
            int index_ebr = 1;
            EBR ebr;
            fseek(f,m.mbr_partitions[ext].part_start,SEEK_SET);
            while(fread(&ebr,sizeof(EBR),1,f)!=0 && (ftell(f) < m.mbr_partitions[ext].part_start + m.mbr_partitions[ext].part_size)) {

                if(ebr.part_status != '1'){
                    dot+="subgraph cluster_";
                    dot+= to_string(index_ebr);
                    dot+= "{\n label=\"EBR_";
                    dot+= to_string(index_ebr);
                    dot+="\"\n";
                    dot+= "\ntbl_";
                    dot+= to_string(index_ebr);
                    dot+= "[shape=box, label=<\n ";
                    dot+= "<TABLE border='0' cellborder='1' cellspacing='0'  width='300' height='160' >\n ";
                    dot+= "<tr>  <td width='150'><b>Nombre</b></td> <td width='150'><b>Valor</b></td>  </tr>\n";
                    char status[3];
                    if(ebr.part_status == '0')strcpy(status,"0");
                    else if(ebr.part_status == '2')strcpy(status,"2");
                    dot+="<tr>  <td><b>part_status_1</b></td> <td>";
                    dot+=status;
                    dot+= "</td>  </tr>\n";
                    dot+= "<tr>  <td><b>part_fit_1</b></td> <td>";
                    dot.append(1,ebr.part_fit);
                    dot+= "</td>  </tr>\n";
                    dot+= "<tr>  <td><b>part_start_1</b></td> <td>";
                    dot+= to_string(ebr.part_start);
                    dot+= "</td>  </tr>\n";
                    dot+= "<tr>  <td><b>part_size_1</b></td> <td>";
                    dot+= to_string(ebr.part_size);
                    dot+= "</td>  </tr>\n";
                    dot+= "<tr>  <td><b>part_next_1</b></td> <td>";
                    dot+= to_string(ebr.part_next);
                    dot+= "</td>  </tr>\n";
                    dot+= "<tr>  <td><b>part_name_1</b></td> <td>";
                    dot+= ebr.part_name;
                    dot+= "</td>  </tr>\n";
                    dot+= "</TABLE>\n>];\n}\n";
                    index_ebr++;
                }
                if(ebr.part_next == -1)break;
                else fseek(f,ebr.part_next,SEEK_SET);
            }
        }
        dot+="}\n";
        fclose(f);

        // Obtener la ruta.
        string pathClone = this->path;
        string pathTwice = this->path;
        string terminacion;
        pathTwice += ".txt";
        const size_t last_slash_idx = pathClone.find_last_of(".");
        if (std::string::npos != last_slash_idx)
        {
            terminacion = pathClone.substr(last_slash_idx, pathClone.length());
            pathClone = pathClone.substr(0, last_slash_idx);
        }

        // Creando comando para crear la carpeta.
        char* ruta_aux = new char(this->path.length());
        strcpy(ruta_aux, this->path.c_str());
        char* path = new char(this->path.length());
        strcpy(path,this->path.c_str());
        string comando = "sudo mkdir -p \'";
        comando+= dirname(path);
        comando+= '\'';
        system(comando.c_str());

        // Comando para permisos.
        string comandow = "sudo chmod -R 777 \'";
        comandow+= dirname(ruta_aux);
        comandow += '\'';
        system(comandow.c_str());

        string cEliminar = "sudo rm '";
        cEliminar += pathTwice + "\'";
        system(cEliminar.c_str());
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        // Creando el file.
        FILE *nuevo = fopen(pathTwice.c_str(),"w+");
        freopen(NULL,"w+",nuevo);
        char dest[dot.length()];
        strcpy(dest,dot.c_str());
        fprintf(nuevo,"%s\n",dest);
        fclose(nuevo);
        string comandoS = "dot \'";
        comandoS += pathTwice;
        comandoS +="\' -o \'" + pathClone + terminacion + " \' -T" + terminacion.substr(1,terminacion.length());
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        system(comandoS.c_str());
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        cout << "Reporte del MBR ha sido creado." << endl;
    }
    else
    {
        cout << "El disco no existe." << endl;
    }

}

void REP_::reportDISK()
{
    string pathCopy = this->getRuta();//Debo de ponerle la path obtenida
    FILE *fp;
    if((fp = fopen(pathCopy.c_str(),"r"))){
        string dest ="digraph G{\n\n";
        dest+= "tbl[\nshape=box\nlabel=<\n";
        dest+=  "<table border='0' cellborder='2' width='500' height=\"180\">\n";
        dest+=  "<tr>\n";
        dest+=  "<td height='200' width='100'> MBR </td>\n";
        MBR master;
        fseek(fp,0,SEEK_SET);
        fread(&master,sizeof(MBR),1,fp);
        int size = master.mbr_tamano;
        double used = 0;
        for(int i = 0; i < 4; i++){
            int partSize = master.mbr_partitions[i].part_size;
            if(master.mbr_partitions[i].part_start > -1){

                double op1=size;
                double op2=partSize;
                double real_ = (op2/op1);
                double real = real_*100.0;

                double width = 200;
                used += real;
                if(master.mbr_partitions[i].part_status != '1'){
                    if(master.mbr_partitions[i].part_type == 'E')//
                    {
                        EBR ebr;
                        dest+= "<td  height='200' width='100'>\n     <table border='0'  height='200' WIDTH='100' cellborder='1'>\n";
                        dest+= "<tr>  <td height='60' colspan='15'>EXTENDIDA</td>  </tr>\n     <tr>\n";
                        fseek(fp, master.mbr_partitions[i].part_start,SEEK_SET);
                        fread(&ebr,sizeof(EBR),1,fp);
                        if(ebr.part_size != 0){
                            fseek(fp, master.mbr_partitions[i].part_start,SEEK_SET);
                            while(fread(&ebr,sizeof (EBR),1,fp)!=0 && (ftell(fp) < (master.mbr_partitions[i].part_start + master.mbr_partitions[i].part_size))){
                                double parcial = ebr.part_size;
                                double porcentaje_real = (parcial*100)/size;
                                if(porcentaje_real!=0){
                                    if(ebr.part_status != '1'){
                                        dest+=  "<td height='200' width='75'>EBR</td>\n";
                                        dest+=  "     <td height='200' width='150'>LOGICA<br/>Porcentaje: ";
                                        dest += to_string(porcentaje_real);
                                        dest+= "%</td>\n";
                                    }else{
                                        dest+=  "      <td height='200' width='150'>LIBRE <br/> Porcentaje: ";
                                        dest+= to_string(porcentaje_real);
                                        dest+= "%</td>\n";
                                    }
                                    if(ebr.part_next==-1){
                                        parcial = (master.mbr_partitions[i].part_start + master.mbr_partitions[i].part_size) - (ebr.part_start + ebr.part_size);
                                        porcentaje_real = (parcial*100)/size;
                                        if(porcentaje_real!=0){
                                            dest+=  "     <td height='200' width='150'>LIBRE <br/> Porcentaje: ";
                                            dest+= to_string(porcentaje_real);
                                            dest+="% </td>\n";
                                        }
                                        break;
                                    }
                                    else
                                    {
                                        fseek(fp,ebr.part_next,SEEK_SET);
                                    }
                                }
                            }
                        }else{
                            dest+= "     <td height='140'> Utilizado: ";
                            dest+= real;
                            dest+= "%</td>";
                        }
                        dest+= "     </tr>\n     </table>\n     </td>\n";

                        if(i!=3){
                            int p1 = master.mbr_partitions[i].part_start + master.mbr_partitions[i].part_size;
                            int p2 = master.mbr_partitions[i+1].part_start;
                            if(master.mbr_partitions[i+1].part_start != -1){
                                if((p2-p1)!=0){
                                    int fragmentacion = p2-p1;
                                    double real = (fragmentacion*100)/size;
                                    double porcentaje_aux = 200;
                                    dest+= "     <td height='200' width='";
                                    dest+= to_string(porcentaje_aux);
                                    dest+= "'>LIBRE<br/> Utilizado: ";
                                    dest+= to_string(real);
                                    dest+= "%</td>\n";
                                }
                            }
                        }else{
                            int p1 = master.mbr_partitions[i].part_start + master.mbr_partitions[i].part_size;
                            int mbr_size = size + (int)sizeof(MBR);
                            if((mbr_size-p1)!=0){
                                double libre = (mbr_size - p1) + sizeof(MBR);
                                double real = (libre*100)/size;
                                double porcentaje_aux = 100;
                                dest+=  "     <td height='200' width='";
                                dest+= to_string(porcentaje_aux);
                                dest+="'>LIBRE<br/> Utilizado:: ";
                                dest+= to_string(real);
                                dest+="%</td>\n";
                            }
                        }
                    }else{
                        dest+=  "<td height='200' width='200'>PRIMARIA <br/> Utilizado: ";
                        dest+= to_string(real);
                        dest+= "%</td>\n";
                        if(i==3){
                            int suposed = master.mbr_partitions[i].part_start + master.mbr_partitions[i].part_size;
                            int mbr_size = size + (int)sizeof(MBR);
                            if((mbr_size-suposed)!=0){
                                double free = (mbr_size - suposed) + sizeof(MBR);
                                double real = (free*100)/size;
                                double aux = real*4;
                                dest+=  "<td height='200' width='";
                                dest+= to_string(aux);
                                dest+= "'>LIBRE<br/> Utilizado: ";
                                dest+= to_string(real);
                                dest+="%</td>\n";
                            }
                        }else{
                            int suposed = master.mbr_partitions[i].part_start + master.mbr_partitions[i].part_size;
                            int exact = master.mbr_partitions[i+1].part_start;
                            if(master.mbr_partitions[i+1].part_start != -1){
                                if((exact-suposed)!=0){
                                    int fragment = exact-suposed;
                                    double _real = (fragment*100)/size;
                                    double aux = (_real*500)/100;
                                    dest+= "<td height='200' width='";
                                    dest+= to_string(aux);
                                    dest+="'>LIBRE<br/> Utilizado: ";
                                    dest+="%</td>\n";
                                }
                            }
                        }
                    }
                }else{
                    dest+= "     <td height='200' width='";
                    dest+= to_string(width);
                    dest+= "'>LIBRE <br/> Utilizado: ";
                    dest+= to_string(real);
                    dest+= "%</td>\n";
                }
            }
        }
        dest+= "</tr> \n     </table>        \n>];\n\n}";

        // Obtener la ruta.
        string pathClone = this->path;
        string pathTwice = this->path;
        string terminacion;
        pathTwice += ".txt";
        const size_t last_slash_idx = pathClone.find_last_of(".");
        if (std::string::npos != last_slash_idx)
        {
            terminacion = pathClone.substr(last_slash_idx, pathClone.length());
            pathClone = pathClone.substr(0, last_slash_idx);
        }

        // Creando comando para crear la carpeta.
        char* ruta_aux = new char(this->path.length());
        strcpy(ruta_aux, this->path.c_str());
        char* path = new char(this->path.length());
        strcpy(path,this->path.c_str());
        string comando = "sudo mkdir -p \'";
        comando+= dirname(path);
        comando+= '\'';
        system(comando.c_str());

        // Comando para permisos.
        string comandow = "sudo chmod -R 777 \'";
        comandow+= dirname(ruta_aux);
        comandow += '\'';
        system(comandow.c_str());

        //Eliminando el reporte previo
        string cEliminar = "sudo rm '";
        cEliminar += pathTwice + "\'";
        system(cEliminar.c_str());
        string dotF = dest;
        char arreglo[dotF.length()];
        strcpy(arreglo, dotF.c_str());

        // Creando el file.
        FILE *nuevo = fopen(pathTwice.c_str(),"w");
        fprintf(nuevo,"%s\n",arreglo);
        fclose(nuevo);
        string comandoS = "dot \'";
        comandoS += pathTwice;
        comandoS +="\' -o \'" + pathClone + terminacion + " \' -T" + terminacion.substr(1,terminacion.length());
        system(comandoS.c_str());
        cout << "Reporte del DISK ha sido creado." << endl;
    }
}

void REP_::reportINODE()
{
    // -----------------------OBTENER LOS DATOS PARA LEER EL DISCO QUE QUIERO ---------------------------------------------------------
    int partIndex = -1;
    MOUNT_ disk;
    int aux = 0;
    QList<MOUNT_>::iterator i;
    for(i=mounted->begin(); i != mounted->end(); i++)
    {
        if(i->getId() == this->getId())
        {
            partIndex = i->partIndex();//Obtengo el indice de la partición si es primaria o extendida.
            disk = mounted->at(aux);// Obtengo la referencia al disco montado.
            break;
        }
        aux++;
    }
    // ----------------------------------------------------------------------------------------------------------------------------------

    if(partIndex != -1)// Verifico si existe la partición y se encontró.
    {
        MBR masterboot;
        SuperBloque super;
        FILE *fp = fopen(disk.getPath().c_str(),"r+b");
        fread(&masterboot,sizeof(MBR),1,fp);
        fseek(fp,masterboot.mbr_partitions[partIndex].part_start,SEEK_SET);
        fread(&super,sizeof(SuperBloque),1,fp);

        // -------------------------- ARÉA EN LA QUE SE GRAFICA -------------------------------------------------------------------------
        InodoTable inodo;
        int aux = super.s_bm_inode_start;
        int i = 0;
        char buffer;

        string dest = "digraph G{\n\n";

        while(aux < super.s_bm_block_start){
            fseek(fp,super.s_bm_inode_start + i,SEEK_SET);
            buffer = static_cast<char>(fgetc(fp));
            aux++;
            if(buffer == '1'){
                fseek(fp,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*i,SEEK_SET);
                fread(&inodo,sizeof(InodoTable),1,fp);
                dest += "    nodo_";
                dest += to_string(i);
                dest += "[ shape=none fontname=\"Century Gothic\" label=<\n";
                dest += "   <table border=\'0\' cellborder=\'1\' cellspacing=\'0\' bgcolor=\"royalblue\">";
                dest += "    <tr> <td colspan=\'2\'> <b>Inodo ";
                dest += to_string(i);
                dest += "</b> </td></tr>\n";
                dest += "    <tr> <td> i_uid </td> <td bgcolor=\"white\"> ";
                dest += to_string(inodo.i_gid);
                dest += "</td>  </tr>\n";
                dest += "    <tr> <td> i_gid </td> <td bgcolor=\"white\"> ";
                dest += to_string(inodo.i_gid);
                dest += "</td>  </tr>\n";
                dest += "    <tr> <td> i_size </td> <td bgcolor=\"white\"> ";
                dest += to_string(inodo.i_size);
                dest += "</td> </tr>\n";
                struct tm *tm;
                char fecha[100];
                tm=localtime(&inodo.i_atime);
                strftime(fecha,100,"%d/%m/%y %H:%S",tm);
                dest += "    <tr> <td> i_atime </td> <td bgcolor=\"white\"> ";
                dest += fecha ;
                dest += " </td>  </tr>\n";
                tm=localtime(&inodo.i_ctime);
                strftime(fecha,100,"%d/%m/%y %H:%S",tm);
                dest += "    <tr> <td> i_ctime </td> <td bgcolor=\"white\">";
                dest += fecha;
                dest += " </td>  </tr>\n";
                tm=localtime(&inodo.i_mtime);
                strftime(fecha,100,"%d/%m/%y %H:%S",tm);
                dest += "    <tr> <td> i_mtime </td> <td bgcolor=\"white\"> ";
                dest += " </td></tr>\n";
                for(int b = 0; b < 15; b++)
                {
                    dest += "    <tr> <td> i_block_";
                    dest += to_string(b);
                    dest += "</td> <td bgcolor=\"white\">";
                    dest += to_string(inodo.i_block[b]);
                    dest += " </td> </tr>\n";
                }
                dest += "    <tr> <td> i_type </td> <td bgcolor=\"white\"> ";
                dest += to_string(inodo.i_type);
                dest += " </td> </tr>\n";
                dest += "    <tr> <td> i_perm </td> <td bgcolor=\"white\">";
                dest += to_string(inodo.i_perm);
                dest += "</td> </tr>\n";
                dest += "   </table>>]\n";
            }
            i++;
        }
        dest +="\n}";

        // Obtener la ruta.
        string pathClone = this->path;
        string pathTwice = this->path;
        string terminacion;
        pathTwice += ".txt";
        const size_t last_slash_idx = pathClone.find_last_of(".");
        if (std::string::npos != last_slash_idx)
        {
            terminacion = pathClone.substr(last_slash_idx, pathClone.length());
            pathClone = pathClone.substr(0, last_slash_idx);
        }

        // Creando comando para crear la carpeta.
        string ruta_aux = this->path;
        string path = this->path;
        string comando = "sudo mkdir -p \'";
        comando+= dirNam(path);
        comando+= '\'';
        system(comando.c_str());

        // Comando para permisos.
        string comandow = "sudo chmod -R 777 \'";
        comandow+= dirNam(ruta_aux);
        comandow += '\'';
        system(comandow.c_str());

        //Eliminando el reporte previo
        string cEliminar = "sudo rm '";
        cEliminar += pathTwice + "\'";
        system(cEliminar.c_str());

        // Creando el file.
        FILE *nuevo = fopen(pathTwice.data(),"w");
        fprintf(nuevo,"%s\n",dest.data());
        fclose(nuevo);
        string comandoS = "dot \'";
        comandoS += pathTwice;
        comandoS +="\' -o \'" + pathClone + terminacion + " \' -T" + terminacion.substr(1,terminacion.length());
        system(comandoS.c_str());
        cout << "Reporte de inodos generado con exito " << endl;
        fclose(fp);

    }
    else
    {
        int index = disk.LogicPartIndex();
        if(index != -1)
        {
            EBR extendedBoot;
            SuperBloque super;
            FILE *fp = fopen(disk.getPath().c_str(),"r+b");
            fseek(fp,index,SEEK_SET);
            fread(&extendedBoot,sizeof(EBR),1,fp);
            fread(&super,sizeof(SuperBloque),1,fp);
            InodoTable inodo;
            int aux = super.s_bm_inode_start;
            int i = 0;
            char buffer;

            string dest = "digraph G{\n\n";

            while(aux < super.s_bm_block_start){
                fseek(fp,aux + i,SEEK_SET);
                buffer = static_cast<char>(fgetc(fp));
                aux++;
                if(buffer == '1'){
                    fseek(fp,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*i,SEEK_SET);
                    fread(&inodo,sizeof(InodoTable),1,fp);
                    dest += "    nodo_";
                    dest += to_string(i);
                    dest += "[ shape=none fontname=\"Century Gothic\" label=<\n";
                    dest += "   <table border=\'0\' cellborder=\'1\' cellspacing=\'0\' bgcolor=\"royalblue\">";
                    dest += "    <tr> <td colspan=\'2\'> <b>Inodo ";
                    dest += to_string(i);
                    dest += "</b> </td></tr>\n";
                    dest += "    <tr> <td> i_uid </td> <td bgcolor=\"white\"> ";
                    dest += to_string(inodo.i_gid);
                    dest += "</td>  </tr>\n";
                    dest += "    <tr> <td> i_gid </td> <td bgcolor=\"white\"> ";
                    dest += to_string(inodo.i_gid);
                    dest += "</td>  </tr>\n";
                    dest += "    <tr> <td> i_size </td> <td bgcolor=\"white\"> ";
                    dest += to_string(inodo.i_size);
                    dest += "</td> </tr>\n";
                    struct tm *tm;
                    char fecha[100];
                    tm=localtime(&inodo.i_atime);
                    strftime(fecha,100,"%d/%m/%y %H:%S",tm);
                    dest += "    <tr> <td> i_atime </td> <td bgcolor=\"white\"> ";
                    dest += fecha ;
                    dest += " </td>  </tr>\n";
                    tm=localtime(&inodo.i_ctime);
                    strftime(fecha,100,"%d/%m/%y %H:%S",tm);
                    dest += "    <tr> <td> i_ctime </td> <td bgcolor=\"white\">";
                    dest += fecha;
                    dest += "%s </td>  </tr>\n";
                    tm=localtime(&inodo.i_mtime);
                    strftime(fecha,100,"%d/%m/%y %H:%S",tm);
                    dest += "    <tr> <td> i_mtime </td> <td bgcolor=\"white\"> ";
                    dest += " </td></tr>\n";
                    for(int b = 0; b < 15; b++)
                    {
                        dest += "    <tr> <td> i_block_";
                        dest += to_string(b);
                        dest += "</td> <td bgcolor=\"white\">";
                        dest += to_string(inodo.i_block[b]);
                        dest += " </td> </tr>\n";
                    }
                    dest += "    <tr> <td> i_type </td> <td bgcolor=\"white\"> ";
                    dest += to_string(inodo.i_type);
                    dest += " </td> </tr>\n";
                    dest += "    <tr> <td> i_perm </td> <td bgcolor=\"white\">";
                    dest += to_string(inodo.i_perm);
                    dest += "</td> </tr>\n";
                    dest += "   </table>>]\n";
                }
                i++;
            }
            dest +="\n}";
            fclose(fp);

            // Obtener la ruta.
            string pathClone = this->path;
            string pathTwice = this->path;
            string terminacion;
            pathTwice += ".txt";
            const size_t last_slash_idx = pathClone.find_last_of(".");
            if (std::string::npos != last_slash_idx)
            {
                terminacion = pathClone.substr(last_slash_idx, pathClone.length());
                pathClone = pathClone.substr(0, last_slash_idx);
            }

            // Creando comando para crear la carpeta.
            string ruta_aux = this->path;
            string path = this->path;
            string comando = "sudo mkdir -p \'";
            comando+= dirNam(path);
            comando+= '\'';
            system(comando.c_str());

            // Comando para permisos.
            string comandow = "sudo chmod -R 777 \'";
            comandow+= dirNam(ruta_aux);
            comandow += '\'';
            system(comandow.c_str());

            // Creando el file.
            FILE *nuevo = fopen(pathTwice.c_str(),"w");
            fprintf(nuevo,"%s\n",dest.data());
            fclose(nuevo);
            string comandoS = "dot \'";
            comandoS += pathTwice;
            comandoS +="\' -o \'" + pathClone + terminacion + " \' -T" + terminacion.substr(1,terminacion.length());
            system(comandoS.c_str());
            cout << "Reporte de inodos generado con exito " << endl;
        }
    }
}

void REP_::reportJOURNAL()
{
    int partIndex = -1;
    MOUNT_ disk;
    int aux = 0;
    QList<MOUNT_>::iterator i;
    for(i=mounted->begin(); i != mounted->end(); i++)
    {
        if(i->getId() == this->getId())
        {
            partIndex = i->partIndex();//Obtengo el indice de la partición si es primaria o extendida.
            disk = mounted->at(aux);// Obtengo la referencia al disco montado.
            break;
        }
        aux++;
    }
    if(partIndex != -1){//Primaria|Extendida
        FILE *fp = fopen(disk.getPath().c_str(),"r+b");
        MBR masterboot;
        SuperBloque super;
        fread(&masterboot,sizeof(MBR),1,fp);
        fseek(fp,masterboot.mbr_partitions[partIndex].part_start,SEEK_SET);
        fread(&super,sizeof(SuperBloque),1,fp);
        int inicio_super = masterboot.mbr_partitions[partIndex].part_start;
        Journal j;
        fseek(fp,inicio_super,SEEK_SET);
        fread(&super,sizeof(SuperBloque),1,fp);

        string dest = "digraph G{\n";
        dest += "    nodo [shape=none, fontname=\"Century Gothic\" label=<\n";
        dest += "   <table border=\'0\' cellborder='1\' cellspacing=\'0\'>\n";
        dest += "    <tr> <td COLSPAN=\'7\' bgcolor=\"cornflowerblue\"> <b>JOURNALING</b> </td></tr>\n";
        dest += "    <tr> <td bgcolor=\"lightsteelblue\"><b>Operacion</b></td> <td bgcolor=\"lightsteelblue\"><b>Tipo</b></td><td bgcolor=\"lightsteelblue\"><b>Nombre</b></td><td bgcolor=\"lightsteelblue\"><b>Contenido</b></td>\n";
        dest += "    <td bgcolor=\"lightsteelblue\"><b>Propietario</b></td><td bgcolor=\"lightsteelblue\"><b>Permisos</b></td><td bgcolor=\"lightsteelblue\"><b>Fecha</b></td></tr>\n";

        fseek(fp,inicio_super + static_cast<int>(sizeof(SuperBloque)),SEEK_SET);
        while(ftell(fp) < super.s_bm_inode_start)
        {
            fread(&j,sizeof(Journal),1,fp);
            if(j.journal_type == 0 || j.journal_type == 1){
                struct tm *tm;
                char fecha[100];
                tm = localtime(&j.journal_date);
                strftime(fecha,100,"%d/%m/%y %H:%S",tm);
                dest +="<tr><td>";
                dest += j.journal_operation_type;
                dest += "</td><td>";
                dest += to_string(j.journal_type);
                dest += "</td><td>";
                dest += j.journal_name;
                dest += "</td><td>";
                dest += j.journal_content;
                dest += "</td><td>";
                dest += to_string(j.journal_owner);
                dest += "</td><td>";
                dest += to_string(j.journal_permissions);
                dest += "</td><td>";
                dest += fecha;
                dest += "</td></tr>\n";
            }
        }
        dest += "   </table>>]\n";
        dest +="}";
        fclose(fp);

        // Obtener la ruta.
        string pathClone = this->path;
        string pathTwice = this->path;
        string terminacion;
        pathTwice += ".txt";
        const size_t last_slash_idx = pathClone.find_last_of(".");
        if (std::string::npos != last_slash_idx)
        {
            terminacion = pathClone.substr(last_slash_idx, pathClone.length());
            pathClone = pathClone.substr(0, last_slash_idx);
        }

        // Creando comando para crear la carpeta.
        string ruta_aux = this->path;
        string path = this->path;
        string comando = "sudo mkdir -p \'";
        comando+= dirNam(path);
        comando+= '\'';
        system(comando.c_str());

        // Comando para permisos.
        string comandow = "sudo chmod -R 777 \'";
        comandow+= dirNam(ruta_aux);
        comandow += '\'';
        system(comandow.c_str());

        //Eliminando el reporte previo
        string cEliminar = "sudo rm '";
        cEliminar += pathTwice + "\'";
        system(cEliminar.c_str());
        string dotF = dest;
        char arreglo[dotF.length()];
        strcpy(arreglo, dotF.c_str());

        // Creando el file.
        FILE *nuevo = fopen(pathTwice.c_str(),"w");
        fprintf(nuevo,"%s\n",arreglo);
        fclose(nuevo);
        string comandoS = "dot \'";
        comandoS += pathTwice;
        comandoS +="\' -o \'" + pathClone + terminacion + " \' -T" + terminacion.substr(1,terminacion.length());
        system(comandoS.c_str());

        cout << "Reporte Journaling generado con exito " << endl;
    }
}

void REP_::reportBLOQUE()
{
    int partIndex = -1;
    MOUNT_ disk;
    int aux = 0;
    QList<MOUNT_>::iterator i;
    for(i=mounted->begin(); i != mounted->end(); i++)
    {
        if(i->getId() == this->getId())
        {
            partIndex = i->partIndex();//Obtengo el indice de la partición si es primaria o extendida.
            disk = mounted->at(aux);// Obtengo la referencia al disco montado.
            break;
        }
        aux++;
    }
    if(partIndex != -1)
    {
        MBR masterboot;
        SuperBloque super;
        FILE *fp = fopen(disk.getPath().data(),"r+b");
        fread(&masterboot,sizeof(MBR),1,fp);
        fseek(fp,masterboot.mbr_partitions[partIndex].part_start,SEEK_SET);
        fread(&super,sizeof(SuperBloque),1,fp);
        BloqueArchivo archivo;
        BloqueApuntadores apuntador;
        BloqueCarpeta carpeta;
        int block_start = super.s_block_start;
        int bm_block_start = super.s_bm_block_start;
        int inode_start = super.s_inode_start;
        int aux = bm_block_start;
        int i = 0;
        char buffer;

        string graph = "digraph G{\n\n";

        while(aux < inode_start){
            fseek(fp,bm_block_start + i,SEEK_SET);
            buffer = static_cast<char>(fgetc(fp));
            aux++;
            if(buffer == '1'){
                fseek(fp,block_start + static_cast<int>(sizeof(BloqueCarpeta))*i,SEEK_SET);
                fread(&carpeta,sizeof(BloqueCarpeta),1,fp);
                graph += "    nodo_"+to_string(i) + "[ shape=none, fontname=\"Century Gothic\" label=< \n";
                graph += "   <table border=\'0\' cellborder='1' cellspacing='0' bgcolor=\"seagreen\">";
                graph += "    <tr> <td colspan=\'2\'> <b>Bloque Carpeta " + to_string(i) +"</b> </td></tr>\n";
                graph += "    <tr> <td bgcolor=\"mediumseagreen\"> b_name </td> <td bgcolor=\"mediumseagreen\"> b_inode </td></tr>\n";
                for(int c = 0;c < 4;c++)
                {
                    graph += "    <tr> <td bgcolor=\"white\">";
                    graph+= carpeta.b_content[c].b_name;
                    graph += " </td> <td bgcolor=\"white\"> "+ to_string(carpeta.b_content[c].b_inodo) + " </td></tr>\n";
                }
                graph += "   </table>>]\n\n";
            }else if(buffer == '2'){
                fseek(fp,block_start + static_cast<int>(sizeof(BloqueArchivo))*i,SEEK_SET);
                fread(&archivo,sizeof(BloqueArchivo),1,fp);
                graph += "    nodo_"+to_string(i) +"[ shape=none, label=< \n";
                graph += "   <table border=\'0\' cellborder='1' cellspacing='0' bgcolor=\"sandybrown\">";
                graph += "    <tr> <td colspan=\'2\'> <b>Bloque Archivo "+to_string(i)+" </b></td></tr>\n";
                graph += "    <tr> <td colspan=\'2\' bgcolor=\"white\"> ";
                graph += archivo.b_content;
                graph += "</td></tr>\n";
                graph += "   </table>>]\n\n";
            }else if(buffer == '3'){
                fseek(fp,block_start + static_cast<int>(sizeof(BloqueApuntadores))*i,SEEK_SET);
                fread(&apuntador,sizeof(BloqueApuntadores),1,fp);
                fseek(fp,block_start + static_cast<int>(sizeof(BloqueApuntadores))*i,SEEK_SET);
                fread(&apuntador,sizeof(BloqueApuntadores),1,fp);
                graph += "    bloque_"+to_string(i)+" [shape=plaintext fontname=\"Century Gothic\" label=< \n";
                graph += "   <table border=\'0\' bgcolor=\"khaki\">\n";
                graph += "    <tr> <td> <b>Pointer block "+to_string(i)+"</b></td></tr>\n";
                for(int j = 0; j < 16; j++)
                    graph += "    <tr> <td bgcolor=\"white\">"+to_string(apuntador.b_pointer[j])+"</td> </tr>\n";
                graph += "   </table>>]\n\n";
            }
            i++;
        }
        graph +="\n}";
        fclose(fp);

        // Obtener la ruta.
        string pathClone = this->path;
        string pathTwice = this->path;
        string terminacion;
        pathTwice += ".txt";
        const size_t last_slash_idx = pathClone.find_last_of(".");
        if (std::string::npos != last_slash_idx)
        {
            terminacion = pathClone.substr(last_slash_idx, pathClone.length());
            pathClone = pathClone.substr(0, last_slash_idx);
        }

        // Creando comando para crear la carpeta.
        string ruta_aux = this->path;
        string path = this->path;
        string comando = "sudo mkdir -p \'";
        comando+= dirNam(path);
        comando+= '\'';
        system(comando.c_str());

        // Comando para permisos.
        string comandow = "sudo chmod -R 777 \'";
        comandow+= dirNam(ruta_aux);
        comandow += '\'';
        system(comandow.c_str());

        //Eliminando el reporte previo
        string cEliminar = "sudo rm '";
        cEliminar += pathTwice + "\'";
        system(cEliminar.c_str());
        char arreglo[graph.length()];
        strcpy(arreglo, graph.c_str());

        // Creando el file.
        FILE *nuevo = fopen(pathTwice.c_str(),"w");
        fprintf(nuevo,"%s\n",arreglo);
        fclose(nuevo);
        string comandoS = "dot \'";
        comandoS += pathTwice;
        comandoS +="\' -o \'" + pathClone + terminacion + " \' -T" + terminacion.substr(1,terminacion.length());
        system(comandoS.c_str());

        cout << "Reporte Bloque generado con exito " << endl;

    }
    else
    {
        int index = disk.LogicPartIndex();
        if(index != -1){
            EBR extendedBoot;
            SuperBloque super;
            FILE *fp = fopen(disk.getPath().data(),"r+b");
            fseek(fp,index,SEEK_SET);
            fread(&extendedBoot,sizeof(EBR),1,fp);
            fread(&super,sizeof(SuperBloque),1,fp);

            BloqueArchivo archivo;
            BloqueApuntadores apuntador;
            BloqueCarpeta carpeta;
            int block_start = super.s_block_start;
            int bm_block_start = super.s_bm_block_start;
            int inode_start = super.s_inode_start;
            int aux = bm_block_start;
            int i = 0;
            char buffer;

            string dot = "digraph G{\n\n";

            while(aux < inode_start){
                fseek(fp,bm_block_start + i,SEEK_SET);
                buffer = static_cast<char>(fgetc(fp));
                aux++;
                if(buffer == '1')
                {
                    fseek(fp,block_start + static_cast<int>(sizeof(BloqueCarpeta))*i,SEEK_SET);
                    fread(&carpeta,sizeof(BloqueCarpeta),1,fp);
                    dot += "    nodo_"+to_string(i) + "[ shape=none, fontname=\"Century Gothic\" label=< \n";
                    dot += "   <table border=\'0\' cellborder='1' cellspacing='0' bgcolor=\"seagreen\">";
                    dot += "    <tr> <td colspan=\'2\'> <b>Bloque Carpeta " + to_string(i) +"</b> </td></tr>\n";
                    dot += "    <tr> <td bgcolor=\"mediumseagreen\"> b_name </td> <td bgcolor=\"mediumseagreen\"> b_inode </td></tr>\n";
                    for(int c = 0;c < 4;c++)
                    {
                        dot += "    <tr> <td bgcolor=\"white\">";
                        dot+= carpeta.b_content[c].b_name;
                        dot += " </td> <td bgcolor=\"white\"> "+ to_string(carpeta.b_content[c].b_inodo) + " </td></tr>\n";
                    }
                    dot += "   </table>>]\n\n";
                }
                else if(buffer == '2')
                {
                    fseek(fp,block_start + static_cast<int>(sizeof(BloqueArchivo))*i,SEEK_SET);
                    fread(&archivo,sizeof(BloqueArchivo),1,fp);
                    dot += "    nodo_"+to_string(i) +"[ shape=none, label=< \n";
                    dot += "   <table border=\'0\' cellborder='1' cellspacing='0' bgcolor=\"sandybrown\">";
                    dot += "    <tr> <td colspan=\'2\'> <b>Bloque Archivo "+to_string(i)+" </b></td></tr>\n";
                    dot += "    <tr> <td colspan=\'2\' bgcolor=\"white\"> ";
                    dot += archivo.b_content;
                    dot += "</td></tr>\n";
                    dot += "   </table>>]\n\n";
                }
                else if(buffer == '3')
                {
                    fseek(fp,block_start + static_cast<int>(sizeof(BloqueApuntadores))*i,SEEK_SET);
                    fread(&apuntador,sizeof(BloqueApuntadores),1,fp);
                    fseek(fp,block_start + static_cast<int>(sizeof(BloqueApuntadores))*i,SEEK_SET);
                    fread(&apuntador,sizeof(BloqueApuntadores),1,fp);
                    dot += "    bloque_"+to_string(i)+" [shape=plaintext fontname=\"Century Gothic\" label=< \n";
                    dot += "   <table border=\'0\' bgcolor=\"khaki\">\n";
                    dot += "    <tr> <td> <b>Pointer block "+to_string(i)+"</b></td></tr>\n";
                    for(int j = 0; j < 16; j++)
                        dot += "    <tr> <td bgcolor=\"white\">"+to_string(apuntador.b_pointer[j])+"</td> </tr>\n";
                    dot += "   </table>>]\n\n";
                }
                i++;
            }
            dot +="\n}";
            fclose(fp);

            // Obtener la ruta.
            string pathClone = this->path;
            string pathTwice = this->path;
            string terminacion;
            pathTwice += ".txt";
            const size_t last_slash_idx = pathClone.find_last_of(".");
            if (std::string::npos != last_slash_idx)
            {
                terminacion = pathClone.substr(last_slash_idx, pathClone.length());
                pathClone = pathClone.substr(0, last_slash_idx);
            }

            // Creando comando para crear la carpeta.
            string ruta_aux = this->path;
            string path = this->path;
            string comando = "sudo mkdir -p \'";
            comando+= dirNam(path);
            comando+= '\'';
            system(comando.c_str());

            // Comando para permisos.
            string comandow = "sudo chmod -R 777 \'";
            comandow+= dirNam(ruta_aux);
            comandow += '\'';
            system(comandow.c_str());

            //Eliminando el reporte previo
            string cEliminar = "sudo rm '";
            cEliminar += pathTwice + "\'";
            system(cEliminar.c_str());
            char arreglo[dot.length()];
            strcpy(arreglo, dot.c_str());

            // Creando el file.
            FILE *nuevo = fopen(pathTwice.c_str(),"w");
            fprintf(nuevo,"%s\n",arreglo);
            fclose(nuevo);
            string comandoS = "dot \'";
            comandoS += pathTwice;
            comandoS +="\' -o \'" + pathClone + terminacion + " \' -T" + terminacion.substr(1,terminacion.length());
            system(comandoS.c_str());

            cout << "Reporte Bloque generado con exito " << endl;
        }
    }
}

void REP_::reportBMI()
{
    int partIndex = -1;
    MOUNT_ disk;
    int aux = 0;
    QList<MOUNT_>::iterator i;
    for(i=mounted->begin(); i != mounted->end(); i++)
    {
        if(i->getId() == this->getId())
        {
            partIndex = i->partIndex();//Obtengo el indice de la partición si es primaria o extendida.
            disk = mounted->at(aux);// Obtengo la referencia al disco montado.
            break;
        }
        aux++;
    }
    if(partIndex != -1)
    {
        MBR masterboot;
        SuperBloque super;
        FILE *file = fopen(disk.getPath().data(),"r+b");
        fread(&masterboot,sizeof(MBR),1,file);
        fseek(file,masterboot.mbr_partitions[partIndex].part_start,SEEK_SET);
        fread(&super,sizeof(SuperBloque),1,file);

        char byte;
        int cont = 0;
        string dot;
        for (int i = 0; i < super.s_inodes_count; i++) {
            fseek(file,super.s_bm_inode_start + i,SEEK_SET);
            byte = static_cast<char>(fgetc(file));
            if(byte == '0')
                dot +="0 ";
            else
                dot +="1 ";
            if(cont == 19){
                cont = 0;
                dot += "\n";
            }else
                cont++;
        }
        string ruta = this->path;
        FILE *repo = fopen(ruta.data(),"w");
        fprintf(repo,"%s\n", dot.data());
        fclose(repo);
        fclose(file);
        cout << "Reporte BITMAP DE INODOS generado con éxito." << endl;
    }
    else
    {
        int index = disk.LogicPartIndex();
        EBR extendedBoot;
        SuperBloque super;
        FILE *file = fopen(disk.getPath().data(),"rb+");
        fseek(file,index,SEEK_SET);
        fread(&extendedBoot,sizeof(EBR),1,file);
        fread(&super,sizeof(SuperBloque),1,file);

        char byte;
        int cont = 0;
        string dot;
        for (int i = 0; i < super.s_inodes_count; i++) {
            fseek(file,super.s_bm_inode_start + i,SEEK_SET);
            byte = static_cast<char>(fgetc(file));
            if(byte == '0')
                dot +="0 ";
            else
                dot +="1 ";
            if(cont == 19){
                cont = 0;
                dot += "\n";
            }else
                cont++;
        }
        string ruta = this->path;
        FILE *repo = fopen(ruta.data(),"w");
        fprintf(repo,"%s\n", dot.data());
        fclose(repo);
        fclose(file);
        cout << "Reporte BITMAP DE INODOS generado con éxito." << endl;
    }

}

void REP_::reportBMB()
{
    int partIndex = -1;
    MOUNT_ disk;
    int aux = 0;
    QList<MOUNT_>::iterator i;
    for(i=mounted->begin(); i != mounted->end(); i++)
    {
        if(i->getId() == this->getId())
        {
            partIndex = i->partIndex();//Obtengo el indice de la partición si es primaria o extendida.
            disk = mounted->at(aux);// Obtengo la referencia al disco montado.
            break;
        }
        aux++;
    }

    if(partIndex != -1)
    {
        MBR masterboot;
        SuperBloque super;
        FILE *file = fopen(disk.getPath().data(),"r+b");
        fread(&masterboot,sizeof(MBR),1,file);
        fseek(file,masterboot.mbr_partitions[partIndex].part_start,SEEK_SET);
        fread(&super,sizeof(SuperBloque),1,file);

        char byte;
        int cont = 0;
        string dot;
        for (int i = 0; i < super.s_blocks_count; i++)
        {
            fseek(file,super.s_bm_block_start + i,SEEK_SET);
            byte = static_cast<char>(fgetc(file));
            if(byte == '0')
                dot +="0 ";
            else
                dot +="1 ";
            if(cont == 19){
                cont = 0;
                dot += "\n";
            }else
                cont++;
        }
        string ruta = this->path;
        FILE *repo = fopen(ruta.data(),"w");
        fprintf(repo,"%s\n", dot.data());
        fclose(repo);
        fclose(file);
        cout << "Reporte BITMAP DE BLOQUES generado con éxito." << endl;
    }
    else
    {
        int index = disk.LogicPartIndex();
        EBR extendedBoot;
        SuperBloque super;
        FILE *file = fopen(disk.getPath().data(),"rb+");
        fseek(file,index,SEEK_SET);
        fread(&extendedBoot,sizeof(EBR),1,file);
        fread(&super,sizeof(SuperBloque),1,file);

        char byte;
        int cont = 0;
        string dot;
        for (int i = 0; i < super.s_blocks_count; i++)
        {
            fseek(file,super.s_bm_block_start + i,SEEK_SET);
            byte = static_cast<char>(fgetc(file));
            if(byte == '0')
                dot +="0 ";
            else
                dot +="1 ";
            if(cont == 19){
                cont = 0;
                dot += "\n";
            }
            else
            {
                cont++;
            }
        }
        string ruta = this->path;
        FILE *repo = fopen(ruta.data(),"w");
        fprintf(repo,"%s\n", dot.data());
        fclose(repo);
        fclose(file);
        cout << "Reporte BITMAP DE BLOQUES generado con éxito." << endl;
    }
}

void REP_::reportTREE()
{
    int partIndex = -1;
    MOUNT_ disk;
    int aux = 0;
    QList<MOUNT_>::iterator i;
    for(i=mounted->begin(); i != mounted->end(); i++)
    {
        if(i->getId() == this->getId())
        {
            partIndex = i->partIndex();
            disk = mounted->at(aux);
            break;
        }
        aux++;
    }

    if(partIndex != -1)
    {
        MBR masterboot;
        SuperBloque super;
        FILE *file = fopen(disk.getPath().data(),"r+b");
        fread(&masterboot,sizeof(MBR),1,file);
        fseek(file,masterboot.mbr_partitions[partIndex].part_start,SEEK_SET);
        fread(&super,sizeof(SuperBloque),1,file);
        int start = masterboot.mbr_partitions[partIndex].part_start;
        graficarTree(disk.getPath().data(), start);
    }
    else
    {
        int logicIndex = disk.LogicPartIndex();
        if(logicIndex != -1)
        {
            EBR extendedBoot;
            FILE *fp = fopen(disk.getPath().data(),"r+b");
            fseek(fp,logicIndex,SEEK_SET);
            fread(&extendedBoot,sizeof(EBR),1,fp);
            int start = static_cast<int>(ftell(fp));
            fclose(fp);
            graficarTree(disk.getPath(),start);
        }
    }
}

void REP_::graficarTree(string direccion, int inicioSuper){
    FILE *file = fopen(direccion.data(),"r");

    BloqueCarpeta carpeta;
    InodoTable inodo;
    SuperBloque super;
    BloqueArchivo archivo;
    BloqueApuntadores apuntador;

    fseek(file,inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,file);

    int aux = super.s_bm_inode_start;
    int i = 0;

    char buffer;

    string dot = "digraph G{\n\n";
    dot += "    rankdir=\"LR\" \n";

    while(aux < super.s_bm_block_start){
        fseek(file,super.s_bm_inode_start + i,SEEK_SET);
        buffer = static_cast<char>(fgetc(file));
        aux++;
        int port = 0;
        if(buffer == '1'){
            fseek(file,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*i,SEEK_SET);
            fread(&inodo,sizeof(InodoTable),1,file);
            dot += "    inodo_"+to_string(i)+" [ shape=plaintext fontname=\"Century Gothic\" label=<\n";
            dot += "   <table bgcolor=\"royalblue\" border=\'0\' >";
            dot += "    <tr> <td colspan=\'2\'><b>Inode "+to_string(i)+"</b></td></tr>\n";
            dot += "    <tr> <td bgcolor=\"lightsteelblue\"> i_uid </td> <td bgcolor=\"white\"> "+to_string(inodo.i_uid)+" </td>  </tr>\n";
            dot += "    <tr> <td bgcolor=\"lightsteelblue\"> i_gid </td> <td bgcolor=\"white\"> "+to_string(inodo.i_gid)+" </td>  </tr>\n";
            dot += "    <tr> <td bgcolor=\"lightsteelblue\"> i_size </td><td bgcolor=\"white\"> "+to_string(inodo.i_size)+" </td> </tr>\n";
            struct tm *tm;
            char fecha[100];
            tm=localtime(&inodo.i_atime);
            strftime(fecha,100,"%d/%m/%y %H:%S",tm);
            dot += "    <tr> <td bgcolor=\"lightsteelblue\"> i_atime </td> <td bgcolor=\"white\"> ";
            dot+=fecha;
            dot+=" </td> </tr>\n";
            tm=localtime(&inodo.i_ctime);
            strftime(fecha,100,"%d/%m/%y %H:%S",tm);
            dot += "    <tr> <td bgcolor=\"lightsteelblue\"> i_ctime </td> <td bgcolor=\"white\"> ";
            dot += fecha;
            dot +=" </td> </tr>\n";
            tm=localtime(&inodo.i_mtime);
            strftime(fecha,100,"%d/%m/%y %H:%S",tm);
            dot += "    <tr> <td bgcolor=\"lightsteelblue\"> i_mtime </td> <td bgcolor=\"white\"> ";
            dot += fecha;
            dot += " </td> </tr>\n";
            for(int b = 0; b < 15; b++){
                dot += "    <tr> <td bgcolor=\"lightsteelblue\"> i_block_"+to_string(port)+" </td> <td bgcolor=\"white\" port=\"f"+to_string(b)+"\"> "+to_string(inodo.i_block[b])+" </td></tr>\n";
                port++;
            }
            dot += "    <tr> <td bgcolor=\"lightsteelblue\"> i_type </td> <td bgcolor=\"white\"> "+to_string(inodo.i_type)+" </td>  </tr>\n";
            dot += "    <tr> <td bgcolor=\"lightsteelblue\"> i_perm </td> <td bgcolor=\"white\"> "+to_string(inodo.i_perm)+" </td>  </tr>\n";
            dot += "   </table>>]\n\n";
            for (int j = 0; j < 15; j++){
                port = 0;
                if(inodo.i_block[j] != -1){
                    fseek(file,super.s_bm_block_start + inodo.i_block[j],SEEK_SET);
                    buffer = static_cast<char>(fgetc(file));
                    if(buffer == '1'){
                        fseek(file,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*inodo.i_block[j],SEEK_SET);
                        fread(&carpeta,sizeof(BloqueCarpeta),1,file);
                        dot += "    bloque_"+to_string(inodo.i_block[j])+" [shape=plaintext fontname=\"Century Gothic\" label=< \n";
                        dot += "   <table bgcolor=\"seagreen\" border=\'0\'>\n";
                        dot += "    <tr> <td colspan=\'2\'><b>Folder block "+to_string(inodo.i_block[j])+"</b></td></tr>\n";
                        dot += "    <tr> <td bgcolor=\"mediumseagreen\"> b_name </td> <td bgcolor=\"mediumseagreen\"> b_inode </td></tr>\n";
                        for(int c = 0;c < 4; c++){
                            dot += "    <tr> <td bgcolor=\"white\" > ";
                            dot += carpeta.b_content[c].b_name;
                            dot += " </td> <td bgcolor=\"white\"  port=\"f"+to_string(port)+"\"> "+to_string(carpeta.b_content[c].b_inodo)+" </td></tr>\n";
                            port++;
                        }
                        dot += "   </table>>]\n\n";
                        for(int c = 0; c < 4; c++){
                            if(carpeta.b_content[c].b_inodo !=-1){
                                if(strcmp(carpeta.b_content[c].b_name,"-")!=0 && strcmp(carpeta.b_content[c].b_name,"--")!=0)
                                    dot += "    bloque_"+to_string(inodo.i_block[j])+":f"+to_string(c)+" -> inodo_"+to_string(carpeta.b_content[c].b_inodo)+";\n";
                            }
                        }
                    }else if(buffer == '2'){
                        fseek(file,super.s_block_start + static_cast<int>(sizeof(BloqueArchivo))*inodo.i_block[j],SEEK_SET);
                        fread(&archivo,sizeof(BloqueArchivo),1,file);
                        dot += "    bloque_"+to_string(inodo.i_block[j])+" [shape=plaintext fontname=\"Century Gothic\" label=< \n";
                        dot += "   <table border=\'0\' bgcolor=\"sandybrown\">\n";
                        dot += "    <tr> <td> <b>File block "+to_string(inodo.i_block[j])+"</b></td></tr>\n";
                        dot += "    <tr> <td bgcolor=\"white\"> ";
                        dot += archivo.b_content;
                        dot += " </td></tr>\n";
                        dot += "   </table>>]\n\n";
                    }else if(buffer == '3'){
                        fseek(file,super.s_block_start + static_cast<int>(sizeof(BloqueApuntadores))*inodo.i_block[j],SEEK_SET);
                        fread(&apuntador,sizeof(BloqueApuntadores),1,file);
                        dot += "    bloque_"+to_string(inodo.i_block[j])+" [shape=plaintext fontname=\"Century Gothic\" label=< \n";
                        dot += "   <table border=\'0\' bgcolor=\"khaki\">\n";
                        dot += "    <tr> <td> <b>Pointer block "+to_string(inodo.i_block[j])+"</b></td></tr>\n";
                        for(int a = 0; a < 16; a++){
                            dot += "    <tr> <td bgcolor=\"white\" port=\"f"+to_string(port)+"\">"+to_string(apuntador.b_pointer[a])+"</td> </tr>\n";
                            port++;
                        }
                        dot += "   </table>>]\n\n";
                        for (int x = 0; x < 16; x++) {
                            port = 0;
                            if(apuntador.b_pointer[x] != -1){
                                fseek(file,super.s_bm_block_start + apuntador.b_pointer[x],SEEK_SET);
                                buffer = static_cast<char>(fgetc(file));
                                if(buffer == '1'){
                                    fseek(file,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*apuntador.b_pointer[x],SEEK_SET);
                                    fread(&carpeta,sizeof(BloqueCarpeta),1,file);
                                    dot += "    bloque_"+to_string(apuntador.b_pointer[x])+" [shape=plaintext fontname=\"Century Gothic\" label=< \n";
                                    dot += "   <table border=\'0\' bgcolor=\"seagreen\" >\n";
                                    dot += "    <tr> <td colspan=\'2\'> <b>Folder block "+to_string(apuntador.b_pointer[x])+"</b> </td></tr>\n";
                                    dot += "    <tr> <td bgcolor=\"mediumseagreen\"> b_name </td> <td bgcolor=\"mediumseagreen\"> b_inode </td></tr>\n";
                                    for(int c = 0;c < 4; c++){
                                        dot += "    <tr> <td bgcolor=\"white\"> ";
                                        dot += carpeta.b_content[c].b_name;
                                        dot += "</td> <td bgcolor=\"white\" port=\"f"+to_string(port)+"\"> "+to_string(carpeta.b_content[c].b_inodo)+" </td></tr>\n";
                                        port++;
                                    }
                                    dot += "   </table>>]\n\n";
                                    for(int c = 0; c < 4; c++){
                                        if(carpeta.b_content[c].b_inodo !=-1){
                                            if(strcmp(carpeta.b_content[c].b_name,"-")!=0 && strcmp(carpeta.b_content[c].b_name,"--")!=0)
                                            {
                                                dot += "    bloque_"+to_string(apuntador.b_pointer[x])+":f"+to_string(c)+" -> inodo_"+to_string(carpeta.b_content[c].b_inodo)+";\n";
                                            }
                                        }
                                    }
                                }else if(buffer == '2'){
                                    fseek(file,super.s_block_start + static_cast<int>(sizeof(BloqueArchivo))*apuntador.b_pointer[x],SEEK_SET);
                                    fread(&archivo,sizeof(BloqueArchivo),1,file);
                                    dot += "    bloque_"+to_string(apuntador.b_pointer[x])+" [shape=plaintext fontname=\"Century Gothic\" label=< \n";
                                    dot += "   <table border=\'0\' bgcolor=\"sandybrown\">\n";
                                    dot += "    <tr> <td> <b>File block "+to_string(apuntador.b_pointer[x])+"</b></td></tr>\n";
                                    dot += "    <tr> <td bgcolor=\"white\"> ";
                                    dot += archivo.b_content;
                                    dot += " </td></tr>\n";
                                    dot += "   </table>>]\n\n";
                                }else if(buffer == '3'){

                                }
                            }
                        }

                        for(int b = 0; b < 16; b++){
                            if(apuntador.b_pointer[b] != -1)
                                dot += "    bloque_"+to_string(inodo.i_block[j])+":f"+to_string(b)+" -> bloque_"+to_string(apuntador.b_pointer[b])+";\n";
                        }
                    }
                    dot += "    inodo_"+to_string(i)+":f"+to_string(j)+" -> bloque_"+to_string(inodo.i_block[j])+"; \n";
                }
            }
        }
        i++;
    }
    dot +="\n\n}";

    fclose(file);

    // Obtener la ruta.
    string pathClone = this->path;
    string pathTwice = this->path;
    string terminacion;
    pathTwice += ".txt";
    const size_t last_slash_idx = pathClone.find_last_of(".");
    if (std::string::npos != last_slash_idx)
    {
        terminacion = pathClone.substr(last_slash_idx, pathClone.length());
        pathClone = pathClone.substr(0, last_slash_idx);
    }

    // Creando comando para crear la carpeta.
    string ruta_aux = this->path;
    string path = this->path;
    string comando = "sudo mkdir -p \'";
    comando+= dirNam(path);
    comando+= '\'';
    system(comando.c_str());

    // Comando para permisos.
    string comandow = "sudo chmod -R 777 \'";
    comandow+= dirNam(ruta_aux);
    comandow += '\'';
    system(comandow.c_str());

    //Eliminando el reporte previo
    string cEliminar = "sudo rm '";
    cEliminar += pathTwice + "\'";
    system(cEliminar.c_str());
    char arreglo[dot.length()];
    strcpy(arreglo, dot.c_str());

    // Creando el file.
    FILE *nuevo = fopen(pathTwice.c_str(),"w");
    fprintf(nuevo,"%s\n",arreglo);
    fclose(nuevo);
    string comandoS = "dot \'";
    comandoS += pathTwice;
    comandoS +="\' -o \'" + pathClone + terminacion + " \' -T" + terminacion.substr(1,terminacion.length());
    system(comandoS.c_str());

    cout << "Reporte TREE generado con exito " << endl;
}

void REP_::reportFILE()
{
    int partIndex = -1;
    MOUNT_ disk;
    int aux = 0;
    QList<MOUNT_>::iterator i;
    for(i=mounted->begin(); i != mounted->end(); i++)
    {
        if(i->getId() == this->getId())
        {
            partIndex = i->partIndex();
            disk = mounted->at(aux);
            break;
        }
        aux++;
    }

    if(partIndex!= -1){
        MBR masterboot;
        char auxRuta[500];
        strcpy(auxRuta,this->cont.data());
        FILE *fp = fopen(disk.getPath().data(),"r+b");
        fread(&masterboot,sizeof(MBR),1,fp);
        int existe = findFile(fp,auxRuta);
        if(existe != -1)
        {
            char nombre[50];
            char auxRuta[400];
            strcpy(auxRuta,cont.data());
            strcpy(nombre,basename(auxRuta));
            string nom = nombre;
            graphFILE(masterboot.mbr_partitions[partIndex].part_start, nom, existe);
        }
        else cout << "El archivo que deseas reportar no existe." << endl;
        fclose(fp);
    }
}

void REP_::graphFILE(int n, string name, int start_super)
{
    FILE *fp = fopen(path.data(),"r");

    BloqueArchivo archivo;
    SuperBloque super;
    InodoTable inodo;

    fseek(fp,start_super,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,fp);
    fseek(fp,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*n,SEEK_SET);
    fread(&inodo,sizeof(InodoTable),1,fp);

    string dot= "digraph G{\n";
    dot +="    nodo [shape=none, fontname=\"Century Gothic\" label=<";
    dot +="   <table border=\'0\' cellborder='1\' cellspacing=\'0\' bgcolor=\"lightsteelblue\">";
    dot +="    <tr><td align=\"left\"> <b>%s</b> </td></tr>\n",name.data();
    dot +="    <tr><td bgcolor=\"white\">";
    for (int i = 0; i < 15; i++) {
        if(inodo.i_block[i] != -1){
            if(i == 12){//Apuntador indirecto simple
                BloqueApuntadores apuntador;
                fseek(fp,super.s_block_start + static_cast<int>(sizeof(BloqueApuntadores))*inodo.i_block[i],SEEK_SET);
                fread(&apuntador,sizeof(BloqueApuntadores),1,fp);
                for(int j = 0; j < 16; j++){
                    if(apuntador.b_pointer[j] != -1){
                        fseek(fp,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*apuntador.b_pointer[j],SEEK_SET);
                        fread(&archivo,sizeof(BloqueArchivo),1,fp);
                        dot += archivo.b_content;
                        dot +=" <br/>";
                    }
                }
            }else if(i == 13){

            }else if(i == 14){

            }else{//Apuntadores directos
                fseek(fp,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*inodo.i_block[i],SEEK_SET);
                fread(&archivo,sizeof(BloqueArchivo),1,fp);
                dot += archivo.b_content;
                dot +=" <br/>";
            }
        }
    }
    dot +="    </td></tr>\n";
    dot +="   </table>>]\n";
    dot +="\n}";
    fclose(fp);

    // Obtener la ruta.
    string pathClone = this->path;
    string pathTwice = this->path;
    string terminacion;
    pathTwice += ".txt";
    const size_t last_slash_idx = pathClone.find_last_of(".");
    if (std::string::npos != last_slash_idx)
    {
        terminacion = pathClone.substr(last_slash_idx, pathClone.length());
        pathClone = pathClone.substr(0, last_slash_idx);
    }

    // Creando comando para crear la carpeta.
    string ruta_aux = this->path;
    string path = this->path;
    string comando = "sudo mkdir -p \'";
    comando+= dirNam(path);
    comando+= '\'';
    system(comando.c_str());

    // Comando para permisos.
    string comandow = "sudo chmod -R 777 \'";
    comandow+= dirNam(ruta_aux);
    comandow += '\'';
    system(comandow.c_str());

    //Eliminando el reporte previo
    string cEliminar = "sudo rm '";
    cEliminar += pathTwice + "\'";
    system(cEliminar.c_str());
    char arreglo[dot.length()];
    strcpy(arreglo, dot.c_str());

    // Creando el file.
    FILE *nuevo = fopen(pathTwice.c_str(),"w");
    fprintf(nuevo,"%s\n",arreglo);
    fclose(nuevo);
    string comandoS = "dot \'";
    comandoS += pathTwice;
    comandoS +="\' -o \'" + pathClone + terminacion + " \' -T" + terminacion.substr(1,terminacion.length());
    system(comandoS.c_str());
    cout << "Reporte de FILE creado exitosamente." << endl;
}

int REP_::findFile(FILE *stream, string path)
{
    BloqueApuntadores apuntador;
    BloqueCarpeta carpeta;
    SuperBloque super;
    InodoTable inodo;

    QList<string> lista = QList<string>();
    char* data = new char[path.length() + 1 ];
    strcpy(data, path.c_str());
    char *token = strtok(data,"/");
    int cont = 0;
    int indexInodo = 0;

    while(token != NULL){
        lista.append(token);
        cont++;
        token = strtok(NULL,"/");
    }

    fseek(stream,sesion.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,stream);
    indexInodo = super.s_inode_start;

    for (int cont2 = 0; cont2 < cont; cont2++) {
        fseek(stream,indexInodo,SEEK_SET);
        fread(&inodo,sizeof(InodoTable),1,stream);
        int siguiente = 0;
        for(int i = 0; i < 15; i++){
            if(inodo.i_block[i] != -1){
                int byteBloque = byteInodoBloque(stream,inodo.i_block[i],'2');
                fseek(stream,byteBloque,SEEK_SET);
                if(i < 12){
                    fread(&carpeta,sizeof(BloqueCarpeta),1,stream);
                    for (int j = 0; j < 4; j++) {
                        if((cont2 == cont - 1) && (strcasecmp(carpeta.b_content[j].b_name,lista.at(cont2).c_str()) == 0)){//Tendria que ser la carpeta
                            return carpeta.b_content[j].b_inodo;
                        }else if((cont2 != cont - 1) && (strcasecmp(carpeta.b_content[j].b_name,lista.at(cont2).c_str()) == 0)){
                            indexInodo = byteInodoBloque(stream,carpeta.b_content[j].b_inodo,'1');
                            siguiente = 1;
                            break;
                        }
                    }
                }else if(i == 12){
                    fread(&apuntador,sizeof(BloqueApuntadores),1,stream);
                    for(int j = 0; j < 16; j++){
                        if(apuntador.b_pointer[j] != -1){
                            byteBloque = byteInodoBloque(stream,apuntador.b_pointer[j],'2');
                            fseek(stream,byteBloque,SEEK_SET);
                            fread(&carpeta,sizeof(BloqueCarpeta),1,stream);
                            for (int k = 0; k < 4; k++) {
                                if((cont2 == cont - 1) && (strcasecmp(carpeta.b_content[k].b_name,lista.at(cont2).c_str()) == 0)){//Tendria que ser la carpeta
                                    return carpeta.b_content[k].b_inodo;
                                }else if((cont2 != cont - 1) && (strcasecmp(carpeta.b_content[k].b_name,lista.at(cont2).c_str()) == 0)){
                                    indexInodo = byteInodoBloque(stream,carpeta.b_content[k].b_inodo,'1');
                                    siguiente = 1;
                                    break;
                                }
                            }
                            if(siguiente == 1)
                                break;
                        }
                    }
                }else if(i == 13){

                }else if(i == 14){

                }
                if(siguiente == 1)
                    break;
            }
        }
    }

    return -1;
}

int REP_::byteInodoBloque(FILE *stream , int pos, char tipo)
{
    SuperBloque super;
    fseek(stream,sesion.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,stream);
    if(tipo == '1'){
        return (super.s_inode_start + static_cast<int>(sizeof(InodoTable))*pos);
    }else if(tipo == '2')
        return (super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*pos);
    return 0;
}

void REP_::reportSB()
{
    MOUNT_ disk;
    int aux = 0;
    QList<MOUNT_>::iterator i;
    for(i=mounted->begin(); i != mounted->end(); i++)
    {
        if(i->getId() == this->getId())
        {
            disk = mounted->at(aux);
            break;
        }
        aux++;
    }

    int index = disk.partIndex();
    if(index != -1){//Primaria|Extendida
        MBR masterboot;
        FILE *fp = fopen(disk.getPath().data(),"r+b");
        fread(&masterboot,sizeof(MBR),1,fp);
        fseek(fp,masterboot.mbr_partitions[index].part_start,SEEK_SET);

        SuperBloque super;

        fseek(fp,masterboot.mbr_partitions[index].part_start,SEEK_SET);
        fread(&super,sizeof (super),1,fp);

        string dot = "digraph G{\n";
        dot += "    nodo [shape=none, fontname=\"Century Gothic\" label=<";
        dot += "   <table border=\'0\' cellborder='1\' cellspacing=\'0\' bgcolor=\"cornflowerblue\">";
        dot += "    <tr> <td COLSPAN=\'2\'> <b>SUPERBLOQUE</b> </td></tr>\n";
        dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_inodes_count </td> <td bgcolor=\"white\">";
        dot += to_string(super.s_inodes_count);
        dot += " </td> </tr>\n";
        dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_blocks_count </td> <td bgcolor=\"white\"> ";
        dot += to_string(super.s_blocks_count);
        dot += " </td> </tr>\n";
        dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_free_block_count </td> <td bgcolor=\"white\"> ";
        dot += to_string(super.s_free_blocks_count);
        dot += " </td> </tr>\n";
        dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_free_inodes_count </td> <td bgcolor=\"white\"> ";
        dot += to_string(super.s_free_inodes_count);
        dot +=" </td> </tr>\n";
        struct tm *tm;
        char fecha[100];
        tm=localtime(&super.s_mtime);
        strftime(fecha,100,"%d/%m/%y %H:%S",tm);
        dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_mtime </td> <td bgcolor=\"white\"> ";
        dot += fecha;
        dot += " </td></tr>\n";
        tm=localtime(&super.s_umtime);
        strftime(fecha,100,"%d/%m/%y %H:%S",tm);
        dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_umtime </td> <td bgcolor=\"white\"> ";
        dot += fecha;
        dot += " </td> </tr>\n";
        dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_mnt_count </td> <td bgcolor=\"white\"> ";
        dot += to_string(super.s_mnt_count);
        dot += " </td> </tr>\n";
        dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_magic </td> <td bgcolor=\"white\"> ";
        dot += to_string(super.s_magic);
        dot += " </td> </tr>\n";
        dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_inode_size </td> <td bgcolor=\"white\"> ";
        dot += to_string(super.s_inode_size);
        dot += " </td> </tr>\n";
        dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_block_size </td> <td bgcolor=\"white\"> ";
        dot += to_string(super.s_block_size);
        dot += " </td> </tr>\n";
        dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_first_ino </td> <td bgcolor=\"white\"> ";
        dot += to_string( super.s_first_ino);
        dot += " </td> </tr>\n";
        dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_first_blo </td> <td bgcolor=\"white\"> ";
        dot += to_string(super.s_first_blo);
        dot += " </td> </tr>\n";
        dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_bm_inode_start </td> <td bgcolor=\"white\"> "+to_string(super.s_bm_inode_start)+" </td></tr>\n";
        dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_bm_block_start </td> <td bgcolor=\"white\"> "+to_string(super.s_bm_block_start)+" </td> </tr>\n";
        dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_inode_start </td> <td bgcolor=\"white\"> "+to_string(super.s_inode_start)+" </td> </tr>\n";
        dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_block_start </td> <td bgcolor=\"white\"> "+to_string(super.s_block_start)+" </td> </tr>\n";
        dot += "   </table>>]\n";
        dot +="\n}";

        fclose(fp);

        // Obtener la ruta.
        string pathClone = this->path;
        string pathTwice = this->path;
        string terminacion;
        pathTwice += ".txt";
        const size_t last_slash_idx = pathClone.find_last_of(".");
        if (std::string::npos != last_slash_idx)
        {
            terminacion = pathClone.substr(last_slash_idx, pathClone.length());
            pathClone = pathClone.substr(0, last_slash_idx);
        }

        // Creando comando para crear la carpeta.
        string ruta_aux = this->path;
        string path = this->path;
        string comando = "sudo mkdir -p \'";
        comando+= dirNam(path);
        comando+= '\'';
        system(comando.c_str());

        // Comando para permisos.
        string comandow = "sudo chmod -R 777 \'";
        comandow+= dirNam(ruta_aux);
        comandow += '\'';
        system(comandow.c_str());


        // Creando el file.
        char arreglo[dot.length()];
        strcpy(arreglo, dot.c_str());
        FILE *nuevo = fopen(pathTwice.c_str(),"w");
        fprintf(nuevo,"%s\n",arreglo);
        fclose(nuevo);
        string comandoS = "dot \'";
        comandoS += pathTwice;
        comandoS +="\' -o \'" + pathClone + terminacion + " \' -T" + terminacion.substr(1,terminacion.length());
        system(comandoS.c_str());
        cout << "Reporte SUPERBLOQUE ha sido creado." << endl;
    }
    else
    {
        int index = disk.LogicPartIndex();
        if(index != -1){
            EBR extendedBoot;
            FILE *fp = fopen(disk.getPath().data(),"r+b");
            fseek(fp,index,SEEK_SET);
            fread(&extendedBoot,sizeof(EBR),1,fp);
            int start = static_cast<int>(ftell(fp));
            fclose(fp);
            SuperBloque super;

            fseek(fp,start,SEEK_SET);
            fread(&super,sizeof (super),1,fp);

            string dot = "digraph G{\n";
            dot += "    nodo [shape=none, fontname=\"Century Gothic\" label=<";
            dot += "   <table border=\'0\' cellborder='1\' cellspacing=\'0\' bgcolor=\"cornflowerblue\">";
            dot += "    <tr> <td COLSPAN=\'2\'> <b>SUPERBLOQUE</b> </td></tr>\n";
            dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_inodes_count </td> <td bgcolor=\"white\">";
            dot += to_string(super.s_inodes_count);
            dot += " </td> </tr>\n";
            dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_blocks_count </td> <td bgcolor=\"white\"> ";
            dot += to_string(super.s_blocks_count);
            dot += " </td> </tr>\n";
            dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_free_block_count </td> <td bgcolor=\"white\"> ";
            dot += to_string(super.s_free_blocks_count);
            dot += " </td> </tr>\n";
            dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_free_inodes_count </td> <td bgcolor=\"white\"> ";
            dot += to_string(super.s_free_inodes_count);
            dot +=" </td> </tr>\n";
            struct tm *tm;
            char fecha[100];
            tm=localtime(&super.s_mtime);
            strftime(fecha,100,"%d/%m/%y %H:%S",tm);
            dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_mtime </td> <td bgcolor=\"white\"> ";
            dot += fecha;
            dot += " </td></tr>\n";
            tm=localtime(&super.s_umtime);
            strftime(fecha,100,"%d/%m/%y %H:%S",tm);
            dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_umtime </td> <td bgcolor=\"white\"> ";
            dot += fecha;
            dot += " </td> </tr>\n";
            dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_mnt_count </td> <td bgcolor=\"white\"> ";
            dot += to_string(super.s_mnt_count);
            dot += " </td> </tr>\n";
            dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_magic </td> <td bgcolor=\"white\"> ";
            dot += to_string(super.s_magic);
            dot += " </td> </tr>\n";
            dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_inode_size </td> <td bgcolor=\"white\"> ";
            dot += to_string(super.s_inode_size);
            dot += " </td> </tr>\n";
            dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_block_size </td> <td bgcolor=\"white\"> ";
            dot += to_string(super.s_block_size);
            dot += " </td> </tr>\n";
            dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_first_ino </td> <td bgcolor=\"white\"> ";
            dot += to_string( super.s_first_ino);
            dot += " </td> </tr>\n";
            dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_first_blo </td> <td bgcolor=\"white\"> ";
            dot += to_string(super.s_first_blo);
            dot += " </td> </tr>\n";
            dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_bm_inode_start </td> <td bgcolor=\"white\"> "+to_string(super.s_bm_inode_start)+" </td></tr>\n";
            dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_bm_block_start </td> <td bgcolor=\"white\"> "+to_string(super.s_bm_block_start)+" </td> </tr>\n";
            dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_inode_start </td> <td bgcolor=\"white\"> "+to_string(super.s_inode_start)+" </td> </tr>\n";
            dot += "    <tr> <td bgcolor=\"lightsteelblue\"> s_block_start </td> <td bgcolor=\"white\"> "+to_string(super.s_block_start)+" </td> </tr>\n";
            dot += "   </table>>]\n";
            dot +="\n}";

            fclose(fp);

            // Obtener la ruta.
            string pathClone = this->path;
            string pathTwice = this->path;
            string terminacion;
            pathTwice += ".txt";
            const size_t last_slash_idx = pathClone.find_last_of(".");
            if (std::string::npos != last_slash_idx)
            {
                terminacion = pathClone.substr(last_slash_idx, pathClone.length());
                pathClone = pathClone.substr(0, last_slash_idx);
            }

            string ruta_aux = this->path;
            string path = this->path;
            string comando = "sudo mkdir -p \'";
            comando+= dirNam(path);
            comando+= '\'';
            system(comando.c_str());

            string comandow = "sudo chmod -R 777 \'";
            comandow+= dirNam(ruta_aux);
            comandow += '\'';
            system(comandow.c_str());


            // Creando el file.
            char arreglo[dot.length()];
            strcpy(arreglo, dot.c_str());
            FILE *nuevo = fopen(pathTwice.c_str(),"w");
            fprintf(nuevo,"%s\n",arreglo);
            fclose(nuevo);
            string comandoS = "dot \'";
            comandoS += pathTwice;
            comandoS +="\' -o \'" + pathClone + terminacion + " \' -T" + terminacion.substr(1,terminacion.length());
            system(comandoS.c_str());
            cout << "Reporte SUPERBLOQUE ha sido creado." << endl;
        }
    }
}

void REP_::reportLS()
{
    MOUNT_ disk;
    int aux = 0;
    QList<MOUNT_>::iterator i;
    for(i=mounted->begin(); i != mounted->end(); i++)
    {
        if(i->getId() == this->getId())
        {
            disk = mounted->at(aux);
            break;
        }
        aux++;
    }
    int index = disk.partIndex();
    if(index != -1){
        MBR masterboot;
        SuperBloque super;
        InodoTable inodo;
        char auxRuta[500];
        strcpy(auxRuta,cont.data());
        FILE *fp = fopen(disk.getPath().data(),"r+b");
        fread(&masterboot,sizeof(MBR),1,fp);
        fseek(fp,masterboot.mbr_partitions[index].part_start,SEEK_SET);
        fread(&super,sizeof(SuperBloque),1,fp);
        int existe = findFile(fp,auxRuta);
        if(existe != -1){
            char nombre[50];
            char auxRuta[400];
            strcpy(auxRuta,cont.data());
            strcpy(nombre,basename(auxRuta));
            fseek(fp,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*existe,SEEK_SET);
            fread(&inodo,sizeof(InodoTable),1,fp);
            Usuario user = getUsuario(disk.getPath(),masterboot.mbr_partitions[index].part_start,inodo.i_uid);
            //r.graficarPermisos(aux->direccion,valPath,ext,masterboot.mbr_partitions[index].part_start,existe,user,QString(nombre));
            SuperBloque super;
            InodoTable inodo;

            fseek(fp,masterboot.mbr_partitions[index].part_start,SEEK_SET);
            fread(&super,sizeof(SuperBloque),1,fp);
            fseek(fp,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*existe,SEEK_SET);
            fread(&inodo,sizeof(InodoTable),1,fp);

            FILE *graph = fopen("grafica.dot","w");
            fprintf(graph,"digraph G{\n\n");
            fprintf(graph, "    nodo [ shape=none, fontname=\"Century Gothic\" \n");
            fprintf(graph, "    label=< <table border=\'0\' cellborder='1\' cellspacing=\'0\' bgcolor=\"lightsteelblue\">\n");
            fprintf(graph, "     <tr> <td><b>Permisos</b></td><td><b>Owner</b></td><td><b>Grupo</b></td><td><b>Size</b></td><td><b>Fecha</b></td><td><b>Hora</b></td><td><b>Tipo</b></td><td><b>Name</b></td> </tr>\n");

            string auxPermisos = to_string(inodo.i_perm);
            char propietario = auxPermisos[0];
            char grupo = auxPermisos[1];
            char otros = auxPermisos[2];
            char permisos[50];

            //Tipo de permisos para el propietario
            if(propietario == '0')
                strcpy(permisos,"---");
            else if(propietario == '1')
                strcpy(permisos,"--x");
            else if(propietario == '2')
                strcpy(permisos,"-w-");
            else if(propietario == '3')
                strcpy(permisos,"-wx");
            else if(propietario == '4')
                strcpy(permisos,"r--");
            else if(propietario == '5')
                strcpy(permisos,"r-x");
            else if(propietario == '6')
                strcpy(permisos,"rw-");
            else if(propietario == '7')
                strcpy(permisos,"rwx");

            //Tipo de permisos para grupo
            if(grupo == '0')
                strcat(permisos," ---");
            else if(grupo == '1')
                strcat(permisos," --x");
            else if(grupo == '2')
                strcat(permisos," -w-");
            else if(grupo == '3')
                strcat(permisos," -wx");
            else if(grupo == '4')
                strcat(permisos," r--");
            else if(grupo == '5')
                strcat(permisos," r-x");
            else if(grupo == '6')
                strcat(permisos," rw-");
            else if(grupo == '7')
                strcat(permisos," rwx");

            //Tipo de permisos para otros
            if(otros == '0')
                strcat(permisos," ---");
            else if(otros == '1')
                strcat(permisos," --x");
            else if(otros == '2')
                strcat(permisos," -w-");
            else if(otros == '3')
                strcat(permisos," -wx");
            else if(otros == '4')
                strcat(permisos," r--");
            else if(otros == '5')
                strcat(permisos," r-x");
            else if(otros == '6')
                strcat(permisos," rw-");
            else if(otros == '7')
                strcat(permisos," rwx");

            fprintf(graph,"<tr> <td bgcolor=\"white\">%s</td> ",permisos);
            fprintf(graph, "<td bgcolor=\"white\">%s</td>",user.username);
            fprintf(graph, "<td bgcolor=\"white\">%s</td>",user.group);
            fprintf(graph, "<td bgcolor=\"white\">%d</td>",inodo.i_size);

            struct tm *tm;
            char fecha[100];
            tm=localtime(&inodo.i_atime);
            strftime(fecha,100,"%d/%m/%y",tm);
            fprintf(graph, "<td bgcolor=\"white\">%s</td>",fecha);
            strftime(fecha,100,"%H:%S",tm);
            fprintf(graph,"<td bgcolor=\"white\">%s</td>",fecha);
            if(inodo.i_type == '0')
                fprintf(graph,"<td bgcolor=\"white\">%s</td>","Carpeta");
            else if(inodo.i_type == '1')
                fprintf(graph,"<td bgcolor=\"white\">%s</td>","Archivo");
            fprintf(graph, "<td bgcolor=\"white\">%s</td> </tr>\n",nombre);

            fprintf(graph, "    </table>>]\n");
            fprintf(graph,"\n}");
            fclose(graph);

            fclose(fp);


            // Obtener la ruta.
            string pathClone = this->path;
            string pathTwice = this->path;
            string terminacion;
            pathTwice += ".txt";
            const size_t last_slash_idx = pathClone.find_last_of(".");
            if (std::string::npos != last_slash_idx)
            {
                terminacion = pathClone.substr(last_slash_idx, pathClone.length());
                pathClone = pathClone.substr(0, last_slash_idx);
            }

            string ruta_aux = this->path;
            string path = this->path;
            string comando = "sudo mkdir -p \'";
            comando+= dirNam(path);
            comando+= '\'';
            system(comando.c_str());

            string comandow = "sudo chmod -R 777 \'";
            comandow+= dirNam(ruta_aux);
            comandow += '\'';
            system(comandow.c_str());


            // Creando el file.

            string comandoS = "dot -Tpng grafica.dot -o \'"+ pathClone + terminacion + "\'";
            system(comandoS.c_str());

            cout << "Reporte LS generado con éxito." << endl;
        }
        else
        {
            cout << "La ruta especificada no ha podido ubicarse." << endl;
        }
        fclose(fp);
    }
}

Usuario REP_::getUsuario(string direccion, int inicioSuper, int usuario)
{
    FILE *fp = fopen(direccion.data(),"rb+");

    char cadena[400] = "\0";
    SuperBloque super;
    InodoTable inodo;
    Usuario response;

    fseek(fp,inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,fp);
    //Nos posicionamos en el inodo del archivo users.txt
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
        char user[12];
        char grupo[12];
        char *end_token;
        char *token2 = strtok_r(token,",",&end_token);
        strcpy(id,token2);
        if(strcmp(id,"0") != 0){//Verificar que no sea un U/G eliminado
            token2 = strtok_r(nullptr,",",&end_token);
            strcpy(tipo,token2);
            if(strcmp(tipo,"U") == 0){
                token2 = strtok_r(nullptr,",",&end_token);
                strcpy(grupo,token2);
                token2 = strtok_r(nullptr,",",&end_token);
                strcpy(user,token2);
                int idAux = atoi(id);
                if(idAux == usuario){
                    string groupName(grupo);
                    response.id_usr = atoi(id);
                    response.id_grp = buscarGrupo(groupName);
                    strcpy(response.username,user);
                    strcpy(response.group,grupo);
                    return response;
                }

            }
        }
        token = strtok_r(nullptr,"\n",&end_str);
    }
    return response;
}

int REP_::buscarGrupo(string name)
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
