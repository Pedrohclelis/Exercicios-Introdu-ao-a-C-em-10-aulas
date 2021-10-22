#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main(){
	setlocale(LC_ALL,"");
	
	FILE *f1;
	f1 = fopen("arq.txt", "a");
	if (f1 == NULL){
		printf("ERRO");
		exit(1);
	}
	
	
	//New text
	char new[256];	
	int l, i;
	printf("Input the number of new lines: ");
	scanf("%i", &l);
	printf("Input new text: \n");
	for (i=0; i<l+1; i++){
		fgets(new, sizeof(new), stdin);
		fprintf(f1, "%s", new);
	}
	
	fclose(f1);
	//Reading
	f1 = fopen("arq.txt", "r");
	if (f1 == NULL){
		printf("ERRO3");
		exit(1);
	}
	
	printf("\n\nThe content of the file is:\n");
	char data[256];
	while (fgets(data, sizeof(data), f1) != NULL){
		printf("%s", data);
	}	
	fclose(f1);
	
	return 0;
}
