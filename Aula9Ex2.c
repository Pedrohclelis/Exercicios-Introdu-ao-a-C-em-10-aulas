#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*  2. Crie um programa que leia n�meros reais em um vetor de tamanho 10. Imprima
o endere�o de cada posi��o desse vetor. */

int main(){
	setlocale(LC_ALL,"");
	int i, num[10];
	
	for (i=0; i<10; i++){
		printf("%i: %i\n", i+1, &num[i]);
	}
}
