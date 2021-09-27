#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define MAX 10

/*  6. Construa uma função que, recebendo como parâmetros quatro números inteiros,
devolva ao módulo que o chamou os dois maiores números dentre os quatro recebidos. Faça um programa que leia tantos conjuntos de quatro valores quantos o
usuário deseje e que acione a função para cada conjunto de valores, apresentando
a cada vez os dois maiores números. Se preferir, utilize vetor para armazenar o
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
		printf("%iº valor: ", i+1);
		scanf("%i", &vet[i]);
	}
	
	maior(vet, &m1, &m2);
	
	printf("1o maior: %i \n2o maior: %i", m1, m2);
	return 0;
}
