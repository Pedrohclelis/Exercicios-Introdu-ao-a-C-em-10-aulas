#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int NumCad = 0;

struct Cad{
	char placa[6];
	char marca[15];
	char modelo[25];
	char ar;
	int anoFab;
	int quilometragem;
	int numeroPortas;
};

void alterarCad2(){
	
}

void inserirCad1(){
	FILE* f;
	f = fopen("carros.txt", "a");
	if (f == NULL){
		printf("Error");
		exit(1);
	}
	
	struct Cad *CadNo[NumCad];
	CadNo[NumCad] = (struct Cad *) malloc(sizeof(struct Cad));
	
	//Input pessoa pro pc
	printf("=======> Inserir novo cadastro de veículo [Cod: %i] <=======\n\n", NumCad);
	printf("Insira sua placa: ");
	scanf("%s", CadNo[NumCad]->placa);
	printf("Insira sua marca: ");
	scanf("%s", CadNo[NumCad]->marca);
	printf("Insira seu modelo: ");
	scanf("%s", CadNo[NumCad]->modelo);
	printf("Tem ar-condicionado? [S/N] ");
	scanf(" %c", &CadNo[NumCad]->ar);
	printf("Ano de Fabricaçao: ");
	scanf("%i", &CadNo[NumCad]->anoFab);
	printf("Quilometragem: ");
	scanf("%i", &CadNo[NumCad]->quilometragem);
	printf("Número de portas: ");
	scanf("%i", &CadNo[NumCad]->numeroPortas);
	
	//Passagem pc pro arquivos
	fprintf(f, ">>> Cad numero %i\n", NumCad);
	fprintf(f, "Placa: %s\n", CadNo[NumCad]->placa);
	fprintf(f, "Marca: %s\n", CadNo[NumCad]->marca);
	fprintf(f, "Modelo: %s\n", CadNo[NumCad]->modelo);
	fprintf(f, "Ar Condicionado: %c\n", CadNo[NumCad]->ar);
	fprintf(f, "Ano de Fabricaçao: %i\n", CadNo[NumCad]->anoFab);
	fprintf(f, "Quilometragem: %i\n", CadNo[NumCad]->quilometragem);
	fprintf(f, "Número de portas: %i\n\n", CadNo[NumCad]->numeroPortas);
	fclose(f);
	
	system("clear||cls");
	printf("> Cadastro nº%i finalizado! Retornando ao menu inicial...\n\n", NumCad);
	printf("%i", sizeof(CadNo[0]));
	NumCad++;
}

void apagaReg4(){
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

void mostrarDados3(){
	char placa[6];
	int i;
	
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
			
			printf("\n");
			fclose(f);
			return;
		}
	}	
	
	printf("> Não foi possivel encontrar a placa '%s'. Voltando ao menu...\n", placa);
	printf("\n");
	fclose(f);
	return;
}

int main(){
	setlocale(LC_ALL,"");
	int cmd;
	
	//struct Cad *CadNo[NumCad];
	//CadNo[NumCad] = (struct Cad *) malloc(sizeof(struct Cad));
	
	struct Cad * CadNo = (struct Cad *)malloc(sizeof(struct Cad));
	
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
				printf("--- Alterar cadastro ---\n");
				break;
			case 3:
				system("clear||cls");
				mostrarDados3();
				break;
			case 4:
				apagaReg4();
				break;
			case 5:
				printf("Saindo...\n");
				break;
			default:
				//system("clear||cls");
				printf("> ERRO: digite uma opçao valida!\n\n");
				break;
		}
	} while (cmd!=5);
	
	return 0;
}




