// Criação da biblioteca vendas.h
#ifndef _VENDAS_H
#define _VENDAS_H
#include "cardapio.h"

// ESSE ARQUIVO TEM COMO OBJETIVO CRIAR OS PROTÓTIPOS DO QUE SERÁ USADO NO ARQUIVO VENDAS.C #####

void showVendasI();
void trySell(int, char[12]);
void cupomFiscal(item[100], int, float, char[100], char[12]);
#endif	
