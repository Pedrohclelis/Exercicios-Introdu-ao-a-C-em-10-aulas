#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"");
	int cic, dependentes, isentos, desconto;
	float rendaBru, rendaLiq, imposto, impostoTotal;

	do {
		printf("CIC [0 para finalizar]: ");
		scanf("%i", &cic);
		if (cic == 0){break; }
		printf("Numero de dependentes: ");
		scanf("%i", &dependentes);	
		printf("Renda brutal : ");
		scanf("%f", &rendaBru);	
		rendaLiq = rendaBru - 600 * dependentes;
		
		if (rendaLiq <= 1000){
			imposto = 0;
			desconto = 0;
			isentos++;
		} else if (rendaLiq <= 5000){
			imposto = 0.15 * rendaLiq;
			desconto = 15;
		} else{
			imposto = 0.25 * rendaLiq;
			desconto = 25;
		}
		
		impostoTotal += imposto;
		printf(">>> CIC: %i; %i dependentes; Renda liquida de R$%.2f (Desconto de %i%%)\n", cic, dependentes, rendaLiq, desconto);
		printf(">>> Imposto: R$%.2f\n\n", imposto);	
	} while(1);
	
	printf("Programa finalizado, calculando dados...\n\n");
	printf("Total de imposto arrecadado: R$%.2f", impostoTotal);
	printf("Isentos: %i\n", isentos);
	return 0;
}
