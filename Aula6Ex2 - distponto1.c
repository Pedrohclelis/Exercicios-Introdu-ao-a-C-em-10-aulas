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

int main(){
	setlocale(LC_ALL,"");
	float dist;
	struct coords ponto;
	
	printf("Coordenadas do ponto: ");
	scanf("%i %i", &ponto.x, &ponto.y);

	dist = sqrt(pow(ponto.x - 0, 2) + pow(ponto.x - 0, 2));
	
	printf("Distancia do ponto (%i, %i) at� a origem (0, 0): %.1f", ponto.x, ponto.y, dist);
}


