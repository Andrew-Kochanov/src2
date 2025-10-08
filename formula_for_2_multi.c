#include <stdio.h>

int main(int argc, char **argv)
{
    int x = 0;
    printf("Введите значение x: ");
    scanf("%d", &x);

    // квадрат числа
    int t = x * x;

    // сама формула
    int formula = (t + 1) * (t + x) + 1;
    printf("%d\n", formula);
    return 0;
}
