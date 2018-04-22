#include<stdlib.h>
#include<stdio.h>

//declarar função
void push(int x);
void pop();
void stackpop();
void menu();
int size();
int mostrar();

int topo=0;
int ceg[10];


int main (){
	
	menu();
	
	return 0;	
}

void push(int x){
	if (topo==10){
		printf("A cegonha esta cheia!\n");
			
	}else{
		ceg[topo]=x;
		topo++;
		printf("\nInserido com sucesso!\n");
	}
		
}

void pop(){
	if(topo==0){
		printf("\nCegonha esta vazia!\n");	
	}else{
		ceg[topo--];
		printf("\nRemovido com sucesso!\n");
	}
	
	}
void stackpop(){
	if(topo!=0){
		printf("\n%d\n", ceg[topo-1]);
	}else{
		printf("A cegonha está vazia!\n");	
	}

}

int size(){

	return topo;
}

int mostrar(){
	int i;
	
	for(i=topo-1;i>=0;i--){
		printf("\n%d\n",ceg[i]);
	
	}
	
}

void menu(){
	int opc;
	int x;
	
	do{
		
		printf("\nEscolha uma opcao:\n1-push\n2-pop\n3-stackpop\n4-size\n5-mostrar\n6-sair\n\n");
		scanf("%d",&opc);
		
		switch(opc){
			case 1:
				printf("\nDigite o valor:\n");
				scanf("%d",&x);
				push(x);
								
				break;
				
			case 2:
				pop();
				break;
				
			case 3:
				stackpop();
				break;
				
			case 4:
				printf("\n%d\n",size());
				
				break;
				
			case 5:
				
				system("cls");
				mostrar();
				
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



