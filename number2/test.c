#include "binComparison"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool run_tests()
{
    int s = 0;

    bool a[] = { 1, 0, 1 };
    bool b[] = { 1, 1, 1 };
    int size1 = sizeof(a) / sizeof(a[0]) int size1 = sizeof(b) / sizeof(b[0])

                                                         if (!compar(a, b, size1, size2))
    {
        s++;
    }

    bool c[] = { 1, 1, 1, 1 };
    bool d[] = { 1, 1, 1 };
    int size3 = sizeof(c) / sizeof(c[0]);
    int size4 = sizeof(d) / sizeof(d[0]);

    if (compar(c, d, size3, size4)) {
        s++;
    }

    bool e[] = { 1, 1, 0 };
    bool f[] = { 0, 1, 1 };
    int size5 = sizeof(e) / sizeof(e[0]);
    int size6 = sizeof(f) / sizeof(f[0]);
    if (compar(e, f, size5, size6)) {
        s++;
    }

    return s == 3;
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