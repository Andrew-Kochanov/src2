#include <stdio.h>
#include <stdlib.h>

int countZero(int* array, int lenght)
{
    int count = 0;

    // проверка на нули и подсчет количества
    for (int i = 0; i < lenght; i++) {
        if (array[i] == 0) {
            count++;
        }
    }
    return count;
}

int main(int argc, char** argv)
{
    // создание массива с рандомными числами
    int len = 20;
    int* array = (int*)malloc(len * sizeof(int));

    for (int i = 0; i < len; i++) {
        int randNumber = rand() % 10;
        array[i] = randNumber;
        printf("%d ", randNumber);
    }
    printf("\n");

    printf("Количество нулей в массиве: %d\n", countZero(array, len));
    free(array);
    return 0;
}
