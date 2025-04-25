/*
Tarefa 23/03/2025
1- Estudar exemplo (verificar a escrita e execu��o - compilar, por pra rodar e depura��o, verificar o que est� acontecendo com os 
atributos e m�todos do programa).

2- Criar uma classe gen�rica e duas classes especializadas, sendo uma mais gen�rica chamada "animal" e depois criar classes mais 
espec�ficas, por exemplo: "mam�fero", "r�ptil" cujo relacionamento da classe gen�rica ser� por heran�a simples. Definir pelo menos 
2 atributos para cada uma das classes. Definir m�todo construtor e destrutor para cada uma dessas classes e pelo menos mais dois 
m�todos de get e set para cada uma das classes. 
Avaliar o efeito da execu��o quando modificar os tipos de acesso entre os atributos de classe gen�rica e a classe especializada 
(definir tudo como p�blico, depois protegido e depois como privado. Rastrear com o GDB para ver o que est� acontecendo�l�).

- Trabalhar Geter e Setter
- Trabalhar Heran�a
*/

#include <iostream>
using namespace std;

// Classe gen�rica Animal
class Animal {
private:
    string nome;
    int idade;

public:
    // Construtor
    Animal(string nome, int idade) {
        this->nome = nome;
        this->idade = idade;
        cout << "Construtor chamado para Animal: " << nome << endl;
    }

    // Destrutor
    ~Animal() {
        cout << "Destrutor chamado para Animal: " << nome << endl;
    }

    // M�todo Getters
    string getNome() const { return nome; }
    int getIdade() const { return idade; }

    // M�todo Setters
    void setNome(string novoNome) { nome = novoNome; }
    void setIdade(int novaIdade) { idade = novaIdade; }
};

// Classe especializada Mam�fero
class Mamifero : public Animal {
private:
    string tipoPelo;

public:
    // Construtor
    Mamifero(string nome, int idade, string tipoPelo) : Animal(nome, idade) {
        this->tipoPelo = tipoPelo;
        // cout << "Construtor chamado para Mam�fero: " << nome << endl;
        cout << "Construtor chamado para Mam�fero: " << getNome() << endl;
    }

    // Destrutor
    ~Mamifero() {
        //cout << "Destrutor chamado para Mam�fero: " << nome << endl;
        cout << "Destrutor chamado para Mam�fero: " << getNome() << endl;
    }

    // M�todos Getters
    string getTipoPelo() const { return tipoPelo; }

    // M�todos Setters
    void setTipoPelo(string novoTipoPelo) { tipoPelo = novoTipoPelo; }

    void exibirDados() {
        //cout << "Nome: " << nome << ", Idade: " << idade << ", Tipo de pelo: " << tipoPelo << endl;
        cout << "Nome: " << getNome() << ", Idade: " << getIdade() << ", Tipo de pelo: " << tipoPelo << endl;
    }
};

// Classe especializada Reptil
class Reptil : public Animal {
private:
    bool temEscamas;

public:
    // Construtor
    Reptil(string nome, int idade, bool temEscamas) : Animal(nome, idade) {
        this->temEscamas = temEscamas;
        //cout << "Construtor chamado para Reptil: " << nome << endl;
        cout << "Construtor chamado para Réptil: " << getNome() << endl;
    }

    // Destrutor
    ~Reptil() {
        //cout << "Destrutor chamado para Reptil: " << nome << endl;
        cout << "Destrutor chamado para Réptil: " << getNome() << endl;
    }

    // M�todos Getters
    bool getTemEscamas() const { return temEscamas; }

    // M�todos Setters
    void setTemEscamas(bool novoTemEscamas) { temEscamas = novoTemEscamas; }

    void exibirDados() {
        //cout << "Nome: " << nome << ", Idade: " << idade << ", Tem escamas: " << (temEscamas ? "Sim" : "N�o") << endl;
        cout << "Nome: " << getNome() << ", Idade: " << getIdade() << ", Tem escamas: " << (temEscamas ? "Sim" : "N�o") << endl;
    }
};

int main() {
    cout << "Criando um Mam�fero e um R�ptil...\n";
    Mamifero cachorro("Rex", 5, "Curto");
    Reptil cobra("Naja", 3, true);

    cout << "\nExibindo dados:\n";
    cachorro.exibirDados();
    cobra.exibirDados();

    cout << "\nModificando atributos...\n";
    cachorro.setIdade(6);
    cachorro.setTipoPelo("Longo");
    cobra.setTemEscamas(false);

    cout << "\nDados atualizados:\n";
    cachorro.exibirDados();
    cobra.exibirDados();

    cout << "\nEncerrando programa...\n";
    return 0;
}
