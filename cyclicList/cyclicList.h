#pragma once
#include <stdbool.h>

typedef struct List List;

List* newList();
bool isEmpty(List* list);
int getSize(List* list);
void insert(List* list, int value);
bool deleteNode(List* list, int value);
void printList(List* list);
void deleteList(List* list);
