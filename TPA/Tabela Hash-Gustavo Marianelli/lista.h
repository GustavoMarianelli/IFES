#include <stdio.h>
#include <stdlib.h>
 //-- defini??o das estrturas de lista --
typedef struct contato{
	int numero;
	struct contato * prox;
}Contato;

typedef struct lista{
	Contato * inic;
	int tam;
}Lista;

//-- defini??o dos m?todos -- 
void inicLista(Lista *l);
void inserir(Lista *l, int num);
void exibeLista(Lista *l);
int buscarNumero(Lista * l, int num);
int remover(Lista * l, int num);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       #include <stdio.h>
#include <stdlib.h>
 //-- defini??o das estrturas de lista --
typedef struct contato{
	int numero;
	struct contato * prox;
}Contato;

typedef struct lista{
	Contato * inic;
	int tam;
}Lista;

//-- defini??o dos m?todos -- 
void inicLista(Lista *l);
void inserir(Lista *l, int num);
void exibeLista(Lista *l);
int buscarNumero(Lista * l, int num);
int remover(Lista * l, int num);
