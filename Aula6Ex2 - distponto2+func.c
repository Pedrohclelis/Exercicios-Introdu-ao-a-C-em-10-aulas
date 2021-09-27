#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
/*  Crie uma estrutura para representar as coordenadas de um ponto no plano (posi��es X e Y). Em seguida, declare e leia do teclado um ponto e exiba a dist�ncia
dele at� a origem das coordenadas, isto �, posi��o (0, 0). Para realizar o c�lculo,
utilize a f�rmula a seguir:
dAB = [(xB � xA)^2+ (yB � yA)^2]^(1/2)
Em que:
� d = dist�ncia entre os pontos A e B
� X = coordenada X em um ponto
� Y = coordenada Y em um ponto */

struct coords {
	int x;
	int y;
};

float dist(int xa, int ya, int xb, int yb){
	return sqrt(pow(xb - xa, 2) + pow(yb - ya, 2));
}

int main(){
	setlocale(LC_ALL,"");
	struct coords ponto;
	
	printf("Coordenadas do ponto: ");
	scanf("%i %i", &ponto.x, &ponto.y);

	
	printf("Distancia do ponto (%i, %i) at� a origem (0, 0): %.1f", ponto.x, ponto.y, dist(ponto.x, ponto.y, 0, 0));
}


