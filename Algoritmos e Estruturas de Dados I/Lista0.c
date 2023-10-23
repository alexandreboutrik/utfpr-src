/*
 * Lista 0
 *  Algoritmos e Estruturas de Dados I
 * Revisão de Fundamentos da Programação
 */

#include <err.h>
#include <errno.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define     S16     wchar_t

#define     IX      intmax_t
#define     I32     int_fast32_t
#define     I8      int_fast8_t

#define     UX      uintmax_t
#define     U16     uint_fast16_t
#define     U8      uint_fast8_t
#define     U0      void

#define     F32     float

#define     Fn      static
#define     Reg     register
#define     Cst     const

/*
 * Lista de Exercícios
 */

Fn  U0      HelloWorld  (void);                     /* Ex 01 */

Fn  U8      Triangle    (Cst UX, Cst UX, Cst UX);   /* Ex 02 */
Fn  U0      Average     (void);                     /* Ex 03 */
Fn  I8      Square      (Cst U8);                   /* Ex 04 */
Fn  U0      Dynamic     (I32);                      /* Ex 05 */
Fn  U16     StrLen      (Cst S16*);                 /* Ex 07 */

Fn  U8      Linear      (IX*, Cst U16, Cst IX);     /* Ex 12 */

/*
 * Exercício 01
 * Imprime Hello World!
 */

Fn U0
HelloWorld(void)
{
    printf("Hello World!\n");
}

/*
 * Exercício 02
 * Retorna 1 caso exista um triângulo cujos lados tem comprimento 
 * A, B e C. Retorna 0 caso contrário.
 */

Fn U8 
Triangle(Cst UX A, Cst UX B, Cst UX C)
{
    if ((A < (B + C)) && (B < (A + C)) && (C < (A + B)))
        return 1;

    return 0;
}

/*
 * Exercício 03
 * Lê do stdin uma sequência de inteiros até que o usuário entre com -1 
 * (que não faz parte da sequência).
 * Determina e imprime a média aritmética dos valores lidos, com duas
 * casas decimais.
 */

Fn U0
Average(void) 
{
    IX Sum, Input, N;

    for (Sum = 0, Input = 0, N = -1; Input != -1; N++) {

        scanf("%" PRIiMAX, &Input);
        Sum += Input;

    }

    /* Pois o último Input foi -1 */
    Sum++;

    printf("Média: %.2f\n", ((F32) Sum / (F32) N));
}

/*
 * Exercício 04
 * Imprime um quadrado NxN no formato assim exemplificado: se N = 3:
 *  x.x
 *  .x.
 *  x.x
 * Se N for par, retorna -1 sinalizando um erro.
 */

Fn I8 
Square(Cst U8 N) 
{
    Reg U8 l, c;

    if (N % 2 == 0)
        return -1;

    /* Percorre as linhas */
    for (l = 0; l < N; l++) {

        /* Percorre as colunas */
        for (c = 0; c < N; c++) {

            if (c == l || c == N-l-1)
                printf("x");
            else
                printf(".");

        }
    
        printf("\n");

    }

    return 0;
}

/*
 * Exercício 05
 * Preencha um vetor de tamanho N com valores lidos do stdin.
 * Em seguida, imprima a soma dos elementos do vetor.
 */

Fn U0
Dynamic(I32 N) 
{
    IX *Vetor;
    IX  Sum;

    Reg I32 i;

    if ((Vetor = (IX *) malloc(N * sizeof(IX))) == NULL)
        err(errno, "malloc");

    for (i = 0; i < N; i++)
        scanf("%" SCNiMAX, &(Vetor[i]));

    for (N--; N >= 0; N--)
        Sum += Vetor[N];

    printf("%" PRIiMAX "\n", Sum);

    free(Vetor);
}

/*
 * Exercício 07
 * Retorna a quantidade de letras de uma String.
 */

Fn U16 
StrLen(Cst S16* String) 
{
    Reg U16 i;

    for (i = 0; String[i] != '\0'; i++);

    return i;
}

/*
 * Exercício 12
 * Retorna 1 caso X pertence ao vetor V de tamanho N.
 * Retorna 0 caso contrário.
 */

Fn U8
Linear(IX *V, Cst U16 N, Cst IX X) 
{
    Reg U16 i;

    for (i = 0; i < N; i++)
        if (V[i] == X)
            return 1;

    return 0;
}

int 
main(int argc, const char* argv[]) 
{
    (void) argc; (void) argv;

    return 0;
}

