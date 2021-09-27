#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int fatorial(int num){
	int i, resp=1;
	if (num < 0){
		resp = 0;
	} else{
		for(i=1; i<=num; i++){
		resp *= i;
		}
	} return resp;
	
}

int main(){
	setlocale(LC_ALL,"");
	int num;
	
	printf("Digite um numero: ");
	scanf("%i", &num);
	printf("Seu fat é %i", fatorial(num));
	return 0;
}


