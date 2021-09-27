#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define max 6

/*  9. A Google está desenvolvendo um novo sistema operacional para máquinas de
venda de bolinhas de borracha de R$1,00, mas precisa realizar testes no Gerenciador de Memória desse novo sistema. Você foi contratado para fazer um
programa para verificar se o gerenciador de memória está funcionando corretamente. Seu programa deverá ler 3 números inteiros, 3 números decimais, 3 letras,
armazená-las em variáveis,

 e depois, através de ponteiros, trocar os seus valores,
substituindo todos os números inteiros pelo número 2014, os decimais por 9.99,
e as letras por ’Y’. Depois da substituição, o programa deverá exibir o valor das
variáveis já devidamente atualizados. */


int main(){
	setlocale(LC_ALL,"");
	int i, num[3];
	float dec[3];
	char let[3];
	
	for (i=0; i<3; i++){
		printf("%iº num: ", i+1);
		scanf("%i", &num[i]);
	}
	for (i=0; i<3; i++){
		printf("%iº dec: ", i+1);
		scanf("%f", &dec[i]);
	}
	for (i=0; i<3; i++){
		printf("%iº let: ", i+1);
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
