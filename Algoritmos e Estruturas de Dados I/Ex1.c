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

typedef		intmax_t		imax;
typedef		uintmax_t		umax;

typedef		int_fast32_t	i32;
typedef		uint_fast32_t	u32;

/*
 * Lista de Funções
 */

void	 Swap		(imax*, u32, u32);
void	 Copy		(imax*, imax*, u32);
void	 Print		(wchar_t*, imax*, u32, umax);

void	 Insertion	(imax*, u32, umax*);
void	 Quick		(imax*, i32, i32, umax*);

/*
 * Função de Troca - Θ(1) = O = Ω
 *  Swap
 * Troca os valores de V[i] e V[j].
 */

void Swap(imax *V, u32 i, u32 j) {

	imax Tmp;

	Tmp  = V[i];
	V[i] = V[j];
	V[j] = Tmp;

}

/*
 * Função de Cópia - Θ(1) = O = Ω
 *  Copy
 * Copia os elementos do vetor W para o vetor V.
 */

void Copy(imax *V, imax *W, u32 N) {

	u32 i;

	for (i = 0; i < N; i++)
		V[i] = W[i];

}

/*
 * Função de Impressão Θ(1) = O = Ω
 *  Print
 * Imprime os elementos de um vetor V.
 */

void Print(wchar_t *Name, imax *V, u32 N, umax C) {

	u32 i;

	if (Name != NULL)
		printf("%ls\n", Name);

	for (i = 0; i < N; i++)
		printf("%" PRIiMAX " ", V[i]);

	printf("\n%" PRIuMAX " comparacoes\n", C);

}

/*
 * Função de Ordenação por comparação
 *  Insertion Sort - O(n²) Ω(n) Θ(n²), in-place, estável
 * Empurra o elemento para trás até ficar ordenado.
 * Retorna o número total de comparações por dereferência.
 */

void Insertion(imax *V, u32 N, umax *C) {

	u32  i, j;

	for (i = 0; i < N; i++, (*C)++)
		for (j = i; (j > 0) && (V[j] < V[j-1]); j--, (*C)++)
			Swap(&(V[0]), j, j-1);

}

/*
 * Função de Ordenação recursiva por comparação
 *  Quick Sort - O(n lg n) Ω(n²) Θ(n lg n), in-place
 * Utiliza o algoritmo de particionamento para ordenar um vetor.
 * Retorna o número total de comparações por dereferência.
 */

void Quick(imax *V, i32 Start, i32 End, umax *C) {

	if (Start >= End)
		return;

	imax Pivot = V[Start];
	i32  i, m  = Start;

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

int main(void) {

	imax *I, *Q;
	umax  C1 = 0, C2 = 0;
	u32   N, i;

	scanf("%" SCNuFAST32, &N);

	if ((I = (imax *) calloc(N, sizeof(imax))) == NULL)
		err(errno, "calloc");

	if ((Q = (imax *) calloc(N, sizeof(imax))) == NULL)
		err(errno, "calloc");

	for (i = 0; i < N; i++)
		scanf("%" SCNiMAX, &(I[i]));

	Copy		(&(Q[0]), &(I[0]), N);

	Insertion	(&(I[0]), N, &C1);
	Quick		(&(Q[0]), 0, N-1, &C2);
	
	Print		(L"Insertion", &(I[0]), N, C1);
	printf		("\n");
	Print		(L"Quick"	 , &(Q[0]), N, C2);

	free(Q); free(I);

	return 0;

}

