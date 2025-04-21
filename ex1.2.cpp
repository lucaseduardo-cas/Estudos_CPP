/*
1- Tarefa 25/02/2025: Construa um tipo abstrato de dados que contenha pelo menos 2 atributos e 2 m�todos
que v�o manipular os atributos. Ou seja, definir uma classe com 2 m�todos e 2 atributos. Al�m disso, 
construir um programa em linguagem C++ para implementar o tipo abstrato de dados (TAD). 
*/

#include <iostream>

class Computador {
public:
    std::string SO;
    std::string processador;

    Computador(const std::string& SO, const std::string& processador) : SO(SO), processador(processador) {} 

    void exibirSO () const {
        std::cout << "SO: " << SO << std::endl;
    }
    void exibirProcessador () const {
        std::cout << "Processador: " << processador << std::endl;
    }
};

int main () {

    // Declarando vari�veis
    std::string SO = "Windows 10";
    std::string processador = "Intel Core 15";

    // Criando de um objeto da classe computador chamado meuComputador
    Computador meuComputador(SO, processador);

    // Chamando o m�todo p�blico, fun��o exibirSO e exibirProcessador
    meuComputador.exibirSO();
    meuComputador.exibirProcessador();

    return 0;
}