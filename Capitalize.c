#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*  Captalize  */

int main(){
	setlocale(LC_ALL,"");
	char frase[100];
	int i;
	
	printf("Digite uma frase: ");
	fgets(frase, sizeof(frase), stdin);
	
	for (i=0; i<strlen(frase)-1; i++){
		if (frase[i] >= 97 && frase[i] <= 122){  // Minuscula
			if (frase[i-1] == ' ' || i == 0){
				frase[i] -= 32;
			}
		} else if (frase[i] >= 65 && frase[i] <= 90){  // Maiuscula
			if (frase[i-1] != ' '){
				frase[i] += 32;
			}
		}
	}
	
	printf("Saida captalizada: %s", frase);
	
	return 0;
}
