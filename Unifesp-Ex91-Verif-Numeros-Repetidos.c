#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 10

// 91) Faça um algoritmo para ler 10 números e armazenar em um vetor VET, verificar e escrever se
// existem números repetidos no vetor VET e em que posições se encontram.

int main(){
	setlocale(LC_ALL,"");
	int vet[MAX], i, j, cont=0, aux=0;
	
	// Ler e armazenar
	for (i=0; i<MAX; i++){
		printf("vet[%i] = ", i);
		scanf("%i", &vet[i]);
	}
	
	// Verificar e escrever repetidos
	for (i=0; i<MAX; i++){
		for (j=0; j<MAX; j++){
			if (vet[i] == vet[j] && i!=j){
				if (i>j) {break; }
				printf(">>> O numero %i (de primeira ocorrencia em vet[%i]) se repete em vet[%i]. \n", vet[i], i, j);
				cont++;
				aux++;
			}
		}
		if (aux>0) {printf("\n"); }
		aux = 0;
	}
	
	// Conclusao
	if (cont == 0){
		printf("Nenhum valor se repete!");
	} else{
		printf("No total, há %i valores repetidos.", cont);
	}
	
	return 0;
}
