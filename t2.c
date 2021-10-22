#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*
Pedro Henrique Cometti Lelis
RA 156341
*/

typedef struct{
	char nomeProduto[30];
	int quantidadeVendida;
	char quemComprou[30];
	int mesVenda;
} Dados;


int main(){
	setlocale(LC_ALL,"");
	int cmd, *dado, tam;
	
	printf("Digite o tamanho do vetor de struct:");
	scanf("%i", tam);
	
	Dados dado
	
	
	
	
	
	//Alocando, para o ponteiro 'dado', o tamanho de memoria suficiente para uma struct 'Dados' de tamanho 'tam'
	Dados dado;
	dado = (Dados *) malloc (tam * sizeof(Dados)); //Semelhante a fazer "Dados v[tam];" 
	if (dado = NULL){
		printf("Nao foi possivel alocar o vetor");
		exit(1);
	}
	
	//Menu inicial
	do{
		printf("===========> PROGRAMA DE CADASTRAR CARROS AED UNIFESP <===========\n\n");
		printf("1) Total de vendas num dado mês (de todos os produtos)\n");
		printf("2) Total de vendas de um determinado produto num dado mês para um determinado cliente (qual produto, para quem e em que mês)\n");
		printf("3) Total de vendas de cada produto (em todos os meses)\n");
		printf("4) Total vendido para cada cliente\n");
		printf("5) Sair\n\n");
		printf(">>> Sua resposta: ");
		scanf("%i", &cmd);

		switch (cmd){
			case 1:
				system("clear||cls");
				totalVendas(dado);
				break;
			case 2:
				system("clear||cls");
				alterarCad2();
				break;
			case 3:
				system("clear||cls");
				mostrarDados3();
				break;
			case 4:
				system("clear||cls");
				apagaReg4();
				break;
			case 5:
				printf("Saindo...\n");
				break;
			default:
				system("clear||cls");
				printf("> ERRO: %i nao é uma opçao valida!\n\n", cmd);
				break;
		}
	} while (cmd!=5);
	
	free(dado);
	return 0;
}

int totalVendas(Dados D){
	int i, total=0, mes;
	
	printf("Mes:");
	scanf("%i", &mes);
	
	for(i=0; i<sizeof(Dados); i++){
		if (D[i].mesVenda == mes){
			total += D[i].mesVenda;
		}
	}



}

