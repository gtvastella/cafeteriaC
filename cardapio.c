#include <stdio.h>
#include "cardapio.h"
#include <string.h>
#include <stdlib.h>
#include "dados.h"
// ESSE ARQUIVO TEM COMO OBJETIVO FORMAR TODA A LISTA DE FUNÇÕES E PROCEDIMENTOS QUE DEVEM SER USADOS NA ELABORAÇÃO,
// EXIBIÇÃO E MANUSEIO DO CARDÁPIO. #####



void showCardapio(){
	

	system("cls");
	printf("----------------------- Confira nosso cardápio -----------------------\n");
	printf("----- Digite -1 para voltar                                      -----\n");
	printf("%s %-35s %30s\n\n", "Cód", "Nome", "Valor");
	for (int i=0;i<produtos;i++){
		char nm[40];
		strncpy(nm, lista[i].desc, 35);
		if (lista[i].cod != -1)
		printf("%.2d  %-35s %30.2f\n", lista[i].cod, lista[i].desc, lista[i].valor);
	}
	printf("----------------------------------------------------------------------\n\n");

}
void manage(){ 
	
		int input;
	scanf("%i", &input);
	if (input != 3 && input != 2 && input != 1){
		
		system("cls");
		return;
	} else if (input == 3){
		showInsertInstructions();
		fflush(stdin);
		
		int c;
		if (!scanf("%i", &c) || c == 0){
			printf("######## ERRO: Código inválido. Retornando para menu inicial. ######## \n\n");
			return;
		}
	
			fflush(stdin);
		char d[100];
	   	fgets(d, 100, stdin);
		fflush(stdin);
		int q;
		if (!scanf("%i", &q)){
			printf("######## ERRO: Quantidade inválida. Retornando para menu inicial. ######## \n\n");
			return;
		}
		
		float va;
		if (!scanf("%f", &va) || va == 0){
			printf("######## ERRO: Valor inválido. Retornando para menu inicial. ######## \n\n");
			return;
		}
		
	  		d[strlen(d)-1]='\0';
		cadastrarItem(c,d,q, va);
		return;
		
	} else if (input == 1){
		showEditInstructions();
		fflush(stdin);
		
		int c;
		if (!scanf("%i", &c) || c == 0){
			printf("######## ERRO: Código inválido. Retornando para menu inicial. ######## \n\n");
			return;
		}
			fflush(stdin);
		char d[100];
		
	    fgets(d, 100, stdin);
			d[strlen(d)-1]='\0';
		int q;
			fflush(stdin);
		if (!scanf("%i", &q)){
			printf("######## ERRO: Quantidade inválida. Retornando para menu inicial. ######## \n\n");
			return;
		}
		
		float va;
		if (!scanf("%f", &va) || va == 0){
			printf("######## ERRO: Valor inválido. Retornando para menu inicial. ######## \n\n");
			return;
		}
		
		editarItem(c,d,q, va);
		return;
	}  else if (input == 2){
		showDeleteInstructions();
		fflush(stdin);
		
		int c;
		if (!scanf("%i", &c) || c == 0){
			printf("######## ERRO: Código inválido. Retornando para menu inicial. ######## \n\n");
			return;
		}
	
		deletarItem(c);
		return;
		}
}
void showCardapioManage(){

	system("cls");
	printf("---------------- Gerenciamento de Cardápio -----------------\n");
	printf("----- -1. Voltar ao menu inicial                        -----\n");
	printf("----- 1. Editar produto                                -----\n");
	printf("----- 2. Apagar produto                                -----\n");
	printf("----- 3. Inserir produto                               -----\n");		
	printf("------------------------------------------------------------\n\n");
}
void showEditInstructions(){

	system("cls");
	printf("------------------------- Edição de produto --------------------------\n");
	printf("----- Para editar um produto, insira os dados na seguinte ordem: -----\n");
	printf("----- ID                                                         -----\n");
	printf("----- Nova descrição do produto                                  -----\n");
	printf("----- Nova quantidade disponível                                 -----\n");	
	printf("----- Novo valor (unitário)                                      -----\n");		
	printf("---------------------------------------------------------------------\n\n");
}
void showInsertInstructions(){
	
	system("cls");
	printf("--------------------------- Inserir produto ---------------------------\n");
	printf("----- Para inserir um produto, insira os dados na seguinte ordem: -----\n");
	printf("----- ID                                                          -----\n");
	printf("----- Descrição do produto                                        -----\n");
	printf("----- Quantidade do produto                                       -----\n");	
	printf("----- Valor do produto (unitário)                                 -----\n");		
	printf("---------------------------------------------------------------------\n\n");
}
void showDeleteInstructions(){
	

	system("cls");
	printf("--------------------------- Deletar produto ---------------------------\n");
	printf("----- Para deletar um produto, insira os dados na seguinte ordem: -----\n");
	printf("----- ID                                                          -----\n");		
	printf("-----------------------------------------------------------------------\n\n");
}
int itemExiste(int c){
	if (produtos==0)
		return 0;
	for (int x=0;x<produtos;x++){
		item k = lista[x];
		if (k.cod == c)
		return 1;
	}

return 0;
}

void cadastrarItem(int c, char d[100], int q, float v){
	system("cls");
	int ok=1;
	if (itemExiste(c)==1){
		
		printf("######## ERRO: Já existe um produto com esse codigo. Retornando para menu inicial. ######## \n");
		ok=0;
	}
	
	if (ok == 1){
	item cc;
	cc.cod = c;
	strcpy(cc.desc, d);
	cc.qnt = q;
	cc.valor = v;
	produtos++;
	lista = (item*) realloc(lista, produtos*sizeof(item));
	if (!lista)
	printf("######## ERRO: Memoria insuficiente para alocar. Retornando para menu inicial. ######## \n\n");	
	
	lista[produtos-1] = cc;
	gravarCardapio();	
	printf("########  SUCESSO: Produto cadastrado com sucesso. Retornando para menu inicial. ######## \n\n");	
	}
	
}

void editarItem(int cod, char d[100], int q, float v){
		system("cls");
	if (itemExiste(cod) == 0){
		printf("######## ERRO: Produto inexistente. Retornando para o menu inicial. ######## \n\n");
		
	} else{
		for (int i=0;i<produtos;i++){
			if (lista[i].cod == cod){
		    	strcpy(lista[i].desc, d);
				lista[i].qnt = q;
				lista[i].valor = v;
				gravarCardapio();	
				printf("######## SUCESSO: Produto editado com sucesso. Retornando para menu inicial. ########\n\n");	
			}
		}		
	}
	
	
}

void deletarItem(int cod){
		system("cls");
	if (itemExiste(cod) == 0){
		printf("######## ERRO: Produto inexistente. Retornando para o menu inicial. ######## \n\n");
		
	} else{
		int td = -1;
		for (int i=0;i<produtos;i++){
			if (lista[i].cod == cod){
				td=i;
		
			}
		}
		for (int i=td; i<produtos - 1;i++) {
            lista[i] = lista[i+1];
           } 
        produtos--;
     
      	lista = (item*) realloc(lista, produtos*sizeof(item));
	if (!lista)
	printf("######## ERRO: Memoria insuficiente para alocar. Retornando para menu inicial. ######## \n\n");	
	else
	printf("######## SUCESSO: Produto deletado com sucesso. Retornando para menu inicial. ######## \n\n");	
	gravarCardapio();	
	}
	
	
}

item getItem(int c){
	item n;
	if (produtos==0)
		return n;
	for (int x=0;x<produtos;x++){
		item k = lista[x];
		if (k.cod == c)
		return k;
	}

return n;

}
