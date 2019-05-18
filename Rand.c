#include<stdio.h>
#include<stdlib.h>

int main(){
	int n, i, *vet;
	
	scanf("%d", &n);
	vet=(int*)malloc(n* sizeof(int));

	srand(n);
	for (i = 0; i <n ; i++){
		printf("%d\n",rand());
     }
     
     return 0;
}

