#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


int main(){
	setlocale(LC_ALL,"");
	int n=0;
	FILE* f;
	f = fopen("arq.txt", "r");
	if (f == NULL){
		printf("Error");
		exit(1);
	}
	
	printf("File opened successfully.");
	
	char data[1024];
	while (fgets(data, sizeof(data), f) != NULL){
		n++;
	}	
	printf("The lines in the file test.txt are: %i", n);
	
	fclose(f);
	return 0;
}
