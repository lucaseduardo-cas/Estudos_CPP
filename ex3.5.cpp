/*
Tarefa 18/03/2025
C�digo com heran�a: ClienteVip acessando identificador
- Analogia r�pida:
private = tranca o dado no cofre. S� o pr�prio dono (a classe) tem a chave.

protected = o dono e os filhos t�m a chave.

public = t� em cima da mesa, qualquer um v�.
*/

#include <iostream>
#include <string>

// Classe base
class ClienteBanco {
private:
    double saldo = 1000.0; // privado: acesso s� dentro da classe base

protected:
    int identificador; // protegido: acesso dentro da classe e das herdeiras

public:
    std::string nome;
    std::string numeroConta;

    void inicializarCliente(const std::string& nomeCliente, int idCliente, const std::string& conta) {
        nome = nomeCliente;
        identificador = idCliente;
        numeroConta = conta;
    }

    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
        }
    }

    void sacar(double valor) {
        if (valor >= 0 && valor <= saldo) {
            saldo -= valor;
        }
    }

    double consultarSaldo() const {
        return saldo;
    }
};

/// Classe derivada
class ClienteVip : public ClienteBanco {
public:
    void mostrarDadosVip() {
        std::cout << "=== Cliente VIP ===\n";
        std::cout << "Nome: " << nome << std::endl;
        std::cout << "Conta: " << numeroConta << std::endl;
        std::cout << "Identificador (protegido): " << identificador << std::endl;
        std::cout << "Saldo: R$" << consultarSaldo() << std::endl;
    }
};

int main() {
    ClienteVip vip;
    vip.inicializarCliente("Lucas Eduardo", 999, "4444-8");

    // vip.identificador = 1234; ? Erro: identificador � protected, n�o pode ser acessado direto aqui
    vip.depositar(500);
    vip.sacar(300);
    
    vip.mostrarDadosVip(); // ? Aqui a classe derivada acessa os dados da base

    return 0;
}
