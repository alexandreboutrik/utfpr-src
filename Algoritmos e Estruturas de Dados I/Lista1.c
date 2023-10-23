/*
 * Lista 1
 *  Algoritmos e Estruturas de Dados I
 * Recursão
 */

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <wchar.h>

#define     S16     wchar_t

#define     IX      intmax_t
#define     UX      uintmax_t
#define     U16     uint_fast16_t
#define     U8      uint_fast8_t
#define     U0      void

#define     Fn      static
#define     Reg     register
#define     Cst     const

/*
 * Lista de Exercícios
 */

Fn  IX      Factorial       (Cst IX);                   /* Ex 02 */
Fn  IX      Power_2         (Cst IX);                   /* Ex 05 */
Fn  IX      Fibonnaci       (Cst IX);                   /* Ex 07 */
Fn  U16     Digits          (Cst IX);                   /* Ex 08 */

Fn  U0      PrintIn_Digits  (Cst IX);                   /* Ex 09 */
Fn  U0      Print_Digits    (Cst IX);                   /* Ex 10 */
Fn  U0      Print_Bin       (Cst IX);                   /* Ex 11 */

Fn  IX      Pow             (Cst IX, Cst IX);           /* Ex 12 */
Fn  IX      Custom_Pow      (Cst IX, Cst IX);           /* Ex 13 */
Fn  IX      Sum             (IX*, Cst U16);             /* Ex 14 */
Fn  U8      Linear          (IX*, Cst U16, Cst IX);     /* Ex 15 */
Fn  IX      Biggest         (IX*, Cst U16);             /* Ex 16 */
Fn  U16     StrLen          (Cst S16*);                 /* Ex 17 */
Fn  U8      Palindrome      (IX*, Cst U16);             /* Ex 18 */

Fn  U0      Print_Inv       (IX*, Cst U16);             /* Ex 19 */

Fn  IX      Sum_Digits      (Cst IX);                   /* Ex de sala */

/*
 * Função Recursiva - Ex 02
 * Calcula o fatorial de um inteiro N.
 */

Fn IX
Factorial(Cst IX N)
{
    if (N == 0)
        return 1;

    return (N * Factorial(N-1));
}

/*
 * Função Recursiva - Ex 05
 * Retorna 2^N.
 */

Fn IX
Power_2(Cst IX N)
{
    if (N == 0)
        return 1;

    return (Power_2(N-1) + Power_2(N-1));
}

/*
 * Função Recursiva - Ex 07
 * Retona o N-ésimo número da sequência de Fibonacci.
 */

Fn IX
Fibonnaci(Cst IX N)
{
    if (N == 0 || N == 1)
        return N;
    
    return (Fibonnaci(N-1) + Fibonnaci(N-2));
}

/*
 * Função Recursiva - Ex 08
 * Retorna a quantidade de dígitos de um inteiro N.
 */

Fn U16
Digits(Cst IX N) 
{
    if (N == 0)
        return 0;

    return (1 + Digits(N / 10));
}

/*
 * Função Recursiva - Ex 09
 * Imprime os dígitos de um inteiro N da direita para a esquerda.
 */

Fn U0
PrintIn_Digits(Cst IX N)
{
    if (N == 0)
        return;

    printf("%" PRIiMAX, (N % 10));

    PrintIn_Digits(N / 10);
}

/*
 * Função Recursiva - Ex 10
 * Imprime os dígitos de um inteiro N da esquerda para a direita.
 */

Fn U0
Print_Digits(Cst IX N) 
{
    if (N == 0)
        return;

    Print_Digits(N / 10);

    printf("%" PRIiMAX, (N % 10));
}

/*
 * Função Recursiva - Ex 11
 * Imprime a representação binária de um inteiro N.
 */

Fn U0
Print_Bin(Cst IX N)
{
    if (N == 0)
        return;

    Print_Bin(N >> 1);

    printf("%" PRIiMAX, (N % 2));
}

/*
 * Função Recursiva - Ex 12
 * Retorna X^K.
 */

Fn IX
Pow(Cst IX X, Cst IX K) 
{
    if (K == 0)
        return 1;

    return (X * Pow(X, K-1));
}

/*
 * Função Recursiva - Ex 13
 * Retorna X^K, com:
 *   X^K = X^((K/2)^2)  <- se K for par
 *   X^K = X * X^(K-1)  <- se K for ímpar
 */

Fn IX
Custom_Pow(Cst IX X, Cst IX K) 
{
    if (K == 0)
        return 1;

    if (K % 2 == 0)
        return Pow(Pow(X, K >> 1), 2);

    return (X * Pow(X, K-1));
}

/*
 * Função Recursiva - Ex 14
 * Retorna a soma os elementos de um vetor V de tamanho N.
 */

Fn IX
Sum(IX *V, Cst U16 N) 
{
    if (N == 0)
        return 0;

    return (V[0] + Sum(&(V[0]), N-1));
}

/*
 * Função Recursiva - Ex 15
 * Retorna 1 caso X pertença ao vetor V de tamanho N. Retorna 0 caso
 * contrário.
 */

Fn U8
Linear(IX *V, Cst U16 N, Cst IX X) 
{
    if (N == 0)
        return 0;

    if (V[N-1] == X)
        return 1;

    return Linear(&(V[0]), N-1, X);
}

/*
 * Função Recursiva - Ex 16
 * Retorna o maior elemento de um vetor V de tamanho N.
 */

Fn IX
Biggest(IX *V, Cst U16 N) 
{
    if (N == 1)
        return V[0];
    
    if (V[0] > V[N-1])
        return Biggest(&(V[0]), N-1);

    return Biggest(&(V[1]), N-1);
}

/*
 * Função Recursiva - Ex 17
 * Retorna a quantidade de letras de uma String.
 */

Fn U16
StrLen(Cst S16 *String) 
{
    if (String[0] == '\0')
        return 0;

    return (1 + StrLen(&(String[1])));
}

/*
 * Função Recursiva - Ex 18
 * Retorna 1 se o vetor V é palíndrome, 0 caso contrário.
 */

Fn U8
Palindrome(IX *V, Cst U16 N) 
{
    if (N == 0)
        return 1;

    if (V[0] == V[N-1])
        return Palindrome(&(V[1]), N-2);

    return 0;
}

/*
 * Função Recursiva - Ex 19
 * Imprime os elementos do vetor V de tamanho N na ordem invertida.
 */

Fn U0
Print_Inv(IX *V, Cst U16 N) 
{
    if (N == 0)
        return;

    printf("%" PRIiMAX, V[N-1]);

    Print_Inv(&(V[0]), N-1);
}

/*
 * Função Recursiva - Ex de Sala
 * Retorna a soma dos dígitos de um inteiro N.
 */

Fn IX
Sum_Digits(Cst IX N)
{
    if (N == 0)
        return 0;

    return ((N % 10) + Sum_Digits(N / 10));
}

int 
main(int argc, const char* argv[]) 
{
    (void) argc; (void) argv;

    return 0;
}

