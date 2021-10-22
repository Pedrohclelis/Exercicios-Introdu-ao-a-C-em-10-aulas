#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main(){
	setlocale(LC_ALL,"");
	int lr, i=1;
	
	FILE *f1, *f2;
	f1 = fopen("arq.txt", "r");
	if (f1 == NULL){
		printf("ERRO");
		exit(1);
	}
	f2 = fopen("arq2.txt", "w");
	if (f2 == NULL){
		printf("ERRO2");
		exit(1);
	}
	
	printf("Input the line you want to remove: ");
	scanf("%i", &lr);
	
	//Getting data from f1 to print for f2
	char data[1024];
	while (fgets(data, sizeof(data), f1) != NULL){
		if (i != lr){
			fprintf(f2, "%s", data);
		}
		i++;
	}	
	
	//Turn f2 into f1
	fclose(f1);
	fclose(f2);
	remove("arq.txt");
	rename("arq2.txt", "arq.txt");
		
	//Reading
	f1 = fopen("arq.txt", "r");
	if (f1 == NULL){
		printf("ERRO3");
		exit(1);
	}
	
	printf("The content of the file is:\n");
	while (fgets(data, sizeof(data), f1) != NULL){
		printf("%s", data);
	}	
	fclose(f1);
	
	return 0;
}
