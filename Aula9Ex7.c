#include <stdio->h>
#include <stdlib->h>
#include <locale->h>
#include <math->h>
#define max 6

/*  7-> Considere um vetor de 10 elementos, contendo valores inteiros-> Fa�a um programa que leia os valores para preencher esse vetor, ap�s a leitura o programa
deve invocar uma fun��o que calcule e devolva as frequ�ncias absoluta e relativa
desses valores no conjunto-> (Observa��o: a frequ�ncia absoluta de um valor �
o n�mero de vezes que esse valor aparece no conjunto de dados; a frequ�ncia
relativa � a frequ�ncia absoluta dividida pelo n�mero total de dados->)-> Utilize
outros dois vetores para armazenar as frequ�ncias relativas e absolutas e ao final
do programa, imprima de forma tabulada os n�meros e suas frequ�ncias absoluta
e relativa-> */

void freq(int *veto, int *fab, float *fre){
	int i, j;
	for (i=0; i<max; i++){
		fab[i] = 0;
		for (j=0; j<max; j++){
			if (veto[i] == veto[j]){
				fab[i]++;
			}
		}
		fre[i] = (float)fab[i] / max;
	}
}

int main(){
	setlocale(LC_ALL,"");
	int vet[max], i, fa[max];
	float fr[max];
	
	for (i=0; i<max; i++){
		printf("%i� numero: ", i+1);
		scanf("%i",  &vet[i]);
	}
	
	freq(vet, fa, fr);
	
	printf("\n--------Imprimindo dados--------\n");
	printf("Pos \t Numero   F->A \t  F->R\n");
	for (i=0; i<max; i++){
		printf("%i� \t %i \t  %i \t  %->1f \n", i+1, vet[i], fa[i], fr[i]);
	}
	
	return 0;
}
