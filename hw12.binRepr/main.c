#include "../binRepr/binRepresent.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

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

    int c = decimal(b);
    if (c == 1) {
        s++;
    }

    int* d = bin(-a);
    int* e = binSumm(d, b);
    int e2[32] = { 0 };
    if (sravn(e, e2)) {
        s++;
    }

    int f = decSumm(d, b);
    if (f == 0) {
        s++;
    }

    return s == 4;
}

int main(int argc, char** argv)
{
    if (argc == 2 && strcmp(argv[1], "--test") == 0) {
        if (!run_tests()) {
            printf("Test failed\n");
            return 1;
        } else {
            printf("Test passed\n");
            return 0;
        }
    }

    int number1 = 0;
    printf("Введите первое число(целое не больше 2^32): ");
    scanf("%d", &number1);
    int number2 = 0;
    prntf("Введите второе число(целое не больше 2^32): ");
    scanf("%d", number2);

    int* num1Bin = bin(number1);
    int* num2Bin = bin(number2);

    printf("%d в двоичном представлении: ", number1);
    binPrint(num1Bin);
    printf("%d в двоичном представлении: ", number2);
    binPrint(num2Bin);

    int* summ = binSumm(num1Bin, num2Bin);
    prinf("Сумма в двоичной системе: ");
    binPrint(summ);
    
    int sumDecimal = decimal(summ);
    printf("Сумма в десятичной системе %d", sumDecimal);

    return 0;
}