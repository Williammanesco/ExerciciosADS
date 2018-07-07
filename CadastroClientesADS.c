#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define QUANTIDADE_MAXIMA_CLIENTES 5


typedef struct {
	int id;
	char nome[100];
	char telefone[20];
	char endereco[100];
} Cliente;

typedef enum OpcoesMenu { Sair, Cadastrar, Consultar } OpcaoMenu;

OpcaoMenu apresenta_menu();
void executa( OpcaoMenu opcao );
void cadastra_novo_cliente();
void consulta_clientes();
int podeCadastrarNovoCliente();
int geraNovoId();
int contaClientesCadastrados();
void grava_cadastro_cliente(Cliente cliente);

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
			else {
			  printf("Agenda lotada! (5)\n");
			  sleep(3);	
			} 
			      
			break;
			
		case Consultar:
			if(contaClientesCadastrados() == 0){
				printf("Agenda vazia!");
				sleep(3);
			} else {
			   	consulta_clientes();	
			}
			
			break;
	}
}

void cadastra_novo_cliente(){
	Cliente cliente;
	cliente.id = geraNovoId();
	char nome[100];
	char telefone[20];
	char endereco[100];

	system("cls");
		
	printf("Cadastrando cliente ID: %i\n\n", cliente.id);
	
	printf("Nome do cliente:");
	gets(nome);
	
	printf("\nTelefone do cliente:");
    gets(telefone);
	
	printf("\nEndereco do cliente:");
    gets(endereco);
    
	strcpy(cliente.nome, nome);
	strcpy(cliente.telefone, telefone);
	strcpy(cliente.endereco, endereco);
	
	printf("\n CLIENTE CADASTRADO!");
	sleep(2);
	
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
	printf("Clientes cadastrados\n");

	int i;
	Cliente cliente;
	
	printf("Codigo | Nome                                         | Telefone    | Endereco \n");
	for(i = 0; i < QUANTIDADE_MAXIMA_CLIENTES ; i++ ){
		cliente = clientes[i];
		
		if(cliente.id > 0){
			printf("      %i", cliente.id);
			printf("  %-45s", cliente.nome);
			printf("  %-13s", cliente.telefone);
			printf(" %s", cliente.endereco);
			printf("\n");	
		}
		
	}
	
	//printf("\n Pressione qualquer tecla para sair...");
	system("PAUSE");
}

int contaClientesCadastrados(){
	int count = 0, i;
	
	for(i = 0; i < QUANTIDADE_MAXIMA_CLIENTES ; i++ ){
		if(clientes[i].id != 0){
			count++;
		}
	}
	
	return count;	
}

int podeCadastrarNovoCliente(){
	return contaClientesCadastrados() < 5;
}

