#include <stdio.h>
#include "estoque.h"
#include <string.h>
#include <stdlib.h>
#include "dados.h"
//ESSE ARQUIVO INCLUI TUDO QUE DIZ RESPEITO A VISUALIZAÇÃO E MANUSEIO DO ESTOQUE 



void showEstoque(){
	

	
	system("cls");
	printf("----------------------- Situação do estoque -----------------------\n");
	printf("----- Digite -1 para voltar                                   -----\n");
	printf("%s %-25s %37s\n\n", "Cód", "Nome", "Quantidade disp.");
	for (int i=0;i<ings;i++){
		printf("%.2d  %-25s %37i\n", estq[i].cod, estq[i].desc, estq[i].qnt);
	}
	printf("-------------------------------------------------------------------\n\n");
}
void manageE(){
		int input;
	scanf("%i", &input);
	if (input != 2 && input != 1){
			system("cls");
		return;
	} else if (input == 2){
		showInsertInstructionsE();
		fflush(stdin);
		
		int c;
		if (!scanf("%i", &c) || c == 0){
			printf("######## ERRO: Código inválido. Retornando para menu inicial. ########\n\n");
			return;
		}
		fflush(stdin);
		char d[100];
	     fgets(d, 100, stdin);
	  	d[strlen(d)-1]='\0';
			fflush(stdin);
		int q;
		if (!scanf("%i", &q)){
			printf("######## ERRO: Quantidade inválida. Retornando para menu inicial. ########\n\n");
			return;
		}
	fflush(stdin);
		cadastrarMaterial(c,d,q);
		return;
		
	} else if (input == 1){
		showEditInstructionsE();
		fflush(stdin);
		
		int c;
		if (!scanf("%i", &c) || c == 0){
			printf("######## ERRO: Código inválido. Retornando para menu inicial. ########\n\n");
			return;
		}
		
		char d[100];
	    scanf("%s", d);
		
		int q;
		if (!scanf("%i", &q)){
			printf("######## ERRO: Quantidade inválida. Retornando para menu inicial. ########\n\n ");
			return;
		}

		editarMaterial(c,d,q);
		return;
		
}
}
void showEstoqueManage(){
		system("cls");

	
	printf("---------------- Gerenciamento de Estoque -------------------\n");
	printf("----- -1. Voltar ao menu inicial                        -----\n");
	printf("----- 1. Editar ingrediente                             -----\n");
	printf("----- 2. Inserir ingrediente                            -----\n");		
	printf("-------------------------------------------------------------\n\n");
}
void showEditInstructionsE(){
	
	system("cls");
	
	printf("------------------------- Edição de ingrediente --------------------------\n");
	printf("----- Para editar um ingrediente, insira os dados na seguinte ordem: -----\n");
	printf("----- ID                                                             -----\n");
	printf("----- Nova quantidade disponível                                     -----\n");		
	printf("------------------------------------------------------------------------\n\n");
}
void showInsertInstructionsE(){
		system("cls");

	
	printf("--------------------------- Inserir ingrediente ---------------------------\n");
	printf("----- Para inserir um ingrediente, insira os dados na seguinte ordem: -----\n");
	printf("----- ID                                                              -----\n");
	printf("----- Descrição do ingrediente                                        -----\n");
	printf("----- Quantidade do ingrediente                                       -----\n");			
	printf("---------------------------------------------------------------------------\n\n");
}

int materialExiste(int c){
	if (ings==0)
		return 0;
	for (int x=0;x<ings;x++){
		material k = estq[x];
		if (k.cod == c)
		return 1;
	}

return 0;
}

void cadastrarMaterial(int c, char d[100], int q){
	int ok=1;
	if (materialExiste(c)==1){
		printf("######## ERRO: Já existe um ingrediente com esse codigo. Retornando para menu inicial. ########\n\n");
		ok=0;
	}
	
	if (ok == 1){
	material cc;
	cc.cod = c;
	strcpy(cc.desc, d);
	cc.qnt = q;
	ings++;
	estq = (material*) realloc(estq, ings*sizeof(material));
	if (!estq)
	printf("######## ERRO: Memoria insuficiente para alocar. Retornando para menu inicial. ########\n\n");	
	
	estq[ings-1] = cc;
	gravarEstoque();
	printf("######## SUCESSO: Ingrediente cadastrado com sucesso. Retornando para menu inicial. ########\n\n");	
	}
	
}

void editarMaterial(int cod, char d[100], int q){
	if (materialExiste(cod) == 0){
		printf("######## ERRO: Ingrediente inexistente. Retornando para o menu inicial. ########\n\n");
		
	} else{
		for (int i=0;i<ings;i++){
			if (estq[i].cod == cod){
		    	strcpy(estq[i].desc, d);
				estq[i].qnt = q;
				gravarEstoque();
				printf("######## SUCESSO: Ingrediente editado com sucesso. Retornando para menu inicial. ########\n\n");	
			}
		}		
	}
	
	
}

material getMaterial(int c){
	material n;
	if (ings==0)
		return n;
	for (int x=0;x<ings;x++){
		material k = estq[x];
		if (k.cod == c)
		return k;
	}

return n;

}
