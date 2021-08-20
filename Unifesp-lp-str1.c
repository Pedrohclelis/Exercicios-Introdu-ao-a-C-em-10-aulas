#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*  Captalize  */

int main(){
	setlocale(LC_ALL,"");
	char palavra1[100];
	int i;
	
	printf("Digite uma palavra1: ");
	fgets(palavra1, sizeof(palavra1), stdin);
	
	for (i=0; i<strlen(palavra1)-1; i++){
		if (palavra1[i] >= 97 && palavra1[i] <= 122){  // Minuscula
			if (palavra1[i-1] == ' ' || i == 0){
				palavra1[i] -= 32;
			}
		}
	}
	
	printf("Saida: %s", palavra1);
	
	return 0;
}
