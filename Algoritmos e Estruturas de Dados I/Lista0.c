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

typedef		intmax_t			imax;
typedef		int_fast8_t			i8;

typedef		uintmax_t			umax;
typedef		uint_fast16_t		u16;
typedef		uint_fast8_t		u8;

typedef		float				f32;

/*
 * Lista de Exercícios
 */

void	 HelloWorld		(void);					/* Ex 01 */

u8		 Triangle		(umax, umax, umax);		/* Ex 02 */
void	 Average		(void);					/* Ex 03 */
i8		 Square			(u8);					/* Ex 04 */
void	 Dynamic		(u16);					/* Ex 05 */
u16		 StrLen			(wchar_t*);				/* Ex 07 */

u8		 Linear_Search	(imax*, u16, imax);		/* Ex 12 */

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

u8 Triangle(umax A, umax B, umax C) {

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

i8 Square(u8 N) {

	u8 l, c;

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

void Dynamic(u16 N) {

	imax *Vetor;
	imax  Sum;

	u16   i;

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

u16 StrLen(wchar_t* String) {

	u16 i;

	for (i = 0; String[i] != '\0'; i++);

	return i;

}

/*
 * Exercício 12
 * Retorna 1 caso X pertence ao vetor V de tamanho N.
 * Retorna 0 caso contrário.
 */

u8 Linear_Search(imax *V, u16 N, imax X) {

	u16 i;

	for (i = 0; i < N; i++)
		if (V[i] == X)
			return 1;

	return 0;

}

int main(int argc, const char* argv[]) {

	(void) argc; (void) argv;

	return 0;

}

