#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


typedef struct vetor{
	int num, flagExistiu;
}Vetor;


Vetor * lerArq(FILE * arq, int tam);

void preencherTabela(FILE * arq, Vetor hash[], int tam);

void inicVetor(Vetor hash[], int tam);

int gerarHash(int chave, int tam);

int inserirNoVetor(Vetor hash[], int num, int tam);

int buscarNumero(Vetor hash[], int num, int tam);

int removerNumero(Vetor hash[], int num, int tam);

void exibirTabelaHash(Vetor hash[], int tam);


                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            #include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


typedef struct vetor{
	int num, flagExistiu;
}Vetor;


Vetor * lerArq(FILE * arq, int tam);

void preencherTabela(FILE * arq, Vetor hash[], int tam);

void inicVetor(Vetor hash[], int tam);

int gerarHash(int chave, int tam);

int inserirNoVetor(Vetor hash[], int num, int tam);

int buscarNumero(Vetor hash[], int num, int tam);

int removerNumero(Vetor hash[], int num, int tam);

void exibirTabelaHash(Vetor hash[], int tam);


