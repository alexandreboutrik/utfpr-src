/*
 * C - Na Travel
 */

#include <err.h>
#include <errno.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define     UX      uintmax_t
#define     U8      uint_fast8_t

#define     Reg     register

int
main(int argc, const char *argv[])
{
    /*
     * Ranges:
     *  (1 <=  Y        ) -  Y - quantidade de anos de competições
     *  (      N <=  315) -  N - competidores que Vini conversou
     *  (0 <= Xi <=  105) - Xi - vagas para a ICPC em cada ano   (i->Y)
     *  (1 <= Ai <=    Y) - Ai - ano em que o i-ésimo participou (i->N)
     *  (1 <= Pi <=  105) - Pi - colocação do i-ésimo            (i->N)
     *  (0 <= Fi <= Y-Ai) - Fi - anos em que seguiram na ativa   (i->N)
     */

    UX      Y, A, F;
    U8      N, *X, P;

    Reg U8  i, j, Frustration;

    scanf("%" SCNuMAX " %" SCNuFAST8, &Y, &N);

    if ((X = (U8 *) calloc(Y, sizeof(U8))) == NULL)
        err(errno, "calloc");

    for (i = 0; i < Y; i++)
        scanf("%" SCNuFAST8, &(X[i]));

    for (i = 0, Frustration = 0; i < N; i++, Frustration = 0)
    {
        scanf("%" SCNuMAX " %" SCNuFAST8 " %" SCNuMAX, &A, &P, &F);

        if (X[A-1] < P)
            for (j = 1; j <= F; j++)
                if (X[A+j-1] >= P)
                        Frustration++;

        printf("%" PRIuFAST8 "\n", Frustration);
    }

    free(X);

    return 0;
}

