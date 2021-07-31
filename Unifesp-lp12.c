//12.Ler a velocidade máxima permitida em uma avenida e a velocidade com
//que o motorista estava dirigindo nela e calcular a multa do motorista,
//sabendo que são pagos: (a) R$ 50,00, se o motorista estiver ultrapassar
//em até 10km/h a velocidade permitida (ex.: velocidade máxima:
//50km/h; motorista a 60km/h ou a 56km/h); (b) R$ 100,00, se o
//motorista ultrapassar de 11 a 30 km/h a velocidade permitida. (c) 200
//reais, se estiver acima de 31km/h da velocidade permitida.

#include <stdio.h>

int main(){
	float vMax, v, dif;
	printf("Velocidade maxima: ");
	scanf("%f", &vMax);
	printf("Velocidade do motorista: ");
	scanf("%f", &v);
	dif = v - vMax;
	if (dif <= 0){
		printf("Velocidade aceita, sem multa");
	} else{
		if (dif <= 10){
			printf("%.1f km/h alem da velocidade maxima, 50 reais de multa", dif);
		} else if (11 <= dif && dif <= 30){
			printf("%.1f km/h alem da velocidade maxima, 100 reais de multa", dif);
		} else{
			printf("%.1f km/h alem da velocidade maxima, 200 reais de multa", dif);
		}
	}
	return 0;
}
