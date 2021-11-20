// Criação da biblioteca clientes.h
#ifndef _CLIENTES_H
#define _CLIENTES_H
#include "dados.h"
//ESSE ARQUIVO TEM COMO OBJETIVO CRIAR OS PROTÓTIPOS DO QUE SERÁ USADO NO ARQUIVO CLIENTES.C 


void showClientes();
void showClientesManage();
void menage();
void showEditClients();
void showInsertClients();
void showDeleteClients();
int clienteExiste(char[12]);
void editarClient(char[12], char[12]);
void cadastrarClient(char[100], char[12], char[12]);
void addPontos(char[12]);
void deletarClient(char[12]);
usuario getClient(char[12]);

#endif	
