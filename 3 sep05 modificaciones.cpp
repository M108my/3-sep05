#include<iostream>
using namespace std;

class cBase1{
    int objeto_base_1;
    int objeto_base_2;
public:
    cBase1();
    virtual ~cBase1();

    void funcion_A();
    void funcion_B();
    virtual void funcion_C(); ///POLIMORFIMO
    virtual void funcion_D() = 0;
};

cBase1 :: cBase1() : objeto_base_1(1), objeto_base_2(2){
    cout<<"Constructor de PRIMERA CLASE BASE" <<endl;
}

cBase1 :: ~cBase1(){cout<<"Destructor de PRIMERA CLASE BASE"<<endl;}

void cBase1:: funcion_A(){
    cout<<"Funcion A de PRIMERA CLASE BASE"<<endl;
}

void cBase1:: funcion_B(){
    cout<<"Funcion B de PRIMERA CLASE BASE"<<endl;
}

void cBase1:: funcion_C(){
    cout<<"Funcion C de PRIMERA CLASE BASE"<<endl;
}

class cBase2{
    int objeto_base_3;
    int objeto_base_4;
public:
    cBase2();
    virtual ~cBase2();

    void funcion_A();
    void funcion_B();
    virtual void funcion_C(); ///POLIMORFISMO
    virtual void funcion_D() = 0;
};

cBase2 :: cBase2() : objeto_base_3(3), objeto_base_4(4){
    cout<<"Constructor de SEGUNDA CLASE BASE" <<endl;
}

cBase2 :: ~cBase2(){cout<<"Destructor de SEGUNDA CLASE BASE"<<endl;}

void cBase2:: funcion_A(){
    cout<<"Funcion A de SEGUNDA CLASE BASE"<<endl;
}

void cBase2:: funcion_B(){
    cout<<"Funcion B de SEGUNDA CLASE BASE"<<endl;
}

void cBase2:: funcion_C(){
    cout<<"Funcion C de SEGUNDA CLASE BASE"<<endl;
}

///CLASE DERIVADA
class cDerivada : public cBase1, public cBase2{
    int objeto_deriv_1;
    int objeto_deriv_2;
public:
    cDerivada();
    ~cDerivada();

    void funcion_A();
    void funcion_C();
    void funcion_D();
};

cDerivada :: cDerivada() : cBase1(), cBase2(), objeto_deriv_1(5), objeto_deriv_2(6){
    cout<<"Constructor de DERIVADA" <<endl;
}

cDerivada :: ~cDerivada(){
    cout<<"Destructor de DERIVADA"<<endl;
}

void cDerivada:: funcion_A(){
    cout<<"Funcion A de DERIVADA"<<endl;
}

void cDerivada :: funcion_C(){
    cout<<"Funcion C de DERIVADA"<<endl;
}

void cDerivada::funcion_D(){
   cout<<"Funcion D de DERIVADA"<<endl;
}


int main(void){
    cDerivada derivada;
    cBase1 *base1_ptr = &derivada;
    cBase2 *base2_ptr = &derivada;


    derivada.funcion_A();
    base1_ptr->funcion_A();
    base2_ptr->funcion_A();

    derivada.cBase1::funcion_B();
    base1_ptr->funcion_B();
    base2_ptr->funcion_B();

    derivada.funcion_C();
    base1_ptr->funcion_C();
    base2_ptr->funcion_C();

    derivada.funcion_D();
    base1_ptr->funcion_D(); /// = derivada.funcion_D();
    base2_ptr->funcion_D();

}
