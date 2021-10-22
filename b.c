#include <stdio.h>
#include <stdlib.h>

struct dados {
  int numero;
  char nome[5];
};
typedef struct dados Das;

void manipula_um_par (struct dados *a, int b) {
  a[b].numero = a[b].numero /2;
}

void manipula_pares(struct dados *x, int w) {
  int z;
  for (z = 0; z < w; z++) {
    if (x[z].numero % 2 == 0) {
      // manipula_um_par(x,z); // errado
      manipula_um_par(&x[z], z);
    }
  }
}

int main()
{
  Das *p;
  int k;

  printf("Qual sera o numero de alunos?\n");
  scanf("%d", &k);

  p = (Das*)malloc(k*sizeof(Das));

  // erro, tamanho nao e' constante...
  // mas essa declaracao nao faz sentido mesmo, e' desnecessaria
  // Das v[p];

  int x;
  for (x = 0; x < k; x++) {
    printf("\nDigite o nome do %d aluno: ", x+1);
    // scanf("%s", v[p].nome); // <---- nao faz sentido
    scanf("%s", p[x].nome);
    printf("\nDigite o %d numero: ", x+1);
    // scanf("%d",&v[p].numero); // nao faz sentido
    scanf("%d", &p[x].numero);
  }

  // manipula_pares(v, k); // nao faz sentido
  manipula_pares(p, k);

  for (x = 0; x < k; x++) {
    // printf("--- %d ", v[p].numero); // nao faz sentido
    printf("--- %d ", p[x].numero);
  }

  return 0;
}
