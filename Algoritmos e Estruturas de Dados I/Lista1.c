/*
 * Lista 1
 *  Algoritmos e Estruturas de Dados I
 * Recursão
 */

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <wchar.h>

#define		imax		intmax_t
#define		umax		uintmax_t

#define		u16			uint_fast16_t
#define		u8			uint_fast8_t

#define		cimax		const intmax_t
#define		cumax		const uintmax_t
#define		cu16		const uint_fast16_t

/*
 * Lista de Exercícios
 */

imax	 Fatorial		(cimax);				/* Ex 02 */
imax	 Power_2		(cimax);				/* Ex 05 */
imax	 Fibonnaci		(cimax);				/* Ex 07 */
u16		 Digits			(cimax);				/* Ex 08 */

void	 PrintIn_Digits	(cimax);				/* Ex 09 */
void	 Print_Digits	(cimax);				/* Ex 10 */
void	 Print_Bin		(cimax);				/* Ex 11 */

imax	 Pow			(cimax, cimax);			/* Ex 12 */
imax	 Custom_Pow		(cimax, cimax);			/* Ex 13 */
imax	 Sum			(imax*, cu16);			/* Ex 14 */
u8		 Linear_Search	(imax*, cu16, cimax);	/* Ex 15 */
imax	 Biggest		(imax*, cu16);			/* Ex 16 */
u16		 StrLen			(const wchar_t*);		/* Ex 17 */
u8		 Palindrome		(imax*, cu16);			/* Ex 18 */

void	 Print_Inv		(imax*, cu16);			/* Ex 19 */

imax	 Sum_Digits		(cimax);				/* Sala de Aula */

/*
 * Função Recursiva - Ex 02
 * Calcula o fatorial de um inteiro N.
 */

imax Fatorial(cimax N) {

	if (N == 0)
		return 1;

	return (N * Fatorial(N-1));

}

/*
 * Função Recursiva - Ex 05
 * Retorna 2^N.
 */

imax Power_2(cimax N) {

	if (N == 0)
		return 1;

	return (Power_2(N-1) + Power_2(N-1));

}

/*
 * Função Recursiva - Ex 07
 * Retona o N-ésimo número da sequência de Fibonacci.
 */

imax Fibonnaci(cimax N) {

	if (N == 0 || N == 1)
		return N;
	
	return (Fibonnaci(N-1) + Fibonnaci(N-2));

}

/*
 * Função Recursiva - Ex 08
 * Retorna a quantidade de dígitos de um inteiro N.
 */

u16 Digits(cimax N) {

	if (N == 0)
		return 0;

	return (1 + Digits(N / 10));

}

/*
 * Função Recursiva - Ex 09
 * Imprime os dígitos de um inteiro N da direita para a esquerda.
 */

void PrintIn_Digits(cimax N) {

	if (N == 0)
		return;

	printf("%" PRIiMAX, (N % 10));

	PrintIn_Digits(N / 10);

}

/*
 * Função Recursiva - Ex 10
 * Imprime os dígitos de um inteiro N da esquerda para a direita.
 */

void Print_Digits(cimax N) {

	if (N == 0)
		return;

	Print_Digits(N / 10);

	printf("%" PRIiMAX, (N % 10));

}

/*
 * Função Recursiva - Ex 11
 * Imprime a representação binária de um inteiro N.
 */

void Print_Bin(cimax N) {

	if (N == 0)
		return;

	Print_Bin(N / 2);

	printf("%" PRIiMAX, (N % 2));

}

/*
 * Função Recursiva - Ex 12
 * Retorna X^K.
 */

imax Pow(cimax X, cimax K) {

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

imax Custom_Pow(cimax X, cimax K) {

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

imax Sum(imax *V, cu16 N) {

	if (N == 0)
		return 0;

	return (V[0] + Sum(&(V[0]), N-1));

}

/*
 * Função Recursiva - Ex 15
 * Retorna 1 caso X pertença ao vetor V de tamanho N. Retorna 0 caso
 * contrário.
 */

u8 Linear_Search(imax *V, cu16 N, cimax X) {

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

imax Biggest(imax *V, cu16 N) {

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

u16 StrLen(const wchar_t* String) {

	if (String[0] == '\0')
		return 0;

	return (1 + StrLen(&(String[1])));

}

/*
 * Função Recursiva - Ex 18
 * Retorna 1 se o vetor V é palíndrome, 0 caso contrário.
 */

u8 Palindrome(imax *V, cu16 N) {

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

void Print_Inv(imax *V, cu16 N) {

	if (N == 0)
		return;

	printf("%" PRIiMAX, V[N-1]);

	Print_Inv(&(V[0]), N-1);

}

/*
 * Função Recursiva - Ex de Sala
 * Retorna a soma dos dígitos de um inteiro N.
 */

imax Sum_Digits(cimax N) {

	if (N == 0)
		return 0;

	return ((N % 10) + Sum_Digits(N / 10));

}

int main(int argc, const char* argv[]) {

	(void) argc; (void) argv;

	return 0;

}

