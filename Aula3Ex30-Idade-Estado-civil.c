#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//30. Faça um programa que receba a idade e o estado civil (C-casado, S-solteiro, Vviúvo e D-desquitado ou separado) de várias pessoas. Calcule e imprima:
//• a quantidade de pessoas casadas;
//• a quantidade de pessoas solteiras;
//• a média das idades das pessoas viúvas;
//• a porcentagem de pessoas desquitadas ou separadas dentre todas as pessoas
//analisadas.
//Obs.: Para encerrar a entrada de dados, digite um número menor ou igual a zero para a idade

int main(){
	setlocale(LC_ALL,"");
	int idade=0, idadeTotal=0, nc=0, ns=0, nv=0, iv=0, nd=0, nt=0;
	char ec;
	
	do {
		printf("Idade [idade =< 0 para encerrar a entrada de dados]: ");
		scanf("%i", &idade);
		if (idade<=0) {break;}
		idadeTotal++;
		
		printf("Estado civil [C-casado, S-solteiro, V-viúvo e D-desquitado ou separado]: ");
		scanf(" %c", &ec);
		if (ec == 'c' || ec == 'C'){
			nc++;
		}
		else if (ec == 's' || ec == 'S'){
			ns++;
		}		
		else if (ec == 'v' || ec == 'V'){
			iv += idade;
			nv++;
		}		
		else if (ec == 'd' || ec == 'D'){
			nd++;
		}				
		printf("Contabilizado!\n\n");
	} while (idade>0);
	
	if (idadeTotal == 0) {idadeTotal = 1;}
	if (nv == 0) {nv = 1;}	
	
	printf("\nEntrada de dados encerrada, calculando resultados...\n");
	printf("Há %i pessoas casadas\n", nc);
	printf("E também %i pessoas solteiras\n", ns);
	printf("Além disso, a media das idades dos viúvos é %.1f\n", ((float)iv/nv));
	printf("E por fim %.1f%% é a porcentagem de pessoas desquitadas ou separadas dentre todas as pessoas\n", (float)(nd*100/idadeTotal));		
	return 0;
}
