#include <stdio.h>
#include "clientes.h"

#include <string.h>
#include <stdlib.h>
#include "dados.h"
// ESSE ARQUIVO TEM COMO OBJETIVO ELABORAR TODOS OS PROCEDIMENTOS E FUNÇÕES QUE ENVOLVEM CLIENTES.




void showClientes(){
	
	system("cls");
	
	printf("------------------------------ Clientes -------------------------------\n");
	printf("----- Digite -1 para voltar                                       -----\n");
	printf("%-40s %11s %11s %6s\n\n", "Nome", "Telefone", "CPF", "Pontos");
	for (int i=0;i<costumer;i++){

		printf("%-40s %.11s %.11s %5d\n", cli[i].nome, cli[i].tel, cli[i].cpf, cli[i].pontos);
		
	} 
	printf("-----------------------------------------------------------------------\n\n");

}
void menage(){
	
		int input;
	scanf("%d", &input);
	if (input != 1 && input != 2 && input != 3){
		system("cls");
		return;
	} else if (input == 2){
		showInsertClients();
		fflush(stdin);
		
		char nome[100];
	   fgets(nome, 100, stdin);
	  	nome[strlen(nome)-1]='\0';
		fflush(stdin);
	
		char cpf[12];
		if (!fgets(cpf, 12, stdin) || strlen(cpf) != 11){
			fflush(stdin);
			printf("######## ERRO: CPF inválido. Retornando para menu inicial. ########\n\n");
			return;
		}
		fflush(stdin);
		char tel[12];
			if (!fgets(tel, 12, stdin) || strlen(tel) != 11){
			fflush(stdin);
			printf("######## ERRO: Telefone inválido. Retornando para menu inicial. ########\n\n");
			return;
		}
		fflush(stdin);
		cpf[strlen(cpf)]='\0';
		tel[strlen(tel)]='\0';
		cadastrarClient(nome,cpf, tel);
		return;
		
	} else if (input == 1){
		showEditClients();
		fflush(stdin);
		
	char cpf[12];
		if (!fgets(cpf, 12, stdin) || strlen(cpf) != 11){
			printf("######## ERRO: CPF inválido. Retornando para menu inicial. ########\n\n");
			return;
		}
			fflush(stdin);
		char tel[12];
			if (!fgets(tel, 12, stdin) || strlen(tel) != 11){
			printf("######## ERRO: Telefone inválido. Retornando para menu inicial. ########\n\n");
			return;
		}
			fflush(stdin);
			cpf[strlen(cpf)]='\0';
		tel[strlen(tel)]='\0';
		editarClient(cpf, tel);
		return;
	}  else if (input == 3){
		showDeleteClients();
		fflush(stdin);
		
			char cpf[12];
		if (!fgets(cpf, 12, stdin) || strlen(cpf) != 11){
			printf("######## ERRO: CPF inválido. Retornando para menu inicial. ########\n\n");
			return;
		}
	
		deletarClient(cpf);
		return;
		}
}
void showClientesManage(){
	
	system("cls");
	
	printf("------------------------------------ Gerenciar Clientes ------------------------------------\n");
	printf("----- -1. Voltar ao menu                                                              ------\n");
	printf("----- 1. Editar cadastro de cliente                                                   ------\n");
	printf("----- 2. Adicionar cadastro de cliente                                                ------\n");
	printf("----- 3. Excluir cadastro de cliente                                                  ------\n");
	printf("--------------------------------------------------------------------------------------------\n");
}
void showEditClients(){
	

		system("cls");
	printf("------------------ Editar cadastro de cliente ------------------------\n");
	printf("----- Para editar um cliente, insira os dados na seguinte ordem: -----\n");
	printf("----- CPF                                                        -----\n");
	printf("----- Novo número de telefone                                    -----\n");	
	printf("----------------------------------------------------------------------\n");
	
}
void showDeleteClients(){
	
	system("cls");
	
	printf("------------------ Excluir cadastro de cliente ------------------------\n");
	printf("----- Para excluir um cliente, insira os dados na seguinte ordem: -----\n");
	printf("----- CPF                                                         -----\n");
	printf("-----------------------------------------------------------------------\n");
}
void showInsertClients(){
	
	system("cls");
	
	printf("--------------------- Editar cadastro de cliente ------------------------\n");
	printf("----- Para adicionar um cliente, insira os dados na seguinte ordem: -----\n");
	printf("----- Nome                                                          -----\n");
	printf("----- CPF                                                           -----\n");
	printf("----- Número de telefone                                            -----\n");	
	printf("-------------------------------------------------------------------------\n");
}

