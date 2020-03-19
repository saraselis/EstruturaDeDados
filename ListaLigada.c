// Criar lista ligada

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct lista{
	int qtd;	
	struct elemento *inicio;
}lista;

typedef struct elemento{
	char nome[20];
	int mat;
	struct elemento *prox;
}elemento;


lista *alocarlista();
void menu(lista *l);
void inserir(lista *l, int mat, char nome[20]);
elemento *alocarelemento(lista *l);
void mostrar(lista *l);
int excluir(lista*l, char nome[20]);
int buscar(lista*l, char nome[20]);


int main(){
	lista *l;
	l=alocarlista();
	
	//só passa variável no parâmetro
	menu(l);
	
	return 0;
}

lista *alocarlista(){
	
	lista *aux;
	aux=(lista*)malloc(sizeof(lista));
	aux->qtd=0;
	aux->inicio=NULL;
	
	return aux;
}

void inserir(lista *l, int mat, char nome[20]){
	elemento *novo;
	novo=alocarelemento(l);
	
	novo->mat=mat;
	strcpy(novo->nome, nome);
	//criando ligação entre lista e elemento
	elemento *aux;
	
	if(l->inicio==NULL){
		l->inicio=novo;

	}else{
		aux=l->inicio;
		while(aux->prox!=NULL){
			aux=aux->prox;
		}
		aux->prox=novo;
	}
	
	l->qtd++;
}

elemento *alocarelemento(lista *l){
	elemento *aux;
	aux=(elemento*)malloc(sizeof(elemento));
	aux->mat=0;
	strcpy(aux->nome, " ");
	aux->prox=NULL;
	
	return aux;
}

void mostrar(lista *l){
	elemento *aux;
	if(l->inicio==NULL){
		printf("Nenhum aluno cadastrado\n");
	}else{
		aux=l->inicio;
		while(aux!=NULL){
			printf("%s %d\n",aux->nome, aux->mat);
			aux=aux->prox;
		}
	}
}

int excluir(lista*l, char nome[20]){
	elemento *aux, *ant;
	
	if(l->qtd==0){
		printf("Nenhum aluno cadastrado!\n");
		return 0;
	}else{
		ant=NULL;
		aux=l->inicio;
			while((strcmp(nome,aux->nome)!=0) && (aux->prox!=NULL)){
				ant=aux;
				aux=aux->prox;
			}if(strcmp(nome, aux->nome)!=0){
				return 0;
			}else{
				if(ant==NULL){
					l->inicio=aux->prox;
				}else{
					ant->prox=aux->prox;
				}
			}
				free(aux);
				l->qtd--;
				return 1;
	}
}
	
int buscar(lista*l, char nome[20]){
	elemento *aux;
	
	if(l->qtd==0){
		return 0;
	}else{
		aux=l->inicio;
		while(aux!=NULL){
			if(strcmp(nome, aux->nome)==0){
				printf("%s\n", aux->nome);
				printf("%p\n", aux);
			
				return 1;
			}
		}
		
		return 0;
	}
}	
	
void menu(lista *l){
	int op;
	int mat;
	char nome[20];
	
	do{
		
		printf("1 - Cadastrar alunos\n2 - Mostrar alunos cadastrados\n3 - Excluir alunos cadastrados\n4 - Buscar\n6 - Para sair\n");
		scanf("%d",&op);
		
		switch(op){
			case 1:
				scanf("%s", nome);
				fflush(stdin);
				
				scanf("%d", &mat);
				inserir(l, mat, nome);
				
				break;
				
			case 2:
				mostrar(l);
				system("pause");
				break;
				
			case 3:
				printf("Digite o nome que quer remover:\n");
				fflush(stdin); //limpar buffer
				
				gets(nome);
				
				if(excluir(l, nome)){
				printf("Elemento com sucesso\n");
				}else{
					printf("Elemento nao encontrado\n");
				}
					system("pause");
				break;
			case 4:
				fflush(stdin);
				gets(nome);
				if(buscar(l, nome)==0){
					printf("Elemento nao encontrado\n");	
				}
				system("pause");
		}
		system("cls");
	}while(op!=6);
}

