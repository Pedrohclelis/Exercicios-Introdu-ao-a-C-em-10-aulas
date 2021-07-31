#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 20

// Escreva um algoritmo para ordenar um vetor num ´erico de
// 20 elementos em ordem crescente

int main(){
	setlocale(LC_ALL,"");
	int vet[MAX], i, j, aux;
	
	// Armazenar
	for (i=0; i<MAX; i++){
		printf("vet[%i] = ", i);
		scanf("%i", &vet[i]);
	}
	
	// Organizar
	for (i=0; i<MAX; i++){
		for (j=i+1; j<MAX; j++){
			// Mecanismo de troca caso o antecessor for maior
			if (vet[i] > vet[j]){
				aux = vet[j];
				vet[j] = vet[i];
				vet[i] = aux;
			}
		}
	}
	
	
	// Ler
	printf("\n");
	for (i=0; i<MAX; i++){
		printf("%i", vet[i]);
		if (i < MAX-1){printf(" -> ");}
	}
	
	return 0;
}
