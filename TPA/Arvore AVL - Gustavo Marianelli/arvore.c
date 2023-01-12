#include "arvore.h"

void iniciaArvore(No ** r){
	*r = NULL;
}

No * consultarNumero(No * r, long long int numero){
	
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
			aux = consultarNumero (r->dir, numero);// se encontrar o NULL, busca no lado direito
	}
}

int maiorAltura(int a, int b){ // compara qual número é maior
	if (a>b) return a; //se for o a
	return b;//se for o b
}

int alturaNo(No * r){
	if(r == NULL) return -1; // se a árvore estiver vazia retorna NULL
	
	return r->altura; // se não, retorna a altura
}

//rotação esquerda
No * rotEsq(No * r){
	No *x, *y; // auxiliares da rotação

    x = r->dir; //o aux x recebe o lado direito da raiz
    y = x->esq; // aux y recebe o lado esquerdo do aux x

    x->esq = r; // lado esquerdo do aux x recebe a rai#include "arvore.h"

void iniciaArvore(No ** r){
	*r = NULL;
}

No * consultarNumero(No * r, long long int numero){
	
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
			aux = consultarNumero (r->dir, numero);// se encontrar o NULL, busca no lado direito
	}
}

int maiorAltura(int a, int b){ // compara qual número é maior
	if (a>b) return a; //se for o a
	return b;//se for o b
}

int alturaNo(No * r){
	if(r == NULL) return -1; // se a árvore estiver vazia retorna NULL
	
	return r->altura; // se não, retorna a altura
}

//rotação esquerda
No * rotEsq(No * r){
	No *x, *y; // auxiliares da rotação

    x = r->dir; //o aux x recebe o lado direito da raiz
    y = x->esq; // aux y recebe o lado esquerdo do aux x

    x->esq = r; // lado esquerdo do aux x recebe a raiz
    r->dir = y; //lado direito da raiz recebe o aux y

    r->altura = maiorAltura(alturaNo(r->esq), alturaNo(r->dir)) + 1; // recalcula a altura da raiz
    x->altura = maiorAltura(alturaNo(x->esq), alturaNo(x->dir)) + 1; // recalcula a altura do aux x

    return x; // retorna o aux x
}

//rotação direita
No * rotDir(No * r){
	No *x, *y; // auxliares da rotação

    x = r->esq; // aux x recebe o lado esquerdo da raiz
    y = x->dir; // aux y recebe o lado direito do aux x

    x->dir = r; // lado direito do aux x recebe a raiz
    r->esq = y;//lado esquerdo da raiz recebe o aux y

    r->altura = maiorAltura(alturaNo(r->esq), alturaNo(r->dir)) + 1; //recalcula a altura da raiz
    x->altura = maiorAltura(alturaNo(x->esq), alturaNo(x->dir)) + 1; // recalcula a altura do aux x

    return x; //retorna o aux x
}

No * rotEsqDir (No * r){
	r->esq = rotEsq(r->esq); //lado esquerdo da raiz recebe o resultado da rotação esquerda
    return rotDir(r); // retorna a rotação pro lado direito a partir da raiz
}

No * rotDirEsq (No * r){
	r->dir = rotDir(r->dir);//lado direito da raiz recebe o resultado da rotação direita
    return rotEsq(r);// retorna a rotação pro lado esquerdo a partir da raiz
}


int calculoFB(No * r){ // cálculo do fator de balanceamento
	if(r) // se a raiz não for nula
		return (alturaNo(r->esq) - alturaNo(r->dir)); // retorna o fator de balanceamento (altura esquerda - altura direita)
	
	else 
		return 0; // se for nula, retorna 0
}

No * balancearArvore(No * r){
	int fb = calculoFB(r); // calculo do fb
	
	if(fb < -1 && calculoFB(r->dir) <= 0) // se a rotação for para esquerda
		r = rotEsq(r);
	else if(fb > 1 && calculoFB(r->esq) >= 0) // se a rotação for para direita
		r = rotDir(r);
	else if(fb > 1 && calculoFB(r->esq) < 0) // se a rotação for para esquerda-direita
		r = rotEsqDir(r);
	else if(fb < -1 && calculoFB(r->dir) > 0)// se a rotação for para direita-esquerda
		r = rotDirEsq(r);
		
	return r;
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
		
		else{//se o nome buscado for menor que o nome da raiz
			if((*r)->esq == NULL)// se a raiz não tver filho do lado esquerdo
				(*r)->esq = novo; //o novo passa a ser o filho do lado esquerdo
			else // se a raiz tiver filho do lado esquerdo
				inserirNo(&(*r)->esq, novo);  // chamo novamenta e função inserindo  na subarvore do lado esquerdo
		}
	}
	
	(*r)->altura = maiorAltura(alturaNo((*r)->esq), alturaNo((*r)->dir)) + 1;
	(*r) = balancearArvore(*r);
}


int inserir(No**r, long long int numero){
	if(consultarNumero(*r, numero) == NULL){//se o nome informado não está na árvore
		No * novo = (No*)malloc(sizeof(No)); //cria um novo nó que recebe nome e número, seus filhos apontam para NULL
		novo->numero = numero;
		novo->dir = NULL;
		novo->esq = NULL;
		novo->altura = 0;
		inserirNo(r, novo);//insere na árvore
		return 1;
	}
	
	else return 0;//se o nome já estiver na árvore, retorna 0
}

void exibirPreOrdem(No * r){
	if(r!=NULL){ // se a raiz for diferente de NULL
		printf("Numero: %lld\n",r->numero); // printa o numero da raiz
		exibirPreOrdem(r->esq); //chamo novamente a função fazendo a raiz ser o número à esquerda
		exibirPreOrdem(r->dir); //chamo a função passando o número da direita como raiz
	}
}


void exibirEmOrdem(No * r){
	if(r!=NULL){//se a raiz for diferente de nulo
		exibirEmOrdem(r->esq); //chamo a função recursivamnte até encontrar o último elemento do lado esquerdo da árvore e retorno esse elemento
		printf("Número: %lld\n", r->numero);//mostro nome e numero retornado
		exibirEmOrdem(r->dir); //chamo a função recursivamnte até encontrar o último elemento do lado direito da árvore e retorno esse elemento
	}
}

void exibirPosOrdem(No * r){
	if(r!=NULL){ // se a raiz for diferente de NULL
		exibirPosOrdem(r->esq); //chamo novamente a função fazendo a raiz ser o número à esquerda
		exibirPosOrdem(r->dir); // quando o número da raiz for nulo, chamo a função passando o número da direita como raiz
		printf("Numero: %lld\n",r->numero); // printa o numero da raiz
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

No * remover(No ** r, long long int numero){
	No * exc = NULL;//serve de referência pro elemento que será excluido
	
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
		
		}
		else if((numero < (*r)->numero)) //se o nome buscado for menor que o numero da raiz
			(*r)->esq = remover(&(*r)->esq, numero);
		else //se o nome buscado for maior que o numero da raiz
			(*r)->dir = remover(&(*r)->dir, numero);
	
		(*r)->altura = maiorAltura(alturaNo((*r)->esq), alturaNo((*r)->dir)) + 1;
		(*r) = balancearArvore(*r);
	}	
	return exc;
}



