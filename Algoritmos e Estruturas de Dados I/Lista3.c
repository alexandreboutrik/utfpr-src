/*
 * Lista 3
 *  Algoritmos e Estruturas de Dados I
 * Busca e Ordenação
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
#define     U32     uint_fast32_t
#define     U0      void

#define     Fn      static
#define     In      inline
#define     Reg     register
#define     Cst     const

/*
 * Lista de Funções
 */

Fn  I8      Linear      (IX*, Cst IX, Cst U32);
Fn  I8      Binary      (IX*, Cst IX, Cst U32);

Fn  I8      Linear_R    (IX*, Cst IX, Cst U32);
Fn  I8      Binary_R    (IX*, Cst IX, Cst U32);

Fn  In U0   Swap        (IX*, Cst U32, Cst U32);
Fn  In U0   Copy        (IX*, IX*, Cst U32);
Fn  In U0   Print       (Cst S16*, IX*, Cst U32);

Fn  U0      Bubble      (IX*, Cst U32);
Fn  U0      Selection   (IX*, Cst U32);
Fn  U0      Insertion   (IX*, Cst U32);

Fn  U0      Merge       (IX*, IX*, IX*, Cst U32, Cst U32);
Fn  U0      Merge_Sort  (IX*, IX*, Cst U32);        /* NOT WORKING */
Fn  U0      Quick       (IX*, Cst I32, Cst I32);

Fn  U0      Counting    (IX*, U32, Cst UX);
Fn  U0      Bucket      (IX*, Cst U32);             /* NOT WORKING */
Fn  U0      Radix       (IX*, Cst U32, Cst UX);     /* NOT WORKING */

/*
 * Função de Busca
 *  Linear Search - O(n), melhor caso: O(1)
 * Compara cada elemento do vetor com X para verificar se X E V.
 */

Fn I8
Linear(IX *V, Cst IX X, Cst U32 N)
{
    Reg U32 i;

    for (i = 0; i < N; i++)
        if (V[i] == X)
            return 1;

    return 0;
}

/*
 * Função de Busca
 *  Binary Search - O(lg n), melhor caso: O(1)
 * Em um vetor já pré-ordenado, verifica se o X está no meio do vetor
 * recursivamente.
 */

Fn I8
Binary(IX *V, Cst IX X, Cst U32 N)
{
    Reg U32 Avg;
    Reg U32 Start = 0, End = (N - 1);

    while (Start <= End) {

        Avg = (Start + End) / 2;

        if (V[Avg] == X)
            return 1;

        if (V[Avg] > X)
            End   = Avg - 1;
        else
            Start = Avg + 1;

    }
    
    return 0;
}

/*
 * Função de Busca recursiva
 *  Linear Search - O(n), melhor caso: O(1)
 * Compara cada elemento do vetor com X para verificar se X E V.
 */

Fn I8
Linear_R(IX *V, Cst IX X, Cst U32 N)
{
    if (N == 0)
        return 0;
    
    if (V[0] == X)
        return 1;

    return Linear_R(&(V[1]), X, N-1);
}

/*
 * Função de Busca recursiva
 *  Binary Search - O(lg n), melhor caso: O(1)
 * Em um vetor já pré-ordenado, verifica se o X está no meio do vetor
 * recursivamente.
 */

Fn I8
Binary_R(IX *V, Cst IX X, Cst U32 N)
{
    if (N == 0)
        return 0;

    if (V[N >> 1] == X)
        return 1;

    if (V[N >> 1] < X)
        return Binary_R(&(V[N/2+1]), X, (N >> 1) + 1);
        
    return Binary_R(&(V[0]), X, N >> 1);
}

/*
 * Função de Troca
 *  Swap - Θ(1)
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
 * Função de Cópia
 *  Copy - Θ(1)
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
 * Função de Impressão
 *  Print - Θ(1)
 * Função que imprime um vetor V.
 */

