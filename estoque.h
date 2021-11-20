// Criação da biblioteca cardapio.h
#ifndef _ESTOQUE_H
#define _ESTOQUE_H
#include "dados.h"
//ESSE ARQUIVO TEM COMO OBJETIVO CRIAR OS PROTÓTIPOS DO QUE SERÁ USADO NO ARQUIVO ESTOQUE.C.



void showEstoque();
void showEstoqueManage();
void manageE();
void showEditInstructionsE();
void showInsertInstructionsE();
int materialExiste(int);
void editarMaterial(int, char[100], int);
void cadastrarMaterial(int, char[100], int);
material getMaterial(int);

#endif	
