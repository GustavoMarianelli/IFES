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
	
	Lista tabela[tam]; // cria��o do vetor tipo lista
 	
	int op, ret; // vari�veis que recebem a op��o do usu�rio e o retorno de algumas fun��es
	Contato * aux; 
	long long int val; //vai receber a matr�cula informada
	char nome[50];// receber� o nome informado

    inicTabela(tabela, tam);// inicializa��o da tabela
    
    lerDados(tabela, tam); // os dados do arquivo s�o lidos e passados para a tabela
	
	//-- Menu -- 
	do{
        printf("\n\tSelecione a op��o:\n1 - Inserir\n2 - Buscar\n3 - Imprimir\n4 - Remover\n5 - Salvar Dados\n0 - Sair\n");
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
            
            
            printf("\tDigite a matr�cula: ");
            scanf("%lld", &val);
            
            aux = buscaTabela(tabela,val, tam); // a vari�vel aux recebe o retorno da fun��o buscaTabela
            
			if(aux != NULL) // se o retorno for diferente de nulo, significa que a matr�cula informada j� est� cadastrada na tabela
				printf("Esta matr�cula j� est� cadastrada!\n");
			else{ //se o retorno for NULL, a nome e a matr�cula s�o inseridos 
				inserirTabela(tabela, nome, val, tam); 
				printf("Aluno inserido!\n");
			}
            break;
        
		case 2:
            printf("\tDigite a matr�cula: ");
            scanf("%lld", &val);
            
			aux = buscaTabela(tabela, val, tam); // a matr�cula informada � procurada na tabela
			
			if(aux != 0) // se o retorno n�o for NULL, a matr�cula foi encontrada
                printf("\tA matr�cula %lld foi encontrada. Aluno(a) %s\n", aux->matricula,aux->nome); // se ele for encontrado
            else // retorno NULL, matr�cula n�o est� na tabela
                printf("\tA matr�cula %lld n�o foi encontrada\n",val); // se ele n�o for encontrado
            break;
        
		case 3:
            imprimirTabela(tabela, tam); // a tabela � impressa
            break;
        	
        case 4:
        	printf("\tDigite a matr�cula: ");
            scanf("%lld", &val);
            
            aux = removerTabela(tabela, val, tam);//o aux recebe o retorno da fun��o removerTabela
            
            if(aux != NULL) // se o retorno n�o for NULL, a matr�cula foi encontrada e removida
            	printf("\tA matr�cula %lld (%s) foi removida!\n", aux->matricula, aux->nome); // se a remo��o tiver sucesso 
            
            else // se o retorno for NULL, a mat�cula n�o foi encontrada ou n�o pode ser removida
            	printf("\tA matr�cula %lld n�o p�de ser removida!\n", val); // se a remo��o n�o tiver sucesso
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
	
	Lista tabela[tam]; // cria��o do vetor tipo lista
 	
	int op, ret; // vari�veis que recebem a op��o do usu�rio e o retorno de algumas fun��es
	Contato * aux; 
	long long int val; //vai receber a matr�cula informada
	char nome[50];// receber� o nome informado

    inicTabela(tabela, tam);// inicializa��o da tabela
    
    lerDados(tabela, tam); // os dados do arquivo s�o lidos e passados para a tabela
	
	//-- Menu -- 
	do{
        printf("\n\tSelecione a op��o:\n1 - Inserir\n2 - Buscar\n3 - Imprimir\n4 - Remover\n5 - Salvar Dados\n0 - Sair\n");
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
            
            
            printf("\tDigite a matr�cula: ");
            scanf("%lld", &val);
            
            aux = buscaTabela(tabela,val, tam); // a vari�vel aux recebe o retorno da fun��o buscaTabela
            
			if(aux != NULL) // se o retorno for diferente de nulo, significa que a matr�cula informada j� est� cadastrada na tabela
				printf("Esta matr�cula j� est� cadastrada!\n");
			else{ //se o retorno for NULL, a nome e a matr�cula s�o inseridos 
				inserirTabela(tabela, nome, val, tam); 
				printf("Aluno inserido!\n");
			}
            break;
        
		case 2:
            printf("\tDigite a matr�cula: ");
            scanf("%lld", &val);
            
			aux = buscaTabela(tabela, val, tam); // a matr�cula informada � procurada na tabela
			
			if(aux != 0) // se o retorno n�o for NULL, a matr�cula foi encontrada
                printf("\tA matr�cula %lld foi encontrada. Aluno(a) %s\n", aux->matricula,aux->nome); // se ele for encontrado
            else // retorno NULL, matr�cula n�o est� na tabela
                printf("\tA matr�cula %lld n�o foi encontrada\n",val); // se ele n�o for encontrado
            break;
        
		case 3:
            imprimirTabela(tabela, tam); // a tabela � impressa
            break;
        	
        case 4:
        	printf("\tDigite a matr�cula: ");
            scanf("%lld", &val);
            
            aux = removerTabela(tabela, val, tam);//o aux recebe o retorno da fun��o removerTabela
            
            if(aux != NULL) // se o retorno n�o for NULL, a matr�cula foi encontrada e removida
            	printf("\tA matr�cula %lld (%s) foi removida!\n", aux->matricula, aux->nome); // se a remo��o tiver sucesso 
            
            else // se o retorno for NULL, a mat�cula n�o foi encontrada ou n�o pode ser removida
            	printf("\tA matr�cula %lld n�o p�de ser removida!\n", val); // se a remo��o n�o tiver sucesso
            break;
        
        case 5:
        	
			ret = salvarDados(tabela, tam);
			
			if(ret == 0) // se a fun��o retornar 0, algum erro ocorreu ao salvar os dados
				printf("N�o foi poss�vel salvar os dados!\n");
			else //caso contr�rio, os dados foram salvos com sucesso
				printf("Os dados foram salvos com sucesso!\n");
			break;
        	
		default:
            printf("Opc�o inv�lida!\n");
        }
    }while(op != 0);
	
    return 0;
}
