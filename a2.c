#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
Pedro Henrique Cometti Lelis
RA 156341
*/

struct dados{
	char nomeProduto[30];
	int quantidadeVendida;
	char comprador[30];
	int mesVenda;
};
typedef struct dados Dados;


int main(){
	setlocale(LC_ALL,"");
	int cmd, tam, i, total, mes;
	char nome[30], produto[30];
	char tamS[10], cmdS[10];
	
	printf("===========> CADASTRAR PRODUTOS <===========\n\n");
	printf("Digite a quantidade de cadastros desejada: ");
	scanf("%s", tamS);
	//Verificação para passar somente numeros no 'tam'
	while (atoi(tamS) == 0){
		printf("ERRO: '%s' nao é um numero valido. Digite a quantidade de cadastros desejada: ", tamS);
		scanf("%s", tamS);
	}
	tam = atoi(tamS);
	
	//Definindo um ponteiro '*dado' para a struct. Alocando a memoria necessaria pra o ponteiro '*Dado' guardar um tamanho 'tam' de structs 'Dados'. Agindo como um vetor.
	Dados *Dado;
	Dado = (Dados *) malloc (tam * sizeof(Dados));	
	
	//Cadastrando produtos
	/*for (i=0; i<tam; i++){
		printf("[%i] Nome do produto: ", i+1);
		scanf("%s", &Dado[i].nomeProduto);
		printf("[%i] Quantidade vendida: ", i+1);
		scanf("%i", &Dado[i].quantidadeVendida);
		printf("[%i] Comprador: ", i+1);
		scanf("%s", &Dado[i].comprador);
		printf("[%i] Mês da venda: ", i+1);
		scanf("%i", &Dado[i].mesVenda);
		printf("\n");
	}*/
	
	//DADOS JA PRONTOS PARA TESTE (TORNAR O FOR ACIMA COMO COMENTARIO)
	strcpy(Dado[0].nomeProduto, "Cana");
	Dado[0].quantidadeVendida = 5;
	strcpy(Dado[0].comprador, "Cesar");
	Dado[0].mesVenda = 11;
	strcpy(Dado[1].nomeProduto, "Cana");
	Dado[1].quantidadeVendida = 2;
	strcpy(Dado[1].comprador, "Paulo");
	Dado[1].mesVenda = 11;
	strcpy(Dado[2].nomeProduto, "Peixe");
	Dado[2].quantidadeVendida = 10;
	strcpy(Dado[2].comprador, "Pedro");
	Dado[2].mesVenda = 11;
	strcpy(Dado[3].nomeProduto, "Bana");
	Dado[3].quantidadeVendida = 7;
	strcpy(Dado[3].comprador, "Jano");
	Dado[3].mesVenda = 11;
	strcpy(Dado[4].nomeProduto, "Trigo");
	Dado[4].quantidadeVendida = 6;
	strcpy(Dado[4].comprador, "Cesar");
	Dado[4].mesVenda = 11;
	strcpy(Dado[5].nomeProduto, "Cafe");
	Dado[5].quantidadeVendida = 3;
	strcpy(Dado[5].comprador, "Cesar");
	Dado[5].mesVenda = 7;
	

	//Menu inicial
	do{
		
		printf("===========> MENU INICIAL <===========\n\n");
		printf("1) Total de vendas num dado mês (de todos os produtos)\n");
		printf("2) Total de vendas de um determinado produto num dado mês para um determinado cliente (qual produto, para quem e em que mês)\n");
		printf("3) Total de vendas de cada produto (em todos os meses)\n");
		printf("4) Total vendido para cada cliente\n");
		printf("5) Sair\n\n");
		printf(">>> Sua resposta: ");
		scanf("%s", &cmdS);
		//Verificação para passar somente numeros no 'cmd'
		while (atoi(cmdS) == 0){
			printf("ERRO: '%s' nao é um numero valido.\n", cmdS);
			printf(">>> Sua resposta: ");
			scanf("%s", cmdS);
		}
		cmd = atoi(cmdS);

		switch (cmd){
			case 1:
				system("clear||cls");
				total = 0;
				
				//Pega o mes das compras
				printf("===========> BUSCA POR MÊS <===========\n\n");
				printf("Mês: ");
				scanf("%i", &mes);
				while (mes < 1 || mes > 12){
					printf("ERRO: '%i' nao é um mês valido! Digite um mês entre 1 e 12: ", mes);
					scanf("%i", &mes);
				}
				
				
				//Verifica cada 'Dado' 
				printf("\nMês \t Qtde \t Produto \t Comprador\n");
				for(i=0; i<tam; i++){
					if (Dado[i].mesVenda == mes){
						printf("%i \t %i \t %s \t\t %s\n", Dado[i].mesVenda, Dado[i].quantidadeVendida, Dado[i].nomeProduto, Dado[i].comprador);
						total += Dado[i].quantidadeVendida;
					}
				}
				
				//Resultados
				printf("------------------------------------------\n");
				printf("> Total de vendas no %iº mês: %i\n\n", mes, total);
				
				break;
			case 2:
				system("clear||cls");
				total = 0;
				
				//Pega os dados
				printf("===========> BUSCA POR PRODUTO, MES, E COMPRADOR <===========\n\n");
				printf("Nome do produto: ");
				scanf("%s", produto);
				printf("Mês: ");
				scanf("%i", &mes);
				while (mes < 1 || mes > 12){
					printf("ERRO: '%i' nao é um mês valido! Digite um mês entre 1 e 12: ", mes);
					scanf("%i", &mes);
				}
				printf("Nome do cliente comprador: ");
				scanf("%s", nome);
				
				printf("\nMês \t Qtde \t Produto \t Comprador\n");
				for(i=0; i<tam; i++){
					if (Dado[i].mesVenda == mes && strcmp(Dado[i].nomeProduto, produto) == 0 && strcmp(Dado[i].comprador, nome) == 0){
						printf("%i \t %i \t %s \t\t %s\n", Dado[i].mesVenda, Dado[i].quantidadeVendida, Dado[i].nomeProduto, Dado[i].comprador);
						total += Dado[i].quantidadeVendida;
					}
				}
				
				//Resultados
				printf("------------------------------------------\n");
				printf("> Total de vendas do produto '%s' no %iº mês para o cliente '%s': %i\n\n", produto, mes, nome, total);
				
				break;
			case 3:
				system("clear||cls");
				total = 0;
				
				//Pega o nome do produto
				printf("===========> BUSCA POR PRODUTO <===========\n\n");
				printf("Nome do produto: ");
				scanf("%s", &produto);
				
				//Verifica cada 'Dado' 
				printf("\nMês \t Qtde \t Produto \t Comprador\n");
				for (i=0; i<tam; i++){
					if(strcmp(Dado[i].nomeProduto, produto) == 0){
						printf("%i \t %i \t %s \t\t %s\n", Dado[i].mesVenda, Dado[i].quantidadeVendida, Dado[i].nomeProduto, Dado[i].comprador);
						total += Dado[i].quantidadeVendida;
					}
				}
				
				//Resultados
				printf("------------------------------------------\n");
				if (total == 0){
					printf("> Desculpe, nao há vendas cadastradas para o produto '%s'.\n\n", produto);
				} else{
					printf("> Total vendido acerca do produto '%s': %i\n\n", produto, total);
				}
				
				break;
			case 4:
				system("clear||cls");
				total = 0;
				
				//Pega o nome do comprador
				printf("===========> BUSCA POR COMPRADOR <===========\n\n");
				printf("Nome do cliente comprador: ");
				scanf("%s", nome);
				
				//Verifica cada 'Dado' 
				printf("\nMês \t Qtde \t Produto \t Comprador\n");
				for (i=0; i<tam; i++){
					if(strcmp(Dado[i].comprador, nome) == 0){
						printf("%i \t %i \t %s \t\t %s\n", Dado[i].mesVenda, Dado[i].quantidadeVendida, Dado[i].nomeProduto, Dado[i].comprador);
						total += Dado[i].quantidadeVendida;
					}
				}
				
				//Resultados
				printf("------------------------------------------\n");
				if (total == 0){
					printf("> Desculpe, nao há compras cadastradas para o cliente de nome '%s'.\n\n", nome);
				} else{
					printf("> Total vendido para o cliente '%s': %i\n\n", nome, total);
				}
				
				break;
			case 5:
				printf("\n> ADEUS. VOLTE SEMPRE!");
				break;
			default:
				system("clear||cls");
				printf("> ERRO: %i nao é uma opçao valida!\n\n", cmd);
				break;
		}
	} while (cmd!=5);
	
	free(Dado);
	return 0;
}

