// Criar um algorítimo que gere números aleatórios e ordene utilizando diferentes tipos de algorítimos.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <locale.h>


void bubble(int n, int *vet);
void qs(int *vet, int inicio, int fim);
int particiona(int *vet, int inicio, int fim);
void mergesort(int vet[],int i,int j);
void merge(int vet[],int i1,int j1,int i2,int j2);
void selection(int vet[], int n);
void insert(int vet[], int n);
void menu(int n, int *vet);


int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int n, i, *vet;
	
	printf("Digite a quantidade de números:\n");
	scanf("%d", &n);
	printf("\n");
	vet=(int*)malloc(n* sizeof(int));

	for (i = 0; i <n ; i++){
		vet[i]=rand();
    }
    
    printf("Sequência de números aleatórios:\n");
    
	if(n<1){
		
		for(i=0;i<n;i++){
 		int x, aux;
 		x=rand()%n;
 		aux=vet[i];
 		vet[i]=vet[x];
 		vet[x]=aux;
	} 
	printf("\n");
	
		for (i = 0; i <n ; i++){
			printf("%d" ,vet[i]);
   		}
   		
	}else{
		for (i = 0; i <n ; i++){
			printf("%d ",vet[i]);
   		}
	}
	
	printf("\n");
 	
 	menu(n,vet);
 		
     return 0;
}

void bubble(int n, int *vet){

	int j, k, i, aux;
	
	for(j=0;j<n;j++){
		for(k=0;k<n;k++){
			if(vet[j]<vet[k]){
				aux=vet[j];
				vet[j]=vet[k];
				vet[k]=aux;
			}
		}
	}
}

void qs(int *vet, int inicio, int fim){
	int pivo, i, n;
	
    if(fim>inicio){
        pivo=particiona(vet, inicio, fim );
        qs(vet, inicio, pivo-1);
        qs(vet, pivo+1, fim);//fim 
    }
}

int particiona(int *vet, int inicio, int fim){
	 int aux, direita, esquerda, pivo;

    esquerda=inicio;
    direita=fim;
    pivo=vet[inicio];

    while(esquerda<direita){
        
        while(vet[esquerda]<=pivo && esquerda<=fim){
            esquerda++;
        }
        
        while(vet[direita]>pivo){
            direita--;
        }

        if(esquerda<direita){
            aux=vet[esquerda];
            vet[esquerda]=vet[direita];
            vet[direita]=aux;
        }
    }

    vet[inicio]=vet[direita];
    vet[direita]=pivo;

    return direita;
}

void merge(int vet[],int i1,int j1,int i2,int j2){
    int temp[100000];    
    int i,j,k;
    i=i1;    
    j=i2;    
    k=0;
    
    while(i<=j1 && j<=j2)   {
        if(vet[i]<vet[j])
            temp[k++]=vet[i++];
        else
            temp[k++]=vet[j++];
    }
    
    while(i<=j1)    
        temp[k++]=vet[i++];
        
    while(j<=j2)    
        temp[k++]=vet[j++];
        
 
    for(i=i1,j=0;i<=j2;i++,j++)
        vet[i]=temp[j];
}

void mergesort(int vet[],int i,int j){ 
    int mid;
        
    if(i<j){
        mid=(i+j)/2;
        mergesort(vet,i,mid);        
        mergesort(vet,mid+1,j);    
        merge(vet,i,mid,mid+1,j);    
    }
}

void selection(int vet[], int n){
	int aux, pivo, j, i, k;
	
	
	for(i=0;i<n-1;i++){
		pivo=i;
		for(j=i+1;j<n;j++){
			if(vet[j]<vet[pivo]){
				pivo=j;
			}
		}
		aux=vet[i];
		vet[i]=vet[pivo];
		vet[pivo]=aux;	
	}
	
	for (i = 0; i<n ; i++){
		printf("%d ",vet[i]);
   	}	
}

void insert(int vet[], int n){
   int i, aux, j;
   
   for (i = 1; i < n; i++){
       aux = vet[i];
       j = i-1;

       while (j >= 0 && vet[j] > aux){
           vet[j+1] = vet[j];
           j = j-1;
       }
       vet[j+1] = aux;
    }
   	
	for (i = 0; i<n ; i++){
		printf("%d ",vet[i]);
   	}	
}

void menu(int n, int *vet){
	int opc, i;
	clock_t start_time, end_time;
	
	do{
		printf("\n");
		printf("Escola a forma de ordenacao:\n1 - Bubble Sort\n2 - Quick Sort\n3 - Merge Sort\n4 - Selection Sort\n5 - Insert Sort\n6 - Sair\n\n");
		scanf("%d", &opc);
		printf("\n");
		switch(opc){
			
			case 1: 
				start_time = clock();
				bubble(n,vet);
				end_time = clock();
				break;
			
			case 2:
				start_time = clock();
				qs(vet, 0, n-1);
				end_time = clock();	
				
				
				break;
				
			case 3:
				start_time = clock();
				mergesort(vet, 0, n-1);
				end_time = clock();
				break;
				
			case 4:
				start_time = clock();
				selection(vet,n);
				end_time = clock();
				break;
				
			case 5:
				start_time = clock();
				insert(vet,n);
				end_time = clock();
				break;
				
			case 6:
				break;
				
			default:
				printf("Opcao invalida!\n");
				break;
		}
		for (i = 0; i<n ; i++){
			printf("%d ",vet[i]);
   		}
   		printf("\n");
		printf( "\nO tempo de execução foi: %f segundos. \n\n", (end_time - start_time) / (double)CLOCKS_PER_SEC);
		system("pause");
		system("cls");
	}while(opc!=4);
}
