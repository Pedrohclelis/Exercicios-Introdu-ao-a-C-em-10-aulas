#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*  Crie uma estrutura representando um aluno de uma disciplina. Essa estrutura
deve conter o número de matrícula do aluno, seu nome e as notas de três provas.
Defina também um tipo para esta estrutura. Agora, escreva um programa que
leia os dados de cinco alunos e os armazena nessa estrutura. Em seguida, exiba o
nome e as notas do aluno que possui a maior média geral dentre os cinco. */

struct registro{
	int matricula;
	char nome[50];
	float nota[3];
};

int main(){
	setlocale(LC_ALL,"");
	int i, j, iMaior;
	float aux, mediaMaior=0;
	struct registro aluno[5];
	
	for (i=0; i<5; i++){
		printf("Nome do %iº aluno: ", i+1);
		scanf("%s", &aluno[i].nome);
		printf("Nº de Matricula: ");
		scanf("%i", &aluno[i].matricula);
		
		aux = 0;
		for (j=0; j<3; j++){
			printf("%iª Nota: ", j+1);
			scanf("%f", &aluno[i].nota[j]);
			aux += aluno[i].nota[j];
		}
		
		if (aux > mediaMaior){
			mediaMaior = aux;
			iMaior = i;
		}

		printf("\n");
	}

	printf("---------Dados do aluno com maior media---------\n");
	printf("Nome: %s", aluno[iMaior].nome);
	printf("Matricula: %i", aluno[iMaior].matricula);
	printf("1ª Nota: %.1f", aluno[iMaior].nota[0]);
	printf("2ª Nota: %.1f", aluno[iMaior].nota[1]);
	printf("3ª Nota: %.1f", aluno[iMaior].nota[2]);
	printf("Media final: %.1f", mediaMaior);
}
