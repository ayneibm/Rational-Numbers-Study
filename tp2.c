/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo do programa principal, que usa o TAD racional.
 * Feito em 24/09/2024 para a disciplina CI1001 - Programação 1.
*/

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include <stdlib.h>

#include "racional.h"

#define MAX_RACIONAIS 99
#define MIN_RACIONAIS 1

/* coloque aqui as funções auxiliares que precisar neste arquivo */

void imprime_racionais(struct racional* racionais, long n) {
  int i;

  printf("VETOR = ");
  for (i = 0; i < n; i++) {
    imprime_r(racionais[i]);
    printf(" ");
  }
  printf("\n");
}

void retira_invalidos(struct racional* racionais, long *n) {
  int i, j;

  i = 0;
  while (i < *n) {
    if (valido_r(racionais[i])) {
      ++i;
      continue;
    }
    // imprime_racionais(racionais, *n);
    for (j = i; j < *n - 1; j++)
      racionais[j] = racionais[j + 1];

    --(*n);
  }
}

void ordena_racionais(struct racional* racionais, long n) {
  struct racional aux_r;
  int i, j;

  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      // imprime_r(racionais[i]);
      // printf(" ");
      // imprime_r(racionais[j]);
      // printf("\n");
      if (compara_r(racionais[i], racionais[j]) != 1 && compara_r(racionais[i], racionais[j]) != 0)
        continue;
      // printf("Ordenando\n");
      // printf("%ld, %ld\n", racionais[i], racionais[j]);
      aux_r = racionais[i];
      racionais[i] = racionais[j];
      racionais[j] = aux_r;
      // printf("Ordenando\n");
    }
  }
}

struct racional soma_racionais(struct racional* racionais, long n) {
  int i;
  struct racional resultado_r;

  resultado_r = cria_r(0,1);

  for (i = 0; i < n; i++)
    soma_r(resultado_r, racionais[i], &resultado_r);

  return resultado_r;
}

/* programa principal */

int main ()
{
  int i;
  long num = 0, den = 0, n = 0;
  struct racional racionais[MAX_RACIONAIS];

  scanf("%ld", &n);
  if (n < MIN_RACIONAIS || n > MAX_RACIONAIS)
    return 1;

  for (i = 0; i < n; i++) {
    scanf("%ld", &num);
    scanf("%ld", &den);
    racionais[i] = cria_r(num, den);
  }

  imprime_racionais(racionais, n);
  retira_invalidos(racionais, &n);
  imprime_racionais(racionais, n);
  ordena_racionais(racionais, n);
  imprime_racionais(racionais, n);
  printf("SOMA = ");
  imprime_r(soma_racionais(racionais, n));
  printf("\n");

  return (0) ;
}
