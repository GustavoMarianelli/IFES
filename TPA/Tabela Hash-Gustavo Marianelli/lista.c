#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


void inicLista(Lista *l){ // iniciando a lista
	l->inic = NULL; //inicio recebe NULL
	l->tam = 0;// tam definido como 0
}

void inserir(Lista *l, int num){
	Contato * novo = (Contato*)malloc(sizeof(Contato)); //vari�veis auxiliares
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
	Contato * novo = (Contato*)malloc(sizeof(Contato)); //vari�veis auxiliares
	Contato *atual = NULL, *anterior;
	Contato * fim;
	
	int inserido = 0, pausa = 0;
	
	novo->numero = num; //o novo recebe o n�mero informado e seu pr�ximo aponta para nulo
	novo->prox = NULL;
	
	if(l->inic == NULL) // se a lista estiver vazia
		l->inic = novo; //o in�cio da lista aponta para o novo
			
	else{ // se a lista n�o estiver vazia
		atual = l->inic; // atual recebe o in�cio da lista
		anterior = NULL; // o anterior recebe NULL
		
		while(atual != NULL && inserido == 0){ // enquanto o atual n�o for nulo e nenhum n�mero tive sido inserido na lista
		
			if(atual->numero >= novo->numero){ // compara o n�mero atual com o numero informado. Se for maior ou igual...
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
		//se o n�mero informado for maior que o n�mero atual, ele automaticamente vai pro fim da fila
		if(inserido == 0){
			fim = l->inic;
			while(fim->prox != NULL)
				fim = fim->prox;
			fim->prox = novo;
		}
	}
	l->tam++;
}

void exibeLista(Lista *l){ // essa fun��o exibe a lista
	Contato * atual;
	atual = l->inic;
	
	printf("[%d]: ",l->tam); // diz quantos elementos tem na fila no �ndice do vetor
	
	while(atual != NULL){
		printf("%d ", atual->numero);
		atual = atual->prox;
	}
	printf("\n");
}

int buscarNumero(Lista * l, int num){ //busca o n�mero informado na lista 
	Contato * atual = l->inic;
	int achou = 0;
	
	while(atual != NULL && achou == 0){
		if(atual->numero == num)
			achou=1;
		else
			atual = atual->prox;
	}
	
	return achou; // se o retorno for 0, n�o encontrou. Caso contr�rio, o retorno ser� 1;
}

int remover(Lista * l, int num){// essa fun��o remove o n�mero informado da lista
	Contato * atual, * remover = NULL;
	int exc = 0;
	
	atual = l->inic;
	
	if(atual != NULL && l->inic->numero == num){ // se o n�mero informado estiver no in�cio da lista
		remover = l->inic;
		l->inic = remover->prox;	
		exc=1;	
	}
	
	else{ // se n�o...
		while(atual!=NULL && atual->prox != NULL && atual->prox->numero != num) // enquanto o atual, proximo e o n�mero do proximo n�o forem NULL
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
	return exc; // se o valor foi removido, retorna 1. Caso contr�rio, retorna 0
}
