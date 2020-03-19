// Simulado para a prova p1.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//funcoes
void push();
void mostrar();
void pop();

//variaveis globais
int topo=0;
int pilha[31];
int entrada;
int i=0, c, qtd=0;


//main
int main(){
		
	for(i=0; i<5;i++){
		
		scanf("%d", &entrada);
	
		if(entrada%2==0){
			push();
		}else{
			pop();
		}
	}	
	
		mostrar();
}



//funcoes
void push(){
	pilha[topo]=entrada;
	topo++;
	qtd++;
}

void pop(){
	if(topo!=0){
		pilha[topo-1]= 0;
		topo--;
	}
}

void mostrar(){
	
	if(topo!=0){
		for(c=0; c<qtd;c++){
		printf("\n%d\n", pilha[c]);	
		}
		
	}else{
		printf("Nao existem numeros armazenados\n");	
	}
	}
