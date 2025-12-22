#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "binRepresent.h"

void binPrint(int num[])
{
    for (int i = 0; i < 32; i++) {
        printf("%d", num[i]);
    }
    printf("\n");
}

void bin(int result[], int number)
{
    int num = number;
    if (number < 0) {
        num *= -1;
    }
    int ind = 31;

    while (num != 0) {
        result[ind] = num % 2;
        num /= 2;
        ind--;
    }

    if (number < 0) {
        for (int i = 1; i < 32; i++) {
            result[i] = 1 - result[i];
        }
        result[0] = 1;

        int one[32] = { 0 };
        one[31] = 1;
        binSumm(result, one, result); 
    }
}

int decimal(int num[])
{
    int decimalNum = 0;

    for (int i = 0; i < 32; i++) {
        int degree = 1 << i;
        decimalNum += degree * num[31 - i];
    }
    return decimalNum;
}

void binSumm(int result[], int num1[], int num2[])
{
    int carry = 0;
    for (int i = 31; i > -1; i--) {
        int sum = num1[i] + num2[i] + carry;
        result[i] = sum % 2;
        carry = sum / 2;
    }
}

int decSumm(int num1[], int num2[])
{
    int biSumm[32] = { 0 };
    binSumm(biSumm, num1, num2);
    int deSumm = decimal(biSumm);
    return deSumm;
}