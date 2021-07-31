#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 10

// 20. Fa�a um programa que leia a matr�cula e a m�dia de 100 alunos. Ordene da maior
// para a menor nota e imprima uma rela��o contendo todas as matr�culas e m�dias

int main(){
	setlocale(LC_ALL,"");
	int matricula[MAX], i, j, auxMat;
	float media[MAX], auxMed;
	
	// Armazenar
	for (i=0; i<MAX; i++){	
		printf("%i� Matricula: ", i+1);
		scanf("%d", &matricula[i]);
		printf("Media do %i� aluno: ", i+1);
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
	printf("Matricula \t M�dia \n");
	for (i=0; i<MAX; i++){
		printf("%i \t\t %.1f \n", matricula[i], media[i]);
	}
	
	return 0;
}
