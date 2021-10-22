#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


int main(){
	setlocale(LC_ALL,"");
	char ch;
	char str[1024];
	
	FILE* f;
	f = fopen("arq.txt", "w");
	if (f == NULL){
		printf("Error");
		exit(1);
	}
	
	printf("File opened successfully. Write some text. \n\n");
	
	fgets(str, sizeof(str), stdin);
	fprintf(f, "%s", str);
	
	
	fclose(f);

	return 0;
}
