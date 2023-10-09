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

#define		imax		intmax_t
#define		umax		uintmax_t

#define		rimax		register	intmax_t
#define		rumax		register	uintmax_t
#define		cumax		const		uintmax_t

#define		i32			int_fast32_t
#define		u32			uint_fast32_t

#define		ri32		register	int_fast32_t
#define		ru32		register	uint_fast32_t
#define		ci32		const		int_fast32_t
#define		cu32		const		uint_fast32_t

/*
 * Lista de Funções
 */

static inline void	 Swap		(imax*, cu32, cu32);
static inline void	 Copy		(imax*, imax*, cu32);
static inline void	 Print		(const wchar_t*, imax*, cu32);

static void			 Bubble		(imax*, u32);
static void			 Selection	(imax*, u32);
static void			 Insertion	(imax*, cu32);

static void			 Merge		(imax*, imax*, imax*, cu32, cu32);
static void			 Merge_Sort	(imax*, imax*, cu32);	/* NOT WORKING */
static void			 Quick		(imax*, ci32, ci32);

static void			 Counting	(imax*, u32, cumax);
static void			 Bucket		(imax*, cu32);			/* NOT WORKING */
static void			 Radix		(imax*, cu32, cumax);	/* NOT WORKING */

/*
 * Função de Troca - Θ(1) = O = Ω
 *  Swap
 * Troca os valores de V[i] e V[j].
 */

