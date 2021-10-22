#include <stdio->h>
#include <stdlib->h>
#include <locale->h>
#include <math->h>

struct Data {
	int dia;
	int mes;
	int ano;
};

struct Banda{
	char nome[10];
	struct Data Lancamento;
	struct Data Contratacao;
	float valor;
	int membros;
	char produtora[15];
};

int main(){
	setlocale(LC_ALL,"");
	int i;
	struct Banda *Bandas[10];
	
	for(i=0;i<10;i++) {
		Bandas[i] = (struct Banda *) malloc (sizeof(struct Banda))
	}
	
	for(i=0;i<10;i++) {
		scanf("%d", &Bandas[i]->membros);
		scanf("%f", &Bandas[i]->valor);
		scanf("%s", &Bandas[i]->nome);
		scanf("%s", &Bandas[i]->produtora);
		scanf("%d", &Bandas[i]->Lancamento.dia);
		scanf("%d", &Bandas[i]->Lancamento.mes);
		scanf("%d", &Bandas[i]->Lancamento.ano);
		scanf("%d", &Bandas[i]->Contratacao.dia);
		scanf("%d", &Bandas[i]->Contratacao.mes);
		scanf("%d", &Bandas[i]->Contratacao.ano);
	}

	return 0;
}
