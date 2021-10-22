#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float f(int n){
	if (n<=1){
		return 2;
	}
	else{
		return (float)1 / (3-(f(n-1))) ;		
	} 
}

int main(){
	setlocale(LC_ALL,"");
	float num;
	
	while (1){
		printf("\nDigite um numero: ");
		scanf("%f", &num);
		printf("f(%.2f) = %f", num, f(num));
			
	}

	return 0;
}