Fn In U0
Print(Cst S16 *Name, IX *V, Cst U32 N)
{
    Reg U32 i;

    if (Name != NULL)
        printf(" %ls:", Name);

    for (i = 0; i < N; i++)
        printf(" %" PRIiMAX, V[i]);

    printf("\n");
}

/*
 * Função de Ordenação por comparação
 *  Bubble Sort - Θ(n²), in-place, estável
 * Percorre o vetor para encontrar o maior elemento e coloca no final do
 * vetor.
 */

Fn U0
Bubble(IX *V, Cst U32 N)
{
    Reg U32 i, j;

    for (i = 0; i < N; i++)
        for (j = i; j < N; j++)
            if (V[i] > V[j])
                Swap(&(V[0]), i, j);
}

/*
 * Função de Ordenação por comparação
 *  Selection Sort - Θ(n²), in-place
 * Encontra o menor elemento do vetor e coloca na posição inicial.
 */

Fn U0
Selection(IX *V, Cst U32 N) 
{
    Reg U32 i, j, p;

    for (i = 0; i < N; i++)
    {
        for (p = i, j = (i + 1); j < N; j++)
            if (V[j] < V[p])
                p = j;

        Swap(&(V[0]), i, p);
    }
}

/*
 * Função de Ordenação por comparação
 *  Insertion Sort - O(n²), melhor caso: O(n), in-place, estável
 * Empurra o elemento para trás até ficar ordenado.
 */

Fn U0
Insertion(IX *V, Cst U32 N) 
{
    Reg U32 i, j;

    for (i = 0; i < N; i++)
        for (j = i; (j > 0) && (V[j] < V[j-1]); j--)
            Swap(&(V[0]), j, j-1);
}

/*
 * Função de Ordenação por comparação
 *  Merge Algorithm - Θ(n)
 * Junta dois vetores já pré-ordenados.
 */

Fn U0
Merge(IX *R, IX *V, IX *W, Cst U32 Nv, Cst U32 Nw)
{
    Reg U32 i, j, k;

    for (i = 0, j = 0, k = 0; (i < Nv) && (j < Nw); k++) 
    {
        if (V[i] <= W[j])
        {
            R[k] = V[i]; 
            i++;
        }

        else
        {
            R[k] = W[j];
            j++;
        }
    }

    for (; i < Nv; i++, k++)
        R[k] = V[i];

    for (; j < Nw; j++, k++)
        R[k] = W[j];
}

/*
 * Função de Ordenação recursiva por comparação
 *  Merge Sort - Θ(n lg n), estável
 * Utiliza o algoritmo merge para ordenar um vetor.
 */

Fn U0
Merge_Sort(IX *R, IX *V, Cst U32 N)
{
    if (N == 1)
        return;

    Merge_Sort(&(R[0]), &(V[0]),   N/2);
    Merge_Sort(&(R[0]), &(V[N/2]), N/2);

    Merge(&(R[0]), &(V[0]), &(V[N/2]), N/2, N/2);
}

/*
 * Função de Ordenação recursiva por comparação
 *  Quick Sort - O(n lg n), pior caso: O(n²), in-place
 * Utiliza o algoritmo de particionamento para ordenar um vetor.
 */

Fn U0
Quick(IX *V, Cst I32 Start, Cst I32 End) 
{
    if (Start >= End)
        return;

    IX      Pivot  = V[Start];
    U32     m      = Start;
    Reg I32 i;

    for (i = (m + 1); i <= End; i++)
    {
        if (V[i] < Pivot)
        {
            Swap(&(V[0]), i, m+1);
            m++;
        }
    }

    Swap (&(V[0]), Start, m);

    Quick(&(V[0]), Start, m-1);
    Quick(&(V[0]), m+1  , End);
}

/*
 * Função de Ordenação por contagem
 *  Counting Sort - Θ(n + s)
 * Utiliza um vetor auxiliar de contagem para reconstruir o vetor
 * de forma ordenada.
 */

