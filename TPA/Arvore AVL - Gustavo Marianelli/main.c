#include "arvore.h"
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(){
	
	setlocale(LC_ALL,"");
	No * raiz;
	iniciaArvore(&raiz);
	No * aux;
	int res;
	long long int numero;
	
	int op = 1;
	
	// -- Menu -- 
	while(op != 0){
			
		printf("\tSELECIONE A OP??O\n");
		printf("1 - Inserir n?mero\n2 - Exibir n?meros\n3 - Buscar por n?mero\n4 - Remover\n0 - Sair\n");
		scanf("%d",&op);
		
		if(op<0 || op>4) printf("Op??o inv?lida!\n");
		
		else{
		
			switch(op){
			
				case 1:
			
					printf("Digite o n?mero a ser inserido:\n");//o usu?rio informa o n?mero
					scanf("%lld",&numero);

					if(consultarNumero(raiz,numero) == NULL){ // se o n?meor n?o estiver na ?rvore
						res = inserir(&raiz,numero);
						if(res == 0) printf("O n?mero n?o p?de ser inserido!\n\n"); // se ocorrer algum erro na inse??o
						
						else printf("N?mero inserido!\n"); // se o n?m1ero for inserido
				
					}
					
					else 
						printf ("O n?mero %lld j? est? na ?rvore!\n\n",numero);// se o numero estiver na ?rvore
				
					break;				
				
				
				case 2:
					if(raiz!=NULL){
						int tipo;
						printf("Selecione o tipo:\n1 - Pr? Ordem\n2 - Em Ordem\n3 - P?s Ordem\n");//escolhe em qual ordem 
						scanf("%d", &tipo);

						switch(tipo){
							case 1:
								printf("\t--N?meros--\n\n");
								exibirPreOrdem(raiz);
								break;

							case 2:
								printf("\t--N?meros--\n\n");
								exibirEmOrdem(raiz);		
								break;

							case 3:
								printf("\t--N?meros--\n\n");
								exibirPosOrdem(raiz);		
								break;
								
							default:
								printf("Op??o inv?lida!\n");
						}
							
					}
					
					else printf("\t--N?o exixtem n?meros a serem exibidos--\n\n");	// se a ?rvore estiver vazia
				
					break;
							
				case 3:
					printf("Digite o n?mero a ser procurado:\n");//o usu?rio informa o numero a ser procurado
					scanf("%ld",&numero);
					
					aux = consultarNumero(raiz,numero);// verifico se o numero j? est? na ?rvore
					
					if(aux!=NULL) printf ("O n?mero %lld foi encontrado\n",aux->numero); // se o retorno for diferente de NULL
					
					else printf("O n?mero %lld n?o foi encontrado!\n\n",numero); // se o retorno for NULL
				
					break;
				
				case 4:
					printf("Digite o numero a ser removido:\n");//o usu?rio informa o nome a ser procurado
					scanf("%lld",&numero);
					
					aux = consultarNumero(raiz, numero);
					
					if(aux!=NULL) { // se o n?mero estiver na ?rvore
						aux = remover(&raiz,numero);
						
						if(aux != NULL) printf("O numero %lld foi removido!\n\n", aux->numero); // se o contato for removido 
					}
					
					else printf("O numero informado n?o est? na ?rvore!\n\n"); // se o n?mero n?o estiver na ?rvore
					
					break;
				
				default: 
					printf("Programa encerrado!\n");
					return 0;
			}
		}
	}
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             #include "arvore.h"
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(){
	
	setlocale(LC_ALL,"");
	No * raiz;
	iniciaArvore(&raiz);
	No * aux;
	int res;
	long long int numero;
	
	int op = 1;
	
	// -- Menu -- 
	while(op != 0){
			
		printf("\tSELECIONE A OP??O\n");
		printf("1 - Inserir n?mero\n2 - Exibir n?meros\n3 - Buscar por n?mero\n4 - Remover\n0 - Sair\n");
		scanf("%d",&op);
		
		if(op<0 || op>4) printf("Op??o inv?lida!\n");
		
		else{
		
			switch(op){
			
				case 1:
			
					printf("Digite o n?mero a ser inserido:\n");//o usu?rio informa o n?mero
					scanf("%lld",&numero);

					if(consultarNumero(raiz,numero) == NULL){ // se o n?meor n?o estiver na ?rvore
						res = inserir(&raiz,numero);
						if(res == 0) printf("O n?mero n?o p?de ser inserido!\n\n"); // se ocorrer algum erro na inse??o
						
						else printf("N?mero inserido!\n"); // se o n?m1ero for inserido
				
					}
					
					else 
						printf ("O n?mero %lld j? est? na ?rvore!\n\n",numero);// se o numero estiver na ?rvore
				
					break;				
				
				
				case 2:
					if(raiz!=NULL){
						int tipo;
						printf("Selecione o tipo:\n1 - Pr? Ordem\n2 - Em Ordem\n3 - P?s Ordem\n");//escolhe em qual ordem 
						scanf("%d", &tipo);

						switch(tipo){
							case 1:
								printf("\t--N?meros--\n\n");
								exibirPreOrdem(raiz);
								break;

							case 2:
								printf("\t--N?meros--\n\n");
								exibirEmOrdem(raiz);		
								break;

							case 3:
								printf("\t--N?meros--\n\n");
								exibirPosOrdem(raiz);		
								break;
								
							default:
								printf("Op??o inv?lida!\n");
						}
							
					}
					
					else printf("\t--N?o exixtem n?meros a serem exibidos--\n\n");	// se a ?rvore estiver vazia
				
					break;
							
				case 3:
					printf("Digite o n?mero a ser procurado:\n");//o usu?rio informa o numero a ser procurado
					scanf("%ld",&numero);
					
					aux = consultarNumero(raiz,numero);// verifico se o numero j? est? na ?rvore
					
					if(aux!=NULL) printf ("O n?mero %lld foi encontrado\n",aux->numero); // se o retorno for diferente de NULL
					
					else printf("O n?mero %lld n?o foi encontrado!\n\n",numero); // se o retorno for NULL
				
					break;
				
				case 4:
					printf("Digite o numero a ser removido:\n");//o usu?rio informa o nome a ser procurado
					scanf("%lld",&numero);
					
					aux = consultarNumero(raiz, numero);
					
					if(aux!=NULL) { // se o n?mero estiver na ?rvore
						aux = remover(&raiz,numero);
						
						if(aux != NULL) printf("O numero %lld foi removido!\n\n", aux->numero); // se o contato for removido 
					}
					
					else printf("O numero informado n?o est? na ?rvore!\n\n"); // se o n?mero n?o estiver na ?rvore
					
					break;
				
				default: 
					printf("Programa encerrado!\n");
					return 0;
			}
		}
	}
}
