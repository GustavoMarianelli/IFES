#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <locale.h>

typedef struct grafo{
	int **matrizGrafo;
	int arestas;
}Grafo;


int **alocarMatrizInt(int n_linhas, int n_colunas){
	int **matriz;
	matriz =  (int **)malloc(n_linhas*sizeof(int *));
	int i;
	for(i=0; i<n_linhas; i++){
		matriz[i] = (int *)malloc(n_colunas*sizeof(int));
	}
	return matriz;
}
void inicGrafo(Grafo * g, int tam){
	int i,j;
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			g->matrizGrafo[i][j] = 0;
		}
	}

	g->arestas = 0;
}

char **alocarMatrizChar(int n_linhas, int n_colunas){
	char **matriz;
	matriz =  (char **)malloc(n_linhas*sizeof(char *));
	int i;
	for(i=0; i<n_linhas; i++){
		matriz[i] = (char *)malloc(n_colunas*sizeof(char));
	}
	return matriz;
}

void preencherMatrizCidades(char ** matriz){
	matriz[0] = "Oradea";
	matriz[1] = "Zerind";
	matriz[2] = "Arad";
	matriz[3] = "Timisiora";
	matriz[4] = "Lugoj";
	matriz[5] = "Mehadia";
	matriz[6] = "Drobeta";
	matriz[7] = "Craiova";
	matriz[8] = "Rimnicu Vilea";
	matriz[9] = "Sibiu";
}


void inserirAresta(Grafo * g, int origem, int destino, int distancia){
	g->matrizGrafo[origem][destino] = distancia;
	g->matrizGrafo[destino][origem] = distancia;
	g->arestas+=2;
}


void removerAresta(Grafo * g, int origem, int destino){
	g->matrizGrafo[origem][destino] = 0;
	g->matrizGrafo[destino][origem] = 0;
	g->arestas-=2;
	
}

void preencherMatrizAutomaticamente(Grafo * g){
	inserirAresta(g, 0, 1, 71);
	inserirAresta(g, 0, 9, 151);
	inserirAresta(g, 1, 2, 75);
	inserirAresta(g, 2, 3, 118);
	inserirAresta(g, 3, 9, 140);
	inserirAresta(g, 4, 5, 75);
	inserirAresta(g, 5, 6, 75);
	inserirAresta(g, 6, 7, 120);
	inserirAresta(g, 7, 8, 146);
	inserirAresta(g, 8, 9, 80);
	printf("A matriz foi preenchida automaticamente!\n\n");
}

 int buscarDistancia(Grafo g, int origem, int destino, int tam){
	 int i, j, distancia = 0;
	 for(i=0;i<tam;i++)	{
		if(i == origem){
			for(j = 0; j < tam; j++){
				if(j == destino){
					distancia = g.matrizGrafo[i][j];
					return distancia;
				}
			}
		}
	 }
	 return distancia;
 }

void mostrarLegenda(char ** matriz, int tam){
	int i;
	printf("------- Legenda -----------\n");
    for(i=0; i<tam; i++){
	   printf("Cidade %d:\t%s\n", i, matriz[i]);
		
    }	
	printf("---------------------------");
	printf("\n");
}



void mostrarMatriz(Grafo g, char ** matriz, int tam){
	int i, j;
	printf("\n");
	printf("\t\t\t\t\tDestino\n");
	printf("Origem |");
	
	for(i=0;i<tam;i++)
		printf("%4d", i);
	printf("\n-------|----------------------------------------\n");
	//printf("\n");
	
	for(i=0;i<tam;i++){
		printf("\t%2d |",i);
		for(j=0; j<tam; j++){
			printf("%4d", g.matrizGrafo[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	mostrarLegenda(matriz,tam);
}



int main(){
	setlocale(LC_ALL,"");
	int op = 1;
	int tam = 10;

	char ** cidades = alocarMatrizChar(tam,tam);
	preencherMatrizCidades(cidades);
	
	Grafo grafo;
	grafo.matrizGrafo = alocarMatrizInt(tam, tam);
	
	inicGrafo(&grafo, tam);
	
	int op1;
	while(op!=0){
		printf("\n1 - Preencher automaticamente de acordo com o Mapa\n2 - Manipular Arestas\n3 - Mostrar Matriz\n4 - Distancia entre duas cidades\n5 - Mostrar Legenda\n0 - Sair\n");
		scanf("%d",&op);

		int origem, destino, distancia;
		
		switch(op){
			case 0:
				printf("\nPrograma encerrado!\n");
				break;
			
			case 1:
				preencherMatrizAutomaticamente(&grafo);
				break;
			
			case 2:
				printf("\n1 - Inserir Aresta\n2 - Remover Aresta\n");
				scanf("%d",&op1);

				if(op1 < 0 || op1 > 2)
					printf("Opção inválida!\n");
				
				else{
					printf("\nInforme a origem: ");
					scanf("%d",&origem);
					printf("Informe o destino: ");
					scanf("%d",&destino);
					if(origem < 0 || origem > 9 || destino < 0 || destino > 9)
						printf("Algum dado inserido é inválido! A origem e destino devem ser menores que o tamanho %d\n", tam);
							
					
					else{
						if(op1 == 1){
							printf("Informe a distância: ");
							scanf("%d",&distancia);
	
							if(distancia <= 0)
								printf("A distância deve ser maior que 0!\n");
							else{
								inserirAresta(&grafo, origem, destino, distancia);
								printf("Aresta inserida com sucesso!\n\n");
							}
						}
						else{
							removerAresta(&grafo, origem, destino);
							printf("Aresta removida com sucesso!\n\n");	
						}
						
					}
				}
				break;
			
			case 3: 
				mostrarMatriz(grafo, cidades, tam);
				break;
			
			case 4:
				
				printf("\nInforme a origem: ");
				scanf("%d",&origem);
				printf("Informe o destino: ");
				scanf("%d",&destino);
				if(origem < 0 || origem > 9 || destino < 0 || destino > 9)
					printf("Algum dado inserido é inválido! A origem e destino devem ser menores que o tamanho %d", tam);
						
			
				else{
					int dist = buscarDistancia(grafo, origem, destino, tam);
					printf("Distância: %d", dist);
					if(dist == 0)
						printf(". A distância entre as duas cidades desejadas ainda não foi informada ou elas não possuem ligação!");
					
					}
				printf("\n");
				break;

			case 5:
				mostrarLegenda(cidades, tam);
				break;
			
			default:
				printf("\nOpção inválida!\n\n");
		}
	}	
	return 0;
}