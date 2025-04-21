//g++ -g programa.cpp -o programa
//gdb ./programa
//break Pessoa::Pessoa
//break Pessoa::~Pessoa
//run
//print nome
//continue
/*
4- Tarefa 25/03/2025: Definir uma classe para representar o cliente de um banco. Pelo menos 4
atributos e 4 m�todos.
(banco), tem que ter o saldo e identificador do cliente e o identificador n�o pode ser o nome do cliente.
N�o � pra usar o "construtor" e tamb�m definir no m�nimo 4 m�todos para manipular os atributos de cada
cliente. Ex.: 
m�todo saque, tem que trabalhar saldo e subtrair e par�metro que estou passando. Se estou criando um
dep�sito tem que somar.
*/

#include <iostream>
using namespace std;

class Pessoa {
public:
    // Construtor
    Pessoa(string nome) {
        this->nome = nome;
        cout << "Construtor chamado para " << nome << endl;
    }
    
    // Destrutor
    ~Pessoa() {
        cout << "Destrutor chamado para " << nome << endl;
    }

    void exibirNome() {
        cout << "O nome �: " << nome << endl;
    }

private:
    string nome;
};

int main() {
    cout << "Criando objeto...\n";
    Pessoa pessoa1("Talles");

    pessoa1.exibirNome();

    cout << "Encerrando programa...\n";
    return 0;
}