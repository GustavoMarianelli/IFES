#include "arvore.h"

void iniciaArvore(No ** r){
	*r = NULL;
}

No * consultarNumero(No * r, long numero){
	
	No *aux;
	if(r==NULL) // se a árvore estiver vazia retorna NULL
		return NULL;
	
	else if (r->numero == numero) // se o número procurado estiver na raiz retorna a própria árvore
		return r;
	
	else{//se não estiver na raiz
		aux = consultarNumero (r->esq, numero); //busco para o lado esquerdo
		if (aux != NULL) // enquanto não encontrar um NULL, retorna o aux
			return aux;
		else
			return consultarNumero (r->dir, numero);// se encontrar o NULL, busca no lado direito
	}
}

void inserirNo(No ** r, No * novo){
	if(*r == NULL) // se a raiz está vazia
		*r = novo;//o novo é a raiz
		
	else{// se a raiz não está vazia
		if(novo->numero > (*r)->numero){ // se o nome do novo elemento for maior que o nome da raiz
			if((*r)->dir == NULL){// se a raiz não tem filho no lado direito
				(*r)->dir = novo; // o novo vira o filho do lado direito
			}
			else // se a raiz tiver filho do lado direito
				inserirNo(&(*r)->dir, novo); // chamo novamenta e função inserindo  na subarvore do lado direito
		}
		
		else if(novo->numero < (*r)->numero){//se o nome buscado for menor que o nome da raiz
			if((*r)->esq == NULL)// se a raiz não tver filho do lado esquerdo
				(*r)->esq = novo; //o novo passa a ser o filho do lado esquerdo
			else // se a raiz tiver filho do lado esquerdo
				inserirNo(&(*r)->esq, novo);  // chamo novamenta e função inserindo  na subarvore do lado esquerdo
		}
	}
}


int inserir(No**r, long numero){
	if(consultarNumero(*r, numero) == NULL){//se o nome informado não está na árvore
		No * novo = (No*)malloc(sizeof(No)); //cria um novo nó que recebe nome e número, seus filhos apontam para NULL
		novo->numero = numero;
		novo->dir = NULL;
		novo->esq = NULL;
		inserirNo(r, novo);//insere na árvore
		return 1;
	}
	
	else return 0;//se o nome já estiver na árvore, retorna 0
}

void exibirPreOrdem(No * r){
	if(r!=NULL){ // se a raiz for diferente de NULL
		printf("Numero: %ld\n",r->numero); // printa o numero da raiz
		exibirPreOrdem(r->esq); //chamo novamente a função fazendo a raiz ser o número à esquerda
		exibirPreOrdem(r->dir); //chamo a função passando o número da direita como raiz
	}
}


void exibirEmOrdem(No * r){
	if(r!=NULL){//se a raiz for diferente de nulo
		exibirEmOrdem(r->esq); //chamo a função recursivamnte até encontrar o último elemento do lado esquerdo da árvore e retorno esse elemento
		printf("Número: %ld\n", r->numero);//mostro nome e numero retornado
		exibirEmOrdem(r->dir); //chamo a função recursivamnte até encontrar o último elemento do lado direito da árvore e retorno esse elemento
	}
}

