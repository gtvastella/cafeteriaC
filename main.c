#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "cardapio.h"
#include "vendas.h"
#include "estoque.h"
#include "clientes.h"
#include "dados.h"

// ARQUIVO PRINCIPAL DO PROGRAMA. AQUI É ELABORADO O MAIN, EXIBIÇÃO DO MENU PRINCIPAL E INSERÇÃO DE ALGUNS DADOS
// BÁSICOS PRÉ DEFINIDOS. 




void printMenu(int i){

	
printf("888      d8b                        d8b                       .d8888b.            .d888  .d888                  \n");
printf("888      Y8P                        Y8P                      d88P  Y88b          d88P'  d88P'                   \n");
printf("888                                                          888    888          888    888                     \n");
printf("888      888 88888b.d88b.   .d88b.  888 888d888 8888b.       888         .d88b.  888888 888888 .d88b.   .d88b.  \n");
printf("888      888 888 '888 '88b d8P  Y8b 888 888P'      '88b      888        d88''88b 888    888   d8P  Y8b d8P  Y8b \n");
printf("888      888 888  888  888 88888888 888 888    .d888888      888    888 888  888 888    888   88888888 88888888 \n");
printf("888      888 888  888  888 Y8b.     888 888    888  888      Y88b  d88P Y88..88P 888    888   Y8b.     Y8b.     \n");
printf("88888888 888 888  888  888  'Y8888  888 888    'Y888888       'Y8888P'   'Y88P'  888    888    'Y8888   'Y8888  \n\n\n\n");
	
	printf("---------------------- Menu de opções ----------------------\n");
	printf("----- 1. Exibir cardápio (CLIENTE)                     -----\n");
	printf("----- 2. Gerenciar cardápio                            -----\n");
	printf("----- 3. Iniciar venda                                 -----\n");
	printf("----- 4. Estoque                                       -----\n");		
	printf("----- 5. Gerenciar estoque                             -----\n");	
	printf("----- 6. Clientes                                      -----\n");	
	printf("----- 7. Gerenciar clientes                            -----\n");	
	printf("----- -1. Fechar                                       -----\n");	
	printf("------------------------------------------------------------\n\n");

}


int main(int argc, char *argv[]) {
setlocale(LC_ALL, "Portuguese");
printMenu(1);

int op;

loadFiles();
	
do{	
	if (op == -1){
		return 0;
	} else if (op == 1){
	int input;
	showCardapio();
	fflush(stdin);

	if (scanf("%i", &input)){
		system("cls");
		printMenu(0);
		fflush(stdin);
		continue;
	}
	
	} else if (op == 2){
		
	showCardapioManage();
	fflush(stdin);
	manage();
	printMenu(0);
	fflush(stdin);
	continue;
	
	} else if (op == 3){
		showVendasI();
		fflush(stdin);
	
		char cpf[12];
			if (!fgets(cpf, 12, stdin) || strlen(cpf) != 11){
			system("cls");
			if (strcmp(cpf, "-1\n") != 0)
				printf("######## ERRO: CPF Inválido. Retornando para menu inicial. ########\n\n");
			printMenu(0);
			fflush(stdin);
			continue;
		}
		
		int pdt;
		if (!scanf("%i", &pdt) || pdt == 0){
			system("cls");
			if (pdt != -1)
				printf("######## ERRO: Quantidade Inválido. Retornando para menu inicial. ########\n\n");
			printMenu(0);
			fflush(stdin);
			continue;
		}
			cpf[strlen(cpf)]='\0';
		trySell(pdt, cpf);
		printMenu(0);
		fflush(stdin);
		continue;
	} else if (op == 4){ 
	int input;
	showEstoque();
	fflush(stdin);

	if (scanf("%i", &input)){
		system("cls");
		printMenu(0);
		fflush(stdin);
		continue;
	}
	
	} else if (op == 5){
		showEstoqueManage();
	fflush(stdin);
	manageE();
	printMenu(0);
	fflush(stdin);
	continue;
	
	} else if (op == 6){
		int input;
		showClientes();
		fflush(stdin);
		if (scanf("%i", &input)){
		system("cls");
		printMenu(0);
		fflush(stdin);
		continue;
		}
		
	} else if (op == 7){
		showClientesManage();
		fflush(stdin);
	    menage();
	    printMenu(0);
	    fflush(stdin);
		continue;
		
	} 
	
} while (scanf("%d", &op));

	
  return 0;
}
