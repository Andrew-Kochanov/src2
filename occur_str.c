#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char str[1000];
    fgets(str, sizeof(str), stdin);
    // char str1[1000];
    // fgets(str, sizeof(str1), stdin);
    // int len = strlen(str1);
    // int count = 0;
    // for (int i = 0; i < strlen(str); i++)
    // {
    //     if (str[i] == '(')
    //     {
    //         ratio++;

    //     }
    //     else if (str[i] == ')')
    //     {
    //         ratio -= 1;
    //     }
    //     if (ratio < 0)
    //     {
    //         printf("Баланса нет");
    //         return 0;
    //     }

    // }
    // if (ratio == 0)
    // {
    //     printf("Баланс есть");
    // } else {
    //     printf("Баланса нет");
    // }

    strcat(str, 2, 5);
    printf("%s", str);
    return 0;
}
