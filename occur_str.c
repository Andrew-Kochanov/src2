#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* cross(char* str, int indStart, int indFinish){
    int len = indFinish - indStart;
    char *crossStr = (char *)malloc((len + 1) * sizeof(char));

    int indCrStr = 0;
    int indStr = indStart;
    while (indStr < indFinish)
    {
        crossStr[indCrStr] = str[indStr];
        indStr++;
        indCrStr++;
    }

    crossStr[indCrStr] = '\0';

    return crossStr;
}


int main(int argc, char **argv)
{
    char str[1000];
    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);
    char str1[1000];
    printf("Введите подстроку: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    int count = 0;
    int lenStr = strlen(str);
    int lenStr1 = strlen(str1);
    for(int i = 0; i < lenStr - lenStr1 + 1; i++)
    {
        char* str2 = cross(str, i, i + lenStr1);
        if (strcmp(str1, str2) == 0)
        {
            printf("%s\n", str2);
            count++;
        }
        free(str2);
    }




    printf("Количество подстрок: %d\n", count);
    return 0;
}
