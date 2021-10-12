#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


int main(){
	setlocale(LC_ALL,"");
	
	FILE* f;
	f = fopen("arq.txt", "r");
	if (f == NULL){
		printf("Error");
		exit(1);
	}
	
	printf("File opened successfully. Reading file contents line by line: \n\n");
	
	char data[1024];
	while (fgets(data, sizeof(data), f) != NULL){
		printf("%s", data);
	}	
	
	fclose(f);
	return 0;
}
