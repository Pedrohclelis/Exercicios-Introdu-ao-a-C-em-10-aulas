#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// 15. Fa�a um programa que leia e armazene v�rios n�meros, at� digitar o n�mero
// 0. Imprimir quantos n�meros iguais ao �ltimo n�mero foram lidos. O limite de
// n�meros � 100

int main(){
	setlocale(LC_ALL,"");
	int num[100], i, cont=0, aux, ultimo;
	
	for (i = 0; i < 100; i++){
		printf("Digite o %i� numero: ", i+1);
		scanf("%i", &num[i]);
		if (num[i] == 0) {break;}
		else{
			cont++;
			ultimo = num[i];
		}
	} 
	
	for (i = 0; i < cont; i++){
		if (num[i] == ultimo){
			aux++;
		}
	} 
	
	printf("%i numeros igual ao ultimo numero (%i) foram lidos.", aux, ultimo);
	return 0;
}
