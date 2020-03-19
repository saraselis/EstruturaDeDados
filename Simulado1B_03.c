#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void mostrar();
void ordenar();
char lista[30];
char nome[50];
int qtd;


int main(){
	int i, c;

	for(c=0; c<30; c++){
		scanf("%s", &lista[c],50);
		qtd++;	
	}
		
		ordenar();
		mostrar();
		
	return 0;
}

void ordenar(){
	char aux;
	int i, j;
	
	for(i=0;i<30;i++){
		for(j=i+1; j<30;j++){
			if(strcmp(lista[i], lista[j])<0){
				strcpy(aux, lista[i]);
				strcpy(lista[i], lista[j]);
				strcpy(lista[j], aux);
			}	
		}
	}
}

void mostrar(){
	int i;
	for(i=0;i<30;i++){
		printf("%s", &lista[i]);
	}
}
