#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Fa�a um programa que leia um vetor vet de 10 elementos e obtenha um vetor 
// cujos componentes s�o os fatoriais dos respectivos componentes de vet

int fatorial(int num){
	int i, resp=1;
	if (num < 0){
		resp = 0;
	} else{
		for(i=1; i<=num; i++){
		resp *= i;
		}
	} return resp;
	
}

int main(){
	setlocale(LC_ALL,"");
	int num[10], numFat[10], i;
	
	//lendo num
	for(i=0; i<10; i++){
		printf("Digite o %i� numero: ", i+1);
		scanf("%i", &num[i]);
	}
	
	//vetor fat
	for(i=0; i<10; i++){
		numFat[i] = fatorial(num[i]);
	}	
	
	//prova real
	printf("\n");
	for(i=0; i<10; i++){
		printf("%i! = %i\n", num[i], numFat[i]);
	}	
	
	
		
	return 0;
}
