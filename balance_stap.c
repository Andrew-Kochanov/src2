#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void balance(char* str)
{
    // флаг для вложенности
    bool flag = true;

    // коэф для проверки вложености скобок во время пробежки по строке(если коэф меньше 0, вложенность нарушена)
    // открывающая скобка имеет коэф +1
    // закрывающая скобка имеет коэф -1
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(') {
            count++;

        } else if (str[i] == ')') {
            count -= 1;
        }
        if (count < 0) {
            flag = false;
        }
    }

    // если после пробежки по строке коэф неравен 0, значит, количество открывающих и закрывающих скобок разное
    if (count == 0 && flag) {
        printf("Баланс есть\n");
    } else {
        printf("Баланса нет\n");
    }
}

int main(int argc, char** argv)
{
    char str[1000];
    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);
    balance(str);

    return 0;
}
