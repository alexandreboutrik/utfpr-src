/*
 * Trabalho de Física I
 */

#include <inttypes.h>
#include <locale.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

#define     UX      uintmax_t
#define     I16     int_fast16_t
#define     F64     double
#define     U0      void

#define     Fn      static
#define     In      inline
#define     Reg     register
#define     Cst     const

typedef struct Block Block;
struct Block {

    UX      mass;          /* massa do bloco */

    F64     v_initial;     /* velocidade inicial do bloco */
    F64     v_final;       /* velocidade final do bloco */

};

/*
 * Lista de funções
 */

Fn  In I16      ReadInput           (void);
Fn  U0          InitData            (Block*, Block*);

Fn  U0          CalculateCollision  (Block*, Block*);
Fn  U0          PrintNCollision     (Cst UX);

/* Lê um input do usuário para o valor 'd' */
Fn In I16
ReadInput(void)
{
    I16 Input;

    printf("Digite o valor de d: ");
    scanf("%" SCNiFAST16, &Input);

    return Input;
}

/* Inicializa as structs */
Fn U0
InitData(Block* B1, Block* B2)
{
    B1->mass        =   1;      /* 1 Kg */
    B1->v_initial   =   0;      /* está em repouso */

    B2->mass        =   pow(100, ReadInput());
    B2->v_initial   =   -1;     /* -1 m/s */

    /*
     * B2->v_final deve ser menor que B1->v_final para
     * o condicional do for
     */
    B2->v_final = 0; B1->v_final = 1;
}

/*
 * Calcula a velocidade dos dois blocos após a colisão
 */
Fn U0
CalculateCollision(Block *B1, Block *B2) 
{
    B1->v_final = (( (F64) B1->mass - (F64) B2->mass) * B1->v_initial +
            (2 * (F64) B2->mass * B2->v_initial)) /
            ( (F64) B1->mass + (F64) B2->mass);

    B2->v_final = (( (F64) B2->mass - (F64) B1->mass) * B2->v_initial +
            (2 * (F64) B1->mass * B1->v_initial)) /
            ( (F64) B1->mass + (F64) B2->mass);
}

/*
 * Imprime o valor do contador de colisões na tela
 */
Fn U0
PrintNCollision(Cst UX count)
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
    Reg UX count;

    /* Blocos */
    Block B1, B2;

    /* Inicializa as structs */
    InitData(&B1, &B2);

    for (count = 0; B2.v_final < B1.v_final; count += 2U) {

        CalculateCollision(&B1, &B2);

        B1.v_final = B1.v_final * (-1.0);

        B1.v_initial = B1.v_final;
        B2.v_initial = B2.v_final;

        /*
         * Para diminuir a quantidade de printf, só imprimimos
         * Count em múltiplos de 1 milhão (10^6)
         */
        if (count % 1000000U == 0)
            PrintNCollision(count / 1000000U);

    }

    /* Decremento pois não houve colisão entre blocos no último laço */
    --count;

    printf("\rOcorreram %" PRIuMAX " colisões.\n", count);

    return 0;
}

