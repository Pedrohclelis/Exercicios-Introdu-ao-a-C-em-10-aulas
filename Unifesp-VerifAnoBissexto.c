#include <stdio.h>

int main(){
	int ano;
	printf("Verificador de ano bissexto, digite o ano: ");
	scanf("%i", &ano);
	if ((ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0)) {
		printf("Ano BISSEXTO!");
	} else {
		printf("NAO");
	}
	
	
	
}
