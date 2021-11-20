// Criação da biblioteca cardapio.h
#ifndef _CARDAPIO_H
#define _CARDAPIO_H
#include "dados.h"
//ESSE ARQUIVO TEM COMO OBJETIVO CRIAR OS PROTÓTIPOS DO QUE SERÁ USADO NO ARQUIVO CARDAPIO.C 


void showCardapio();
void showCardapioManage();
void manage();
void showEditInstructions();
void showInsertInstructions();
void showDeleteInstructions();
int itemExiste(int);
void editarItem(int, char[100], int, float);
void cadastrarItem(int, char[100], int, float);
void deletarItem(int);
item getItem(int);

#endif	