Fn U0
Counting(IX *V, U32 N, Cst UX M)
{
    IX      *C;
    Reg UX   i;
    Reg IX   j;

    if ((C = (IX *) calloc(M+1, sizeof(IX))) == NULL)
        err(errno, "calloc");

    for (i = 0; i < N; i++)
        C[V[i]]++;

    for (i = 0, N = 0; i < M; i++)
        for (j = 0; j < C[i]; j++)
            V[N++] = i;

    free(C);
}

/*
 * Função de Ordenação por contagem
 *  Bucket Sort - O(depende) Ω(depende) Θ(depende) 
 * Utiliza baldes (vetores representando intervalos) para contar e
 * reconstruir o vetor de forma ordenada.
 */

Fn U0
Bucket(IX *V, Cst U32 N)
{
    (void) V; (void) N;
}

/*
 * Função de Ordenação por contagem
 *  Radix Sort
 * Ordena um vetor por dígito significativo utilizando o Bucket sort.
 */

Fn U0
Radix(IX *V, Cst U32 N, Cst UX D) 
{
    (void) V; (void) N; (void) D;
}

int 
main(void) 
{
    IX  B[]    = { 5, 8, 9, 1, 3, 2, 1, 0, 8 };
    IX  S[]    = { 5, 8, 9, 1, 3, 2, 1, 0, 8 };
    IX  I[]    = { 5, 8, 9, 1, 3, 2, 1, 0, 8 };

    IX  M[]    = { 5, 8, 9, 1, 3, 2, 1, 0, 8 };
    IX  Q[]    = { 5, 8, 9, 1, 3, 2, 1, 0, 8 };
    
    IX  C[]    = { 5, 8, 9, 1, 3, 2, 1, 0, 8 };
    IX  K[]    = { 5, 8, 9, 1, 3, 2, 1, 0, 8 };
    IX  D[]    = { 5, 8, 9, 1, 3, 2, 1, 0, 8 };

    IX  Vo[]   = { 1, 2, 3, 4, 5, 6, 1, 0, 8 };

    Cst U32 N = 9;
    
    IX *R;

    if ((R = (IX *) calloc(N, sizeof(IX))) == NULL)
        err(errno, "calloc");

    Bubble      (&(B[0])    ,       N);
    Selection   (&(S[0])    ,       N);
    Insertion   (&(I[0])    ,       N);

    Merge_Sort  (&(R[0])    , &(M[0]),  N);
    Quick       (&(Q[0])    , 0,   N-1);

    Counting    (&(C[0])    , N,    10);
    Bucket      (&(K[0])    ,       N);
    Radix       (&(D[0])    , N,    2);

    printf(" Linear: %" PRIiFAST8 " - %" PRIiFAST8
              " | R: %" PRIiFAST8 " - %" PRIiFAST8 "\n",
        Linear  (&(Vo[0]), 5, N), Linear  (&(Vo[0]), 11, N),
        Linear_R(&(Vo[0]), 5, N), Linear_R(&(Vo[0]), 11, N));

    printf(" Binary: %" PRIiFAST8 " - %" PRIiFAST8
              " | R: %" PRIiFAST8 " - %" PRIiFAST8 "\n",
        Binary  (&(Vo[0]), 5, N), Binary  (&(Vo[0]), 11, N),
        Binary_R(&(Vo[0]), 5, N), Binary_R(&(Vo[0]), 11, N));

    printf("\n");

    Print       (L"Bubble    ", &(B[0]),    N);
    Print       (L"Selection ", &(S[0]),    N);
    Print       (L"Insertion ", &(I[0]),    N);

    printf("\n");

    Print       (L"Merge     ", &(R[0]),    N);
    Print       (L"Quick     ", &(Q[0]),    N);

    printf("\n");

    Print       (L"Counting  ", &(C[0]),    N);
    Print       (L"Bucket    ", &(K[0]),    N);
    Print       (L"Radix     ", &(D[0]),    N);

    free(R);

    return 0;
}

