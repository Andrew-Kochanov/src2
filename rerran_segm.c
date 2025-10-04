#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int m = 0;
    int n = 0;
    printf("Введите длину начала: ");
    scanf("%d", &m);
    printf("Введите длину конца: ");
    scanf("%d", &n);

    //создание динамического массива
    int lenght = m + n;
    int* list = (int *)malloc(lenght * sizeof(int));
    for (int i = 1; i < m + n + 1; i++)
    {
        list[i - 1] = i;
    }

    // сдвиг отрезка m на 1 n раз
    // каждый следущий элемент после отрезка m передвигает в начало массива
    for (int step1 = 0; step1 < n; step1++)
    {
        for(int step2 = m + step1; step2 > step1; step2--)
        {
            int temprery = list[step2];
            list[step2] = list[step2 - 1];
            list[step2 - 1] = temprery;
        }
    }

    //вывод массива
    for (int i = 0; i < lenght; i++)
    {
        printf(" %d", list[i]);
    }
    printf("\n");
    free(list);
    return 0;
}
