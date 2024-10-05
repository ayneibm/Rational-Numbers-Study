/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo do programa principal, que usa o TAD racional.
 * Feito em 24/09/2024 para a disciplina CI1001 - Programação 1.
*/

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include <stdlib.h>

#include "racional.h"

/* coloque aqui as funções auxiliares que precisar neste arquivo */

/* programa principal */
int main ()
{
  srand(0);

  struct racional meu_r = sorteia_r(-100, 100);
  imprime_r(meu_r);
  printf("\n");

  printf("TEST PROGRAM HAS ENDED\n");
  return (0) ;
}
