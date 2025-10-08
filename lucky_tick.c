#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int array[28] = {0};

    for (int num = 0; num < 1000; num++)
    {
        int sumNumber = (num / 10 % 10) + num / 100 + num % 10;
        array[sumNumber]++;
    }

    int sum = 0;
    for (int ind = 0; ind < 28; ind++)
    {
        sum += pow(array[ind], 2);
    }
    printf("Количество счасливых билетов: %d\n", sum);
    return 0;
}
