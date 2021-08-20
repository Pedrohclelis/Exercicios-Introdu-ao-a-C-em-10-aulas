#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*  Fa ¸ca um programa que receba 2 strings (A e B) e retorne
uma terceira string (C) formada pelos caracteres de A e B
intercalados. Ex.: Se A=’Quarta’ e B=’Segunda’, a
resposta deve ser ’QSueagrutn*a*da’.  */             

int main(){
	setlocale(LC_ALL,"");
	char stringA[100], stringB[100], c[100];
	int i=0, a=0, b=0, cont=0;
	
	printf("Digite a palavra 1: ");
	fgets(stringA, sizeof(stringA), stdin); // Bota um '\n' no final da frase
	printf("Digite a palavra 2: ");
	fgets(stringB, sizeof(stringB), stdin); // Bota um '\n' no final da frase
	
	while (strlen(c) < strlen(stringA)+strlen(stringB)-2){
		if (cont % 2 == 0){
			if (stringA[a] != "\0" && stringA[a] != '\n'){
				c[i] = stringA[a];
				a++;
				i++;
			}
		} else{
			if (stringB[b] != "\0" && stringB[b] != '\n'){
				c[i] = stringB[b];
				b++;
				i++;
			}
		}
		cont++;
	}
	
	
	printf("Saida: %s", c);
	return 0;
}
