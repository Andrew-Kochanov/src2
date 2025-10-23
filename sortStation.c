#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// переносит все операторы от ")" до "(" из стека в очередь по индексу ind
int moveBtwStap(struct Stack* stack, char* queue, int ind)
{
    int index = ind;
    char operator = pop(stack);
    while (operator != '(' && operator != '\0') {
        index++;
        // printf("%s\n", queue[ind]);
        queue[index] = operator;
        operator = pop(stack);
    }
    return index;
}

char* postfNotation(char* str, int lenght)
{
    char* queue = (char*)malloc((lenght + 1) * sizeof(char));
    int indQueue = 0;
    struct Stack* operators = new();

    for (int ind = 0; ind < lenght; ind++) {
        if (str[ind] == '-' || str[ind] == ')' || str[ind] == '+' || str[ind] == '*' || str[ind] == '/') {
            if (str[ind] == ')') {
                indQueue = moveBtwStap(operators, queue, indQueue);
            } else {
                if (str[ind] == '*' || str[ind] == '/') {
                    while (!isEmpty(operators) && (peek(operators) == '*' || peek(operators) == '/')) {
                        indQueue++;
                        queue[indQueue] = pop(operators);
                    }
                    push(operators, str[ind]);
                } else if (str[ind] == '+' || str[ind] == '-') {
                    while (!isEmpty(operators) && (peek(operators) == '-' || peek(operators) == '+' || peek(operators) == '*' || peek(operators) == '/')) {
                        indQueue++;
                        queue[indQueue] = pop(operators);
                    }
                    push(operators, str[ind]);
                }
            }
        } else if (str[ind] == '(') {
            push(operators, str[ind]);
        } else if (str[ind] != ' ' && str[ind] != '\n') {
            indQueue++;
            queue[indQueue] = str[ind];
        }
    }

    while (!isEmpty(operators)) {
        char operator = pop(operators);
        if (operator != '(') {
            indQueue++;
            queue[indQueue] = operator;
        }
    }
    indQueue++;
    queue[indQueue] = '\0';
    deleteStack(operators);
    return queue;
}

int main(int argc, char** argv)
{
    char str[1000];
    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);
    int lenght = strlen(str);

    char* results = postfNotation(str, lenght);
    for (int ind = 0; ind < lenght; ind++) {
        printf("%c ", results[ind]);
    }
    printf("\n");
    free(results);
    
    return 0;
}