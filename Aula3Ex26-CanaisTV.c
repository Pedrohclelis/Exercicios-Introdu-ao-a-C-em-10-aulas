#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Aula 3; 26. Foi feita uma pesquisa de audi�ncia de canal de TV em v�rias casas de uma
//certa cidade, em um determinado dia. Para cada casa visitada foram fornecidos o
//n�mero do canal (4, 5, 7, 12) e o n�mero de pessoas que estavam assistindo a ele
//naquela casa. Se a televis�o estivesse desligada, nada seria anotado, ou seja, esta
//casa n�o entraria na pesquisa. Criar um programa que:
//� Leia um n�mero indeterminado de dados, isto �, o n�mero do canal e o
//n�mero de pessoas que estavam assistindo;
//� Calcule e imprima a porcentagem de audi�ncia em cada canal.
//Obs.: Para encerrar a entrada de dados, digite o n�mero do canal zero

int main(){
	setlocale(LC_ALL,"");
	int canal, a4=0, a5=0, a7=0, a12=0, aTotal=0;
	float p4, p5, p7, p12;
	
	do{
		printf("Numero do canal [4, 5, 7 ou 12. Para parar digite 0]: ");
		scanf("%i", &canal);
		if (canal == 0) {break; }
		aTotal++;
		switch(canal){
		case 4:
			a4++;
			printf("Canal %i escolhido com sucesso!\n\n", canal);
			break;
		case 5:
			a5++;
			printf("Canal %i escolhido com sucesso!\n\n", canal); 	
			break;
		case 7:
			a7++;
			printf("Canal %i escolhido com sucesso!\n\n", canal); 	
			break;
		case 12:
			a12++;
			printf("Canal %i escolhido com sucesso!\n\n", canal); 	
			break;
		default:
			printf("Canal inv�lido!\n\n");
		}
	} while(canal != 0);

		if (aTotal ==0) {aTotal = 1; }
		p4 = a4*100/aTotal;
		p5 = a5*100/aTotal;
		p7 = a7*100/aTotal;
		p12 = a12*100/aTotal;
		
	
	printf("\nPrograma encerrado, calculando dados...\n");
	printf("Total de entrevistados: %i\n", aTotal);
	printf("Porcentagem de audiencia do canal 4: %.1f%%\n", p4);
	printf("Porcentagem de audiencia do canal 5: %.1f%%\n", p5);
	printf("Porcentagem de audiencia do canal 7: %.1f%%\n", p7);
	printf("Porcentagem de audiencia do canal 12: %.1f%%\n", p12);
	
	return 0;
}
