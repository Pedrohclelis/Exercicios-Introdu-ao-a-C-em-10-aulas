//16.Ler três valores e colocá-los em ordem crescente.

#include <stdio.h>

int main(){
	float n1, n2, n3;
	
	printf("1o valor: ");    
    scanf("%f", &n1);
	printf("2o valor: ");
    scanf("%f", &n2);
	printf("3o valor: ");
    scanf("%f", &n3);
    
    if (n1<n2 && n2<n3){
        printf("%f < %f < %f", n1, n2, n3);
    } else if (n1<n3 && n3<n2){
        printf("%f < %f < %f", n1, n3, n2);
    } else if (n2<n3 && n3<n1){
        printf("%f < %f < %f", n2, n3, n1);
    } else if (n2<n1 && n1<n3){
        printf("%f < %f < %f", n2, n1, n3);
    } else if (n3<n2 && n2<n1){
        printf("%f < %f < %f", n3, n2, n1);
    } else if (n3<n1 && n1<n2){
        printf("%f < %f < %f", n3, n1, n2);
    }
    
	return(0);
}
