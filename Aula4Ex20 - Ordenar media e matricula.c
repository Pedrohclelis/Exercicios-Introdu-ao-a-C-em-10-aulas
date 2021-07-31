#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 10

// 20. Faça um programa que leia a matrícula e a média de 100 alunos. Ordene da maior
// para a menor nota e imprima uma relação contendo todas as matrículas e médias

int main(){
	setlocale(LC_ALL,"");
	int matricula[MAX], i, j, auxMat;
	float media[MAX], auxMed;
	
	// Armazenar
	for (i=0; i<MAX; i++){	
		printf("%iª Matricula: ", i+1);
		scanf("%d", &matricula[i]);
		printf("Media do %iº aluno: ", i+1);
		scanf("%f", &media[i]);
	}
	
	// Organizar
	for (i=0; i<MAX-1; i++){
		for (j=i+1; j<MAX; j++){
			// Mecanismo de troca se o antecessor for maior
			if (media[i] < media[j]){
				auxMed = media[j];
				media[j] = media[i];
				media[i] = auxMed;
				auxMat = matricula[j];
				matricula[j] = matricula [i];
				matricula[i] = auxMat;
			}
		}
	}
	
	// Ler
	printf("\n");
	printf("Matricula \t Média \n");
	for (i=0; i<MAX; i++){
		printf("%i \t\t %.1f \n", matricula[i], media[i]);
	}
	
	return 0;
}
