#include "hash.h"

// inicialização do vetor
void inicVetor(Vetor hash[], int tam){
	int i;
	for(i=0;i<tam;i++){
		hash[i].num = -1; // numero com -1
		hash[i].flagExistiu = 0; // flag com 0
	}
}

Vetor * lerArq(FILE * arq, int tam){ // lendo os dados do arquivo e passando para a tabela que é retornada pela função
	int t=0,num, j;
	
	
	Vetor * hash = (Vetor*)malloc(tam*sizeof(Vetor)); // criando e iniciadno a tabela
	inicVetor(hash,tam);
	
	
	
	while(fscanf(arq,"%d\n",&num) != EOF) // inserindo
		j = inserirNoVetor(hash, num, tam);
	

	

	return hash;
}



int gerarHash(int chave, int tam){ // função hash
	return chave % tam;
}

int saltoHash(int j, int num, int tam){ // função de salto hash
	int i = 1 + (num % (tam - 1));
	return i+j;
}

int inserirNoVetor(Vetor hash[], int num, int tam){ // função que insere os números na tabela
	int j = gerarHash(num, tam);
	int i = 0;

	while(hash[j].num != -1){ // enquanto a tabela no índice indicado pela função hash já tiver um valor inserido
//		i = saltoHash(j,num,tam);//usar o salto do slide deixa o processo muito lento, gera muitas colisões
//		j = gerarHash(i, tam);
		j = gerarHash(j+2, tam); // dessa forma ficou menos lento
	}
	
	//a tabela recebe o numero informado e a flag muda para 1, indicando que já existiu um numero naquele indice
	hash[j].num = num;
	hash[j].flagExistiu = 1;
	return j; // retorna o indice em que o número foi inserido
}

int buscarNumero(Vetor hash[], int num, int tam){ // busca um numero informado pelo teclado
	int i, j, pos = 0, indice;
	
	j = gerarHash(num, tam); // gera o primeiro hash
	
	// se a flag no indice indicado pela função nunca recebeu nenhum valor, logo esse valor procurado nunca foi inserido na tabela
	if(hash[j].flagExistiu == 0)
		return -1;
	
	// se o numero procurado estiver na tabela no indice indicado 
	else if(hash[j].num == num){
		printf("O número buscado de encontra no(s) índice(s): \n");
		printf("[%5d] ",j);
		//a variavel indice recebe o indice gerado pela função hash somente se existir apenas 1 indice com o numero procurado 
		indice  = j; 
		pos++; // variável indica que algum numero ja foi encontrado
	}
	
	while(hash[j].flagExistiu != 0){ // enquanto a flag indicar que algum numero ja existiu no indice indicado 
		
		j = gerarHash(j+2, tam); // gera o segundo hash
		
		if(hash[j].num == num){ // se o numero for encontrado
			if(pos == 0) // se o numero não tiver sido encontrado no primeiro indice indicado pela função hash
				printf("O número buscado de encontra no(s) índice(s): \n");
			printf("[%5d] ",j);
			pos++;
		}
	}
	
	printf("\n\n");
	
	if(pos == 0) return -1; // se o número for encontrado
	else if (pos > 1) return -2; // se mais de um índice tem o número
	else return indice; // se exatamente 1 índice tem o número
}

int removerNumero(Vetor hash[], int num, int tam){ // remover o numero da tabela
	int res = buscarNumero(hash, num, tam); // busca o numero informado pelo teclado
	int indice;

	if(res != -1){// se o numero for encontrado

		if (res == -2) { // se o numero foi encontrado em mais de 1 indice
			printf("Escolha o índice: "); // informa de qual indice deseja remover
			scanf("%d",&indice);
		
			if(hash[indice].num == num){//se o numero informado estiver no indice escolhido
				hash[indice].num = -1;
				return indice;
			}
			
			else return -1; 
		}
		
		else{// se o numero foi encontrado em apenas 1 indice
			hash[res].num = -1;
			return res;
		}
	}

	else return -1;// se o numero não foi encontrado
}

void exibirTabelaHash(Vetor hash[], int tam){ // exibe a tabela
	int i;
	for(i=0;i<tam;i++)
		printf("[%5d] -> Número: %5d\tExistiu: %1d\n", i, hash[i].num, hash[i].flagExistiu);
}
