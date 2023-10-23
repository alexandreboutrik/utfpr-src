/*
 * B - Hour for a Run
 */

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

#define     UX      uintmax_t
#define     U8      uint_fast8_t

#define     Reg     register

int
main(int argc, const char *argv[])
{
    /*
     * Ranges:
     *  (1 <=   V) - Laps  - number of laps
     *  (N <= 104) - Signs - number of signs along the track
     */

    UX      Laps, Answer;
    U8      Signs;
    Reg U8  i;

    scanf("%" SCNuMAX " %" SCNuFAST8, &Laps, &Signs);

    for (i = 1; i < 10; i++)
    {
        Answer = (Laps * Signs * i);

        if (Answer % 10 == 0)
            Answer /= 10;
        else
            Answer = (Answer / 10) + 1;

        printf("%" PRIuMAX " ", Answer);
    }

    printf("\n");

    return 0;
}

