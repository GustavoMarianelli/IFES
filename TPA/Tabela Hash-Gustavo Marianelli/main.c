#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "hash.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,""); // define a linguagem
	
	Lista tabela[TAM]; // cria��o do vetor tipo lista
 	
	int op, val, ret;

    inicTabela(tabela);// inicializa��o da tabela

    do{
        #include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "hash.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,""); // define a linguagem
	
	Lista tabela[TAM]; // cria��o do vetor tipo lista
 	
	int op, val, ret;

    inicTabela(tabela);// inicializa��o da tabela

    do{
        printf("\n\tSelecione a op��o:\n1 - Inserir\n2 - Buscar\n3 - Imprimir\n4 - Remover\n0 - Sair\n");
        scanf("%d", &op);

        switch(op){
        case 1:
            printf("\tDigite o n�mero: ");
            scanf("%d", &val);
            inserirTabela(tabela, val); // o valor informado � inserido na tabela
            break;
        
		case 2:
            printf("\tDigite o n�mero: ");
            scanf("%d", &val);
            
			ret = buscaTabela(tabela, val); // o valor informado � procurado na tabela. Se for encontrado, a fun��o retorna 1, caso contr�rio,
            //retorna 0
			if(ret != 0) 
                printf("\tO n�mero %d foi encontrado\n", val); // se ele for encontrado
            else
                printf("\tO n�mero %d n�o foi encontrado!\n",val); // se ele n�o for encontrado
            break;
        
		case 3:
            imprimirTabela(tabela); // a tabela � impressa
            break;
        
        case 4:
        	printf("\tDigite o n�mero: ");
            scanf("%d", &val);
            
			ret = 0;
            ret = removerTabela(tabela, val);// o n�mero informado � removido da tabela. Se a remo��o tiver �xito, ele retorna 0, caso contr�rio,
            //retorna 1
            
            if(ret == 0)
            	printf("\tO n�mero %d foi removido!\n", val); // se a remo��o tiver sucesso 
            else 
            	printf("\tO n�mero %d n�o p�de ser removido!\n", val); // se a remo��o n�o tiver sucesso
            break;
        	
		default:
            printf("Opc�o inv�lida!\n");
        }
    }while(op != 0);
	
	printf("Programa encerrado!\n");
    return 0;
}
