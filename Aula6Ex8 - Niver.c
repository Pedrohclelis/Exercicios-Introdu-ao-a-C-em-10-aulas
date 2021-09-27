#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*  Crie uma estrutura capaz de armazenar o nome e a data de nascimento de uma
pessoa. Faça uso de estruturas aninhadas e definição de novo tipo de dado. Agora,
escreva um programa que leia os dados de seis pessoas. Calcule e exiba os nomes
da pessoa mais nova e da mais velha. */

struct dataNiver{
	int dia;
	int mes;
	int ano;
};

struct pessoa{
	char nome[30];
	struct dataNiver Data;
};

int main(){
	setlocale(LC_ALL,"");
	int i, iVelho, iNovo;
	struct pessoa Pessoa[6];
	struct dataNiver Velho, Novo;
	
	for (i=0; i<6; i++){
		printf("[%i] Nome: ", i+1);
		scanf("%s", &Pessoa[i].nome);
		printf("[%i] Dia: ", i+1);
		scanf("%i", &Pessoa[i].Data.dia);
		printf("[%i] Mes: ", i+1);
		scanf("%i", &Pessoa[i].Data.mes);
		printf("[%i] Ano: ", i+1);
		scanf("%i", &Pessoa[i].Data.ano);
		printf("\n");
	}
	
	//Mais jovem, nasceu dps, data maior
	for (i=0; i<6; i++){
		if (i==0){
			Novo.ano = Pessoa[i].Data.ano;
			Novo.mes = Pessoa[i].Data.mes;
			Novo.dia = Pessoa[i].Data.dia;
			iNovo = i;
		} else if(Pessoa[i].Data.ano > Novo.ano || (Pessoa[i].Data.ano == Novo.ano && Pessoa[i].Data.mes > Novo.mes) || 
		(Pessoa[i].Data.ano == Novo.ano && Pessoa[i].Data.mes == Novo.mes && Pessoa[i].Data.dia > Novo.dia)){
			Novo.ano = Pessoa[i].Data.ano;
			Novo.mes = Pessoa[i].Data.mes;
			Novo.dia = Pessoa[i].Data.dia;
			iNovo = i;
		}
	}
	
	//Mais velho
	for (i=0; i<6; i++){
		if (i==0){
			Velho.ano = Pessoa[i].Data.ano;
			Velho.mes = Pessoa[i].Data.mes;
			Velho.dia = Pessoa[i].Data.dia;
			iVelho = i;
		} else if(Pessoa[i].Data.ano < Velho.ano || (Pessoa[i].Data.ano == Velho.ano && Pessoa[i].Data.mes < Velho.mes) || 
		(Pessoa[i].Data.ano == Velho.ano && Pessoa[i].Data.mes == Velho.mes && Pessoa[i].Data.dia < Velho.dia)){
			Velho.ano = Pessoa[i].Data.ano;
			Velho.mes = Pessoa[i].Data.mes;
			Velho.dia = Pessoa[i].Data.dia;
			iVelho = i;
		}
	}

	//Print
	printf("---------Pessoa mais velha---------\n");
	printf("Nome........: %s \n", Pessoa[iVelho].nome);
	printf("Nascimento..: %d/%d/%d \n", Pessoa[iVelho].Data.dia, Pessoa[iVelho].Data.mes, Pessoa[iVelho].Data.ano);
	
	printf("---------Pessoa mais nova---------\n");
	printf("Nome........: %s \n", Pessoa[iNovo].nome);
	printf("Nascimento..: %d/%d/%d \n", Pessoa[iNovo].Data.dia, Pessoa[iNovo].Data.mes, Pessoa[iNovo].Data.ano);
}
