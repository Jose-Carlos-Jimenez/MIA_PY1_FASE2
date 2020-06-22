#ifndef MKUSR_H
#define MKUSR_H

#endif // MKUSR_H

#include <iostream>
#include <string.h>

using namespace std;

class MKUSR_
{
private:
    string usr;
    string pwd;
    string grp;
    bool correct;
public:
    MKUSR_():usr(""),pwd(""),grp(""),correct(true){};
    void setUsr(char* usr);
    void setPwd(char* pwd);
    void setGrp(char* grp);
    void semantic();
    void run();
};

void MKUSR_::setUsr(char *usr)
{
    this->usr = usr;
    if(this->usr[0] == '\"')
    {
        this->usr = this->usr.substr(1,this->usr.length()-2);
    }
}

void MKUSR_::setPwd(char *pwd)
{
    this->pwd = pwd;
    if(this->pwd[0] == '\"')
    {
        this->pwd = this->pwd.substr(1,this->pwd.length()-2);
    }
}

void MKUSR_::setGrp(char *grp)
{
    this->grp = grp;
    if(this->grp[0] == '\"')
    {
        this->grp = this->grp.substr(1,this->grp.length()-2);
    }
}

void MKUSR_::semantic()
{
    if(this->grp == "")
    {
        correct = false;
        cout << "El parámetro grp es obligatorio." << endl;
    }
    if(this->pwd == "")
    {
        correct = false;
        cout << "El parámetro pwd es obligatorio." << endl;
    }
    if(this->usr == "")
    {
        correct = false;
        cout << "El parámetro usr es obligatorio." << endl;
    }
}

void MKUSR_::run()
{
    semantic();
    if(this->correct)
    {
        cout << "TOY CORRECTO " << endl;
    }

}
