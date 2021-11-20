#include <stdio.h>
#include <stdlib.h>
#include "dados.h"

//ESSE ARQUIVO POSSUI TODOS OS PROCEDIMENTOS PARA O CARREGAMENTO, ATUALIZAÇÃO E MANUTENÇÃO DOS ARQUIVOS DO SISTEMA E OS DADOS SALVOS NELES.

void loadFiles(){
	
 FILE *clie; 
 FILE *card; 
 FILE *esto; 
  
 clie = fopen("clie.dat", "rb"); 
 card = fopen("card.dat", "rb"); 
 esto = fopen("esto.dat", "rb"); 
 
 if (clie != NULL) { 

fread(&costumer, sizeof(int), 1, clie);
cli = (usuario*) malloc(costumer*sizeof(usuario));
fread(cli, sizeof(usuario), costumer, clie);
fclose(clie);
 } else
costumer =0;

if (card != NULL) {
	
fread(&produtos, sizeof(int), 1, card);
lista = (item*) malloc( produtos*sizeof(item));
fread(lista, sizeof(item), produtos, card);
fclose(card);
 } else
produtos =0;

if (esto != NULL) { 

fread(&ings, sizeof(int), 1, esto);
estq= (material*) malloc(ings*sizeof(material));
fread(estq, sizeof(material), ings, esto);
fclose(esto);
 } else
ings =0;
}

void gravarClientes(){
 FILE *clie; 

 clie = fopen("clie.dat", "wb"); 
 
 if (clie == NULL)
 printf("\nErro na criacao do arquivo. Não foi possível gravar os registros.");
 else {

fwrite(&costumer, sizeof(int), 1, clie);
fwrite(cli, sizeof(usuario), costumer, clie);
fclose(clie);
 }


}

void gravarEstoque(){

 FILE *esto; 
 esto = fopen("esto.dat", "wb"); 
 
 if (esto == NULL)
 printf("\nErro na criacao do arquivo. Não foi possível gravar os registros.");
 else {

fwrite(&ings, sizeof(int), 1, esto);
fwrite(estq, sizeof(material), ings, esto);
fclose(esto);
 }
}

void gravarCardapio(){

 FILE *card; 
 card = fopen("card.dat", "wb"); 


 if (card == NULL)
 printf("\nErro na criacao do arquivo. Não foi possível gravar os registros.");
 else {

fwrite(&produtos, sizeof(int), 1, card);
fwrite(lista, sizeof(item), produtos, card);
fclose(card);
 }

 
 }





