#include <iostream>
#include <string>

class Aluno {
private: // S� pode ser acessado de dentro da pr�pria classe.
    std::string nome; // Atributo da classe

public: // Pode ser acessado fora da classe, como por exemplo no main().
    // Construtor
    Aluno(const std::string& nome) : nome(nome) {}

    // M�todo para exibir o nome do aluno
    void exibirNome() const {
        std::cout << "Nome: " << nome << std::endl;
    }
};

// argc = argument count -> � a quantidade de argumentos passados na linha de comando.
// argv[] = argument vector -> � um vetor de strings (na verdade char*) que representa os argumentos.
int main(int argc, char* argv[]) {
    // Imprime mensagem de erro no terminal usando std::cerr (que � como std::cout, mas para erros).
    // caso n�o tenha passado 2 argumentos
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <nome_do_aluno>" << std::endl;
        return 1;
    }

    // Obtendo o nome do aluno a partir dos argumentos da linha de comando
    std::string nome = argv[1]; // converte char* para std::string, que � o tipo moderno e mais seguro em C++.

    // Criando um objeto da classe Aluno chamado aluno1
    // O nome que voc� digiou na linha de comando est� sendo passado para o construtor
    Aluno aluno1(nome); // Chama construtor

    // Exibindo o m�todo p�blico: fun��o exibirNome
    aluno1.exibirNome();

    return 0;
}