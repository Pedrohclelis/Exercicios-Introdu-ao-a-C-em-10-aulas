#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//27. Crie um programa que calcule e imprima o CR do per�odo para os alunos de
//computa��o. Para cada aluno, o algoritmo dever� ler:
//� n�mero da matr�cula;
//� quantidade de disciplinas cursadas;
//� notas em cada disciplina;
//Al�m do CR de cada aluno, o programa deve imprimir o melhor CR dos
//alunos que cursaram 5 ou mais disciplinas.
//� fim da entrada de dados � marcada por uma matr�cula inv�lida (matr�culas
//v�lidas de 1 a 5000);
//� CR do aluno � igual � m�dia aritm�tica de suas notas

int main(){
	setlocale(LC_ALL,"");
	int i, numMat, quantDisc;
	float nota, notasTotal, maiorCR=0;
	
	do{
		notasTotal = 0;
		printf("Numero de matr�cula [1 a 5000]: ");
		scanf("%i", &numMat);
		if (numMat < 1 || numMat > 5000) {break; }
		
		printf("Quantidade de disciplinas cursadas: ");
		scanf("%i", &quantDisc);
		
		for(i=1; i<=quantDisc; i++){
			printf("Nota da %i� disciplina: ", i);
			scanf("%f", &nota);
			notasTotal += nota;
		}
		
		printf("\nMatricula: %i\n", numMat);
		printf("Numero de disciplinas: %i\n", quantDisc);
		printf("CR do aluno: %.1f/%i = %.1f\n\n\n", notasTotal, quantDisc, notasTotal/quantDisc);
	
		if (quantDisc >= 5 || notasTotal/quantDisc > maiorCR){
			maiorCR = notasTotal/quantDisc;
		}
	} while (1);
	
	printf("Maior CR: %.1f", maiorCR);
	return 0;
}
