#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	int n, i, fat;
	setlocale(LC_ALL,"");
		
	do{
		printf("Digite um numero para calculo de fatorial [n < 1 para encerrar]: ");
		scanf("%i", &n);
		
		if (n>=1){
			printf("O fatorial de %i! é ", n);	
			for (i=n; i>0; i--) {
				printf("%i", i);
				if (i>1) {printf(" x ");}
				fat *= i;
			}
			printf(" = %i\n\n", fat);
			fat = 1;
		}
		
	} while (n>=1);
	
	printf("Programa encerrado");
	return 0;
}
