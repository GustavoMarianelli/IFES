#include "arvore.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(){
	setlocale(LC_ALL,"");
	No * raiz;
	iniciaArvore(&raiz);
	No * aux;
	int res;
	long long int numero;
	char * nome = (char*)malloc(50*sizeof(char));
	
	abrirArq(&raiz);
	int op = 1;
	
	while(op != 0){
			
		printf("\tSELECIONE A OP??O\n");
		printf("1 - Inserir aluno\n2 - Exibir alunos\n3 - Buscar por matr?cula\n4 - Remover\n5 - Salvar dados\n0 - Sair\n");
		scanf("%d",&op);
		
		if(op<0 || op>5) printf("Op??o inv?lida!\n");
		
		else{
		
			switch(op){
			
				case 1:
					
					printf("Digite o nome: "); // informa o nome
					fflush(stdin);
					gets(nome);
					
					printf("Digite a matr?cula a ser inserida: ");//o usu?rio informa a matr?cula
					
					scanf("%lld",&numero);

					if(consultarNumero(raiz,numero) == NULL){ // se a matr?cula informada n?o estiver na ?rvore
						res = inserir(&raiz,nome,numero); // insiro o aluno 
						if(res == 0) printf("O aluno n?o p?de ser inserido!\n\n");	
					}
				
					
					else 
						printf ("a matr?cula %lld j? foi inserida!\n\n",numero);// se o aluno j? estiver na ?rvore
				
					break;				
				
				
				case 2:
					if(raiz!=NULL){
						int tipo;
						printf("Selecione o tipo:\n1 - Pr? Ordem\n2 - Em Ordem\n3 - P?s Ordem\n");
						scanf("%d", &tipo);

						switch(tipo){
							case 1:
								printf("\t--Alunos--\n\n");
								exibirPreOrdem(raiz);
								break;

							case 2:
								printf("\t--Alunos--\n\n");
								exibirEmOrdem(raiz);		
								break;

							case 3:
								printf("\t--Alunos--\n\n");
								exibirPosOrdem(raiz);		
								break;
								
							default:
								printf("Op??o inv?lida!\n");
						}
							
					}
					
					else printf("\t--N?o exixtem alunos a serem exibidos--\n\n");	
				
					break;
							
				case 3:
					printf("Digite a matr?cula a ser procurada:\n");//o usu?rio informa a matr?cula a ser procurada
					scanf("%lld",&numero);
					
					aux = consultarNumero(raiz,numero);// verifico a matr?cula j? est? na ?rvore
					
					//se a matr?cula for encontrada
					if(aux!=NULL) printf ("A matr?cula %lld foi encontrada e pertence ao aluno %s\n\n",aux->matricula, aux->nome);
					
					//se a matr?cula n?o for encontrada
					else printf("A matr?cula %lld n?o foi encontrada!\n\n",numero);
				
					break;
				
				case 4:
					printf("Digite a matr?cula a ser removida:\n");//o usu?rio informa a matr?cula a ser removida
					scanf("%lld",&numero);
					
					aux = consultarNumero(raiz, numero);
					
					if(aux!=NULL) { // se a matr?cula for encontrada
						res = remover(&raiz,numero);
						
						if(res == 1) printf("A matr?cula %lld foi removida!\n\n", numero);
					}
					
					else printf("A matr?cula informada n?o foi encontrada!\n\n");
					
					break;
				case 5:
					salvarDados(raiz);
					printf("Dados salvos!\n");
					break;
				
				default: 
					printf("Programa encerrado!\n");
			}
		}
	}
	
	return 0;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     #include "arvore.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(){
	setlocale(LC_ALL,"");
	No * raiz;
	iniciaArvore(&raiz);
	No * aux;
	int res;
	long long int numero;
	char * nome = (char*)malloc(50*sizeof(char));
	
	abrirArq(&raiz);
	int op = 1;
	
	while(op != 0){
			
		printf("\tSELECIONE A OP??O\n");
		printf("1 - Inserir aluno\n2 - Exibir alunos\n3 - Buscar por matr?cula\n4 - Remover\n5 - Salvar dados\n0 - Sair\n");
		scanf("%d",&op);
		
		if(op<0 || op>5) printf("Op??o inv?lida!\n");
		
		else{
		
			switch(op){
			
				case 1:
					
					printf("Digite o nome: "); // informa o nome
					fflush(stdin);
					gets(nome);
					
					printf("Digite a matr?cula a ser inserida: ");//o usu?rio informa a matr?cula
					
					scanf("%lld",&numero);

					if(consultarNumero(raiz,numero) == NULL){ // se a matr?cula informada n?o estiver na ?rvore
						res = inserir(&raiz,nome,numero); // insiro o aluno 
						if(res == 0) printf("O aluno n?o p?de ser inserido!\n\n");	
					}
				
					
					else 
						printf ("a matr?cula %lld j? foi inserida!\n\n",numero);// se o aluno j? estiver na ?rvore
				
					break;				
				
				
				case 2:
					if(raiz!=NULL){
						int tipo;
						printf("Selecione o tipo:\n1 - Pr? Ordem\n2 - Em Ordem\n3 - P?s Ordem\n");
						scanf("%d", &tipo);

						switch(tipo){
							case 1:
								printf("\t--Alunos--\n\n");
								exibirPreOrdem(raiz);
								break;

							case 2:
								printf("\t--Alunos--\n\n");
								exibirEmOrdem(raiz);		
								break;

							case 3:
								printf("\t--Alunos--\n\n");
								exibirPosOrdem(raiz);		
								break;
								
							default:
								printf("Op??o inv?lida!\n");
						}
							
					}
					
					else printf("\t--N?o exixtem alunos a serem exibidos--\n\n");	
				
					break;
							
				case 3:
					printf("Digite a matr?cula a ser procurada:\n");//o usu?rio informa a matr?cula a ser procurada
					scanf("%lld",&numero);
					
					aux = consultarNumero(raiz,numero);// verifico a matr?cula j? est? na ?rvore
					
					//se a matr?cula for encontrada
					if(aux!=NULL) printf ("A matr?cula %lld foi encontrada e pertence ao aluno %s\n\n",aux->matricula, aux->nome);
					
					//se a matr?cula n?o for encontrada
					else printf("A matr?cula %lld n?o foi encontrada!\n\n",numero);
				
					break;
				
				case 4:
					printf("Digite a matr?cula a ser removida:\n");//o usu?rio informa a matr?cula a ser removida
					scanf("%lld",&numero);
					
					aux = consultarNumero(raiz, numero);
					
					if(aux!=NULL) { // se a matr?cula for encontrada
						res = remover(&raiz,numero);
						
						if(res == 1) printf("A matr?cula %lld foi removida!\n\n", numero);
					}
					
					else printf("A matr?cula informada n?o foi encontrada!\n\n");
					
					break;
				case 5:
					salvarDados(raiz);
					printf("Dados salvos!\n");
					break;
				
				default: 
					printf("Programa encerrado!\n");
			}
		}
	}
	
	return 0;
}
