#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Construa um programa que leia dados para um vetor de 10 elementos inteiros.
// Imprimir o maior e o menor, sem ordenar, o percentual de números pares e a
// média dos elementos do vetor.


int main(){
	setlocale(LC_ALL,"");
	int i, num[10], maior, menor;
	float soma=0, pares=0;
	
	for(i=0; i<10; i++){
		printf("Digite o %iº numero: ", i+1);
		scanf("%i", &num[i]);
		soma += num[i];
		if (i==0){
			maior = menor = num[0];
		} else{
			if (num[i] > maior){
				maior = num[i];
			} else if (num[i] < menor){
				menor = num[i];
			}
		}
		if (num[i] % 2 == 0){
			pares++;
		}
	}
	
	
	printf("\nMaior elemento do vetor: %i\n", maior);
	printf("Menor elemento do vetor: %i\n", menor);
	printf("Media dos elementos do vetor: %.1f\n", soma/10);
	printf("Porcentagem de numeros pares: %.1f%%\n", pares*100/10);
}
