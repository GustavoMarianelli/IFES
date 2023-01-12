/*
Trabalho 1
Nome: Gustavo Pereira Marianelli

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "lista.h"


// -- MENU -- 
int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"Portuguese"); // define a linguagem
	
	int tam_arq = tamanho(tam_arq); // me diz quantas linhas possui o arquivo
	
	int qtd_alunos = tam_arq/2; // me fala a quantidade de alunos
	
	int tam = qtd_alunos*1.5; // define o tamanho da minha tabela
	
	Lista tabela[tam]; // criação do vetor tipo lista
 	
	int op, ret; // variáveis que recebem a opção do usuário e o retorno de algumas funções
	Contato * aux; 
	long long int val; //vai receber a matrícula informada
	char nome[50];// receberá o nome informado

    inicTabela(tabela, tam);// inicialização da tabela
    
    lerDados(tabela, tam); // os dados do arquivo são lidos e passados para a tabela
	
	//-- Menu -- 
	do{
        printf("\n\tSelecione a opção:\n1 - Inserir\n2 - Buscar\n3 - Imprimir\n4 - Remover\n5 - Salvar Dados\n0 - Sair\n");
        scanf("%d", &op);

        switch(op){
        case 0:
        	printf("Programa encerrado!\n");
        	return 0;
        	break;
        
		case 1:
        	printf("\tDigite o nome: ");
        	fflush(stdin);
            fgets(nome,100,stdin);
            
            
            printf("\tDigite a matrícula: ");
            scanf("%lld", &val);
            
            aux = buscaTabela(tabela,val, tam); // a variável aux recebe o retorno da função buscaTabela
            
			if(aux != NULL) // se o retorno for diferente de nulo, significa que a matrícula informada já está cadastrada na tabela
				printf("Esta matrícula já está cadastrada!\n");
			else{ //se o retorno for NULL, a nome e a matrícula são inseridos 
				inserirTabela(tabela, nome, val, tam); 
				printf("Aluno inserido!\n");
			}
            break;
        
		case 2:
            printf("\tDigite a matrícula: ");
            scanf("%lld", &val);
            
			aux = buscaTabela(tabela, val, tam); // a matrícula informada é procurada na tabela
			
			if(aux != 0) // se o retorno não for NULL, a matrícula foi encontrada
                printf("\tA matrícula %lld foi encontrada. Aluno(a) %s\n", aux->matricula,aux->nome); // se ele for encontrado
            else // retorno NULL, matrícula não está na tabela
                printf("\tA matrícula %lld não foi encontrada\n",val); // se ele não for encontrado
            break;
        
		case 3:
            imprimirTabela(tabela, tam); // a tabela é impressa
            break;
        	
        case 4:
        	printf("\tDigite a matrícula: ");
            scanf("%lld", &val);
            
            aux = removerTabela(tabela, val, tam);//o aux recebe o retorno da função removerTabela
            
            if(aux != NULL) // se o retorno não for NULL, a matrícula foi encontrada e removida
            	printf("\tA matrícula %lld (%s) foi removida!\n", aux->matricula, aux->nome); // se a remoção tiver sucesso 
            
            else // se o retorno for NULL, a matícula não foi encontrada ou não pode ser removida
            	printf("\tA matrícula %lld não pôde ser removida!\n", val); // se a remoção não tiver sucesso
            break;
        
 /*
Trabalho 1
Nome: Gustavo Pereira Marianelli

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "lista.h"


// -- MENU -- 
int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"Portuguese"); // define a linguagem
	
	int tam_arq = tamanho(tam_arq); // me diz quantas linhas possui o arquivo
	
	int qtd_alunos = tam_arq/2; // me fala a quantidade de alunos
	
	int tam = qtd_alunos*1.5; // define o tamanho da minha tabela
	
	Lista tabela[tam]; // criação do vetor tipo lista
 	
	int op, ret; // variáveis que recebem a opção do usuário e o retorno de algumas funções
	Contato * aux; 
	long long int val; //vai receber a matrícula informada
	char nome[50];// receberá o nome informado

    inicTabela(tabela, tam);// inicialização da tabela
    
    lerDados(tabela, tam); // os dados do arquivo são lidos e passados para a tabela
	
	//-- Menu -- 
	do{
        printf("\n\tSelecione a opção:\n1 - Inserir\n2 - Buscar\n3 - Imprimir\n4 - Remover\n5 - Salvar Dados\n0 - Sair\n");
        scanf("%d", &op);

        switch(op){
        case 0:
        	printf("Programa encerrado!\n");
        	return 0;
        	break;
        
		case 1:
        	printf("\tDigite o nome: ");
        	fflush(stdin);
            fgets(nome,100,stdin);
            
            
            printf("\tDigite a matrícula: ");
            scanf("%lld", &val);
            
            aux = buscaTabela(tabela,val, tam); // a variável aux recebe o retorno da função buscaTabela
            
			if(aux != NULL) // se o retorno for diferente de nulo, significa que a matrícula informada já está cadastrada na tabela
				printf("Esta matrícula já está cadastrada!\n");
			else{ //se o retorno for NULL, a nome e a matrícula são inseridos 
				inserirTabela(tabela, nome, val, tam); 
				printf("Aluno inserido!\n");
			}
            break;
        
		case 2:
            printf("\tDigite a matrícula: ");
            scanf("%lld", &val);
            
			aux = buscaTabela(tabela, val, tam); // a matrícula informada é procurada na tabela
			
			if(aux != 0) // se o retorno não for NULL, a matrícula foi encontrada
                printf("\tA matrícula %lld foi encontrada. Aluno(a) %s\n", aux->matricula,aux->nome); // se ele for encontrado
            else // retorno NULL, matrícula não está na tabela
                printf("\tA matrícula %lld não foi encontrada\n",val); // se ele não for encontrado
            break;
        
		case 3:
            imprimirTabela(tabela, tam); // a tabela é impressa
            break;
        	
        case 4:
        	printf("\tDigite a matrícula: ");
            scanf("%lld", &val);
            
            aux = removerTabela(tabela, val, tam);//o aux recebe o retorno da função removerTabela
            
            if(aux != NULL) // se o retorno não for NULL, a matrícula foi encontrada e removida
            	printf("\tA matrícula %lld (%s) foi removida!\n", aux->matricula, aux->nome); // se a remoção tiver sucesso 
            
            else // se o retorno for NULL, a matícula não foi encontrada ou não pode ser removida
            	printf("\tA matrícula %lld não pôde ser removida!\n", val); // se a remoção não tiver sucesso
            break;
        
        case 5:
        	
			ret = salvarDados(tabela, tam);
			
			if(ret == 0) // se a função retornar 0, algum erro ocorreu ao salvar os dados
				printf("Não foi possível salvar os dados!\n");
			else //caso contrário, os dados foram salvos com sucesso
				printf("Os dados foram salvos com sucesso!\n");
			break;
        	
		default:
            printf("Opcão inválida!\n");
        }
    }while(op != 0);
	
    return 0;
}
