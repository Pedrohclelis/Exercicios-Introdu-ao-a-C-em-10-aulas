#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*  n +1 se m = 0
A(m,n) = A(m -1, 1) se m > 0 e n = 0
A(m -1, A(m,n -1)) se m > 0 e n > 0 */

int main(){
	setlocale(LC_ALL,"");
	int m, n, r;
	printf("Digite o valor de m e n: ");
	scanf("%d %d", &m, &n);
	r = ackermann(m, n);
	printf("Resultado: %i \n", r);
}

int ackermann(int m, int n){
	if (m == 0){
		return n+1;
	}	
	else if ((m > 0) && (n ==0)){
		return ackermann(m-1, 1);
	}
	else if ((m > 0) && (n > 0)){
		return ackermann(m-1, ackermann(m, n-1));
	}
}
