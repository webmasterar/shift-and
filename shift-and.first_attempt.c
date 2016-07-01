//License MIT 2016 Ahmad Retha
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shift-and.h"

void preprocess(WORD ** B, const char * p, unsigned int m)
{
    unsigned int i;
    for (i = 0; i < m; i++) {
        (*B)[p[i]] = (*B)[p[i]] | (1ul << (m - i - 1));
    }
}

void search(const char * t, unsigned int n, const char * p, unsigned int m)
{
    WORD * B;
    B = (WORD *) calloc(CHARLIMIT, WORDSIZE);

    preprocess(&B, p, m);

    WORD d = 0;
    WORD z = 1ul << m - 1;
    int i;
    for (i = n - 1; i > -1; i--) {
        d = ((d << 1) + 1) & B[t[i]];
        if (d & z) {
            printf("Match found at position %u\n", i);
        }
    }

    free(B);
}
