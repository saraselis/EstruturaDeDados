#include<stdlib.h>
#include<stdio.h>
#ifdef WIN32
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif

//funções
void qs(long long *vet, long long inicio, long long fim);
long long particiona(long long *vet, long long inicio, long long fim);

//função principal
int main(){
    long long n, vet[100000], inicio=0, fim=0, k, j;

    scanf(INT64, &n);

    for(k=0;k<n;k++){
        scanf(INT64, &vet[k]);
    }

    fim=n-1;

    qs(vet, inicio, fim);

    for(j=0;j<n;j++){
        printf(INT64, vet[j]);
        printf(" ");
    }
    printf("\n");

    return 0;
}

void qs(long long *vet, long long inicio, long long fim){
    long long pivo;

    if(fim>inicio){
        pivo=particiona(vet, inicio, fim );
        qs(vet, inicio, pivo-1);
        qs(vet, pivo+1, fim);//fim ja é n-1
    }
}

long long particiona(long long *vet, long long inicio, long long fim){
    long long aux, direita, esquerda, pivo;

    esquerda=inicio;
    direita=fim;
    pivo=vet[inicio];

    while(esquerda<direita){
        //veloresXindices

        //anda a esquerda
        while(vet[esquerda]<=pivo && esquerda<=fim){
            esquerda++;
        }
        //anda a direita
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