static inline void 
Swap(imax* V, cu32 i, cu32 j)
{
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

static inline void 
Copy(imax *V, imax *W, cu32 N)
{
	ru32 i;

	for (i = 0; i < N; i++)
		V[i] = W[i];
}

/*
 * Função de Impressão - Θ(1) = O = Ω
 *  Print
 * Função que imprime um vetor V.
 */

static inline void 
Print(const wchar_t* Name, imax* V, cu32 N)
{
	ru32 i;

	if (Name != NULL)
		printf(" %ls:", Name);

	for (i = 0; i < N; i++)
		printf(" %" PRIiMAX, V[i]);

	printf("\n");
}

/*
 * Função de Ordenação por comparação
 *  Bubble Sort - Θ(n²) = O = Ω, in-place, estável
 * Percorre o vetor para encontrar o maior elemento e coloca no final do
 * vetor.
 */

static void 
Bubble(imax* V, cu32 N)
{
	ru32 i, j;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if (V[i] < V[j])
				Swap(&(V[0]), i, j);
}

/*
 * Função de Ordenação por comparação
 *  Selection Sort - Θ(n²) = O = Ω, in-place
 * Encontra o menor elemento do vetor e coloca na posição inicial.
 */

static void 
Selection(imax* V, cu32 N) 
{
	ru32 i, j, p;

	for (i = 0; i < N; i++) {

		for (p = i, j = (i + 1); j < N; j++)
			if (V[j] < V[p])
				p = j;

		Swap(&(V[0]), i, p);

	}
}

/*
 * Função de Ordenação por comparação
 *  Insertion Sort - O(n²) Ω(n) Θ(n²), in-place, estável
 * Empurra o elemento para trás até ficar ordenado.
 */

static void 
Insertion(imax* V, cu32 N) 
{
	ru32 i, j;

	for (i = 0; i < N; i++)
		for (j = i; (j > 0) && (V[j] < V[j-1]); j--)
			Swap(&(V[0]), j, j-1);
}

/*
 * Função de Ordenação por comparação
 *  Merge Algorithm - Θ(n) = O = Ω
 * Junta dois vetores já pré-ordenados.
 */

static void 
Merge(imax* R, imax* V, imax* W, cu32 Nv, cu32 Nw)
{
	ru32 i, j, k;

	for (i = 0, j = 0, k = 0; (i < Nv) && (j < Nw); k++) {

		if (V[i] <= W[j]) {

			R[k] = V[i]; 
			i++;

		}

		else {

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
 *  Merge Sort - Θ(n lg n) = O = Ω, estável
 * Utiliza o algoritmo merge para ordenar um vetor.
 */

static void 
Merge_Sort(imax* R, imax* V, cu32 N)
{
	if (N == 1)
		return;

	Merge_Sort(&(R[0]), &(V[0]),   N/2);
	Merge_Sort(&(R[0]), &(V[N/2]), N/2);

	Merge(&(R[0]), &(V[0]), &(V[N/2]), N/2, N/2);
}

/*
 * Função de Ordenação recursiva por comparação
 *  Quick Sort - O(n lg n) Ω(n²) Θ(n lg n), in-place
 * Utiliza o algoritmo de particionamento para ordenar um vetor.
 */

static void 
Quick(imax* V, ci32 Start, ci32 End) 
{
	if (Start >= End)
		return;

	imax Pivot	= V[Start];
	u32  m		= Start;
	ri32 i;

	for (i = (m + 1); i <= End; i++) {

		if (V[i] < Pivot) {

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
 *  Counting Sort - Θ(n + s) = O = Ω
 * Utiliza um vetor auxiliar de contagem para reconstruir o vetor
 * de forma ordenada.
 */

static void 
Counting(imax *V, u32 N, cumax M)
{
	imax  *C;
	rumax  i;
	rimax  j;

	if ((C = (imax *) calloc(M+1, sizeof(imax))) == NULL)
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

static void 
Bucket(imax *V, cu32 N)
{
	(void) V; (void) N;
}

/*
 * Função de Ordenação por contagem
 *  Radix Sort
 * Ordena um vetor por dígito significativo utilizando o Bucket sort.
 */

static void 
Radix(imax *V, cu32 N, cumax D) 
{
	(void) V; (void) N; (void) D;
}

int 
main(void) 
{
	imax  B[] 	 = { 5, 8, 9, 1, 3, 2, 1, 0, 8 };
	imax  S[] 	 = { 5, 8, 9, 1, 3, 2, 1, 0, 8 };
	imax  I[] 	 = { 5, 8, 9, 1, 3, 2, 1, 0, 8 };

	imax  M[] 	 = { 5, 8, 9, 1, 3, 2, 1, 0, 8 };
	imax  Q[] 	 = { 5, 8, 9, 1, 3, 2, 1, 0, 8 };
	imax  H[] 	 = { 5, 8, 9, 1, 3, 2, 1, 0, 8 };
	
	imax  C[] 	 = { 5, 8, 9, 1, 3, 2, 1, 0, 8 };
	imax  K[] 	 = { 5, 8, 9, 1, 3, 2, 1, 0, 8 };
	imax  D[] 	 = { 5, 8, 9, 1, 3, 2, 1, 0, 8 };

	imax  Vo[]	 = { 1, 2, 3, 4, 5, 6, 1, 0, 8 };

	cu32  N		 = 9;
	
	imax *R;

	if ((R = (imax *) calloc(N, sizeof(imax))) == NULL)
		err(errno, "calloc");

	Bubble		(&(B[0])	,		N);
	Selection	(&(S[0])	,		N);
	Insertion	(&(I[0])	,		N);

	Merge_Sort	(&(R[0])	, &(M[0]),	N);
	Quick		(&(Q[0])	, 0,	N-1);

	Counting	(&(C[0])	, N,	10);
	Bucket		(&(K[0])	, 		N);
	Radix		(&(D[0])	, N,	2);

	Print		(L"Bubble    ", &(B[0]),	N);
	Print		(L"Selection ", &(S[0]),	N);
	Print		(L"Insertion ", &(I[0]),	N);

	printf("\n");

	Print		(L"Merge     ", &(R[0]),	N);
	Print		(L"Quick     ", &(Q[0]),	N);

	printf("\n");

	Print		(L"Counting  ", &(C[0]),	N);
	Print		(L"Bucket    ", &(K[0]),	N);
	Print		(L"Radix     ", &(D[0]),	N);

	free(R);

	return 0;
}

