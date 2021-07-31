#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// 13. Construa um programa que realize as reservas de passagens �reas de uma companhia. O programa deve permitir cadastrar o n�mero de 10 voos e definir a
//quantidade de lugares dispon�veis para cada um. Ap�s o cadastro, leia v�rios
//pedidos de reserva, constitu�dos do n�mero da carteira de identidade do cliente e
//do n�mero do voo desejado. Para cada cliente, verificar se h� possibilidade no
//voo desejado. Em caso afirmativo, imprimir o n�mero da identidade do cliente e
//o n�mero do voo, atualizando o n�mero de lugares dispon�veis. Caso contr�rio,
//avisar ao cliente a inexist�ncia de lugares. A leitura do n�mero 0 (zero) para o voo
//desejado indica o t�rmino da leitura de reservas

int main(){
	setlocale(LC_ALL,"");
	int voo[10], i, id;
	
	//Cadastrar 10 voos
	for (i = 0; i < 10; i++){
		printf("Cadastro do %i� voo. Quantidade de lugares: ", i+1);
		scanf("%i", &voo[i]);
	}
	
	//Ler varios pedidos de reserva
	do{
		printf("\nCarteira de identidade: ");
		scanf("%i", &id);
		printf("Numero do voo desejado [0 para cancelar]: ");
		scanf("%i", &i);
		if (i == 0){
			printf("Programa cancelado!");
			break;
		} else{
			if (voo[i-1] > 0){
				printf("Ainda tem disponibilidade de %i lugares no %i� voo\n", voo[i-1], i);
				voo[i-1]--;
				printf("Cadastro feito para o cliente de matricula %i no voo de numero %i. Restando %i lugares restantes\n", id, i, voo[i-1]);
			} else{
				printf("Nao h� disponibilidade no %i� voo\n", i);
			}
		}
	} while(id != 0);
	
		
	return 0;
}
