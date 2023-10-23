/*
 * Exercício 1
 *  Algoritmos e Estruturas de Dados I
 * Alexandre Boutrik, RA 2568993
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
#define     UX      uintmax_t
#define     I32     int_fast32_t
#define     U32     uint_fast32_t
#define     U0      void

#define     Fn      static
#define     In      inline
#define     Reg     register
#define     Cst     const

/*
 * Lista de Funções
 */

Fn  In U0    Swap       (IX*, Cst U32, Cst U32);
Fn  In U0    Copy       (IX*, IX*, Cst U32);
Fn  In U0    Print      (Cst S16*, IX*, Cst U32, Cst UX);

Fn  U0       Insertion  (IX*, Cst U32, UX*);
Fn  U0       Quick      (IX*, Cst I32, Cst I32, UX*);

/*
 * Função de Troca - Θ(1)
 *  Swap
 * Troca os valores de V[i] e V[j].
 */

Fn In U0
Swap(IX *V, Cst U32 i, Cst U32 j) 
{
    IX Tmp;

    Tmp  = V[i];
    V[i] = V[j];
    V[j] = Tmp;
}

/*
 * Função de Cópia - Θ(1)
 *  Copy
 * Copia os elementos do vetor W para o vetor V.
 */

Fn In U0
Copy(IX *V, IX *W, Cst U32 N) 
{
    Reg U32 i;

    for (i = 0; i < N; i++)
        V[i] = W[i];
}

/*
 * Função de Impressão - Θ(1)
 *  Print
 * Imprime os elementos de um vetor V.
 */

Fn In U0
Print(Cst S16 *Name, IX *V, Cst U32 N, Cst UX C)
{
    Reg U32 i;

    if (Name != NULL)
        printf("%ls\n", Name);

    for (i = 0; i < N; i++)
        printf("%" PRIiMAX " ", V[i]);

    printf("\n%" PRIuMAX " comparacoes\n", C);
}

/*
 * Função de Ordenação por comparação
 *  Insertion Sort - O(n²), melhor caso: O(n), in-place, estável
 * Empurra o elemento para trás até ficar ordenado.
 * Retorna o número total de comparações por dereferência.
 */

Fn U0
Insertion(IX *V, Cst U32 N, UX *C) 
{
    Reg U32 i, j;

    for (i = 0; i < N; i++, (*C)++)
        for (j = i; (j > 0) && (V[j] < V[j-1]); j--, (*C)++)
            Swap(&(V[0]), j, j-1);
}

/*
 * Função de Ordenação recursiva por comparação
 *  Quick Sort - O(n lg n), pior caso: O(n²), in-place
 * Utiliza o algoritmo de particionamento para ordenar um vetor.
 * Retorna o número total de comparações por dereferência.
 */

Fn U0
Quick(IX *V, Cst I32 Start, Cst I32 End, UX *C)
{
    if (Start >= End)
        return;

    IX      Pivot = V[Start];
    I32     m     = Start;
    Reg I32 i;

    for (i = (m + 1); i <= End; i++) {

        if (V[i] < Pivot) {

            Swap(&(V[0]), i, m+1);
            m++;

        }

        (*C)++;

    }

    Swap (&(V[0]), Start, m);

    Quick(&(V[0]), Start, m-1, C);
    Quick(&(V[0]), m+1  , End, C);
}

int
main(int argc, const char* argv[]) 
{
    (void) argc; (void) argv;

    IX      *I, *Q;
    UX       C1 = 0, C2 = 0;
    U32      N;
    Reg U32  i;

    scanf("%" SCNuFAST32, &N);

    if ((I = (IX *) calloc(N, sizeof(IX))) == NULL)
        err(errno, "calloc");

    if ((Q = (IX *) calloc(N, sizeof(IX))) == NULL)
        err(errno, "calloc");

    for (i = 0; i < N; i++)
        scanf("%" SCNiMAX, &(I[i]));

    Copy        (&(Q[0]), &(I[0]), N);

    Insertion   (&(I[0]), N, &C1);
    Quick       (&(Q[0]), 0, N-1, &C2);
    
    Print       (L"Insertion", &(I[0]), N, C1);
    printf      ("\n");
    Print       (L"Quick"    , &(Q[0]), N, C2);

    free(Q); free(I);

    return 0;
}

