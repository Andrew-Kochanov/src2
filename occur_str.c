#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// функция для создания подстроки из строки по индексам
int countSubstring(char* str, char* str1)
{
    int count = 0;

    int lenStr = strlen(str);
    int lenStr1 = strlen(str1);

    for (int indStr = 0; indStr < lenStr - lenStr1; indStr++) {
        bool flag = true;
        for (int indStr1 = 0; indStr1 < lenStr1; indStr1++) {

            if (str[indStr + indStr1] != str1[indStr1]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            count++;
        }
    }
    return count;
}

int main(int argc, char** argv)
{
    char str[1000];
    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);
    char str1[1000];
    printf("Введите подстроку: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // меняем знак переноса строки на нулевой

    printf("Количество подстрок: %d\n", countSubstring(str, str1));
    return 0;
}
