#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main(){
	setlocale(LC_ALL,"");
	int i, nl=1;
	char text[1000];
	
	FILE* f;
	f = fopen("arq.txt", "w");
	if (f == NULL){
		printf("Error");
		exit(1);
	}
	
	printf("Input the number of lines: ");
	scanf("%i", &nl);

	//Writing
	for (i=0; i<=nl; i++){
		fgets(text, sizeof(text), stdin);
		fprintf(f, "%s", text);
	}
	fclose(f);
	
	//Reading
	f = fopen("arq.txt", "r");
	printf("\nThe content of the file arq.txt is:\n");
	char data[1000];
	
	while (fgets(data, sizeof(data), f) != NULL){
		printf("%s", data);
	}
	
	fclose(f);

	return 0;
}
