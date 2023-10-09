/*
 * Trabalho de Física I
 */

#include <inttypes.h>
#include <locale.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

#define		umax		uintmax_t
#define		i16			int_fast16_t
#define		f64			double

typedef struct Block {

	umax	 mass;			/* massa do bloco */

	f64		 v_initial;		/* velocidade inicial do bloco */
	f64		 v_final;		/* velocidade final do bloco */

} Block;

/*
 * Lista de funções
 */

static inline i16	 ReadInput			(void);
static void			 InitData			(Block*, Block*);

static void			 CalculateCollision	(Block*, Block *);
static void			 PrintNCollision	(const umax);

/* Lê um input do usuário para o valor 'd' */
static inline i16 
ReadInput(void)
{
	i16 Input;

	printf("Digite o valor de d: ");
	scanf("%" SCNiFAST16, &Input);

	return Input;
}

/* Inicializa as structs */
static void 
InitData(Block* B1, Block* B2)
{
	B1->mass		=	1;		/* 1 Kg */
	B1->v_initial	=	0;		/* está em repouso */

	B2->mass		=	pow(100, ReadInput());
	B2->v_initial	=	-1;		/* -1 m/s */

	/*
	 * B2->v_final deve ser menor que B1->v_final para
	 * o condicional do for
	 */
	B2->v_final	= 0; B1->v_final = 1;
}

/*
 * Calcula a velocidade dos dois blocos após a colisão
 */
static void 
CalculateCollision(Block* B1, Block* B2) 
{
	B1->v_final = (( (f64) B1->mass - (f64) B2->mass) * B1->v_initial +
			(2 * (f64) B2->mass * B2->v_initial)) /
			( (f64) B1->mass + (f64) B2->mass);

	B2->v_final = (( (f64) B2->mass - (f64) B1->mass) * B2->v_initial +
			(2 * (f64) B1->mass * B1->v_initial)) /
			( (f64) B1->mass + (f64) B2->mass);
}

/*
 * Imprime o valor do contador de colisões na tela
 */
static void 
PrintNCollision(const umax count)
{
	/* carriage return, retorna ao início da linha */
	printf("\r");

	printf(" colisões: %" PRIuMAX " x 10^6", count);
}

/*
 * Trabalho de Física 1
 */
int 
main(int argc, const char* argv[])
{
	setlocale(LC_CTYPE, "");

	/* Contador de colisões */
	register umax count;

	/* Blocos */
	Block B1, B2;

	/* Inicializa as structs */
	InitData(&B1, &B2);

	for (count = 0; B2.v_final < B1.v_final; count += 2) {

		CalculateCollision(&B1, &B2);

		B1.v_final = B1.v_final * (-1.0);

		B1.v_initial = B1.v_final;
		B2.v_initial = B2.v_final;

		/*
		 * Para diminuir a quantidade de printf, só imprimimos
		 * Count em múltiplos de 1 milhão (10^6)
		 */
		if (count % 1000000 == 0)
			PrintNCollision(count / 1000000);

	}

	/* Decremento pois não houve colisão entre blocos no último laço */
	--count;

	printf("\rOcorreram %" PRIuMAX " colisões.\n", count);

	return 0;
}

