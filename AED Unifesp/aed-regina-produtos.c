#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/*
Pedro Henrique Cometti Lelis
RA 156.341
Exercicio 2
*/

struct dados{
	char nomeProduto[30];
	int quantidadeVendida;
	char comprador[30];
	int mesVenda;
};
typedef struct dados Dados;
 

int main(){
	setlocale(LC_ALL, "Portuguese");
	int cmd, tam, i, j, total, mes, mesok, x, jaLido;
	char nome[30], produto[30];
	char tamS[10], cmdS[10], mesS[10];
	
	printf("===========> CADASTRAR PRODUTOS <===========\n\n");
	printf("Digite a quantidade de cadastros desejada: ");
	scanf("%s", tamS);
	//Verificaç�o para passar somente nmeros no 'tam'
	while (atoi(tamS) == 0){
		printf("ERRO: '%s' n�o � um n�mero valido. Digite a quantidade de cadastros desejada: ", tamS);
		scanf("%s", tamS);
	}
	tam = atoi(tamS);
	
	//Definindo um ponteiro '*dado' para a struct. Alocando a memoria necessaria pra o ponteiro '*Dado' guardar um tamanho 'tam' de structs 'Dados'. Agindo como um vetor.
	Dados *Dado;
	Dado = (Dados *) malloc (tam * sizeof(Dados));	
	
	//Cadastrando produtos (TORNAR OS DADOS JA PRONTOS COMO COMENTARIO PRA USAR!)
	/*for (i=0; i<tam; i++){
		printf("[%i] Nome do produto: ", i+1);
		scanf("%s", &Dado[i].nomeProduto);
		printf("[%i] Quantidade vendida: ", i+1);
		scanf("%i", &Dado[i].quantidadeVendida);
		printf("[%i] Comprador: ", i+1);
		scanf("%s", &Dado[i].comprador);
		printf("[%i] M�s da venda: ", i+1);
		scanf("%i", &Dado[i].mesVenda);
		printf("\n");
	}*/
	
	//DADOS JA PRONTOS PARA TESTE (TORNAR O FOR ACIMA COMO COMENTARIO!)
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
	strcpy(Dado[6].nomeProduto, "Peixe");
	Dado[6].quantidadeVendida = 8;
	strcpy(Dado[6].comprador, "Paulo");
	Dado[6].mesVenda = 3;
	strcpy(Dado[7].nomeProduto, "Cana");
	Dado[7].quantidadeVendida = 7;
	strcpy(Dado[7].comprador, "Jano");
	Dado[7].mesVenda = 7;
	strcpy(Dado[8].nomeProduto, "Cana");
	Dado[8].quantidadeVendida = 8;
	strcpy(Dado[8].comprador, "Caio");
	Dado[8].mesVenda = 8;
	strcpy(Dado[9].nomeProduto, "Cafe");
	Dado[9].quantidadeVendida = 3;
	strcpy(Dado[9].comprador, "Luis");
	Dado[9].mesVenda = 9;
	strcpy(Dado[10].nomeProduto, "Cafe");
	Dado[10].quantidadeVendida = 12;
	strcpy(Dado[10].comprador, "Felipe");
	Dado[10].mesVenda = 2;
	strcpy(Dado[11].nomeProduto, "Peixe");
	Dado[11].quantidadeVendida = 3;
	strcpy(Dado[11].comprador, "Felipe");
	Dado[11].mesVenda = 2;
	
	
	system("clear||cls");
	

	//Menu inicial
	do{
		printf("===================> MENU INICIAL <===================\n\n");
		printf("1) Total de vendas num dado m�s (de todos os produtos)\n");
		printf("2) Total de vendas de um determinado produto num dado m�s para um determinado cliente (qual produto, para quem e em que m�s)\n");
		printf("3) Total de vendas de cada produto (em todos os meses)\n");
		printf("4) Total vendido para cada cliente\n");
		printf("5) Sair\n\n");
		printf(">>> Sua resposta: ");
		scanf("%s", cmdS);
		//Verifica��o para passar somente n�meros no 'cmd'
		while (atoi(cmdS) == 0){
			printf("ERRO: '%s' n�o � um numeral valido.\n", cmdS);
			printf(">>> Sua resposta: ");
			scanf("%s", cmdS);
		}
		cmd = atoi(cmdS);

		switch (cmd){
			case 1:
				system("clear||cls");
				total = 0;
				
				//Algoritmo pra pegar o mes das compras. Validando somente n�meros inteiros, e que sejam entre 1 a 12
				printf("===========> BUSCA POR M�S <===========\n\n");
				mesok=0;
				do{
					printf("M�s: ");
					scanf("%s", mesS);
					while (atoi(mesS) == 0){
						printf("ERRO: '%s' n�o � um n�mero valido.\n", mesS);
						printf("M�s: ");
						scanf("%s", mesS);
					}
					mes = atoi(mesS);
					switch (mes){
						case 1 ... 12:
						mesok = 1;
						break;
					default:
						printf("ERRO: '%i' n�o � um m�s valido! Digite um m�s entre 1 e 12.\n", mes);
						break;
					}
				} while(mesok == 0);
				
				//Verifica cada 'Dado' 
				printf("\nM�s \t Qtde \t Produto \t Comprador\n");
				for(i=0; i<tam; i++){
					if (Dado[i].mesVenda == mes){
						printf("%i \t %i \t %s \t\t %s\n", Dado[i].mesVenda, Dado[i].quantidadeVendida, Dado[i].nomeProduto, Dado[i].comprador);
						total += Dado[i].quantidadeVendida;
					}
				}
				
				//Resultados
				printf("------------------------------------------\n");
				printf("> Total de vendas no %i� m�s: %i\n\n", mes, total);
				
				break;
			case 2:
				system("clear||cls");
				total = 0;
				
				//Pega os dados
				printf("===========> BUSCA POR PRODUTO, M�S, E COMPRADOR <===========\n\n");
				printf("Nome do produto: ");
				scanf("%s", produto);
				
				//Algoritmo pra pegar o mes das compras. Validando somente n�meros inteiros, e que sejam entre 1 a 12
				mesok=0;
				do{
					printf("M�s: ");
					scanf("%s", mesS);
					while (atoi(mesS) == 0){
						printf("ERRO: '%s' n�o � um n�mero valido.\n", mesS);
						printf("M�s: ");
						scanf("%s", mesS);
					}
					mes = atoi(mesS);
					switch (mes){
						case 1 ... 12:
						mesok = 1;
						break;
					default:
						printf("ERRO: '%i' n�o � um m�s valido! Digite um m�s entre 1 e 12.\n", mes);
						break;
					}
				} while(mesok == 0);

				printf("Nome do cliente comprador: ");
				scanf("%s", nome);
				
				printf("\nM�s \t Qtde \t Produto \t Comprador\n");
				for(i=0; i<tam; i++){
					if (Dado[i].mesVenda == mes && strcmp(Dado[i].nomeProduto, produto) == 0 && strcmp(Dado[i].comprador, nome) == 0){
						printf("%i \t %i \t %s \t\t %s\n", Dado[i].mesVenda, Dado[i].quantidadeVendida, Dado[i].nomeProduto, Dado[i].comprador);
						total += Dado[i].quantidadeVendida;
					}
				}
				
				//Resultados
				printf("------------------------------------------\n");
				printf("> Total de vendas do produto '%s' no %i� m�s para o cliente '%s': %i\n\n", produto, mes, nome, total);
				
				break;
			case 3:
				system("clear||cls");
				printf("===========> TOTAL DE VENDAS DE CADA PRODUTO <===========\n");
				
				//Loop lendo produto em produto
				for(i=0; i<tam; i++){
					
					//Verificar, nos anteriores da ordem por meio de [x], se ja foi lido algum outro produto com o mesmo nome do produto[i] requerido
					jaLido = 0;
					for (x=0; x<i; x++){
						if (strcmp(Dado[i].nomeProduto, Dado[x].nomeProduto) == 0){
							//printf("\n-------fudeu abaixo--------");
							jaLido = 1;
							break;
						}
					}
					
					//Se ja foi lido, entao pula a vez do for produto-a-produto para o proximo
					if (jaLido == 1){
						continue;
					}
					
					//Caso contrario, imprima a tabela de vendas do produto[i] e calcule seu total
					total = 0;
					printf("\n========== %s ==========\n", Dado[i].nomeProduto);
					printf("M�s \t Qtde \t Comprador \n");
					
					//Le os dados[j] em busca dos quais o produto � o produto[i] ordenado, para imprimi-los 
					for(j=0; j<tam; j++){
						if (strcmp(Dado[j].nomeProduto, Dado[i].nomeProduto) == 0){
							printf("%i \t %i \t %s \n", Dado[j].mesVenda, Dado[j].quantidadeVendida, Dado[j].comprador);
							total += Dado[j].quantidadeVendida;
						}
					}
					printf("> Total: %i\n", total);
				}
				
				printf("\n");
				break;
			case 4:
				system("clear||cls");
				printf("===========> TOTAL DE VENDAS PARA CADA CLIENTE <===========\n");
				
				//Loop lendo cliente em cliente
				for(i=0; i<tam; i++){
					//Verificar, nos anteriores da ordem por meio de [x], se ja foi lido algum outro cliente com o mesmo nome do cliente[i] requerido
					jaLido = 0;
					for (x=0; x<i; x++){
						if (strcmp(Dado[i].comprador, Dado[x].comprador) == 0){
							//printf("\n-------fudeu abaixo--------");
							jaLido = 1;
							break;
						}
					}
					
					//Se ja foi lido, entao pula a vez do for cliente-a-cliente para o proximo
					if (jaLido == 1){
						continue;
					}
					
					//Caso contrario, imprima a tabela de compras do cliente[i] e calcule seu total
					total = 0;
					printf("\n========= %s =========\n", Dado[i].comprador);
					printf("M�s \t Qtde \t Produto \n");
					
					//Le os dados[j] em busca dos quais o cliente � o cliente[i] ordenado, para imprimi-los 
					for(j=0; j<tam; j++){
						if (strcmp(Dado[j].comprador, Dado[i].comprador) == 0){
							printf("%i \t %i \t %s\n", Dado[j].mesVenda, Dado[j].quantidadeVendida, Dado[j].nomeProduto);
							total += Dado[j].quantidadeVendida;
						}
					}
					printf("> Total: %i\n", total);
				}
				
				printf("\n");
				break;
			case 5:
				printf("\n> ADEUS. VOLTE SEMPRE!");
				break;
			default:
				printf("ERRO: %i não é uma opção valida!\n\n", cmd);
				break;
		}
	} while (cmd!=5);
	
	free(Dado);
	return 0;
}

