#pragma once
#ifndef STRUCTS_H
#define STRUCTS_H

#endif // STRUCTS_H

#include <time.h>
#include <string>

/**
 * Structs que son útiles para llevar un manejo
 * lógico de la memoria.
*/

/**
 * Particiones primarias.
*/
struct Partition{
public:
    char part_status = '0';
    char part_type = '0';
    char part_fit = '0';
    int part_start = -1;
    int part_size = 0;
    char part_name[16] = "";
};

/**
 * Particiones lógicas.
*/
struct EBR
{
    char part_status='0';
    char part_fit='0';
    int part_start=-1;
    int part_size=0;
    int part_next=-1;
    char part_name[16];
};

/**
 * Master boot record, sirve para administrar la memoria distribuida
 * a las particiones a manera de meta data.
*/
struct MBR
{
public:
    int mbr_tamano;
    time_t mbr_fecha_creacion;
    int mbr_disk_signature;
    char disk_fit;
    Partition mbr_partitions[4];
};

struct SuperBloque{
    int s_filesystem_type; //Guarda el numero que identifica al sistea de archivos utilizados
    int s_inodes_count; //Guarda el numero total de inodos
    int s_blocks_count; //Guarda el numero total de bloques
    int s_free_blocks_count; //Contiene el numero de bloques libres
    int s_free_inodes_count; //Contiene el numero inodos libres
    time_t s_mtime; //Ultima fecha en el que el sistema fue montado
    time_t s_umtime; //Ultima fecha en que el sistema fue desmontado
    int s_mnt_count; //Indica cuantas veces se ha montado el sistema
    int s_magic; //Valor que identifica al sistema de archivos 0xEF53
    int s_inode_size; //Tamano del inodo
    int s_block_size; //Tamano del bloque
    int s_first_ino; //Primer inodo libre
    int s_first_blo; //Primero bloque libre
    int s_bm_inode_start; //Guardara el inicio del bitmap de inodos
    int s_bm_block_start; //Guardara el inicio del bitmap de bloques
    int s_inode_start; //Guarada el inicio de la tabla de inodos
    int s_block_start; //Guardara el inicio de la tabla de bloques
};

struct InodoTable{
    int i_uid; //UID del usuario propiertario del archivo/carpeta
    int i_gid; //GID del grupo al que pertenece el archivo/carpeta
    int i_size; //Tamano del archivo en bytes
    int i_block[15]; //Array de bloques
    char i_type; //Indica si es archivo o carpeta
    int i_perm; //Guarada los permisos del archivo/carpeta
    time_t i_atime; //Ultima fecha en que se leyo el inodo sin modificarlo
    time_t i_ctime; //Fecha en que se creo el el inodo
    time_t i_mtime; //Ultima fecha en la que se modifco
};

struct Content{
    char b_name[12];//Nombre carpeta/archivo
    int b_inodo;//Apuntador hacia un inodo asociado al archivo o carpeta
};

struct BloqueCarpeta{
    Content b_content[4];//Array con el contenido de la carpeta
};

struct BloqueArchivo{
    char b_content[64];
};

struct BloqueApuntadores{
    int b_pointer[16];//Array con los apuntadores hacia bloques
};

/* Struct para guardar un registro de las operaciones que se hacen el sistema
 * de archivos ejemplo: creacion de carpetas o archivos */
struct Journal{
    char journal_operation_type[10];
    int journal_type;//Archivo/Carpeta
    char journal_name[100];
    char journal_content[100];
    time_t journal_date;
    int journal_owner;
    int journal_permissions;
};

/*Struct para guardar los datos del usuario loggeado*/
struct Sesion{
    int id_user;
    int id_grp;
    int inicioSuper;
    int inicioJournal;
    int tipo_sistema;
    std::string direccion;
    char fit;
};

struct Usuario{
    int id_usr;
    int id_grp;
    char username[12];
    char password[12];
    char group[12];
};

