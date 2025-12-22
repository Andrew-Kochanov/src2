#pragma once
#include <stdbool.h>

// узел списка
typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

typedef struct List {
    ListNode* head;
    ListNode* tail;
    // длина
    int size;
} List;

List* newList();
bool isEmpty(List* list);
int getSize(List* list);
void insert(List* list, int value);
bool deleteNode(List* list, int value);
void printList(List* list);
void deleteList(List* list);
