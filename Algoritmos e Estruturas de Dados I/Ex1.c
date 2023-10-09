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

#define		imax		intmax_t
#define		umax		uintmax_t
#define		i32			int_fast32_t
#define		u32			uint_fast32_t

#define		cumax		const 		uintmax_t
#define		ri32		register	int_fast32_t
#define		ru32		register	uint_fast32_t
#define		ci32		const		int_fast32_t
#define		cu32		const		uint_fast32_t

/*
 * Lista de Funções
 */

static inline void	 Swap		(imax*, cu32, cu32);
static inline void	 Copy		(imax*, imax*, cu32);
static inline void	 Print		(const wchar_t*, imax*, cu32, cumax);

static void			 Insertion	(imax*, cu32, umax*);
static void			 Quick		(imax*, ci32, ci32, umax*);

/*
 * Função de Troca - Θ(1)
 *  Swap
 * Troca os valores de V[i] e V[j].
 */

static inline void
Swap(imax *V, cu32 i, cu32 j) 
{
	imax Tmp;

	Tmp  = V[i];
	V[i] = V[j];
	V[j] = Tmp;
}

/*
 * Função de Cópia - Θ(1)
 *  Copy
 * Copia os elementos do vetor W para o vetor V.
 */

static inline void 
Copy(imax *V, imax *W, cu32 N) 
{
	ru32  i;

	for (i = 0; i < N; i++)
		V[i] = W[i];
}

/*
 * Função de Impressão - Θ(1)
 *  Print
 * Imprime os elementos de um vetor V.
 */

static inline void
Print(const wchar_t *Name, imax *V, cu32 N, cumax C)
{
	ru32  i;

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

static void
Insertion(imax *V, cu32 N, umax *C) 
{
	ru32  i, j;

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

static void
Quick(imax *V, ci32 Start, ci32 End, umax *C)
{
	if (Start >= End)
		return;

	imax  Pivot	= V[Start];
	i32   m		= Start;
	ri32  i;

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

	imax *I, *Q;
	umax  C1 = 0, C2 = 0;
	u32   N;
	ru32  i;

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

