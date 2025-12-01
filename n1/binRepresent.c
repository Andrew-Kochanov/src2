#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void binPrint(int num[])
{
    for (int i = 0; i < 32; i++) {
        printf("%d", num[i]);
    }
    printf("\n");
}

int* bin(int number)
{

    int num = number;
    int* binary = (int*)malloc(32 * sizeof(int));
    if (number < 0) {
        num *= -1;
    }
    int ind = 31;

    while (num != 0) {
        binary[ind] = num % 2;
        num /= 2;
        ind--;
    }

    if (number < 0) {
        for (int i = 1; i < 32; i++) {
            if (binary[i] == 1) {
                binary[i] = 0;
            } else {
                binary[i] = 1;
            }
        }
        binary[0] = 1;

        binary[31]++;
        ind = 31;
        while (binary[ind] == 2) {
            binary[ind] = 0;
            binary[ind - 1]++;
            ind--;
        }
    }
    return binary;
}

int decimal(int num[])
{
    int decimalNum = 0;

    if (num[0] == 0) {
        for (int i = 1; i < 32; i++) {
            int degree = pow(2, i - 1);
            decimalNum += degree * num[31 - i + 1];
        }
        return decimalNum;
    } else {
        for (int i = 1; i < 32; i++) {
            if (num[i] == 1) {
                num[i] = 0;
            } else {
                num[i] = 1;
            }
        }
        num[0] = 1;

        num[31]++;
        int ind = 31;
        while (num[ind] == 2) {
            num[ind] = 0;
            num[ind - 1]++;
            ind--;
        }

        for (int i = 1; i < 32; i++) {
            int degree = pow(2, i - 1);
            decimalNum += degree * num[31 - i + 1];
        }
        return -decimalNum;
    }
}

int* binSumm(int num1[], int num2[])
{
    int* results = (int*)(malloc(32 * sizeof(int)));
    int carry = 0;

    for (int i = 31; i > -1; i--) {
        int sum = num1[i] + num2[i] + carry;
        results[i] = sum % 2;
        carry = sum / 2;
    }
    return results;
}

int decSumm(int num1[], int num2[])
{
    int* biSumm = binSumm(num1, num2);
    int deSumm = decimal(biSumm);
    return deSumm;
}
