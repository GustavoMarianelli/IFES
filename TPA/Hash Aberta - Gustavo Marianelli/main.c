#include "hash.h"



int main(void) {
	setlocale(LC_ALL,"");
	
	// -- arquivo a ser lido -- 
	FILE * arq = fopen("randInt100k.txt","r"); // 
	////////////////// "randInt1k.txt","r" \\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	
//	int tam = 1500; // para o arquivo de 1k
	int tam = 150000; // para o arquivo de 100k
	
	time_t segundos, segundos2;
	time (&segundos);

	Vetor * tabelaHash = lerArq(arq, tam);
	
	time (&segundos2);	
	float tempo = segundos2 - segundos;
	printf("Tempo para inserir na tabela: %.2f\n", tempo);
	
	int #include "hash.h"



int main(void) {
	setlocale(LC_ALL,"");
	
	// -- arquivo a ser lido -- 
	FILE * arq = fopen("randInt100k.txt","r"); // 
	////////////////// "randInt1k.txt","r" \\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	
//	int tam = 1500; // para o arquivo de 1k
	int tam = 150000; // para o arquivo de 100k
	
	time_t segundos, segundos2;
	time (&segundos);

	Vetor * tabelaHash = lerArq(arq, tam);
	
	time (&segundos2);	
	float tempo = segundos2 - segundos;
	printf("Tempo para inserir na tabela: %.2f\n", tempo);
	
	int op=1, num;

	while(op != 0){
		printf("\n\n\t--- MENU ---\n1 - Inserir\n2 - Buscar\n3 - Exibir\n4 - Remover\n0 - Sair\n");
		printf("Op��o: ");
		scanf("%d",&op);

		switch(op){
			case 1:
				printf("Informe o n�emro: ");
				scanf("%d",&num);

				if(num != 0 && inserirNoVetor(tabelaHash, num, tam) == 1) // a fun��o inserir retorna  1
					printf("O n�mero %d foi inserido!\n",num);
				else
					printf("N�mero inv�lido!\n");
				
				break;
			
			case 2:
				printf("Informe o n�emro: ");
				scanf("%d",&num);

				if(num < 0) printf("N�mero inv�lido!\n");

				else{
					int res = buscarNumero(tabelaHash, num, tam);

					if(res == -1) printf("O n�mero n�o foi encontrado!\n");
				}
				break;
			
			case 3:
				exibirTabelaHash(tabelaHash, tam);
				break;

			case 4:
				printf("Informe o n�emro: ");
				scanf("%d",&num);

				if(num < 0) printf("N�mero inv�lido!\n");

				else{
					int r = removerNumero(tabelaHash, num, tam);
					if(r != -1)
						printf("O n�mero %d foi removido do �ndice %d\n", num, r);
					else 
						printf("O n�mero %d n�o p�de ser removido!\n", num);
				}
				break;

			case 0:
				printf("Programa encerrado!\n");
				break;
			default:
				printf("Op��a inv�lida!!\n");			
		}
	}
	
	fclose(arq);

	return 0;
}
