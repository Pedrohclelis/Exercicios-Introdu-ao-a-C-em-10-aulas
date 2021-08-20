#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*  Fa ¸ca um programa que leia uma string e fa ¸ca com que a
primeira letra de cada palavra fique em mai ´uscula. Para
isso, basta subtrair 32 do elemento que deseja alterar
para mai ´usculo
chrNome[0] = chrNome[0] – 32;
Ex. Entrada: lab. de linguagem de programacao
Ex. Sa ´ida : Lab. De Linguagem De Programacao */

int main(){
	setlocale(LC_ALL,"");
	char word[100];
	fgets(word, sizeof(word), stdin);
	
	// 1o
	for (i=0; i<strlen(word)-1; i++){
		word[i] += 3;
	}
	printf("%s", word);
	// 2o
	for (i=0; i<strlen(word)-1; i++){
		word[i] += 3;
	}
	
	return 0;
}
