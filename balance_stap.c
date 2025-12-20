#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void balance(char* str)
{
    // коэф для проверки вложености скобок во время пробежки по строке(если коэф меньше 0, вложенность нарушена)
    // открывающая скобка имеет коэф +1
    // закрывающая скобка имеет коэф -1
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(') {
            count++;

        } else if (str[i] == ')') {
            count--;
        }
    }

    // если после пробежки по строке коэф неравен 0, значит, количество открывающих и закрывающих скобок разное
    if (count == 0) {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char** argv)
{
    char str[1000];
    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);
    if (balance(str)) {
        printf("Баланс есть");
    } else {
        printf("Баланса нет");
    }

    return 0;
}
