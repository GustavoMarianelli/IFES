#include "lista.h"
// -- FUN��ES-- 
void inicLista(Lista *l){ // iniciando a lista
	l->inic = NULL; //inicio recebe NULL
	l->tam = 0;// tam definido como 0
}

void inserir(Lista *l, char * nome, long long int mat){
	Contato * novo = (Contato*)malloc(sizeof(Contato)); //vari�veis auxiliares
	Contato *atual = NULL, *anterior;
	Contato * fim;
	
	int inserido = 0, pausa = 0;
	
	//o novo recebe o nome e matr�cula informados e seu pr�ximo aponta para nulo
	strcpy(novo->nome, nome);
	novo->matricula = mat; 
	novo->prox = NULL;
	
	if(l->inic == NULL) // se a lista estiver vazia
		l->inic = novo; //o in�cio da lista aponta para o novo
			
	else{ // se a lista n�o estiver vazia
		atual = l->inic; // atual recebe o in�cio da lista
		anterior = NULL; // o anterior recebe NULL
		
		while(atual != NULL && inserido == 0){ // enquanto o atual n�o for nulo e nenhum n�mero tive sido inserido na lista
		
			if(strcmp(atual->nome,novo->nome)>=0){ // compara o nome atual com o nome informado. Se for maior ou igual...
				novo->prox = atual;  //o pr�ximo do novo aponta para o atual 
				
				if(anterior == NULL) // se o anterior for NULL, o in�cio da lista passa a ser o novo elemento  
					l->inic = novo;
				else // se o anterior n�o for NULL, o pr�ximo do anterior aponta para o novo elemento 
					anterior->prox = novo;
				inserido = 1; // indica que algum elemento foi inserido e encerra o la�o
			}
			
			anterior = atual; // o anterior recebe o atual
			atual = atual->prox; // o atual recebe seu pr�ximo 
		}
		//se o n�mero informado for maior que o n�mero atual, ele automaticamente vai pro fim da fila
		if(inserido == 0){
			fim = l->inic;
			while(fim->prox != NULL)
				fim = fim->prox;
			fim->prox = novo;
		}
	}
	l->tam++; // incrementa o tamanho da lista
}

void exibeLista(Lista *l){ // essa fun��o exibe a lista
	Contato * atual = l->inic; // auxiliar que recebe o in�cio da lista 
	
	printf("[%d]:\n\n",l->tam); // diz quantos elementos tem na fila no determinado �ndice 
	while(atual != NULL){ // enquanto n�o encontrar o NULL 
		printf("Nome: %sMatr�cula: %lld\n\n",atual->nome, atual->matricula); //mostra os dados do atual
		atual = atual->prox; // vai para o pr�ximo da lista 
	}
	printf("\n");
}

Contato * buscarNumero(Lista * l, long long int mat){ //busca o n�mero informado na lista 
	Contato * atual = l->inic; // auxiliar que recebe o in�cio da lista 
	Contato * aux = NULL; // auxiliar que recebe NULL
	
	while(atual != NULL){// enquanto n�o encontrar o NULL 
		if(atual->matricula == mat){ // se a matr�cula atual for igual � matr�cula buscada 
			aux = atual; // aux recebe o alemento atual e � retornado 
			return aux;
		}		
		else
			atual = atual->prox; // se n�o, vai pro pr�ximo 
	}
	
	return aux; // se o retorno for NULL, n�o encontrou.
}

Contato * remover(Lista * l, long long int mat){// essa fun��o remove o n�mero informado da lista
	Contato * atual = l->inic, * remover = NULL; // auxiliares
	
	
	if(atual != NULL && l->inic->matricula == mat){ // se o n�mero informado estiver no in�cio da lista
		remover = l->inic; // o rmeover recebe o in�cio 
		l->inic = remover->prox; // o in�cio recebe o pr�ximo	
	}
	
	else{ // se n�o...
		while(atual!=NULL && atual->prox != NULL && atual->prox->matricula != mat) // enquanto o atual, proximo e o n�mero do proximo n�o forem NULL
			atual = atual->prox;// atual recebe o pr�ximo 
		
		//quando encontrar um NULL
		if(atual != NULL && atual -> prox != NULL){
			remover = atual->prox;
			atual->prox = remover -> prox;
		}
	}
	
	if(remover != NULL) // se o valor informado foi removido da lista
		l->tam--;
 	
	return remover; // retorna o removido
}

