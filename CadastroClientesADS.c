#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define QUANTIDADE_MAXIMA_CLIENTES 5

typedef struct {
	char rua[50];
	char numero[6];
	char complemento[20];
	char bairro[20];
	char cidade[30];
	char estado[2]; 
} Endereco;

typedef struct {
	int id;
	char nome[100];
	char telefone[10];
	Endereco endereco;
} Cliente;

typedef enum OpcoesMenu { Sair, Cadastrar, Consultar } OpcaoMenu;

OpcaoMenu apresenta_menu();
void executa( OpcaoMenu opcao );
void cadastra_novo_cliente();
void consulta_clientes();
int podeCadastrarNovoCliente();

Cliente clientes[ QUANTIDADE_MAXIMA_CLIENTES ];

int main(int argc, char *argv[]) {
	
	OpcaoMenu opcao;
	
	do {
		opcao = apresenta_menu();
		if (opcao > Consultar){
			printf("Opcao invalida!\n");
			//sleep(2);
		} else {
			executa(opcao);
		}
	} while( opcao != Sair );
	
	return 0;
}

OpcaoMenu apresenta_menu(){
	int opcao;
	
	//system("CLS");

	printf("Seja bem vindo!\n");
	printf("[1] - Cadastrar novo cliente\n");
	printf("[2] - Consultar clientes cadastrados\n");
	printf("[0] - Sair do sistema\n");
	
	printf("Digite a opcao: ");
	scanf("%i", &opcao);
	
	return (OpcaoMenu) opcao;
}

void executa( OpcaoMenu opcao ) {
	switch(opcao){
		case Cadastrar:
			if( podeCadastrarNovoCliente() )
			   cadastra_novo_cliente();
			else 
			   printf("O numero maximo de clientes foi atingido! (5)\n");
			      
			break;
		case Consultar:
			consulta_clientes();
			break;
	}
}

void cadastra_novo_cliente(){
	printf("cadastra cli\n");
}

void consulta_clientes(){
	printf("consulta cli\n");
}

int podeCadastrarNovoCliente(){
	int count = 0, i;
	
	for(i = 0; i < QUANTIDADE_MAXIMA_CLIENTES ; i++ ){
		if(clientes[i].id != 0){
			count++;
		}
	}
	
	return count < 5;
}

