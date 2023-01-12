#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "hash.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,""); // define a linguagem
	
	Lista tabela[TAM]; // criação do vetor tipo lista
 	
	int op, val, ret;

    inicTabela(tabela);// inicialização da tabela

    do{
        #include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "hash.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,""); // define a linguagem
	
	Lista tabela[TAM]; // criação do vetor tipo lista
 	
	int op, val, ret;

    inicTabela(tabela);// inicialização da tabela

    do{
        printf("\n\tSelecione a opção:\n1 - Inserir\n2 - Buscar\n3 - Imprimir\n4 - Remover\n0 - Sair\n");
        scanf("%d", &op);

        switch(op){
        case 1:
            printf("\tDigite o número: ");
            scanf("%d", &val);
            inserirTabela(tabela, val); // o valor informado é inserido na tabela
            break;
        
		case 2:
            printf("\tDigite o número: ");
            scanf("%d", &val);
            
			ret = buscaTabela(tabela, val); // o valor informado é procurado na tabela. Se for encontrado, a função retorna 1, caso contrário,
            //retorna 0
			if(ret != 0) 
                printf("\tO número %d foi encontrado\n", val); // se ele for encontrado
            else
                printf("\tO número %d não foi encontrado!\n",val); // se ele não for encontrado
            break;
        
		case 3:
            imprimirTabela(tabela); // a tabela é impressa
            break;
        
        case 4:
        	printf("\tDigite o número: ");
            scanf("%d", &val);
            
			ret = 0;
            ret = removerTabela(tabela, val);// o número informado é removido da tabela. Se a remoção tiver êxito, ele retorna 0, caso contrário,
            //retorna 1
            
            if(ret == 0)
            	printf("\tO número %d foi removido!\n", val); // se a remoção tiver sucesso 
            else 
            	printf("\tO número %d não pôde ser removido!\n", val); // se a remoção não tiver sucesso
            break;
        	
		default:
            printf("Opcão inválida!\n");
        }
    }while(op != 0);
	
	printf("Programa encerrado!\n");
    return 0;
}
