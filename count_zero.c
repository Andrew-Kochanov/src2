#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char str[1000];
    printf("%s", "Введите числа массива через пробел: ");
    fgets(str, sizeof(str), stdin);
    int count = 0;

    for (int i = 0; i < strlen(str); i+2)
    {
        if (str[i] == '0')
        {
            count++;
        }
    }

    printf("%d", count);
    return 0;
}