void exibirPosOrdem(No * r){
	if(r!=NULL){ // se a raiz for diferente de NULL
		exibirPosOrdem(r->esq); //chamo novamente a função fazendo a raiz ser o número à esquerda
		exibirPosOrdem(r->dir); // quando o número da raiz for nulo, chamo a fu#include "arvore.h"

void iniciaArvore(No ** r){
	*r = NULL;
}

No * consultarNumero(No * r, long numero){
	
	No *aux;
	if(r==NULL) // se a árvore estiver vazia retorna NULL
		return NULL;
	
	else if (r->numero == numero) // se o número procurado estiver na raiz retorna a própria árvore
		return r;
	
	else{//se não estiver na raiz
		aux = consultarNumero (r->esq, numero); //busco para o lado esquerdo
		if (aux != NULL) // enquanto não encontrar um NULL, retorna o aux
			return aux;
		else
			return consultarNumero (r->dir, numero);// se encontrar o NULL, busca no lado direito
	}
}

void inserirNo(No ** r, No * novo){
	if(*r == NULL) // se a raiz está vazia
		*r = novo;//o novo é a raiz
		
	else{// se a raiz não está vazia
		if(novo->numero > (*r)->numero){ // se o nome do novo elemento for maior que o nome da raiz
			if((*r)->dir == NULL){// se a raiz não tem filho no lado direito
				(*r)->dir = novo; // o novo vira o filho do lado direito
			}
			else // se a raiz tiver filho do lado direito
				inserirNo(&(*r)->dir, novo); // chamo novamenta e função inserindo  na subarvore do lado direito
		}
		
		else if(novo->numero < (*r)->numero){//se o nome buscado for menor que o nome da raiz
			if((*r)->esq == NULL)// se a raiz não tver filho do lado esquerdo
				(*r)->esq = novo; //o novo passa a ser o filho do lado esquerdo
			else // se a raiz tiver filho do lado esquerdo
				inserirNo(&(*r)->esq, novo);  // chamo novamenta e função inserindo  na subarvore do lado esquerdo
		}
	}
}


int inserir(No**r, long numero){
	if(consultarNumero(*r, numero) == NULL){//se o nome informado não está na árvore
		No * novo = (No*)malloc(sizeof(No)); //cria um novo nó que recebe nome e número, seus filhos apontam para NULL
		novo->numero = numero;
		novo->dir = NULL;
		novo->esq = NULL;
		inserirNo(r, novo);//insere na árvore
		return 1;
	}
	
	else return 0;//se o nome já estiver na árvore, retorna 0
}

void exibirPreOrdem(No * r){
	if(r!=NULL){ // se a raiz for diferente de NULL
		printf("Numero: %ld\n",r->numero); // printa o numero da raiz
		exibirPreOrdem(r->esq); //chamo novamente a função fazendo a raiz ser o número à esquerda
		exibirPreOrdem(r->dir); //chamo a função passando o número da direita como raiz
	}
}


void exibirEmOrdem(No * r){
	if(r!=NULL){//se a raiz for diferente de nulo
		exibirEmOrdem(r->esq); //chamo a função recursivamnte até encontrar o último elemento do lado esquerdo da árvore e retorno esse elemento
		printf("Número: %ld\n", r->numero);//mostro nome e numero retornado
		exibirEmOrdem(r->dir); //chamo a função recursivamnte até encontrar o último elemento do lado direito da árvore e retorno esse elemento
	}
}

void exibirPosOrdem(No * r){
	if(r!=NULL){ // se a raiz for diferente de NULL
		exibirPosOrdem(r->esq); //chamo novamente a função fazendo a raiz ser o número à esquerda
		exibirPosOrdem(r->dir); // quando o número da raiz for nulo, chamo a função passando o número da direita como raiz
		printf("Numero: %ld\n",r->numero); // printa o numero da raiz
	}
}

No * acharRetirarMaior(No ** r){
	if(*r == NULL) return NULL;//árvore vazia retorna NULL
	else{
		if((*r)->dir == NULL){//se não há filho do lado direito
			No * maior;
			maior = *r; // a raiz é o maior elemento da arvore
			*r = (*r)->esq; // a raiz passa a apontar para o filho esquerdo
			return maior;//retorno o maior elemento
		}
		else // se há filho direito
			return acharRetirarMaior(&(*r)->dir); // procuro e retiro o maior na subarvore direita
	}
}

int remover(No ** r, long numero){
	No * exc;//serve de referência pro elemento que será excluido
	
	if(*r != NULL){// se houver algum nome na raiz
		if((*r)->numero == numero){// se o nome que se deseja remover estiver na raiz
			exc = *r;
			if((*r)->esq == NULL)// se não tem filho esquerdo
				*r = (*r)->dir;// o filho direito assume o lugar da raiz
			else if ((*r)->dir == NULL)//se não tem filho direito
				*r = (*r)->esq;// o filho esq assume o lugar da raiz
			else{ // se tiver 2 filhos
				exc = acharRetirarMaior(&(*r)->esq);//encontro e removo o maior dos menores; coloco o valor dele no exc
				(*r)->numero = exc->numero; //guardo uma referência pro valor de numero
			}
			free(exc);//libera o exc
			return 1; //retorna 1 se a remoção teve êxito
		}
		else if((numero < (*r)->numero)) //se o nome buscado for menor que o numero da raiz
			return remover(&(*r)->esq, numero);
		else //se o nome buscado for maior que o numero da raiz
			return remover(&(*r)->dir, numero);
	}	
	else return 0; //se o nome que se deseja excluir não estiver na árvore, retorna 0
}


