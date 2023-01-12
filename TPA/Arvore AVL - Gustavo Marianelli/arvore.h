#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	long long int numero;
	struct no *esq, *dir;
	int altura;
}No;


void iniciaArvore(No ** r);
int inserir(No**r, long long int numero);
No * consultarNumero(No * r, long long int numero);
void exibirPreOrdem(No * r);
void exibirEmOrdem(No * r);
void exibirPosOrdem(No * r);
No * remover(No ** r, long long int numero);
void imprimirArvoreBalanceada(No *raiz, int nivel);
