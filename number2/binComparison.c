#include <stdbool.h>
#include <stdio.h>

int min(int a, int b)
{
    if (a > b) {
        return b;
    } else {
        return a;
    }
}

// проверяет, что первое больше второго
bool compar(bool num1[], bool num2[], int size1, int size2)
{
    int minInd = min(size1, size2);
    int i1 = 0;
    int i2 = 0;
    while (i1 < minInd && i2 < minInd) {
        if (num1[i1] < num2[i2]) {
            return false;
            break;
        }
        i1++;
        i2++;
    }
    if (size1 > size2) {
        return true;
    } else if (size1 < size2) {
        return false;
    }

    return true;
}