// Cria��o da biblioteca dados.h
#ifndef _DADOS_H
#define _DADOS_H


// ESSE ARQUIVO TEM COMO OBJETIVO CRIAR OS PROT�TIPOS DO QUE SER� USADO NO ARQUIVO DADOS.H BEM COMO AS ESTRUTURAS #####

void loadFiles();
void gravarClientes();
void gravarCardapio();
void gravarEstoque();

typedef struct item{
int cod;
char desc[100];
float valor;
int qnt;
} item;

typedef struct materiais{
int cod;
char desc[100];
int qnt;
} material;

typedef struct usuario{
char cpf[12];
char nome[100];
char tel[12];
int pontos;
} usuario;

int costumer;
int produtos;
int ings;
item *lista;
material *estq;
usuario *cli;

#endif	
