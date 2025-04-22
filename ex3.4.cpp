/*
Tarefa 18/03/2025
MODIFCADORES DE TIPOS:
private	  - Somente dentro da pr�pria classe
protected - Dentro da classe e suas subclasses (heran�a)
public	  - Pode ser acessado de qualquer lugar (ex: no main)

* private - atributo saldo
- Ele � escondido da parte externa (como o main).
- S� pode ser manipulado por m�todos p�blicos da pr�pria classe (depositar, sacar, consultarSaldo).
- Isso protege contra altera��es diretas indesejadas:
    cliente1.saldo = 999999; // ? Isso seria um risco se fosse public

* protected - atributo identificador
- Ele n�o pode ser acessado fora da classe (como no main).
- Mas pode ser acessado por classes que herdam ClienteBanco (se voc� fizesse heran�a futuramente).
- Bom pra manter o controle, mas permitir acesso controlado em classes filhas.

* public - atributos nome e numeroConta + m�todos
- Podem ser acessados de qualquer lugar.
- M�todos depositar, sacar, consultarSaldo, exibirIdentificador s�o a interface p�blica da sua classe, 
ou seja, como o mundo externo interage com ela.

* Encapsulamento - o que � isso?
- Encapsular = esconder detalhes internos da classe, expondo s� o necess�rio.
- Voc� esconde saldo (com private) e obriga o usu�rio a usar m�todos como depositar() e consultarSaldo(). Isso evita erros e garante seguran�a.
- Exemplo de erro que seria poss�vel se n�o usasse encapsulamento:
cliente1.saldo = -999; // Isso seria um problema s�rio!
*/

#include <iostream>
#include <string>

class ClienteBanco {
private:
    double saldo = 1000.0; // Atributo encapsulado (somente a pr�pria classe pode acessar)

protected:
    int identificador; // Protegido: s� a classe e suas herdeiras podem acessar

public:
    std::string nome;
    std::string numeroConta;

    // M�todo p�blico: pode ser chamado no main
    void inicializarCliente(const std::string& nomeCliente, int idCliente, const std::string& conta) {
        nome = nomeCliente;
        identificador = idCliente;
        numeroConta = conta;
        std::cout << "Nome: " << nome
                  << " | Identificador: " << identificador
                  << " | Conta: " << conta << std::endl;
    }

    // M�todo p�blico que acessa atributo privado indiretamente
    void depositar(double valor) {
        if (valor < 0) {
            std::cout << "Valor negativo! Deposite um valor maior do que 0.\n";
        } else {
            saldo += valor;
            std::cout << "Dep�sito de R$" << valor << " realizado com sucesso!\n";
        }
    }

    // Outro m�todo p�blico
    void sacar(double valor) {
        if (valor >= 0 && valor <= saldo) {
            saldo -= valor;
            std::cout << "Saque de R$" << valor << " realizado com sucesso!\n";
        } else {
            std::cout << "Saque inv�lido! Verifique o valor ou saldo insuficiente.\n";
        }
    }

    void consultarSaldo() {
        std::cout << "Saldo: R$" << saldo << std::endl;
    }

    void exibirIdentificador() const {
        std::cout << "Identificador: " << identificador << std::endl;
    }
};

int main() {
    ClienteBanco cliente1;

    cliente1.inicializarCliente("Lucas Eduardo", 123, "2910");

    cliente1.depositar(100.0);
    cliente1.sacar(50.0);
    cliente1.consultarSaldo();
    cliente1.exibirIdentificador();

    // cliente1.saldo = 5000;         ? N�o pode acessar atributo privado
    // cliente1.identificador = 999; ? N�o pode acessar atributo protected

    return 0;
}
