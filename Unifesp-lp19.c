//19.Ler 4 n�meros inteiros e calcular a soma dos que forem par.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"");
	int n1, n2, n3, n4, p1=0, p2=0, p3=0, p4=0;
	
	printf("1� valor: ");    
    scanf("%i", &n1);
    if (n1 % 2 == 0) {p1 = n1; printf("%i � PAR!\n", n1);}
    
	printf("\n2� valor: ");
    scanf("%i", &n2);
    if (n2 % 2 == 0) {p2 = n2; printf("%i � PAR!\n", n2);}
    
	printf("\n3� valor: ");
    scanf("%i", &n3);
    if (n3 % 2 == 0) {p3 = n3; printf("%i � PAR!\n", n3);}
    
	printf("\n4� valor: ");
    scanf("%i", &n4);	
    if (n4 % 2 == 0) {p4 = n4; printf("%i � PAR!\n", n4);}
    
    
	printf("\n\nSoma dos pares: (%i) + (%i) + (%i) + (%i) = %i", p1, p2, p3, p4, p1+p2+p3+p4);	
	return(0);
}
