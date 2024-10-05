/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo de implementação para TAD racional.
 * Feito em 20/09/2024 para a disciplina CI1001 - Programação 1.
 *
 * Este arquivo deve conter as implementações das funções cujos protótipos
 * foram definidos em racional.h. Neste arquivo também podem ser definidas
 * funções auxiliares para facilitar a implementação daquelas funções.
*/

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include "racional.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Implemente aqui as funcoes definidas no racionais.h; caso precise,
 * pode definir aqui funcoes auxiliares adicionais, que devem ser usadas
 * somente neste arquivo.
*/

/* retorna um número aleatório entre min e max, inclusive. */
long aleat (long min, long max)
{
  if (max < min) {
    // printf("Valor maximo nao pode ser menor que minimo.\n");
    perror("Valor maximo nao pode ser menor que minimo.\n");
    exit(1);
  }

  long nm = max - min;
  return (rand() % nm) + min + 1;
}

/* Máximo Divisor Comum entre a e b      */
/* calcula o MDC pelo método de Euclides */
long mdc (long a, long b)
{
  int aux;

  if (b == 0)
    return a;

  while (b != 0) {
    aux = b;
    b = a % b;
    a = aux;
  }

  return a;
}

/* Mínimo Múltiplo Comum entre a e b */
/* mmc = (a * b) / mdc (a, b)        */
long mmc (long a, long b)
{
  if (a == 0 || b == 0) {
    perror("A e B devem ser diferentes de zero.\n");
    exit(1);
  }

  return (a * b) / mdc (a, b);
}

/* Recebe um número racional e o simplifica.
 * Por exemplo, ao receber 10/8 deve retornar 5/4.
 * Se ambos numerador e denominador forem negativos, deve retornar um positivo.
 * Se o denominador for negativo, o sinal deve migrar para o numerador.
 * Se r for inválido, devolve-o sem simplificar. */
struct racional simplifica_r (struct racional r)
{
  struct racional novo_r;
  long m, num_s, den_s, new_s;

  if (!valido_r(r))
    return r;

  m = mdc(r.num, r.den);

  novo_r.num = labs(r.num / m);
  novo_r.den = labs(r.den / m);

  num_s = r.num < 0 ? (-1) : (1);
  den_s = r.den < 0 ? (-1) : (1);
  new_s = num_s * den_s;

  novo_r.num = new_s * novo_r.num;

  return novo_r;
}

/* implemente as demais funções de racional.h aqui */

struct racional cria_r (long numerador, long denominador) {
  struct racional novo_r;
  novo_r.num = numerador;
  novo_r.den = denominador;

  return simplifica_r(novo_r);
}

int valido_r (struct racional r) {
  return r.den == 0 ? (0) : (1);
}

struct racional sorteia_r (long min, long max) {
  long num, den;

  num = aleat(min, max);
  den = aleat(min, max);

  return cria_r(num, den);
}

void imprime_r (struct racional r) {
  if (!valido_r(r)) {
    printf("Nan");
    return;
  }

  if (!r.num) {
    printf("0");
    return;
  }

  if (r.num == r.den || -r.num == r.den) {
    r.num < 0 ? (printf("-1")) : (printf("1"));
    return;
  }

  if (r.den == 1) {
    printf("%ld", r.num);
    return;
  }

  printf("%ld/%ld", r.num, r.den);
}

int compara_r (struct racional r1, struct racional r2) {
  struct racional s_r1, s_r2;

  s_r1 = simplifica_r(r1);
  s_r2 = simplifica_r(r2);

  return (r1.num == r2.num) && (r1.den == r2.den) ? (1) : (0);
}

int soma_r (struct racional r1, struct racional r2, struct racional *r3) {
  if (r3 == NULL)
    return 0;

  if (!(valido_r(r1) && valido_r(r2)))
    return 0;

  r3->den = mmc (r1.den, r2.den);
  r3->num = (((r3->den/r1.den)* r1.num)+(r3->den/r2.num) * r2.num);
  *r3 = simplifica_r (*r3);

  return 1;
}

int subtrai_r (struct racional r1, struct racional r2, struct racional *r3) {
  if (r3 == NULL)
    return 0;

  if (!(valido_r(r1) && valido_r(r2)))
    return 0;  

  r3->den = mmc (r1.den, r2.den);
  r3->num = ((r3->den/r1.den)* r1.num)-(r3->den/r2.num) * r2.num;
  *r3 = simplifica_r (*r3);

  return 1;
}

int multiplica_r (struct racional r1, struct racional r2, struct racional *r3) {
  if (r3 == NULL)
    return 0;

  if (!(valido_r(r1) && valido_r(r2)))
    return 0;

  r3->den = r1.den * r2.den;
  r3->num = r1.num * r2.num;
  *r3 = simplifica_r (*r3);
  return 0;
}

int divide_r (struct racional r1, struct racional r2, struct racional *r3) {
  if (r3 == NULL)
    return 0;

  if (!(valido_r(r1) && valido_r(r2)))
    return 0;

  r3->num = r1.num * r2.den;
  r3->den = r2.num * r1.den;
  *r3 = simplifica_r (*r3);

  return 1;
}