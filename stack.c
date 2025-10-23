#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
// #include<stdbool.h>


struct StackNode {
    // значение
    char value;
    // ссылка на следующую "ячейку"
    struct StackNode* next;
};

// делаем ссулку на голову
struct Stack {
    struct StackNode* head;
};

// создаем пустую тсруктуру с пустой ссылкой на нулевую голову
struct Stack* new(void)
{
    struct Stack* stack = calloc(1, sizeof(*stack));
    return stack;
}

// положить элемент
void push(struct Stack* stack, char value)
{
    // выделяем память для нового стека
    struct StackNode* node = (struct StackNode*)malloc(sizeof(struct StackNode));

    // пихаем в него значение
    node->value = value;

    // пихаем в него ссылку на предыдущий стек
    node->next = stack->head;

    // делаем ссылку на этот же стек ссылкой на голову
    stack->head = node;
}

bool isEmpty(struct Stack* stack)
{
    return stack->head == NULL;
}

char pop(struct Stack* stack)
{
    if (isEmpty(stack)){
        return '\0';
    }
    // получаем ссылку на текущую голову(стек)
    struct StackNode* oldNode = stack->head;

    // переприсваиваем ссылку головы на предыдущую от текущего стека
    stack->head = oldNode->next;

    // вытаскиваем значение из текущего стека
    char result = oldNode->value;
    free(oldNode);
    return result;
}

char peek(struct Stack* stack)
{
    char result = stack->head->value;
    return result;
}

void deleteStack(struct Stack* stack)
{
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}
