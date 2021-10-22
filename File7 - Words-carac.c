#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main(){
	setlocale(LC_ALL,"");
	int words=1, carac=0;
	char ch;
	
	FILE* f;
	f = fopen("arq.txt", "r");
	if (f == NULL){
		printf("ERRO");
		exit(1);
	}
	
	ch = fgetc(f);
	while (ch != EOF) {
		putchar(ch);
	   	if (ch == ' ' || ch == '\n') {
			words++;
		} else{
			carac++;
		}
		ch = fgetc(f);
	}
	
	printf("\n\nWords: %i\n", words);
	printf("Caracters: %i", carac);
	
	
	
	return 0;
}
