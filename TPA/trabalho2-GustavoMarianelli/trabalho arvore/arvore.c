#include "arvore.h"

void iniciaArvore(No ** r){
	*r = NULL;
}

void abrirArq(No ** r){
	FILE * arq = fopen("Lista_Aluno_Matricula_Atual.txt", "r"); // arquivo de alunos
	
	char nome[100]; // auxiliar que recebe o nome
	long long int mat; // auxiliar que recebe a matrícula
	
	if(arq == NULL)
		printf("Arquivo não foi aberto!\n");
	
	else{
		while (!feof(arq)){
			fscanf(arq,"%100[^\n]",&nome);
			fscanf(arq,"%lld\n", &mat);
			inserir(r, nome, mat); // nome e matrícula do arquivo são inseridos na árvore
		}
	}
	fclose(arq); // arquivo é fechado
}


No * consultarNumero(No * r, long long int matricula){
	
	No *aux; // auxiliar
	if(r==NULL) // se a árvore estiver vazia retorna NULL
		return NULL;
	
	else if (r->matricula == matricula) // se o número procurado estiver na raiz retorna a raiz
		return r;
	
	else{//se não estiver na raiz
		aux = consultarNumero (r->esq, matricula); //busco para o lado esquerdo
		if (aux != NULL) // enquanto não encontrar um NULL, retorna o aux
			return aux;
		else
			return consultarNumero (r->dir, matricula);// se encontrar o NULL, busca no lado direito
	}
}

void inserirNo(No ** r, No * novo){
	if(*r == NULL) // se a raiz está vazia
		*r = novo;//o novo é a raiz
		
	else{// se a raiz não está vazia
		if(novo->matricula > (*r)->matricula){ // se a matrícula do novo elemento for maior que a matrícula da raiz
			
			if((*r)->dir == NULL)// se a raiz não tem filho no lado direito
				(*r)->dir = novo; // o novo vira o filho do lado direito
			
			else // se a raiz tiver filho do lado direito
				inserirNo(&(*r)->dir, novo); // chamo novamenta e função inserindo  na subarvore do lado direito
		}
		
		else {//se a matrícula buscada for menor a matrícula da raiz
			if((*r)->esq == NULL)// se a raiz não tver filho do lado esquerdo
				(*r)->esq = novo; //o novo passa a ser o filho do lado esquerdo
			else // se a raiz tiver filho do lado esquerdo
				inserirNo(&(*r)->esq, novo);  // chamo novamenta e função inserindo  na subarvore do lado esquerdo
		}
	}
}


int inserir(No**r, char * nome, long long int matricula){
	if(consultarNumero(*r,matricula) == NULL){//se a matricula informada não está na árvore
		No * novo = (No*)malloc(sizeof(No)); //cria um novo nó que recebe nome e matrícula, seus filhos apontam para NULL
		strcpy(novo->nome, nome); 
		novo->matricula = matricula;
		novo->dir = NULL;
		novo->esq = NULL;
		inserirNo(r, novo);//insere na árvore
	
		return 1;
	}
	
	else return 0;//se a matrícula já estiver na árvore, retorna 0
}

void exibirPreOrdem(No * r){
	if(r!=NULL){ // se a raiz for diferente de NULL
		printf("Nome: %s - Matrícula: %lld\n\n",r->nome, r->matricula); // printa a raiz
		exibirPreOrdem(r->esq); //chamo a função recursivamnte até encontrar o último elemento do lado esquerdo da árvore e retorno esse elemento
		exibirPreOrdem(r->dir); // quando o número da raiz for nulo, chamo a função passando o número da direita como raiz
	}
}

void exibirEmOrdem(No * r){
	if(r!=NULL){//se a raiz for diferente de nulo
		exibirEmOrdem(r->esq); //chamo a função recursivamnte até encontrar o último elemento do lado esquerdo da árvore e retorno esse elemento
		printf("Nome: %s - Matrícula: %lld\n\n",r->nome, r->matricula);//mostro a raiz
		exibirEmOrdem(r->dir); //chamo a função recursivamnte até encontrar o último elemento do lado direito da árvore e retorno esse elemento
	}
}

void exibirPosOrdem(No * r){
	if(r!=NULL){ // se a raiz for diferente de NULL
		exibirPosOrdem(r->esq); //chamo novamente a função fazendo a raiz ser o número à esquerda
		exibirPosOrdem(r->dir); // quando o número da raiz for nulo, chamo a função passando o número da direita como raiz
		printf("Nome: %s - Matrícula: %lld\n\n",r->nome, r->matricula); // printa a raiz
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
			//os números maiores vão para o lado direito, portanto o maior número certamente estará no lado direito da raiz
	}
}

int remover(No ** r, long long int matricula){
	No * exc;//serve de referência pro elemento que será excluido
	
	if(*r != NULL){// se houver alguém na raiz
		if((*r)->matricula == matricula){// se a matrícula que se deseja remover estiver na raiz
			exc = *r; // exc recebe a raiz
			if((*r)->esq == NULL)// se não tem filho esquerdo
				*r = (*r)->dir;// o filho direito assume o lugar da raiz
			else if ((*r)->dir == NULL)//se não tem filho direito
				*r = (*r)->esq;// o filho esq assume o lugar da raiz
			else{ // se tiver 2 filhos
				exc = acharRetirarMaior(&(*r)->esq);//encontro e removo o maior dos menores; coloco o valor dele no exc
				(*r)->matricula = exc->matricula; //guardo uma referência pro valor de numero
			}
			free(exc);//libera o exc
			return 1; //retorna 1 se a remoção teve êxito
		}
		else if((matricula < (*r)->matricula)) //se a matrícula buscada for menor que a matrícula da raiz
			return remover(&(*r)->esq, matricula);// chamo novamente a função fazendo a raiz ser o filho esquerdo
		else //se a matrícula buscada for maior que a matrícula da raiz
			return remover(&(*r)->dir, matricula);//chamo novamente a função fazendo a raiz ser o filho direito
	}	
	else return 0; //se o nome que se deseja excluir não estiver na árvore, retorna 0
}

void percorrerEmOrdem(No * r, FILE * arq){
	char mat[20];
	
	if(r!=NULL){ // se a raiz for diferente de NULL
		percorrerEmOrdem(r->esq, arq); //chamo novamente a função fazendo a raiz ser o número à esquerda
		fputs(r->nome, arq); // coloco o nome retornado no arquivo 
		fputc('\n', arq);// adiciono o \n
		lltoa(r->matricula, mat, 10); // converto a matrícula de long long int para string
		fputs(mat, arq); // coloco a matrícula convertida no arquivo 
		fputc('\n', arq);// adiciono o \n	
		percorrerEmOrdem(r->dir, arq); // quando a raiz for NULL, chamo a função passando o número da direita como raiz		
	}
}

void salvarDados(No * r){
	FILE * arq = fopen("Lista_Aluno_Matricula_Atual.txt", "w"); // abro o arquivo em modo escrita
	
	if(arq == NULL) 
		printf("Erro ao abrir arquivo!\n");
		
	else
		percorrerEmOrdem(r, arq); // chamo a função que salvará os dados
	
	fclose(arq); // fecho o arquivo
}
