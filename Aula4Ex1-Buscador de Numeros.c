#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Aula 4. 1-Fa�a um programa em C que armazene 15 n�meros inteiros em um vetor e depois
//permita que o usu�rio digite um n�mero inteiro para ser buscado no vetor, se
//for encontrado o programa deve imprimir a posi��o desse n�mero no vetor, caso
//contr�rio, deve imprimir a mensagem: "Nao encontrado!"

int main(){
	setlocale(LC_ALL,"");
	int i, busca, encontrado, cont=0, num[15];
	
	for(i=0; i<15; i++){
		printf("Digite o %i� numero: ", i+1);
		scanf("%i", &num[i]);
	}
	
	do{
		printf("\nBuscar o numero [999 para parar]: ");
		scanf("%i", &busca);
		if (busca == 999) {break;}
		for(i=0; i<15; i++){
				if (busca == num[i]){
					encontrado = 1;
					cont++;
				}
		}
		if (encontrado == 1){
			printf("O numero [%i] foi encontrado! E ele aparece %i vez(es) na lista.\n", busca, cont);
		}
		else{
			printf("O numero [%i] N�O foi encontrado!\n", busca);	
		} encontrado = cont = 0;
	} while(1);
	return 0;
}
