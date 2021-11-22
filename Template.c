#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define MAX_PILHA 100

typedef struct{
	int vet[MAX_PILHA];
	int topo;
} TPilha;


//Criando uma pilha
TPilha* nova(){
	TPilha* np = (TPilha *) malloc (sizeof(TPilha));
	np->topo = -1;
	return np;
}

//Empilhando dados na pilha
int push (TPilha* p, int val){
	//Pilha cheia
	if (p->topo>= MAX_PILHA - 1 ){
		return -1;
	}
	
	(p->topo)++;
	p->vet[p->topo] = val;
	return 0;	
}

//Desempilhando dados na Pilha
int pop (TPilha *p, int *val){
	//Pilha vazia
	if (p->topo == -1){
		return -1;
	}
	
	*val = p->vet[p->topo];
	p->topo--;
}

//Liberando espaços alocados
TPilha* remover(TPilha *p){
	free(p);
	return (NULL);
}

//Listar elementos da pilha
void consultaPilha(TPilha *p){
	int i;
	
	for (i = 0; i <= p->topo; i++){
		printf("Elemento: %i \n", p->vet[p->topo-i]);
	}
}

int main(){
	setlocale(LC_ALL,"");
	TPilha *pi;
	char str[40];
	int i;
	
	printf("Insira a frase: ");
	fgets(str, sizeof(str), stdin);


	pi = nova();
	if (pi != NULL){
		for (i=0; i<strlen(str); i++){
			push(pi, str[i]);
		}
	}
	
	for (i = 0; i < pi->topo; i++){
		printf("Elemento: %s \n", &pi->vet[pi->topo-1-i]);
	}
	remover(pi);
	
	return 0;
}
