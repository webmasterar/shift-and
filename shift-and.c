//License MIT 2016 Ahmad Retha
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shift-and.h"

void preprocess(WORD ** B, const char * p, unsigned int m)
{
    unsigned int i;
    for (i = 0; i < m; i++) {
        (*B)[p[i]] = (*B)[p[i]] | (1ul << i);
    }
}

void search(const char * t, unsigned int n, const char * p, unsigned int m)
{
    WORD * B;
    B = (WORD *) calloc(CHARLIMIT, WORDSIZE);

    preprocess(&B, p, m);

    WORD d = 0;
    WORD z = 1ul << m - 1;
    unsigned int i;
    for (i = 0; i < n; i++) {
        d = ((d << 1) | 1ul) & B[t[i]];
        if (d & z) {
            printf("Match found at position %u\n", i - m + 1);
        }
    }

    free(B);
}
