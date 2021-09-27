#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*  Escreva uma função que receba um número inteiro e retorne 1 se esse for primo e 0 caso contrário */

int main(){
	setlocale(LC_ALL,"");
	int num;
	printf("Digite um numero e eu darei 1 para primo, e 0 caso contrario: ");
	scanf("%i", &num);
	printf("\nRetorno: %i", testePrimo(num));
	return 0;
}

int testePrimo(int n){
	int i, divisores=0;
	
	for (i=1; i<=n; i++){
		if (n % i == 0){
			divisores++;
		}
	}
	
	if (divisores == 2){
		return 1;
	} else{
		return 0;
	}
}
