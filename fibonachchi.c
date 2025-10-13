#include <stdio.h>

// функция суммы четных чисел фибоначчи
int evenFibonachchi()
{
    // индекс для текущего числа фибоначчи, сразу с двойки начал
    int index = 3;
    int formerNumberFib = 1;
    int numberFib = 2;
    int sum = 0;
    
    // прибавляет каждое третье число фибоначчи, так как оно четно
    while (numberFib < 1000000) {
        if (index % 3 == 0) {
            sum += numberFib;
        }
        index++;
        numberFib += formerNumberFib;
        formerNumberFib = numberFib - formerNumberFib;
    }
    return sum;
}

int main(int argc, char** argv)
{
    printf("%d\n", evenFibonachchi());
    return 0;
}