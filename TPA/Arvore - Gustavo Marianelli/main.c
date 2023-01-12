#include "arvore.h"
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(){
	
	setlocale(LC_ALL,"");
	No * raiz;
	iniciaArvore(&raiz);
	No * aux;
	int res;
	long numero;
	
	int op = 1;
	
	// -- Menu -- 
	while(op != 0){
			
		printf("\tSELECIONE A OPÇÃO\n");
		printf("1 - Inserir número\n2 - Exibir números\n3 - Buscar por número\n4 - Remover\n0 - Sair\n");
		scanf("%d",&op);
		
		if(op<0 || op>4) printf("Opção inválida!\n");
		
		else{
		
			switch(op){
			
				case 1:
			
					printf("Digite o número a ser inserido:\n");//o usuário informa o número
					scanf("%ld",&numero);

					if(consultarNumero(raiz,numero) == NULL){ // se o númeor não estiver na árvore
						res = inserir(&raiz,numero);
						if(res == 0) printf("O número não pôde ser inserido!\n\n"); // se ocorrer algum erro na inseção
						
						else printf("Número inserido!\n"); // se o número for inserido
					}
				
					
					else 
						printf ("O número %ld já está nos contatos!\n\n",numero);// se o numero estiver na árvore
				
					break;				
				
				
				case 2:
					if(raiz!=NULL){
						int tipo;
						printf("Selecione o tipo:\n1 - Pré Ordem\n2 - Em Ordem\n3 - Pós Ordem\n");//escolhe em qual ordem 
						scanf("%d", &tipo);

						switch(tipo){
							case 1:
								printf("\t--Contatos--\n\n");
								exibirPreOrdem(raiz);
								break;

							case 2:
								printf("\t--Contatos--\n\n");
								exibirEmOrdem(raiz);		
								break;

							case 3:
								printf("\t--Contatos--\n\n");
								exibirPosOrdem(raiz);		
								break;
								
							default:
								printf("Opção inválida!\n");
						}
							
					}
					
					else printf("\t--Não exixtem contatos a serem exibidos--\n\n");	// se a árvore estiver vazia
				
					break;
							
				case 3:
					printf("Digite o número a ser procurado:\n");//o usuário informa o numero a ser procurado
					scanf("%ld",&numero);
					
					aux = consultarNumero(raiz,numero);// verifico se o numero já está na árvore
					
					if(aux!=NULL) printf ("O número %ld foi encontrado\n",aux->numero); // se o retorno for diferente de NULL
					
					else printf("O número %ld não foi encontrado!\n\n",numero); // se o retorno for NULL
				
					break;
				
				case 4:
					printf("Digite o numero a ser removido:\n");//o usuário informa o nome a ser procurado
					scanf("%ld",&numero);
					
					aux = consultarNumero(raiz, numero);
					
					if(aux!=NULL) { // se o número estiver na árvore
						res = remover(&raiz,numero);
						
						if(res == 1) printf("O contato foi removido!\n\n"); // se o contato for removido 
					}
					
					else printf("O numero informado não está nos contatos!\n\n"); // se o número não estiver na árvore
					
					break;
				
				default: 
					printf("Programa encerrado!\n");
					return 0;
			}
		}
	}
}