int clienteExiste(char cpf[12]){
	if (costumer==0)
		return 0;
	for (int x=0;x<costumer;x++){
		usuario k = cli[x];
		if (strcmp(k.cpf, cpf) == 0)
		return 1;
	}

return 0;
}

void cadastrarClient(char nome[100], char cpf[12], char tel[12]){
	int ok=1;
	if (clienteExiste(cpf)==1){
		printf("######## ERRO: Já existe um cliente com este CPF. Retornando para menu inicial. ######## \n\n");
		ok=0;
	}
	
	if (ok == 1){
	usuario cc;
	strcpy(cc.nome, nome);
	strcpy(cc.cpf,cpf);
	strcpy(cc.tel, tel);

	costumer++;
	cli = (usuario*) realloc(cli, costumer*sizeof(usuario));
	if (!cli)
	printf("######## ERRO: Memoria insuficiente para alocar. Retornando para menu inicial. ######## \n\n");	
	
	cli[costumer-1] = cc;
	
	printf("######## SUCESSO: Cliente cadastrado com sucesso. Retornando para menu inicial. ######## \n\n");	
	gravarClientes();
	}
	
}

void editarClient(char cpf[12], char tel[12]){
	if (clienteExiste(cpf) == 0){
		printf("######## ERRO: CPF inexistente. Retornando para o menu inicial. ######## \n\n");
		
	} else{
		for (int i=0;i<costumer;i++){
				if (strcmp(cli[i].cpf, cpf) == 0){
				strcpy(cli[i].tel, tel);
			
				printf("######## SUCESSO: Telefone atualizado com sucesso. Retornando para menu inicial. ######## \n\n");	
			gravarClientes();
			}
		}		
	}
	
	
}

void deletarClient(char cpf[12]){

	if (clienteExiste(cpf) == 0){
		printf("######## ERRO: CPF inexistente. Retornando para o menu inicial. ######## \n\n");
		
	} 
	else
	{
		int td = -1;
		for (int i=0;i<costumer;i++){
			if (strcmp(cli[i].cpf, cpf) == 0){
				td=i;
			
		    
			
			}
		}	
		if (td != -1){
			printf("\n%d\n", td);


		for (int i=td; i<costumer - 1;i++) {
            cli[i] = cli[i+1];
           } 
        costumer--;
     
      	cli = (usuario*) realloc(cli, costumer*sizeof(usuario));
	if (!cli)
	printf("######## ERRO: Memoria insuficiente para alocar. Retornando para menu inicial. ######## \n\n");	
	else
	printf("######## SUCESSO: Cliente deletado com sucesso. Retornando para menu inicial. ######## \n\n");	
	gravarClientes();
		}
	}
	
	
	
}

void addPontos(char cpf[12]){
			for (int i=0;i<costumer;i++){
				if (strcmp(cli[i].cpf, cpf) == 0){
				cli[i].pontos = cli[i].pontos+1;
				gravarClientes();
			}
		}	
}

usuario getClient(char cpf[12])
{

	usuario n;
	if (costumer==0)
		return n;
	for (int x=0;x<costumer;x++){
		usuario k = cli[x];
		if (strcmp(k.cpf, cpf) == 0)
		return k;
	}

return n;

}
