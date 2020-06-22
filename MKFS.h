#ifndef MKFS_H
#define MKFS_H

#endif // MKFS_H
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <MOUNT.h>

using namespace std;

extern QList<MOUNT_> *mounted;

class MKFS_
{
private:
public:
    string id;
    string type;
    bool correct;
    MKFS_():id(""), type(""), correct(false){};
    void run();
    void semantic();
};

void MKFS_::run()
{
    semantic();
    if(correct)
    {
        //-------------------------------------------------------
        //----------- BUSCANDO LA PARTICIÓN MONTADA -------------
        QList<MOUNT_>::iterator i;
        bool finded = false;
        MOUNT_ aux;
        int j = 0;
        for(i=mounted->begin(); i != mounted->end(); i++,j++)
        {
            if(i->getId() == this->id)
            {
                aux = mounted->at(j);
                finded = true;
                break;
            }
            j++;
        }
        //-------------------------------------------------------
        if(finded)
        {
            int  partIndex = aux.partIndex();
            if(partIndex != -1)
            {
                MBR master;
                FILE *file = fopen(aux.getPath().c_str(),"r+b");

                // Leyendo el MBR
                fseek(file,0, SEEK_SET);
                fread(&master,sizeof (MBR),1,file);

                //int inicio = masterboot.mbr_partition[index].part_start;
                //int tamano = masterboot.mbr_partition[index].part_size;
                int byteInitial = master.mbr_partitions[partIndex].part_start;
                int size = master.mbr_partitions[partIndex].part_size;

                // Calculando según la formula.
                double n = (size - static_cast<int>(sizeof(SuperBloque)))/(4+static_cast<int>(sizeof(Journal)) + static_cast<int>(sizeof (InodoTable)) +3*static_cast<int>(sizeof (BloqueArchivo)));
                int cantidadInodos = static_cast<int>(floor(n));
                int cantidadBloques = 3*cantidadInodos;
                int jsize = static_cast<int>(sizeof (Journal))*cantidadInodos;
                int ssize = static_cast<int>(sizeof (SuperBloque))*cantidadInodos;

                // Seteando el superbloque
                SuperBloque super;
                super.s_magic = 0xEF53;
                super.s_mtime = time(nullptr);
                super.s_umtime = 0;
                super.s_first_blo = 2;
                super.s_first_ino = 2;
                super.s_mnt_count = 0;
                super.s_block_size = sizeof(BloqueArchivo);
                super.s_inode_size = sizeof (InodoTable);
                super.s_block_start = byteInitial+ssize+jsize+cantidadInodos+cantidadBloques + static_cast<int>(sizeof(InodoTable))*cantidadInodos;
                super.s_inode_start = byteInitial+ssize+jsize+cantidadInodos+cantidadBloques;
                super.s_blocks_count = cantidadBloques;
                super.s_inodes_count = cantidadInodos;
                super.s_bm_block_start = byteInitial + ssize + jsize  + cantidadInodos;
                super.s_bm_inode_start = byteInitial + ssize + jsize;
                super.s_filesystem_type = 3;
                super.s_free_blocks_count = cantidadBloques - 2;
                super.s_free_inodes_count = cantidadInodos - 2;

                // Seteando los iNodos y Bloques iniciales.
                InodoTable iNodo;
                BloqueCarpeta bloque;

                fclose(file);
                file = fopen(aux.getPath().data(),"r+b");

                // Escribiendo el superbloque en la partición
                fseek(file,byteInitial,SEEK_SET);
                fwrite(&super,sizeof (SuperBloque),1,file);

                //-------------------------------------------
                // Llenando el bitmap inodos
                char buffer = '0';
                for(int i = 0; i < cantidadInodos; i++){
                    fseek(file,super.s_bm_inode_start + i,SEEK_SET);
                    fwrite(&buffer,sizeof(char),1,file);
                }

                // Carpeta raiz
                buffer = '1';
                fseek(file,super.s_bm_inode_start,SEEK_SET);
                fwrite(&buffer,sizeof(char),1,file);
                // Users.txt
                fwrite(&buffer,sizeof(char),1,file);

                //-------------------------------------------
                // Llenando el bitmap bloques
                buffer = '0';
                for(int i = 0; i < cantidadBloques; i++){
                    fseek(file,super.s_bm_block_start+ i,SEEK_SET);
                    fwrite(&buffer,sizeof(char),1,file);
                }

                // Carpeta raiz
                buffer = '1';
                fseek(file,super.s_bm_block_start,SEEK_SET);
                fwrite(&buffer,sizeof(char),1,file);
                // Users.txt
                buffer = '2';
                fwrite(&buffer,sizeof(char),1,file);

                //--------------------------------------------
                // Seteando iNodo para usuario root
                iNodo.i_gid = 1;
                iNodo.i_uid = 1;
                iNodo.i_perm = 664;
                iNodo.i_size = 0;
                iNodo.i_type = '0';
                iNodo.i_atime = time(nullptr);
                iNodo.i_block[0] = 0;
                iNodo.i_ctime = time(nullptr);
                iNodo.i_mtime = time(nullptr);
                for(int i = 1 ; i < 15;i++)
                {
                    iNodo.i_block[i] = -1;
                }
                fseek(file,super.s_inode_start, SEEK_SET);
                fwrite(&iNodo,sizeof (InodoTable),1,file);

                // Seteando bloque para usuario root
                strcpy(bloque.b_content[0].b_name ,"-");
                bloque.b_content[0].b_inodo= 0;
                strcpy(bloque.b_content[1].b_name, "--");
                bloque.b_content[1].b_inodo = 0;
                strcpy(bloque.b_content[2].b_name, "users.txt");
                bloque.b_content[2].b_inodo = 1;
                strcpy(bloque.b_content[3].b_name, "-");
                bloque.b_content[3].b_inodo = 1;

                // Escribiendo el bloque en la partición.
                fseek(file,super.s_block_start,SEEK_SET);
                fwrite(&bloque, sizeof (BloqueArchivo),1,file);

                // Seteando inodo para el archivo users.txt
                iNodo.i_gid = 1;
                iNodo.i_uid = 1;
                iNodo.i_perm = 755;
                iNodo.i_size = 27;
                iNodo.i_type = '1';
                iNodo.i_atime = time(nullptr);
                iNodo.i_block[0] = 1;
                iNodo.i_ctime = time(nullptr);
                iNodo.i_mtime = time(nullptr);
                for(int i = 1 ; i < 15;i++)
                {
                    iNodo.i_block[i] = -1;
                }
                fseek(file,super.s_inode_start+static_cast<int>(sizeof(InodoTable)),SEEK_SET);
                fwrite(&iNodo,sizeof (InodoTable),1,file);

                // Seteando bloque para el archivo users.txt
                BloqueArchivo arch;
                memset(arch.b_content,0,sizeof (BloqueArchivo));
                strcpy(arch.b_content,"1,G,root\n1,U,root,root,123\n");
                fseek(file,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta)), SEEK_SET);
                fwrite(&arch,sizeof (BloqueArchivo),1,file);
                fclose(file);

                cout << "Partición formateada con EXT3 con éxito." << endl;
            }
        }
        else
        {
            cout << "La partición que deseas formatear no está montada." << endl;
        }
    }
}

void MKFS_::semantic()
{
    if(this->id != "" && this->type != "")
    {
        this->correct = true;
    }
    else
    {
        cout << "Falta el parámetro id para establecer el sistema." << endl;
    }
}
