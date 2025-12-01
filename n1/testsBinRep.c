#include "binRepresent"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool sravn(int* bin1, int* bin2)
{
    for (int i = 0; i < 32; i++) {
        if (bin1[i] != bin2[i]) {
            return false;
        }
    }
    return true;
}

bool run_tests()
{
    int s = 0;

    int a = 1;
    int* b = bin(a);
    int b2[32] = { 0 };
    b2[31] = 1;
    if (sravn(b, b2)) {
        s++;
    }
    printf("%d\n", s);

    int c = decimal(b);
    if (c == 1) {
        s++;
    }
    printf("%d\n", s);

    int* d = bin(-a);
    int* e = binSumm(d, b);
    int e2[32] = { 0 };
    if (sravn(e, e2)) {
        s++;
    }
    printf("%d\n", s);

    int f = decSumm(d, b);
    if (f == 0) {
        s++;
    }
    printf("%d\n", s);

    return s == 4;
}

int main(int argc, char* argv[])
{
    if (argc == 2 && strcmp(argv[1], "--test") == 0) {
        if (run_tests()) {
            return 0;
        } else {
            return 1;
        }
    }
}