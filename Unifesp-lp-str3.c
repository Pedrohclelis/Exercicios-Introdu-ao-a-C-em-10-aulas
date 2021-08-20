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
	char A[200], B[200], C[200], D[200];
	
	printf("Programa que recebe A, B e C. E retorna uma string D formada pela substituição das ocorrencias de B, ao longo da string A, por C.\n");
	printf("[A] Frase original: ");
	fgets(A, sizeof(A), stdin); // Bota um '\n' no final da frase
	A[strlen(A)-1]= '\0'; // Tira o '\n' do final
	
	printf("[B] Na qual a palavra..: ");
	fgets(B, sizeof(B), stdin); 
	B[strlen(B)-1]= '\0'; 
	
	printf("[C] ...será substituida por: ");
	fgets(C, sizeof(C), stdin); 
	C[strlen(C)-1]= '\0'; 
	D[0] = '\0';
	
	
	char *tokenA = strtok(A, " ");
	while(tokenA != NULL) {
		if (strcmp(B, tokenA) == 0){
			strcat(D, C);
		} else{
			strcat(D, tokenA);
		}
		strcat(D, " ");			// Adiciona espaço ao final de cada palavra que vai pra D
    	tokenA = strtok(NULL, " "); 		// Vai pro proximo fragmento de A
	}
	printf("\nSua frase modificada ficou: %s", D);
	
	return 0;
}
	
	
