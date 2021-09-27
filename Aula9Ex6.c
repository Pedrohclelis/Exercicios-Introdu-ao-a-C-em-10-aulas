#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define MAX 10

/*  6. Construa uma fun��o que, recebendo como par�metros quatro n�meros inteiros,
devolva ao m�dulo que o chamou os dois maiores n�meros dentre os quatro recebidos. Fa�a um programa que leia tantos conjuntos de quatro valores quantos o
usu�rio deseje e que acione a fun��o para cada conjunto de valores, apresentando
a cada vez os dois maiores n�meros. Se preferir, utilize vetor para armazenar o
conjunto de valores. */

void maior(int *veto, int *p1, int *p2){
	int aux, i, j;
	
	for (i=0; i<MAX; i++){
		for (j=i+1; j<MAX; j++){
			if (veto[i] < veto[j]){
				aux = veto[i];
				veto[i] = veto[j];
				veto[j] = aux;
			}
		}
	}
	*p1 = veto[0];
	*p2 = veto[1];
}

int main(){
	setlocale(LC_ALL,"");
	int vet[MAX], i, m1, m2;
	
	for (i=0; i<MAX; i++){
		printf("%i� valor: ", i+1);
		scanf("%i", &vet[i]);
	}
	
	maior(vet, &m1, &m2);
	
	printf("1o maior: %i \n2o maior: %i", m1, m2);
	return 0;
}
