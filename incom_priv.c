#include <stdio.h>

int main(int argc, char **argv)
{
    int a = 0;
    int b = 0;
    printf("Введите число a: ");
    scanf("%d", &a);
    printf("Введите число b: ");
    scanf("%d", &b);

    // счетчик для неполного частного
    int incomp = 0;

    //коэф прибавляемый к счетчику
    int count = 1;

    if (a < 0)
    {
        a *= -1;
        count *= -1;
        incomp -= 1;
    }
    if (b < 0)
    {
        b *= -1;
        count *= -1;
        incomp *= -1;
    }

    // вычитаем из a число b до тех пор пока b не станет больше а. И прибавляем к счетчику 1.
    while (a > b)
    {
        a = a - b;
        incomp += count;
    }

    printf("Неполное частное: %d", incomp);
    return 0;
}
