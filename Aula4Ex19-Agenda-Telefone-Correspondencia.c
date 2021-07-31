#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define max 30

// 19. Suponha dois vetores de 30 elementos cada, contendo: código e telefone. Faça
// um programa que permita buscar pelo código e imprimir o telefone.

int main(){
	setlocale(LC_ALL,"");
	int cod[max], tel[max], i, buscar, encontrado=0;
	
	// Armazenar 
	for (i=0; i<max; i++){
		printf("Digite o %iº codigo: ", i+1);
		scanf("%i", &cod[i]);
		printf("%iº Telefone: ", i+1);
		scanf("%i", &tel[i]);
	}
	
	// Buscar
	do {
		printf("\nDigite o codigo do telefone que vc deseja buscar (0 parar encerrar): ");
		scanf("%i", &buscar);
		
		if (buscar == 0) {break; }

		// Percorrer a lista de codigo
		for (i=0; i<max; i++){
			if (buscar == cod[i]) {
				// Achado o codigo, acha-se o i, e por fim o telefone relativo ao i do codigo
				printf(">>> Encontrado! O telefone referente ao codigo %i é: %i\n", buscar, tel[i]);
				encontrado++;
				break;
			}
		}
		
		// Caso nao tenha encontrado nenhum codigo no loop for
		if (encontrado == 0){
			printf(">>> Codigo %i NÃO encontrado! Digite novamente...\n", buscar);
		}
		
		encontrado = 0;
		
	} while (buscar != 0);
	
	return 0;
}
