#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*  2. Escreva uma função que leia dois números n1 e n2 (n1 < n2), e retorne quantos números primos existem entre n1 e n2 (incluir n1 e n2). Utilize a função desenvolvida no exercício 1. */

int main(){
	setlocale(LC_ALL,"");
	int num1, num2;
	printf("Digite n1 e n2, e retornarei primos existentes: ");
	scanf("%i %i", &num1, &num2);
	primosEntre(num1, num2);
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

void primosEntre(int n1, int n2){
	int aux
	
	// Corrigindo um n1 > n2
	if (n1 > n2){
		aux = n2;
		n2 = n1;
		n1 = aux;
	}
	
	for (i=n1; i<=n2; i++){
		if (testePrimo(i) == 1){
			print("%i ->", i);
		}
	}
	
}

