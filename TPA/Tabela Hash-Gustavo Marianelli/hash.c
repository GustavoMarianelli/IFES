#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

void inicTabela(Lista t[]){ // iniciando o vetor de listas
    int i;
    for(i = 0; i < TAM; i++)
        inicLista(&t[i]);
}

int hash(int chave){// fun??o que retorna o resto da divis?o da chave pelo tamanho e diz e qual ?ndice do vetor o valor ser? inserido
    return chave % TAM;
}

void inserirTabela(Lista t[], int valor){ // o valor informado pelo ? inserido no ?ndice definido pela fun??o hash
    int id = hash(valor);
    inserir(&t[id], valor);
}

int buscaTabela(Lista t[], int chave){// o valor informado ? buscado na tabela
    int id = hash(chave);
    return buscarNumero(&t[id], chave);
}

void imprimirTabela(Lista t[]){// essa fun??o imprime a tabela hash
    int i;
    for(i = 0; i < TAM; i++){
        printf("?ndice %2d = ", i);
        exibeLista(&t[i]);
        printf("\n");
    }
}

int removerTabela(Lista t[], int valor){// essa fun??o remove o valor informado da tabela hash
	int i, ret;
	for(i=0;i<TAM;i++){
		ret = remover(&t[i],valor);
		if(ret != 0)
			return 0;
	}
	return 1;
}
                                                                                                                                                                                                                                                                     #include <stdio.h>
#include <stdlib.h>
#include "hash.h"

void inicTabela(Lista t[]){ // iniciando o vetor de listas
    int i;
    for(i = 0; i < TAM; i++)
        inicLista(&t[i]);
}

int hash(int chave){// fun??o que retorna o resto da divis?o da chave pelo tamanho e diz e qual ?ndice do vetor o valor ser? inserido
    return chave % TAM;
}

void inserirTabela(Lista t[], int valor){ // o valor informado pelo ? inserido no ?ndice definido pela fun??o hash
    int id = hash(valor);
    inserir(&t[id], valor);
}

int buscaTabela(Lista t[], int chave){// o valor informado ? buscado na tabela
    int id = hash(chave);
    return buscarNumero(&t[id], chave);
}

void imprimirTabela(Lista t[]){// essa fun??o imprime a tabela hash
    int i;
    for(i = 0; i < TAM; i++){
        printf("?ndice %2d = ", i);
        exibeLista(&t[i]);
        printf("\n");
    }
}

int removerTabela(Lista t[], int valor){// essa fun??o remove o valor informado da tabela hash
	int i, ret;
	for(i=0;i<TAM;i++){
		ret = remover(&t[i],valor);
		if(ret != 0)
			return 0;
	}
	return 1;
}