void inicTabela(Lista t[], int tam){ // iniciando o vetor de listas
    int i;
    for(i = 0; i < tam; i++)
        inicLista(&t[i]);
}

int hash(long long int chave, int tam){// fun��o que retorna o resto da divis�o da chave pelo tamanho e diz e qual �ndice do vetor o valor ser� inserido
    return chave % tam;
}


void inserirTabela(Lista t[], char * nome, long long int valor, int tam){ // o valor informado pelo � inserido no �ndice definido pela fun��o hash
    int id = hash(valor, tam);
    inserir(&t[id], nome, valor);
}

Contato * buscaTabela(Lista t[], long long int chave, int tam){// o valor informado � buscado na tabela
    int id = hash(chave, tam);
    return buscarNumero(&t[id], chave);
}

void imprimirTabela(Lista t[], int tam){// essa fun��o imprime a tabela hash
    int i;
    for(i = 0; i < tam; i++){
        printf("�ndice %2d = ", i);
        exibeLista(&t[i]);
        printf("\n");
    }
}

Contato * removerTabela(Lista t[], long long int valor, int tam){// essa fun��o remove o valor informado da tabela hash
	int i;
	Contato * ret;
	
	for(i=0;i<tam;i++){
		ret = remover(&t[i],valor);
		if (ret != NULL)
			return ret;
	}
	return ret;
}

int tamanho(int t){ // fun��o que me retorna o total de linhas do arquivo
	FILE * ar = fopen("Lista_Aluno_Matricula.txt", "r"); // o arquivo � aberto em modo leitura
	
	char nom[50]; // vari�vel auxiliar

	while(!feof(ar)){//enquanto o arquivo n�o chegar ao fim
		fgets(nom, 50, ar);
		t++; // se houver uma linha, o t � incrementado
	}

	fclose(ar);// o arquivo � fechado
	return t; //retorno a qtd de linhas do arquivo
}

void lerDados(Lista t[], int tam){
	FILE * arq = fopen("Lista_Aluno_Matricula.txt", "r"); // o arquivo contendo os alunos � lido aqui
	char nome[100]; // vari�vel auxiliar
	long long int mat;
	char matricula [20];

	while(!feof(arq)){ // enquanto o arquivo n�o chegar ao fim

		fgets(nome,100,arq);
		fgets(matricula,20,arq);
		mat = atoll(matricula);

	    inserirTabela(t,nome,mat, tam);
	}

	fclose(arq);// o arquivo � fechado
}

int atualizar(Lista * l, FILE * arq){// essa fun��o l� a lista presente no �ndice informado e salva os dados em um novo doc
	
	Contato * atual = l->inic; // vari�vel recebe o in�cio da lista

	char mat[20];
	
	//else{
		while(atual != NULL){// enquanto a lista n�o chegar ao fim
			fputs(atual->nome, arq);//coloco o nome no arquivo
			lltoa(atual->matricula,mat,10);// � feita a convers�o para string
			fputs(mat, arq); // a matr�cula em formto string � adicionada no arquivo
			fputc('\n',arq);
			
			atual = atual->prox; // o atual recebe o prox
		}
	
	//}
	return 1; // retorna 1 se o procedimento teve sucesso	
}

int salvarDados(Lista t[], int tam){ // chama a fun��o atulizar passando os respectivo �ndice do vetor
	FILE * arq = fopen("Lista_Aluno_Matricula.txt", "w");// o arquivo � aberto em modo escrita
	int i; 
	
	for(i=0;i<tam;i++)
		atualizar(&t[i], arq);
	
	fclose(arq)	; // o arquivo � fechado

	return 1; // caso n�o ocorra erro, a fun��o retorna 1
}

