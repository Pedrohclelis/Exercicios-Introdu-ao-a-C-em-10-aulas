#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define max 6

/*  9. A Google est� desenvolvendo um novo sistema operacional para m�quinas de
venda de bolinhas de borracha de R$1,00, mas precisa realizar testes no Gerenciador de Mem�ria desse novo sistema. Voc� foi contratado para fazer um
programa para verificar se o gerenciador de mem�ria est� funcionando corretamente. Seu programa dever� ler 3 n�meros inteiros, 3 n�meros decimais, 3 letras,
armazen�-las em vari�veis,

 e depois, atrav�s de ponteiros, trocar os seus valores,
substituindo todos os n�meros inteiros pelo n�mero 2014, os decimais por 9.99,
e as letras por �Y�. Depois da substitui��o, o programa dever� exibir o valor das
vari�veis j� devidamente atualizados. */


int main(){
	setlocale(LC_ALL,"");
	int i, num[3];
	float dec[3];
	char let[3];
	
	for (i=0; i<3; i++){
		printf("%i� num: ", i+1);
		scanf("%i", &num[i]);
	}
	for (i=0; i<3; i++){
		printf("%i� dec: ", i+1);
		scanf("%f", &dec[i]);
	}
	for (i=0; i<3; i++){
		printf("%i� let: ", i+1);
		scanf(" %c", &let[i]);
	}
	
	printf("\nInteiros: ");
	for (i=0; i<3; i++){
		printf("%i; ", num[i]);
	}
	printf("\nDec: ");
	for (i=0; i<3; i++){
		printf("%.1f; ", dec[i]);
	}
	printf("\nLetras: ");
	for (i=0; i<3; i++){
		printf("%c; ", let[i]);
	}
	
	return 0;
}
