/*
 * Lista 1
 *  Algoritmos e Estruturas de Dados I
 * Recursão
 */

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <wchar.h>

typedef		intmax_t		imax;
typedef		int_fast16_t	i16;

typedef		uintmax_t		umax;
typedef		uint_fast16_t	u16;
typedef		uint_fast8_t	u8;

/*
 * Lista de Exercícios
 */

imax	 Fatorial		(imax);					/* Ex 02 */
imax	 Power_2		(imax);					/* Ex 05 */
imax	 Fibonnaci		(imax);					/* Ex 07 */
u16		 Digits			(imax);					/* Ex 08 */

void	 PrintIn_Digits	(imax);					/* Ex 09 */
void	 Print_Digits	(imax);					/* Ex 10 */
void	 Print_Bin		(imax);					/* Ex 11 */

imax	 Pow			(imax, imax);			/* Ex 12 */
imax	 Custom_Pow		(imax, imax);			/* Ex 13 */
imax	 Sum			(imax*, u16);			/* Ex 14 */
u8		 Linear_Search	(imax*, u16, imax);		/* Ex 15 */
imax	 Biggest		(imax*, u16);			/* Ex 16 */
u16		 StrLen			(wchar_t*);				/* Ex 17 */
u8		 Palindrome		(imax*, u16);			/* Ex 18 */

void	 Print_Inv		(imax*, u16);			/* Ex 19 */

imax	 Sum_Digits		(imax);					/* Sala de Aula */

/*
 * Função Recursiva - Ex 02
 * Calcula o fatorial de um inteiro N.
 */

imax Fatorial(imax N) {

	if (N == 0)
		return 1;

	return (N * Fatorial(N-1));

}

/*
 * Função Recursiva - Ex 05
 * Retorna 2^N.
 */

imax Power_2(imax N) {

	if (N == 0)
		return 1;

	return (Power_2(N-1) + Power_2(N-1));

}

/*
 * Função Recursiva - Ex 07
 * Retona o N-ésimo número da sequência de Fibonacci.
 */

imax Fibonnaci(imax N) {

	if (N == 0 || N == 1)
		return N;
	
	return (Fibonnaci(N-1) + Fibonnaci(N-2));

}

/*
 * Função Recursiva - Ex 08
 * Retorna a quantidade de dígitos de um inteiro N.
 */

u16 Digits(imax N) {

	if (N == 0)
		return 0;

	return (1 + Digits(N / 10));

}

/*
 * Função Recursiva - Ex 09
 * Imprime os dígitos de um inteiro N da direita para a esquerda.
 */

void PrintIn_Digits(imax N) {

	if (N == 0)
		return;

	printf("%" PRIiMAX, (N % 10));

	PrintIn_Digits(N / 10);

}

/*
 * Função Recursiva - Ex 10
 * Imprime os dígitos de um inteiro N da esquerda para a direita.
 */

void Print_Digits(imax N) {

	if (N == 0)
		return;

	Print_Digits(N / 10);

	printf("%" PRIiMAX, (N % 10));

}

/*
 * Função Recursiva - Ex 11
 * Imprime a representação binária de um inteiro N.
 */

void Print_Bin(imax N) {

	if (N == 0)
		return;

	Print_Bin(N / 2);

	printf("%" PRIiMAX, (N % 2));

}

/*
 * Função Recursiva - Ex 12
 * Retorna X^K.
 */

imax Pow(imax X, imax K) {

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

imax Custom_Pow(imax X, imax K) {

	if (K == 0)
		return 1;

	if (K % 2 == 0)
		return Pow(Pow(X, K/2), 2);

	return (X * Pow(X, K-1));

}

/*
 * Função Recursiva - Ex 14
 * Retorna a soma os elementos de um vetor V de tamanho N.
 */

imax Sum(imax *V, u16 N) {

	if (N == 0)
		return 0;

	return (V[0] + Sum(&(V[0]), N-1));

}

/*
 * Função Recursiva - Ex 15
 * Retorna 1 caso X pertença ao vetor V de tamanho N. Retorna 0 caso
 * contrário.
 */

u8 Linear_Search(imax *V, u16 N, imax X) {

	if (N == 0)
		return 0;

	if (V[N-1] == X)
		return 1;

	return Linear_Search(&(V[0]), N-1, X);


}

/*
 * Função Recursiva - Ex 16
 * Retorna o maior elemento de um vetor V de tamanho N.
 */

imax Biggest(imax *V, u16 N) {

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

u16 StrLen(wchar_t* String) {

	if (String[0] == '\0')
		return 0;

	return (1 + StrLen(&(String[1])));

}

/*
 * Função Recursiva - Ex 18
 * Retorna 1 se o vetor V é palíndrome, 0 caso contrário.
 */

u8 Palindrome(imax *V, u16 N) {

	if (N == 0)
		return 1;

	if (V[0] == V[N-1])
		return Palindrome(&(V[1]), N-2);

}

/*
 * Função Recursiva - Ex 19
 * Imprime os elementos do vetor V de tamanho N na ordem invertida.
 */

void Print_Inv(imax *V, u16 N) {

	if (N == 0)
		return;

	printf("%" PRIiMAX, V[N-1]);

	return Print_Inv(&(V[0]), N-1);

}

/*
 * Função Recursiva - Ex de Sala
 * Retorna a soma dos dígitos de um inteiro N.
 */

imax Sum_Digits(imax N) {

	if (N == 0)
		return 0;

	return ((N % 10) + Sum_Digits(N / 10));

}

int main(int argc, const char* argv[]) {

	(void) argc; (void) argv;

	return 0;

}

