#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


int main(){
	setlocale(LC_ALL,"");
	char ch;
	
	FILE* f;
	f = fopen("arq.txt", "r");
	if (f == NULL){
		printf("Error");
		exit(1);
	}
	
	printf("File opened successfully. Reading file contents character by character. \n\n");
	
	do {
		ch = fgetc(f);
		putchar(ch);
	} while (!feof(f));
	
	fclose(f);

	return 0;
}
