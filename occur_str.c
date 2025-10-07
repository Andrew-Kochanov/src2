#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// функция для создания подстроки из строки по индексам
char* cross(char* str, int indStart, int indFinish){

    // длина подстроки с учетом нулевого элемента
    int len = indFinish - indStart + 1;
    // выделение памяти
    char *crossStr = (char *)malloc((len) * sizeof(char));

    int indCrStr = 0; // индекс для подстроки
    int indStr = indStart; // индекс для строки

    while (indStr < indFinish)
    {
        crossStr[indCrStr] = str[indStr]; // присвоение элементу подстроки значение элемента строки
        indStr++;
        indCrStr++;
    }

    crossStr[indCrStr] = '\0'; // добавление нулевого элемента

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
    str1[strcspn(str1, "\n")] = '\0'; // меняем знак переноса строки на нулевой

    int count = 0;
    int lenStr = strlen(str);
    int lenStr1 = strlen(str1);

    // пробегаем по строке по-элементно, выделяем подстроку, сравнием полученную подстроку с исходной
    for(int i = 0; i < lenStr - lenStr1 + 1; i++)
    {
        char* str2 = cross(str, i, i + lenStr1);
        if (strcmp(str1, str2) == 0)
        {
            count++;
        }
        // освобождаем память
        free(str2);
    }

    printf("Количество подстрок: %d\n", count);
    return 0;
}
