/*
Definir uma classe para representar o cliente de um banco. Pelo menos 4 atributos�e�4�m�todos.
25/03/2025: (banco), tem que ter o saldo e identificador do cliente e o identificador n�o pode ser o nome do cliente. 
N�o � pra usar o "construtor" e tamb�m definir no m�nimo 4 m�todos para manipular os atributos de cada cliente. Ex.: 
m�todo saque, tem que trabalhar saldo e subtrair e par�metro que estou passando. Se estou criando um dep�sito�tem�que�somar.
*/

#include <iostream>
#include <string>

class Banco {
private:
	int identificador; // ID do cliente
	double saldo;

public:
	// M�todo para definir o identificador (j� que n�o pode usar o construtor)
	void definirIdentificador(int id) {
		identificador = id;
	}

	// M�todo para definir o saldo inicial
	void definirSaldo(double valor) {
		saldo = valor;
	}

	// M�todo para depositar dinheiro
	void depositar(double valor) {
		if (valor > 0) {
			saldo += valor;
			std::cout << "Dep�sito de R$ " << valor << " realizado com sucesso.\n";
		} else {
			std::cout << "Valor inv�lido para depósito!\n";
		}
	}

	// M�todo para sacar dinheiro
	void sacar(double valor) {
		if (valor > 0 && valor <= saldo) {
			saldo -= valor;
			std::cout << "Saque de R$ " << valor << " realizado com sucesso.\n";
		} else {
			std::cout << "Saldo insuficiente ou valor inv�lido!\n";
		}
	}

	// M�todo para exibir saldo
	void exibirSaldo() const {
		std::cout << "Saldo atual: R$ " << saldo  << "\n";
	}
};

int main () {
	Banco cliente;
	int id;
	double saldoInicial;

	std::cout << "Digite o identificador do cliente: ";
	std::cin >> id;
	cliente.definirIdentificador(id);

	std::cout << "Digite o saldo inicial: R$ ";
	std::cin >> saldoInicial;
	cliente.definirSaldo(saldoInicial);

	cliente.exibirSaldo();

	cliente.depositar(500);
	cliente.exibirSaldo();

	cliente.sacar(200);
	cliente.exibirSaldo();

	return 0;

}
