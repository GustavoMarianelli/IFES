#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


void inicLista(Lista *l){ // iniciando a lista
	l->inic = NULL; //inicio recebe NULL
	l->tam = 0;// tam definido como 0
}

void inserir(Lista *l, int num){
	Contato * novo = (Contato*)malloc(sizeof(Contato)); //variáveis auxiliares
	Contato *atual = NULL, *anterior;
	Contato * fim;
	
	int #include <stdio.h>
#include <stdlib.h>
#include "lista.h"


void inicLista(Lista *l){ // iniciando a lista
	l->inic = NULL; //inicio recebe NULL
	l->tam = 0;// tam definido como 0
}

void inserir(Lista *l, int num){
	Contato * novo = (Contato*)malloc(sizeof(Contato)); //variáveis auxiliares
	Contato *atual = NULL, *anterior;
	Contato * fim;
	
	int inserido = 0, pausa = 0;
	
	novo->numero = num; //o novo recebe o número informado e seu próximo aponta para nulo
	novo->prox = NULL;
	
	if(l->inic == NULL) // se a lista estiver vazia
		l->inic = novo; //o início da lista aponta para o novo
			
	else{ // se a lista não estiver vazia
		atual = l->inic; // atual recebe o início da lista
		anterior = NULL; // o anterior recebe NULL
		
		while(atual != NULL && inserido == 0){ // enquanto o atual não for nulo e nenhum número tive sido inserido na lista
		
			if(atual->numero >= novo->numero){ // compara o número atual com o numero informado. Se for maior ou igual...
				novo->prox = atual;  
				
				if(anterior == NULL) 
					l->inic = novo;
				else 
					anterior->prox = novo;
				inserido = 1;
			}
			
			anterior = atual;
			atual = atual->prox;
		}
		//se o número informado for maior que o número atual, ele automaticamente vai pro fim da fila
		if(inserido == 0){
			fim = l->inic;
			while(fim->prox != NULL)
				fim = fim->prox;
			fim->prox = novo;
		}
	}
	l->tam++;
}

void exibeLista(Lista *l){ // essa função exibe a lista
	Contato * atual;
	atual = l->inic;
	
	printf("[%d]: ",l->tam); // diz quantos elementos tem na fila no índice do vetor
	
	while(atual != NULL){
		printf("%d ", atual->numero);
		atual = atual->prox;
	}
	printf("\n");
}

int buscarNumero(Lista * l, int num){ //busca o número informado na lista 
	Contato * atual = l->inic;
	int achou = 0;
	
	while(atual != NULL && achou == 0){
		if(atual->numero == num)
			achou=1;
		else
			atual = atual->prox;
	}
	
	return achou; // se o retorno for 0, não encontrou. Caso contrário, o retorno será 1;
}

int remover(Lista * l, int num){// essa função remove o número informado da lista
	Contato * atual, * remover = NULL;
	int exc = 0;
	
	atual = l->inic;
	
	if(atual != NULL && l->inic->numero == num){ // se o número informado estiver no início da lista
		remover = l->inic;
		l->inic = remover->prox;	
		exc=1;	
	}
	
	else{ // se não...
		while(atual!=NULL && atual->prox != NULL && atual->prox->numero != num) // enquanto o atual, proximo e o número do proximo não forem NULL
			atual = atual->prox;
		
		if(atual != NULL && atual -> prox != NULL){
			remover = atual->prox;
			atual->prox = remover -> prox;
			exc=1;	
		}
	}
	
	if(remover != NULL){ // se o valor informado fo removido da lista
		l->tam--;
		free(remover);
 }
	return exc; // se o valor foi removido, retorna 1. Caso contrário, retorna 0
}
