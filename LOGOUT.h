#ifndef LOGOUT_H
#define LOGOUT_H

#endif // LOGOUT_H
#include <iostream>
#include <string.h>
#include <parser.h>
#include <structs.h>

using namespace std;

class LOGOUT_
{
public:
    LOGOUT_(){};
    void run();
};

extern bool loged;
extern Sesion sesion;

void LOGOUT_::run()
{
    if(loged)
    {
        loged = false;
        sesion.id_user = -1;
        sesion.direccion = "";
        sesion.inicioSuper = -1;
        cout << "Sesión finalizada con éxito." << endl;
    }
    else
    {
        cout << "Debe iniciar sesión para acceder al comando LOGOUT." << endl;
    }
}
