#include "binRepresent.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int length = 32;

bool run_tests()
{
    int s = 0;

    int number1 = 1;
    int number1Bin[32] = { 0 };
    bin(number1Bin, number1);
    int number2Bin[32] = { 0 };
    number2Bin[31] = 1;
    if (memcmp(number1Bin, number2Bin, length) == 0) {
        s++;
    }

    int number3 = decimal(number1Bin);
    if (number3 == 1) {
        s++;
    }

    int number4Bin[32] = { 0 };
    bin(number4Bin, -number1);
    int number5Bin[32] = { 0 };
    binSumm(number5Bin, number4Bin, number1Bin);
    int number6Bin[32] = { 0 };
    if (memcmp(number5Bin, number6Bin, length) == 0) {
        s++;
    }

    int number7 = decSumm(number4Bin, number1Bin);
    if (number7 == 0) {
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
    printf("Введите второе число(целое не больше 2^32): ");
    scanf("%d", &number2);

    int num1Bin[32] = { 0 };
    bin(num1Bin, number1);
    int num2Bin[32] = { 0 };
    bin(num2Bin, number2);

    printf("%d в двоичном представлении: ", number1);
    binPrint(num1Bin);
    printf("%d в двоичном представлении: ", number2);
    binPrint(num2Bin);

    int summ[32] = { 0 };
    binSumm(summ, num1Bin, num2Bin);
    printf("Сумма в двоичной системе: ");
    binPrint(summ);

    int sumDecimal = decimal(summ);
    printf("Сумма в десятичной системе %d\n", sumDecimal);

    return 0;
}