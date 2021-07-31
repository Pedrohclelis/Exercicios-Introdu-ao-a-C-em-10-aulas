#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// 14. Faça um programa que armazene 5 números inteiros em um vetor. O programa
// deve gerar e imprimir um segundo vetor em que cada elemento é o quadrado do
// elemento do primeiro vetor

int main(){
	setlocale(LC_ALL,"");
	int num[5], num2[5], i;
	
	for(i=0; i<5; i++){
		printf("Digite o %iº numero: ", i+1);
		scanf("%i", &num[i]);
		num2[i] = pow(num[i], 2);
	}
	
	printf("\nNumero -> Quadrado\n");
	for(i=0; i<5; i++){
		if (num[i] > 0){
			printf("%5.i^2 = %i\n", num[i], num2[i]);
		} else{
			printf(" (%i)^2 = %i\n", num[i], num2[i]);
		}
	}
		

		
	return 0;
}
