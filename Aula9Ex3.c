#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*  3. Crie um programa que contenha um vetor de inteiros com tamanho 5. Utilizando
apenas ponteiros, leia valores e armazene neste vetor e após isso, imprima o
dobro de cada valor lido. */

int main(){
	setlocale(LC_ALL,"");
	int i, num[5], *p;
	
	for (i=0; i<5; i++){
		p = &num[i];
		printf("[%i] Valor: ", i+1);
		scanf("%i", p);
		printf("[%i] Valor '%i' alocado no endereço '%i'\n", i+1, *p, p);
		printf("\n");
	}
	
	for (i=0; i<5; i++){
		p = &num[i];
		printf("[%i] %i\n", i+1, *p);
	}
}
