/*
 * E - Insert Digit
 */

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <wchar.h>

#define     S16     wchar_t
#define     U8      uint_fast8_t

#define     Reg     register

#define     True    1
#define     False   0

int
main(int argc, const char *argv[])
{
    /*
     * Ranges:
     *  (1 <= t <= 104) - t      - Number of test cases
     *  (1 <= n <= 210) - Length - Lenght of the number
     *  (0 <= d <=   9) - Digit  - Additional digit
     */

    S16      Number[256], Output[256];

    U8       t, Length, Digit, Inserted;
    Reg U8   i, j, k;

    scanf("%" SCNuFAST8, &t);

    for (i = 0; i < t; i++)
    {
        scanf("%" SCNuFAST8 " %" SCNuFAST8 " %ls", 
            &Length, &Digit, &(Number[0]));

        for (j = 0, k = 0, Inserted = False; j < Length; j++)
        {
            if ( ((Number[j] - L'0') < Digit) && (Inserted == False))
            {
                Output[k++] = (Digit + L'0');
                Inserted    = True;
            }

            Output[k++] = Number[j];
        }
        Output[k] = L'\0';
        
        printf("%ls\n", Output);
    }

    return 0;
}

