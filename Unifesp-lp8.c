//8. Ler a razão de uma PA (Progressão Aritmética) e o seu primeiro e último termos e informar a soma dos elementos dessa PA.

#include <stdio.h>

int main(){
	float r, a1, an, soma;
	int n;
	
	printf("Razao: ");
	scanf("%f", &r);
	printf("Primeiro termo: ");
	scanf("%f", &a1);	
	printf("Ultimo termo: ");
	scanf("%f", &an);	
	
	// como an = a1 + (n-1).r, isolamos o n
	n = ((an - a1) + r) / r;
	soma = (a1+an)*n/2;
	printf("Soma dos elementos: %.1f", soma);
	return(0);
}
