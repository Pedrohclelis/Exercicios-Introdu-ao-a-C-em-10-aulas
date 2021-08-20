#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/*  Fa ¸ca uma fun ¸c ~ao que receba como entrada trˆes strings
(A, B e C) e retorne uma quarta string formada pela
substitui ¸c ~ao de todas as ocorrˆencias da string B pela
string C dentro da string A

Ex.: Se A=’Abra a porta para entrar para poder descansar calmamente’, B=’para’ e C=’e tente’, a
resposta deve ser: ’Abra a porta e tente entrar e tente
descansar calmamente’  */             

int main(){
	setlocale(LC_ALL,"");
	char stringA[200], stringB[200], stringC[200], stringD[200];
	int i, a=0, b=0, cont=0, j, igual;
	
	printf("[stringA] Frase original: ");
	fgets(stringA, sizeof(stringA), stdin); // Bota um '\n' no final da frase
	printf("[stringB] Na qual a palavra: ");
	fgets(stringB, sizeof(stringB), stdin); // Bota um '\n' no final da frase
	printf("[stringC] ...será substituida por: ");
	fgets(stringC, sizeof(stringC), stdin); // Bota um '\n' no final da frase
	stringD[0] = '\0';
	
	char * token = strtok(stringA, " ");
	while( token != NULL ) {
    	igual = 0;
    	for(i=0; i<strlen(token); i++) {
    		if (token[i] == stringB[i]){
    			igual++;
			}
		}
		if (igual == strlen(stringB)-1){
			strncat(stringD, stringC, strlen(stringC)-1);
		} else{
			strcat(stringD, token);
		}
		strcat(stringD, " ");
    	token = strtok(NULL, " ");
	}
	printf("\nSua frase modificada ficou: %s", stringD);
	return 0;
}
	
	
