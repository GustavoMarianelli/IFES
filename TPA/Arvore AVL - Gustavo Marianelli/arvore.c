#include "arvore.h"

void iniciaArvore(No ** r){
	*r = NULL;
}

No * consultarNumero(No * r, long long int numero){
	
	No *aux;
	if(r==NULL) // se a �rvore estiver vazia retorna NULL
		return NULL;
	
	else if (r->numero == numero) // se o n�mero procurado estiver na raiz retorna a pr�pria �rvore
		return r;
	
	else{//se n�o estiver na raiz
		aux = consultarNumero (r->esq, numero); //busco para o lado esquerdo
		if (aux != NULL) // enquanto n�o encontrar um NULL, retorna o aux
			return aux;
		else
			aux = consultarNumero (r->dir, numero);// se encontrar o NULL, busca no lado direito
	}
}

int maiorAltura(int a, int b){ // compara qual n�mero � maior
	if (a>b) return a; //se for o a
	return b;//se for o b
}

int alturaNo(No * r){
	if(r == NULL) return -1; // se a �rvore estiver vazia retorna NULL
	
	return r->altura; // se n�o, retorna a altura
}

//rota��o esquerda
No * rotEsq(No * r){
	No *x, *y; // auxiliares da rota��o

    x = r->dir; //o aux x recebe o lado direito da raiz
    y = x->esq; // aux y recebe o lado esquerdo do aux x

    x->esq = r; // lado esquerdo do aux x recebe a rai#include "arvore.h"

void iniciaArvore(No ** r){
	*r = NULL;
}

No * consultarNumero(No * r, long long int numero){
	
	No *aux;
	if(r==NULL) // se a �rvore estiver vazia retorna NULL
		return NULL;
	
	else if (r->numero == numero) // se o n�mero procurado estiver na raiz retorna a pr�pria �rvore
		return r;
	
	else{//se n�o estiver na raiz
		aux = consultarNumero (r->esq, numero); //busco para o lado esquerdo
		if (aux != NULL) // enquanto n�o encontrar um NULL, retorna o aux
			return aux;
		else
			aux = consultarNumero (r->dir, numero);// se encontrar o NULL, busca no lado direito
	}
}

int maiorAltura(int a, int b){ // compara qual n�mero � maior
	if (a>b) return a; //se for o a
	return b;//se for o b
}

int alturaNo(No * r){
	if(r == NULL) return -1; // se a �rvore estiver vazia retorna NULL
	
	return r->altura; // se n�o, retorna a altura
}

//rota��o esquerda
No * rotEsq(No * r){
	No *x, *y; // auxiliares da rota��o

    x = r->dir; //o aux x recebe o lado direito da raiz
    y = x->esq; // aux y recebe o lado esquerdo do aux x

    x->esq = r; // lado esquerdo do aux x recebe a raiz
    r->dir = y; //lado direito da raiz recebe o aux y

    r->altura = maiorAltura(alturaNo(r->esq), alturaNo(r->dir)) + 1; // recalcula a altura da raiz
    x->altura = maiorAltura(alturaNo(x->esq), alturaNo(x->dir)) + 1; // recalcula a altura do aux x

    return x; // retorna o aux x
}

//rota��o direita
No * rotDir(No * r){
	No *x, *y; // auxliares da rota��o

    x = r->esq; // aux x recebe o lado esquerdo da raiz
    y = x->dir; // aux y recebe o lado direito do aux x

    x->dir = r; // lado direito do aux x recebe a raiz
    r->esq = y;//lado esquerdo da raiz recebe o aux y

    r->altura = maiorAltura(alturaNo(r->esq), alturaNo(r->dir)) + 1; //recalcula a altura da raiz
    x->altura = maiorAltura(alturaNo(x->esq), alturaNo(x->dir)) + 1; // recalcula a altura do aux x

    return x; //retorna o aux x
}

No * rotEsqDir (No * r){
	r->esq = rotEsq(r->esq); //lado esquerdo da raiz recebe o resultado da rota��o esquerda
    return rotDir(r); // retorna a rota��o pro lado direito a partir da raiz
}

No * rotDirEsq (No * r){
	r->dir = rotDir(r->dir);//lado direito da raiz recebe o resultado da rota��o direita
    return rotEsq(r);// retorna a rota��o pro lado esquerdo a partir da raiz
}


int calculoFB(No * r){ // c�lculo do fator de balanceamento
	if(r) // se a raiz n�o for nula
		return (alturaNo(r->esq) - alturaNo(r->dir)); // retorna o fator de balanceamento (altura esquerda - altura direita)
	
	else 
		return 0; // se for nula, retorna 0
}

No * balancearArvore(No * r){
	int fb = calculoFB(r); // calculo do fb
	
	if(fb < -1 && calculoFB(r->dir) <= 0) // se a rota��o for para esquerda
		r = rotEsq(r);
	else if(fb > 1 && calculoFB(r->esq) >= 0) // se a rota��o for para direita
		r = rotDir(r);
	else if(fb > 1 && calculoFB(r->esq) < 0) // se a rota��o for para esquerda-direita
		r = rotEsqDir(r);
	else if(fb < -1 && calculoFB(r->dir) > 0)// se a rota��o for para direita-esquerda
		r = rotDirEsq(r);
		
	return r;
}

void inserirNo(No ** r, No * novo){
	if(*r == NULL) // se a raiz est� vazia
		*r = novo;//o novo � a raiz
		
	else{// se a raiz n�o est� vazia
		if(novo->numero > (*r)->numero){ // se o nome do novo elemento for maior que o nome da raiz
			if((*r)->dir == NULL){// se a raiz n�o tem filho no lado direito
				(*r)->dir = novo; // o novo vira o filho do lado direito
			}
			else // se a raiz tiver filho do lado direito
				inserirNo(&(*r)->dir, novo); // chamo novamenta e fun��o inserindo  na subarvore do lado direito
		}
		
		else{//se o nome buscado for menor que o nome da raiz
			if((*r)->esq == NULL)// se a raiz n�o tver filho do lado esquerdo
				(*r)->esq = novo; //o novo passa a ser o filho do lado esquerdo
			else // se a raiz tiver filho do lado esquerdo
				inserirNo(&(*r)->esq, novo);  // chamo novamenta e fun��o inserindo  na subarvore do lado esquerdo
		}
	}
	
	(*r)->altura = maiorAltura(alturaNo((*r)->esq), alturaNo((*r)->dir)) + 1;
	(*r) = balancearArvore(*r);
}


int inserir(No**r, long long int numero){
	if(consultarNumero(*r, numero) == NULL){//se o nome informado n�o est� na �rvore
		No * novo = (No*)malloc(sizeof(No)); //cria um novo n� que recebe nome e n�mero, seus filhos apontam para NULL
		novo->numero = numero;
		novo->dir = NULL;
		novo->esq = NULL;
		novo->altura = 0;
		inserirNo(r, novo);//insere na �rvore
		return 1;
	}
	
	else return 0;//se o nome j� estiver na �rvore, retorna 0
}

void exibirPreOrdem(No * r){
	if(r!=NULL){ // se a raiz for diferente de NULL
		printf("Numero: %lld\n",r->numero); // printa o numero da raiz
		exibirPreOrdem(r->esq); //chamo novamente a fun��o fazendo a raiz ser o n�mero � esquerda
		exibirPreOrdem(r->dir); //chamo a fun��o passando o n�mero da direita como raiz
	}
}


void exibirEmOrdem(No * r){
	if(r!=NULL){//se a raiz for diferente de nulo
		exibirEmOrdem(r->esq); //chamo a fun��o recursivamnte at� encontrar o �ltimo elemento do lado esquerdo da �rvore e retorno esse elemento
		printf("N�mero: %lld\n", r->numero);//mostro nome e numero retornado
		exibirEmOrdem(r->dir); //chamo a fun��o recursivamnte at� encontrar o �ltimo elemento do lado direito da �rvore e retorno esse elemento
	}
}

void exibirPosOrdem(No * r){
	if(r!=NULL){ // se a raiz for diferente de NULL
		exibirPosOrdem(r->esq); //chamo novamente a fun��o fazendo a raiz ser o n�mero � esquerda
		exibirPosOrdem(r->dir); // quando o n�mero da raiz for nulo, chamo a fun��o passando o n�mero da direita como raiz
		printf("Numero: %lld\n",r->numero); // printa o numero da raiz
	}
}

No * acharRetirarMaior(No ** r){
	if(*r == NULL) return NULL;//�rvore vazia retorna NULL
	else{
		if((*r)->dir == NULL){//se n�o h� filho do lado direito
			No * maior;
			maior = *r; // a raiz � o maior elemento da arvore
			*r = (*r)->esq; // a raiz passa a apontar para o filho esquerdo
			return maior;//retorno o maior elemento
		}
		else // se h� filho direito
			return acharRetirarMaior(&(*r)->dir); // procuro e retiro o maior na subarvore direita
	}
}

No * remover(No ** r, long long int numero){
	No * exc = NULL;//serve de refer�ncia pro elemento que ser� excluido
	
	if(*r != NULL){// se houver algum nome na raiz
		if((*r)->numero == numero){// se o nome que se deseja remover estiver na raiz
			exc = *r;
			if((*r)->esq == NULL)// se n�o tem filho esquerdo
				*r = (*r)->dir;// o filho direito assume o lugar da raiz
			else if ((*r)->dir == NULL)//se n�o tem filho direito
				*r = (*r)->esq;// o filho esq assume o lugar da raiz
			else{ // se tiver 2 filhos
				exc = acharRetirarMaior(&(*r)->esq);//encontro e removo o maior dos menores; coloco o valor dele no exc
				(*r)->numero = exc->numero; //guardo uma refer�ncia pro valor de numero
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



