#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// 13. Construa um programa que realize as reservas de passagens áreas de uma companhia. O programa deve permitir cadastrar o número de 10 voos e definir a
//quantidade de lugares disponíveis para cada um. Após o cadastro, leia vários
//pedidos de reserva, constituídos do número da carteira de identidade do cliente e
//do número do voo desejado. Para cada cliente, verificar se há possibilidade no
//voo desejado. Em caso afirmativo, imprimir o número da identidade do cliente e
//o número do voo, atualizando o número de lugares disponíveis. Caso contrário,
//avisar ao cliente a inexistência de lugares. A leitura do número 0 (zero) para o voo
//desejado indica o término da leitura de reservas

int main(){
	setlocale(LC_ALL,"");
	int voo[10], i, id;
	
	//Cadastrar 10 voos
	for (i = 0; i < 10; i++){
		printf("Cadastro do %iº voo. Quantidade de lugares: ", i+1);
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
				printf("Ainda tem disponibilidade de %i lugares no %i° voo\n", voo[i-1], i);
				voo[i-1]--;
				printf("Cadastro feito para o cliente de matricula %i no voo de numero %i. Restando %i lugares restantes\n", id, i, voo[i-1]);
			} else{
				printf("Nao há disponibilidade no %i° voo\n", i);
			}
		}
	} while(id != 0);
	
		
	return 0;
}
