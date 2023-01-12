#include "lista.h"
// -- FUNÇÕES-- 
void inicLista(Lista *l){ // iniciando a lista
	l->inic = NULL; //inicio recebe NULL
	l->tam = 0;// tam definido como 0
}

void inserir(Lista *l, char * nome, long long int mat){
	Contato * novo = (Contato*)malloc(sizeof(Contato)); //variáveis auxiliares
	Contato *atual = NULL, *anterior;
	Contato * fim;
	
	int inserido = 0, pausa = 0;
	
	//o novo recebe o nome e matrícula informados e seu próximo aponta para nulo
	strcpy(novo->nome, nome);
	novo->matricula = mat; 
	novo->prox = NULL;
	
	if(l->inic == NULL) // se a lista estiver vazia
		l->inic = novo; //o início da lista aponta para o novo
			
	else{ // se a lista não estiver vazia
		atual = l->inic; // atual recebe o início da lista
		anterior = NULL; // o anterior recebe NULL
		
		while(atual != NULL && inserido == 0){ // enquanto o atual não for nulo e nenhum número tive sido inserido na lista
		
			if(strcmp(atual->nome,novo->nome)>=0){ // compara o nome atual com o nome informado. Se for maior ou igual...
				novo->prox = atual;  //o próximo do novo aponta para o atual 
				
				if(anterior == NULL) // se o anterior for NULL, o início da lista passa a ser o novo elemento  
					l->inic = novo;
				else // se o anterior não for NULL, o próximo do anterior aponta para o novo elemento 
					anterior->prox = novo;
				inserido = 1; // indica que algum elemento foi inserido e encerra o laço
			}
			
			anterior = atual; // o anterior recebe o atual
			atual = atual->prox; // o atual recebe seu próximo 
		}
		//se o número informado for maior que o número atual, ele automaticamente vai pro fim da fila
		if(inserido == 0){
			fim = l->inic;
			while(fim->prox != NULL)
				fim = fim->prox;
			fim->prox = novo;
		}
	}
	l->tam++; // incrementa o tamanho da lista
}

void exibeLista(Lista *l){ // essa função exibe a lista
	Contato * atual = l->inic; // auxiliar que recebe o início da lista 
	
	printf("[%d]:\n\n",l->tam); // diz quantos elementos tem na fila no determinado índice 
	while(atual != NULL){ // enquanto não encontrar o NULL 
		printf("Nome: %sMatrícula: %lld\n\n",atual->nome, atual->matricula); //mostra os dados do atual
		atual = atual->prox; // vai para o próximo da lista 
	}
	printf("\n");
}

Contato * buscarNumero(Lista * l, long long int mat){ //busca o número informado na lista 
	Contato * atual = l->inic; // auxiliar que recebe o início da lista 
	Contato * aux = NULL; // auxiliar que recebe NULL
	
	while(atual != NULL){// enquanto não encontrar o NULL 
		if(atual->matricula == mat){ // se a matrícula atual for igual à matrícula buscada 
			aux = atual; // aux recebe o alemento atual e é retornado 
			return aux;
		}		
		else
			atual = atual->prox; // se não, vai pro próximo 
	}
	
	return aux; // se o retorno for NULL, não encontrou.
}

Contato * remover(Lista * l, long long int mat){// essa função remove o número informado da lista
	Contato * atual = l->inic, * remover = NULL; // auxiliares
	
	
	if(atual != NULL && l->inic->matricula == mat){ // se o número informado estiver no início da lista
		remover = l->inic; // o rmeover recebe o início 
		l->inic = remover->prox; // o início recebe o próximo	
	}
	
	else{ // se não...
		while(atual!=NULL && atual->prox != NULL && atual->prox->matricula != mat) // enquanto o atual, proximo e o número do proximo não forem NULL
			atual = atual->prox;// atual recebe o próximo 
		
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

int hash(long long int chave, int tam){// função que retorna o resto da divisão da chave pelo tamanho e diz e qual índice do vetor o valor será inserido
    return chave % tam;
}


void inserirTabela(Lista t[], char * nome, long long int valor, int tam){ // o valor informado pelo é inserido no índice definido pela função hash
    int id = hash(valor, tam);
    inserir(&t[id], nome, valor);
}

Contato * buscaTabela(Lista t[], long long int chave, int tam){// o valor informado é buscado na tabela
    int id = hash(chave, tam);
    return buscarNumero(&t[id], chave);
}

void imprimirTabela(Lista t[], int tam){// essa função imprime a tabela hash
    int i;
    for(i = 0; i < tam; i++){
        printf("Índice %2d = ", i);
        exibeLista(&t[i]);
        printf("\n");
    }
}

Contato * removerTabela(Lista t[], long long int valor, int tam){// essa função remove o valor informado da tabela hash
	int i;
	Contato * ret;
	
	for(i=0;i<tam;i++){
		ret = remover(&t[i],valor);
		if (ret != NULL)
			return ret;
	}
	return ret;
}

int tamanho(int t){ // função que me retorna o total de linhas do arquivo
	FILE * ar = fopen("Lista_Aluno_Matricula.txt", "r"); // o arquivo é aberto em modo leitura
	
	char nom[50]; // variável auxiliar

	while(!feof(ar)){//enquanto o arquivo não chegar ao fim
		fgets(nom, 50, ar);
		t++; // se houver uma linha, o t é incrementado
	}

	fclose(ar);// o arquivo é fechado
	return t; //retorno a qtd de linhas do arquivo
}

void lerDados(Lista t[], int tam){
	FILE * arq = fopen("Lista_Aluno_Matricula.txt", "r"); // o arquivo contendo os alunos é lido aqui
	char nome[100]; // variável auxiliar
	long long int mat;
	char matricula [20];

	while(!feof(arq)){ // enquanto o arquivo não chegar ao fim

		fgets(nome,100,arq);
		fgets(matricula,20,arq);
		mat = atoll(matricula);

	    inserirTabela(t,nome,mat, tam);
	}

	fclose(arq);// o arquivo é fechado
}

int atualizar(Lista * l, FILE * arq){// essa função lê a lista presente no índice informado e salva os dados em um novo doc
	
	Contato * atual = l->inic; // variável recebe o início da lista

	char mat[20];
	
	//else{
		while(atual != NULL){// enquanto a lista não chegar ao fim
			fputs(atual->nome, arq);//coloco o nome no arquivo
			lltoa(atual->matricula,mat,10);// é feita a conversão para string
			fputs(mat, arq); // a matrícula em formto string é adicionada no arquivo
			fputc('\n',arq);
			
			atual = atual->prox; // o atual recebe o prox
		}
	
	//}
	return 1; // retorna 1 se o procedimento teve sucesso	
}

int salvarDados(Lista t[], int tam){ // chama a função atulizar passando os respectivo índice do vetor
	FILE * arq = fopen("Lista_Aluno_Matricula.txt", "w");// o arquivo é aberto em modo escrita
	int i; 
	
	for(i=0;i<tam;i++)
		atualizar(&t[i], arq);
	
	fclose(arq)	; // o arquivo é fechado

	return 1; // caso não ocorra erro, a função retorna 1
}

