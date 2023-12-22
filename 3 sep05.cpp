#include<iostream>
using namespace std;

class cBase{
    int objeto_base_1;
    int objeto_base_2;
public:
    cBase();
    virtual ~cBase();

    void funcion_A();
    void funcion_B();
    virtual void funcion_C();
    virtual void funcion_D() = 0;
};

cBase :: cBase() : objeto_base_1(1), objeto_base_2(2){
    cout<<"Constructor de CLASE BASE" <<endl;
}

cBase :: ~cBase(){cout<<"Destructor de CLASE BASE"<<endl;}

void cBase:: funcion_A(){
    cout<<"Funcion A de CLASE BASE"<<endl;
}

void cBase:: funcion_B(){
    cout<<"Funcion B de CLASE BASE"<<endl;
}

void cBase:: funcion_C(){
    cout<<"Funcion C de CLASE BASE"<<endl;
}

class cDerivada : public cBase{
    int objeto_deriv_1;
    int objeto_deriv_2;
public:
    cDerivada();
    ~cDerivada();

    void funcion_A();
    void funcion_D();
};

cDerivada :: cDerivada() : cBase(), objeto_deriv_1(3), objeto_deriv_2(4){
    cout<<"Constructor de DERIVADA" <<endl;
}

cDerivada :: ~cDerivada(){
    cout<<"Destructor de DERIVADA"<<endl;
}

void cDerivada :: funcion_A(){
    cout<<"Funcion A de DERIVADA"<<endl;
}

void cDerivada :: funcion_D(){
    cout<<"Funcion D de DERIVADA"<<endl;
}

int main(void){
    cDerivada derivada;
    cBase *base_ptr = &derivada;

    derivada.funcion_A();
    base_ptr->funcion_A();

    derivada.funcion_B();
    base_ptr->funcion_B();

    derivada.funcion_C();
    base_ptr->funcion_C();

    derivada.funcion_D();
    base_ptr->funcion_D();

}