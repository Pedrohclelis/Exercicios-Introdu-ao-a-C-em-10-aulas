#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// 85) Faça um algoritmo para ler e armazenar em um vetor a temperatura média de todos os dias do ano.
// Calcular e escrever:
//a) Menor temperatura do ano
//b) Maior temperatura do ano
//c) Temperatura média anual
//d) O número de dias no ano em que a temperatura foi inferior a média anual

int main(){
	setlocale(LC_ALL,"");
	int temperatura[365], maior, menor, i, frio=0;
	float media;
	
	for(i=0; i<365; i++){
		printf("Temp media do dia %i: ", i+1);
		scanf("%i", &temperatura[i]);
		media += temperatura[i];
	}
	
	// coletando dados
	media = media /365;
	for (i=0; i<365; i++){
		if (i==0){
			maior = menor = temperatura[0];
		} else{
			if (temperatura[i] > maior){
				maior = temperatura[i];
			} else if (temperatura[i] < menor){
				menor = temperatura[i];
			}
		}
		if (temperatura[i] < media){
			frio++;
		}
	}
	
	printf("\nMenor temperatura do ano: %i°C\n", menor);
	printf("Maior temperatura do ano: %i°C\n", maior);
	printf("Temperatura média anual: %.1f\n", media);	
	printf("Número de dias no ano em que a temperatura foi inferior a média anual: %i", frio);	
		
	return 0;
}
