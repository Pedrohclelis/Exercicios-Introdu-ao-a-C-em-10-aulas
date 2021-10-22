#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
Pedro Henrique Cometti Lelis
RA 156.341
Exercício 1 - Registro e Arquivos (peso 1)
*/

struct Cad{
	char placa[6];
	char marca[15];
	char modelo[25];
	char ar;
	int anoFab;
	int quilometragem;
	int numeroPortas;
};

struct Cad *CadNo[100];
int cont = 0;

void inserirCad1(){
	setlocale(LC_ALL,"");
    
	FILE* f;
	f = fopen("carros.txt", "a");
	if (f == NULL){
		printf("Error");
		exit(1);
	}
	
	//Alocando memoria pra cada CadNo que surgir
	CadNo[cont] = (struct Cad *) malloc(sizeof(struct Cad));
	
	//Input pessoa pro pc
	printf("=======> Inserir novo cadastro de veículo <=======\n\n");
	printf("Insira sua placa: ");
	scanf("%s", CadNo[cont]->placa);
	printf("Insira sua marca: ");
	scanf("%s", CadNo[cont]->marca);
	printf("Insira seu modelo: ");
	scanf("%s", CadNo[cont]->modelo);
	printf("Tem ar-condicionado? [S/N] ");
	scanf(" %c", &CadNo[cont]->ar);
	printf("Ano de Fabricaçao: ");
	scanf("%i", &CadNo[cont]->anoFab);
	printf("Quilometragem: ");
	scanf("%i", &CadNo[cont]->quilometragem);
	printf("Número de portas: ");
	scanf("%i", &CadNo[cont]->numeroPortas);
	
	//Passagem pc pro arquivos
	fprintf(f, ">>> Cad numero %i\n", cont);
	fprintf(f, "Placa: %s\n", CadNo[cont]->placa);
	fprintf(f, "Marca: %s\n", CadNo[cont]->marca);
	fprintf(f, "Modelo: %s\n", CadNo[cont]->modelo);
	fprintf(f, "Ar Condicionado: %c\n", CadNo[cont]->ar);
	fprintf(f, "Ano de Fabricaçao: %i\n", CadNo[cont]->anoFab);
	fprintf(f, "Quilometragem: %i\n", CadNo[cont]->quilometragem);
	fprintf(f, "Número de portas: %i\n\n", CadNo[cont]->numeroPortas);
	fclose(f);
	
	//Finalizando
	system("clear||cls");
	printf("> Cadastro nº%i finalizado! Retornando ao menu inicial...\n\n", cont);
	cont++;
}

void alterarCad2(){
	printf("Funçao indisponivel");
	//Ainda tem que fazer
}

void mostrarDados3(){
	setlocale(LC_ALL,"");
	char placa[6];
	int i;
	
	printf("=======> Mostrar os dados de um veículo <=======\n\n");
	printf("Insira sua placa: ");
	scanf("%s", placa);
	
	FILE* f;
	f = fopen("carros.txt", "r");
	if (f == NULL){
		printf("ERRO");
		exit(1);
	}
	
	char data[256];
	while (fgets(data, sizeof(data), f) != NULL){
		if (strstr(data, placa) != NULL){
			printf("> Placa '%s' encontrada, seus dados são: \n\n", placa);
			
			for (i=0; i<7; i++){
				printf("%s", data);
				fgets(data, sizeof(data), f);
				
			}
			
			printf("\n\n");
			fclose(f);
			return;
		}
	}	
	
	printf("> Não foi possivel encontrar a placa '%s'. Voltando ao menu...\n", placa);
	printf("\n");
	fclose(f);
	return;
}

void apagaReg4(){
	setlocale(LC_ALL,"");
	char placa[6];
	char data[256];
	int i;
	
	printf("Insira sua placa: ");
	scanf("%s", placa);
	
	//Abrindo arquivo 
	FILE* f;
	f = fopen("carros.txt", "r");
	if (f == NULL){
		printf("ERRO");
		exit(1);
	}
	//Criando arquivo temp
	FILE* ft;
	ft = fopen("carrosTemp.txt", "w");
	if (ft == NULL){
		printf("ERRO 2");
		exit(2);
	}
	
	//Localizando referencia da placa
	int linha=1, lp=0;
	while (fgets(data, sizeof(data), f) != NULL){
		if (strstr(data, placa) != NULL){
			lp = linha;
			break;
		}
		linha++;
	}
	//Caso nao ache a placa
	if (lp == 0){
		printf("Não foi possivel encontrar a placa '%s'. Voltando ao menu...\n", placa);
		printf("\n");
		return;
	} else{
		printf("> Placa '%s' encontrada e apagada com sucesso!\n\n", placa);
	}
	
	//Reescrever no temp arq
	rewind(f);
	linha = 1;
	while (fgets(data, sizeof(data), f) != NULL){
		if (linha != lp-1 && linha != lp && linha != lp+1 && linha != lp+2 && linha != lp+3 && linha != lp+4 && linha != lp+5 && linha != lp+6 && linha != lp+7){
			fprintf(ft, "%s", data);
		}
		linha++;
	}
	
	//Transformar o temp em original
	fclose(f);
	fclose(ft);
	remove("carros.txt");
	rename("carrosTemp.txt", "carros.txt");
	
	return;
}

int main(){
	setlocale(LC_ALL,"");
	int cmd;
	
	do{
		printf("===========> PROGRAMA DE CADASTRAR CARROS AED UNIFESP <===========\n\n");
		printf("1) Inserir novo cadastro de veículo\n");
		printf("2) Alterar cadastro\n");
		printf("3) Mostrar os dados de um veículo\n");
		printf("4) Apagar registro\n");
		printf("5) Sair\n\n");
		printf(">>> Sua resposta: ");
		scanf("%i", &cmd);

		switch (cmd){
			case 1:
				system("clear||cls");
				inserirCad1();
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
	
	return 0;
}

