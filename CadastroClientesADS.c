#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define QUANTIDADE_MAXIMA_CLIENTES 5


typedef struct {
	int id;
	char nome[100];
	char telefone[10];
	char endereco[100];
} Cliente;

typedef enum OpcoesMenu { Sair, Cadastrar, Consultar } OpcaoMenu;

OpcaoMenu apresenta_menu();
void executa( OpcaoMenu opcao );
void cadastra_novo_cliente();
void consulta_clientes();
int podeCadastrarNovoCliente();
int geraNovoId();
void grava_cadastro_cliente(cliente);

Cliente clientes[ QUANTIDADE_MAXIMA_CLIENTES ];

int main(int argc, char *argv[]) {
	
	OpcaoMenu opcao;
	
	do {
		opcao = apresenta_menu();
		if (opcao > Consultar){
			printf("Opcao invalida!\n");
			sleep(2);
		} else {
			executa(opcao);
		}
	} while( opcao != Sair );
	
	return 0;
}

OpcaoMenu apresenta_menu(){
	int opcao;
	
	system("CLS");

	printf("Seja bem vindo!\n");
	printf("[1] - Cadastrar novo cliente\n");
	printf("[2] - Consultar clientes cadastrados\n");
	printf("[0] - Sair do sistema\n");
	
	printf("Digite a opcao: ");
	scanf("%i", &opcao);
	fflush(stdin);
	
	return (OpcaoMenu) opcao;
}

void executa( OpcaoMenu opcao ) {
	switch(opcao){
		case Cadastrar:
			if( podeCadastrarNovoCliente() )
			   cadastra_novo_cliente();
			else 
			   printf("Agenda lotada!\n");
			      
			break;
		case Consultar:
			consulta_clientes();
			break;
	}
}

void cadastra_novo_cliente(){
	Cliente cliente;
	cliente.id = geraNovoId();

	system("cls");
		
	printf("Cadastrando cliente ID: %i\n", cliente.id);
	
	printf("\nNome do cliente:");
	scanf("&s", &cliente.nome);
	fflush(stdin);
	
	printf("\nTelefone do cliente:");
    scanf("&s", &cliente.telefone);
	fflush(stdin);
	
	printf("\nEndereco do cliente:");
    scanf("&s", &cliente.endereco);
	fflush(stdin);
	
	grava_cadastro_cliente(cliente);
	
}

void grava_cadastro_cliente(Cliente cliente){
	
	int i;	
	
	for(i = 0; i < QUANTIDADE_MAXIMA_CLIENTES ; i++ ){
		if(clientes[i].id == 0){
			clientes[i] = cliente;
			break;
		}
	}	
}

int geraNovoId(){
	int i;
	int max = 0;
	
	for(i = 0; i < QUANTIDADE_MAXIMA_CLIENTES ; i++ ){
		if(clientes[i].id != 0){
			if(clientes[i].id > max ){
				max = clientes[i].id;
			}
		}
	}
	
	return max + 1;
}

void consulta_clientes(){
	int i;
	printf("CODIGO | NOME                                       | TELEFONE | ENDERECO");

	for(i = 0; i < QUANTIDADE_MAXIMA_CLIENTES ; i++ ){
		if (clientes[i].id != 0){
			printf("      %i", clientes[i].id );
			printf(" %s", clientes[i].nome );
		}
			
	}
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

