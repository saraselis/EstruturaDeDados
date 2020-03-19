// Simulado para a prova p1.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//variaveis globais
int lista[30], qtd;

void ordenar(int qtd);
void mostrar(int qtd);

int main(){
	
	int i;
	
	for(i=0;i<30;i++){
		scanf("%d", &lista[i]);
		qtd++;
	}

	ordenar(qtd);
	mostrar(qtd);
	
	return 0;
}

void ordenar(int qtd){
	int c, j, aux;
	
	for(c=0;c<qtd;c++){
		
		for(j=c+1;j<qtd;j++){
			
			if (lista[c]<lista[j]){
			
				aux=lista[c];
				lista[c]=lista[j];
				lista[j]=aux;	
			}
		}
	}	
}

void mostrar(int qtd){
	int c;
	for(c=0;c<qtd;c++){
		printf("%d",lista[c]);
	}

}
