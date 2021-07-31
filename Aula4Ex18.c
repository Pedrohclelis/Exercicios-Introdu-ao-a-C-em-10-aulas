#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define max 10

// 18. Faça um programa em C que permita entrar com dados para um vetor VET do tipo
// inteiro com 20 posições, em que podem existir vários elementos repetidos. Gere
// um vetor VET2 ordenado a partir do vetor VET e que terá apenas os elementos
// não repetidos.

int main(){
	setlocale(LC_ALL,"");
	int vet[max], vet2[max], i, j, cont=0, aux;
	
	// Lendo
	for (i=0; i<max; i++){
		printf("Vetor[%i]: ", i);
		scanf("%i", &vet[i]);
	}
	
	// Ordenar o vet original
	for (i=0; i<max-1; i++){
		for (j=i+1; j<max; j++){
			// Mecanismo de troca caso o antecessor for maior
			if (vet[i] > vet[j]){
				aux = vet[j];
				vet[j] = vet[i];
				vet[i] = aux;
			}
		}
	}
	
	// Botando os numeros nao repetidos no vet2
	for (i=0; i<max; i++){
		if (i == 0 || vet[1-i] != vet[i]){
			vet2[cont] = vet[i];
			cont++;
		}
	}
	
	// Imprimindo
	for (i=0; i<cont; i++){
		printf("vet2[%i]: %i\n", i, vet2[i]);
	}
	
	return 0;
}
