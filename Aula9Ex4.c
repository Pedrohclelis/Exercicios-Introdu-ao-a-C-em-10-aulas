#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define MAX 7

/*  4. Elabore um programa que leia um valor do tipo inteiro e, por meio de função,
atualize todas as posições de um vetor com o número inteiro lido, depois imprima
os valores. Utilize ponteiros para as operações.
 */

void at(int nume, int *veto){
	int i, *p;
	for (i=0; i<MAX; i++){
		p = &veto[i];
		*p = nume;
	}
}


int main(){
	setlocale(LC_ALL,"");
	int num, vet[MAX], i, *p;
	
	printf("Insira o numero: ");
	scanf("%i", &num);
	at(num, vet);
	
	for (i=0; i<MAX; i++){
		p = &vet[i];
		printf("[%i]: %i \n", i+1, *p);
	}
}
