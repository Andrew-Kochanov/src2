#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void balance(char* str, int lenght)
{
    struct Stack* staples = new();
    char openParent;
    bool flag = true;
    for (int ind = 0; ind < lenght; ind++) {
        if (str[ind] == '(' || str[ind] == '{' || str[ind] == '[') {
            push(staples, str[ind]);
        } else {
            switch (str[ind]) {
            case ')':
                openParent = pop(staples);
                if (openParent != '(') {
                    flag = false;
                }
                break;
            case '}':
                openParent = pop(staples);
                if (openParent != '{') {
                    flag = false;
                }
                break;
            case ']':
                openParent = pop(staples);
                if (openParent != '[') {
                    flag = false;
                }
                break;
            }
            if (!flag) {
                break;
            }
        }
    }
    if (isEmpty(staples) && flag) {
        printf("Баланс есть\n");
        free(staples);
    } else {
        printf("Баланса нет\n");
        free(staples);
    }
}

int main(int argc, char** argv)
{
    char str[1000];
    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);
    balance(str, strlen(str));

    return 0;
}
