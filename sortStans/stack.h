#pragma once
#include <stdbool.h>

typedef struct Stack Stack;

Stack* new(void);
void push(Stack* stack, char value);
char pop(Stack* stack);
bool isEmpty(Stack* stack);
char peek(struct Stack* stack);
void deleteStack(struct Stack* stack);
