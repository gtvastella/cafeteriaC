#include <stdio.h>
#include "vendas.h"
#include <string.h>
#include <stdlib.h>
#include "cardapio.h"
#include "clientes.h"
#include "dados.h"
//ESSE ARQUIVO TEM COMO FUNÇÃO CRIAR OS PROCEDIMENTOS E FUNÇÕES DO QUE ENVOLVEM VENDAS, BEM COMO EMISSÃO DO CUPOM FISCAL.#####

void showVendasI(){
		system("cls");
	
	printf("------------------------------- Vendas -------------------------------\n");
	printf("----- Digite -1 para voltar e cancelar venda                     -----\n");
	printf("----- Para iniciar uma venda, digite os dados na seguinte ordem: -----\n");
	printf("----- CPF do cliente (0 para não identificado)                   -----\n");
	printf("----- Quantidade de produtos distintos a serem comprados         -----\n");
	printf("----------------------------------------------------------------------\n\n");

}

void trySell(int amount, char cpf[12]){
	
	system("cls");
	
	printf("---------------------------------------------- Vendas ----------------------------------------------\n");
	printf("----- Digite -1 para voltar e cancelar venda                                                   -----\n");
	printf("----- O CPF do cliente é: %s                         \n", cpf);
	if (clienteExiste(cpf) == 1){
			printf("----- Cliente identificado no sistema: %s \n", getClient(cpf).nome);
	}
	printf("----- Agora digite o código do produto e a quantidade no formato:                              -----\n");
	printf("----- ID                                                                                       -----\n");
	printf("----- Quantidade                                                                               -----\n");
	printf("----------------------------------------------------------------------------------------------------\n\n");
	int ok = 1;	
	float valorFinal = 0;
	item carrinho[100];
	int count = 0;
	for (int m=0;m<amount;m++){
		
			int c;
		
			if (!scanf("%i", &c) || c == 0){
			printf("######## ERRO: Código inválido. Retornando para menu inicial. ########\n\n");
			ok = 0;
			break;
			}
	
			fflush(stdin);
			int q;
			
			if (itemExiste(c) == 0){
			printf("######## ERRO: Produto inexistente. Retornando para menu inicial. ########\n\n");
			ok = 0;
			break;
			} 
			
			
			if (!scanf("%i", &q) || q == 0){
			printf("######## ERRO: Quantidade inválida. Retornando para menu inicial. ########\n\n");
			ok = 0;
			break;
			}
					
			
			if (itemExiste(c) == 0){
				printf("######## ERRO: Produto inexistente. Retornando para menu inicial. ########\n\n");
				ok = 0;
				break;
				fflush(stdin);
			} 
			
			if (getItem(c).qnt < q){
			printf("######## ERRO: Quantidade insuficiente em estoque (apenas %i). Retornando para menu inicial. ########\n\n", getItem(c).qnt);
			ok = 0;
			fflush(stdin);
			break;
			}
				item ac;
				ac.cod = getItem(c).cod;
				strcpy(ac.desc, getItem(c).desc);
			
				ac.qnt = q;
				ac.valor = getItem(c).valor;
			
				carrinho[count] = ac;
				count++;
				valorFinal = valorFinal+ (float)ac.valor*(float)ac.qnt;
				printf("######## SUCESSO: Produto adicionado ao carrinho... ########\n\n");
	
				}
			if (valorFinal > 0 && ok == 1){
			
				
					if (clienteExiste(cpf) == 1 && getClient(cpf).pontos% 5 == 0){
						int p = getClient(cpf).pontos;
					printf("----- FIDELIDADE: Cliente possui %i pontos e ganhará 30%% de desconto final \n\n", p);

					valorFinal = valorFinal*0.7;
					addPontos(cpf);
					
					}
					if (clienteExiste(cpf))
					cupomFiscal(carrinho, count,valorFinal, getClient(cpf).nome, cpf);
					else
					if (!clienteExiste(cpf))
					cupomFiscal(carrinho, count,valorFinal, "NÃO INFORMADO", cpf);
				// houve compra, portanto pode-se imprimir nota fiscal com os produtos do vetor carrinho
			}
				
			}
			
void cupomFiscal(item l[100], int qtd, float valorFinal, char nome[100], char cpf[12]){
		printf("              LIMEIRA COFFEE SA\n");
	printf("       RUA BLA BLA BLA, 123 - LIMEIRA - SP\n");
	printf(" CPF DO CONSUMIDOR: %s   NOME DO CONSUMIDOR: %s\n\n", cpf, nome);
	printf("              CUPOM FISCAL\n");
	printf(" CÓDIGO   ITEM                        QTD.  VALOR\n");
	for(int z =0; z< qtd; z++){
		printf("   %d      %-25s   %d   %.2f\n", l[z].cod, l[z].desc, l[z].qnt, l[z].valor);
		}
	printf("\n SUBTOTAL:                                  %.2f\n", valorFinal);
	printf(" TOTAL:                                     %.2f\n\n\n\n", valorFinal);
}	
		
	
	
	



