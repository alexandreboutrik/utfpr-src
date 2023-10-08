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

#define		imax		intmax_t
#define		i32			int_fast32_t
#define		i8			int_fast8_t

#define		umax		uintmax_t
#define		u16			uint_fast16_t
#define		u8			uint_fast8_t

#define		cimax		const		intmax_t
#define		cumax		const		uintmax_t

#define		ri32		register	int_fast32_t
#define		ru16		register	uint_fast16_t
#define		cu16		const		uint_fast16_t
#define		ru8			register	uint_fast8_t
#define		cu8			const		uint_fast8_t

#define		f32			float

/*
 * Lista de Exercícios
 */

void	 HelloWorld		(void);					/* Ex 01 */

u8		 Triangle		(cumax, cumax, cumax);	/* Ex 02 */
void	 Average		(void);					/* Ex 03 */
i8		 Square			(cu8);					/* Ex 04 */
void	 Dynamic		(i32);					/* Ex 05 */
u16		 StrLen			(const wchar_t*);		/* Ex 07 */

u8		 Linear_Search	(imax*, cu16, cimax);	/* Ex 12 */

/*
 * Exercício 01
 * Imprime Hello World!
 */

void HelloWorld(void) {
	printf("Hello World!\n");
}

/*
 * Exercício 02
 * Retorna 1 caso exista um triângulo cujos lados tem comprimento 
 * A, B e C. Retorna 0 caso contrário.
 */

u8 Triangle(cumax A, cumax B, cumax C) {

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

void Average(void) {

	imax Sum, Input, N;

	for (Sum = 0, Input = 0, N = -1; Input != -1; N++) {

		scanf("%" PRIiMAX, &Input);
		Sum += Input;

	}

	/* Pois o último Input foi -1 */
	Sum++;

	printf("Média: %.2f\n", ((f32) Sum / (f32) N));

}

/*
 * Exercício 04
 * Imprime um quadrado NxN no formato assim exemplificado: se N = 3:
 *  x.x
 *  .x.
 *  x.x
 * Se N for par, retorna -1 sinalizando um erro.
 */

i8 Square(cu8 N) {

	ru8 l, c;

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

void Dynamic(i32 N) {

	imax *Vetor;
	imax  Sum;

	ri32   i;

	if ((Vetor = (imax *) malloc(N * sizeof(imax))) == NULL)
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

u16 StrLen(const wchar_t* String) {

	ru16 i;

	for (i = 0; String[i] != '\0'; i++);

	return i;

}

/*
 * Exercício 12
 * Retorna 1 caso X pertence ao vetor V de tamanho N.
 * Retorna 0 caso contrário.
 */

u8 Linear_Search(imax *V, cu16 N, cimax X) {

	ru16 i;

	for (i = 0; i < N; i++)
		if (V[i] == X)
			return 1;

	return 0;

}

int main(int argc, const char* argv[]) {

	(void) argc; (void) argv;

	return 0;

}

