#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lista.h"

#define TAM 11 // tamanho do vetor


//-- defini��o dos m�todos -- 
void inicTabela(Lista t[]);
int hash(int chave);
void inserirTabela(Lista t[], int valor);
int buscaTabela(Lista t[], int chave);
void imprimirTabela(Lista t[]);
int removerTabela(Lista t[], int valor);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              #include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lista.h"

#define TAM 11 // tamanho do vetor


//-- defini��o dos m�todos -- 
void inicTabela(Lista t[]);
int hash(int chave);
void inserirTabela(Lista t[], int valor);
int buscaTabela(Lista t[], int chave);
void imprimirTabela(Lista t[]);
int removerTabela(Lista t[], int valor);
