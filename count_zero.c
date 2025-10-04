#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    // создание массива с рандомными числами
    int len = 20;
    int* array = (int *)malloc(len * sizeof(int));

    for (int i = 0; i < len; i++)
    {
        array[i] = rand() % 10;
    }

    int count = 0;

    // проверка на нули и подсчет количества
    for (int i = 0; i < len; i++)
    {
        if (array[i] == 0)
        {
            count++;
        }
    }

    printf("Количество нулей в массиве: %d\n", count);
    free(array);
    return 0;
}
