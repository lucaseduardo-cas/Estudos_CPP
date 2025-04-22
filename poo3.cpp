#include <iostream>
#include "poo3.h" // inclui classe em arquivo externo poo2.h

using namespace std;

int main () {

    Veiculo *v1=new Veiculo(3);
    Veiculo *v2=new Veiculo(2);
    Veiculo *v3=new Veiculo(1);

    //v1->setLigado(0);
    v2->setLigado(1);
    //v3->setLigado(0);

    std::cout << v1->getVelMax() <<std::endl;
    std::cout << v2->getVelMax() <<std::endl;
    std::cout << v3->getVelMax() <<std::endl;

    if(v1->getLigado()) {
        cout << "Ve�culo 1 est� ligado" << endl;
    } else {
        cout << "Ve�culo 1 est� desligado" << endl;
    }
    if(v2->getLigado()) {
        cout << "Ve�culo 2 est� ligado" << endl;
    } else {
        cout << "Ve�culo 2 est� desligado" << endl;
    }
    if(v3->getLigado()) {
        cout << "Ve�culo 3 est� ligado" << endl;
    } else {
        cout << "Ve�culo 3 est� desligado" << endl;
    }

    return 0;
}