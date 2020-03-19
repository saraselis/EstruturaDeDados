// Criar um algorítimo que simule uma cegonha de carros.

#include<stdlib.h>
#include<stdio.h>


typedef struct {
	int tam;
	int *n;
}pilha;


void menu(pilha *p);
pilha *alocar();
int stackpop(pilha *p);
void pop(pilha*p);
int mostrar(pilha *p);

int main(){
	pilha *t;	
	t=alocar();
	menu(t);
	
	return 0;
}

pilha *alocar(){
	pilha *aux;
	aux = (pilha*)malloc(sizeof(pilha));
	
	if(aux==NULL){
		printf("erro de mem�ria");
		exit (1);
	}
	aux->tam=0;
	aux->n=NULL;
	
	return aux;
}

void push(pilha *p, int x){
	if(p->tam==0){
		p->n=(int *)malloc(sizeof(int));	
	}else{
		p->n=(int *)realloc(p->n, sizeof(int)*(p->tam+1));
	}
	if(p->n==NULL){
		printf("Erro de mem�ria");
		exit(1);
	}
	p->n[p->tam]=x;
	p->tam++;
	printf("\n%d Inserido com sucesso\n",p->n[p->tam-1]);

}

void pop(pilha*p){
	if(p->tam==0){
		printf("Cegonha vazia!\n");
	}else{
		
		p->tam--;
		printf("\n%d Removido com sucesso!\n");
	}
}

int stackpop(pilha *p){
	return p->n[p->tam-1]; 	
}

int size(pilha *p){
	return p->tam;
} 

int mostrar(pilha *p){
	int i;
	for(i=p->tam; i>=0; i--){
		printf("%d\n", p->tam);
	}
}

void menu(pilha *p){
	int opc;
	int x;
	
	do{
		
		printf("\nEscolha uma opcao:\n1-push\n2-pop\n3-stackpop\n4-size\n5-mostrar\n6-sair\n\n");
		scanf("%d",&opc);
		
		switch(opc){
			case 1:
				printf("\nDigite o valor:\n");
				scanf("%d",&x);
				push(p,x);
								
				break;
				
			case 2:
				pop(p);
				break;
				
			case 3:
				x=stackpop(p);
				printf("%d\n",x);
				break;
				
			case 4:
				printf("\n%d\n", size(p));
				
				break;
				
			case 5:
				
				system("cls");
				mostrar(p);
				
				break;
				
			case 6:
				
				break;	
				
			default:
				printf("\nOpcao invalida\n");
				break;	
		
		}
		system("pause");
		system("cls");
		
	}while(opc!=6);
}

