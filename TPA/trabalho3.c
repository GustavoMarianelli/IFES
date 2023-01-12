#include <stdio.h>
#include <stdlib.h>

typedef struct grafo{
	int qtdVertices;
	int grauMax;
	int ** arestas;
	int ** pesos;
	int * grau;
}Grafo;


char **alocarMatrizChar(int n_linhas, int n_colunas){
	char **matriz;
	matriz =  (char **)malloc(n_linhas*sizeof(char *));
	int i;
	for(i=0; i<n_linhas; i++){
		matriz[i] = (char *)malloc(n_colunas*sizeof(char));
	}
	return matriz;
}

Grafo * criarGrafo(int qtdVertices, int grauMax){
	Grafo * grafo = (Grafo*) malloc(sizeof(struct grafo));
	if(grafo != NULL){
		int i;
		grafo->qtdVertices = qtdVertices;
		grafo->grauMax = grauMax;
		grafo->grau = (int*)calloc(qtdVertices, sizeof(int));
		grafo->arestas = (int**)malloc(qtdVertices * sizeof(int*));

		grafo->arestas = alocarMatrizInt(qtdVertices, grauMax);
		grafo->pesos = alocarMatrizInt(qtdVertices, grauMax);
		
	}
	return grafo;
}

void liberarGrafo(Grafo * grafo){
	if(grafo != NULL){
		int i;
		for(i=0; i< grafo->qtdVertices; i++)
			free(grafo->arestas[i]);	
		free(grafo->arestas);

		for(i=0; i<grafo->qtdVertices;i++)
			free(grafo->pesos[i]);
		free(grafo->pesos);
	}
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
	matriz[10] = "Fagaras";
	matriz[11] = "Pitesti";
	matriz[12] = "Bucharesti";
	matriz[13] = "Ciurgiu";
	matriz[14] = "Urziceni";
	matriz[15] = "Hirsova";
	matriz[16] = "Eforie";
	matriz[17] = "Vaslui";
	matriz[18] = "Iasi";
	matriz[19] = "Neamt";
}


int inserirAresta(Grafo * grafo, int origem, int destino, int peso){
	if(grafo == NULL) return 0;

	grafo->arestas[origem][grafo->grau[origem]] = destino;
	grafo->pesos[origem][grafo->grau[origem]] = peso;	
	grafo->grau[origem]++;

	grafo->arestas[destino][grafo->grau[destino]] = origem;
	grafo->pesos[destino][grafo->grau[destino]] = peso;	
	grafo->grau[destino]++;

	return 1;
	
}

int removerAresta(Grafo * grafo, int origem, int destino){
	int i = 0;
	while(i < grafo->grau[origem] && grafo->arestas[origem][i] != destino)
		i++;
	if(i == grafo->grau[origem])
		return 0;
	grafo->grau[origem]--;
	grafo->grau[destino]--;
	grafo->pesos[origem][i] = grafo->pesos[origem][grafo->grau[origem]];
	grafo->pesos[destino][i] = grafo->pesos[destino][grafo->grau[destino]];
	grafo->arestas[origem][i] = grafo->arestas[origem][grafo->grau[origem]];
	grafo->arestas[destino][i] = grafo->arestas[destino][grafo->grau[destino]];
	return 1;
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
	inserirAresta(g, 7, 11, 138);
	inserirAresta(g, 8, 9, 80);
	inserirAresta(g, 8, 11, 97);
	inserirAresta(g, 9, 10, 99);
	inserirAresta(g, 10, 12, 211);
	inserirAresta(g, 11, 12, 101);
	inserirAresta(g, 12, 13, 90);
	inserirAresta(g, 12, 14, 85);
	inserirAresta(g, 14, 15, 98);
	inserirAresta(g, 14, 17, 142);
	inserirAresta(g, 15, 16, 86);
	inserirAresta(g, 17, 18, 92);
	inserirAresta(g, 18, 19, 87);
	printf("A matriz foi preenchida automaticamente!\n\n");
}

int menorDistancia(int * distancia, int * visitado, int nivel){
	int i, menor = -1, primeiro = 1;

	for(i=0; i < nivel; i++){
		if(distancia[i] >= 0 && visitado[i] == 0){
			if(primeiro){
				menor = i;
				primeiro = 0;
			}
			else{
				if(distancia[menor] > distancia[i])
					menor = i;
			}
		}
	}
	return menor;
}

int menorCaminho(Grafo * grafo, int ini, int * ant, int * distancia){
	int i, ind,u;
	int cont = grafo->qtdVertices;
	int nivel = cont;
	int *  visitado = (int*)malloc(nivel*sizeof(int));
	int distanciaTotal = 0;
	for(i=0;i< nivel;i++){
		ant[i] = -1;
		distancia[i] = -1;
		visitado[i] = 0;
	}
	
	distancia[ini] = 0;

	printf("{");
	while(cont > 0){
		u = menorDistancia(distancia, visitado, nivel);
		if(u == -1)
			return -1;

		visitado[u] = 1;
	
		for(i=0; i<grafo->grau[u]; i++){
			ind = grafo->arestas[u][i];
			if(distancia[ind] < 0){
				distancia[ind] = grafo->pesos[u][i];
				ant[ind] = u;
				
			}
			else{
				if(distancia[ind] > grafo->pesos[u][i]){
					distancia[ind] = grafo->pesos[u][i];
					ant[ind] = u;								
				}		
			}
			distanciaTotal += distancia[ind];
			if(cont > 1 && distancia[ind] != 0)
			printf("%d: %d, ", ind, distancia [ind]);
		}
		cont--;
		
	}
	printf("%d: %d", ind, distancia [ind]);
	printf("}\n");
	printf("\nDistancia total: %d\n", distanciaTotal);
	
	free(visitado);
	return 0;
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



int main(){
	int tam = 20;
	Grafo * grafo = criarGrafo(tam, 4);
	char ** cidades = alocarMatrizChar(tam, tam);
	int i, ant[tam], dist[tam];
	
	preencherMatrizCidades(cidades);
	mostrarLegenda(cidades, tam);
	preencherMatrizAutomaticamente(grafo);
	
	int origem;
	printf("\nMenor caminho:\n");
	printf("Informe a origem: ");
	scanf("%d", &origem);
	menorCaminho(grafo, origem, ant, dist);
	
	liberarGrafo(grafo);
}