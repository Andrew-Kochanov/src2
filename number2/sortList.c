#include "sortList.h"
#include <stdio.h>
#include <stdlib.h>

// элемент списка
typedef struct ListNode {
    // значение
    int value;
    // сколько раз ввели значение
    int count;
    // ссылка на следующую "ячейку"
    struct ListNode* next;
} ListNode;

typedef struct List {
    ListNode* head;
} List;

List* newList()
{
    List* list = (List*)malloc(sizeof(list));
    list->head = NULL;
    return list;
}

// положить элемент в соответствии с сортировкой
void insert(List* list, int value)
{

    // Если список пуст или новый элемент меньше головы
    if (list->head == NULL || value < list->head->value) {
        ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->value = value;
        newNode->count = 1;
        newNode->next = NULL;

        newNode->next = list->head;
        list->head = newNode;
        return;
    }

    // поиск того, куда вставить новый элемент
    ListNode* current = list->head;
    while (current->next != NULL && current->next->value < value) {
        current = current->next;
        // printf("%d", current->next->value);
    }

    if (current->next != NULL && current->next->value == value) {
        current->next->count++;
        return;
    } else if (current->value == value) {
        current->count++;

    } else {
        ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->value = value;
        newNode->count = 1;
        newNode->next = NULL;

        // вставка
        newNode->next = current->next;
        current->next = newNode;

        return;
    }
}

// проверка на возможность удаления элемента
bool deleteNode(List* list, int value)
{
    // если список пустой
    if (list->head == NULL) {
        return false;
    }

    // если элемент это голова
    if (list->head->value == value) {
        ListNode* temprery = list->head;
        list->head = list->head->next;
        free(temprery);
        return true;
    }

    // поиск элемента для удаления
    ListNode* current = list->head;
    while (current->next != NULL && current->next->value != value) {
        current = current->next;
    }

    // Если элемент не найден
    if (current->next == NULL) {
        return false;
    }

    // удаление элемента
    ListNode* temprery = current->next;
    current->next = current->next->next;
    free(temprery);
    return true;
}

// вывод списка
void printList(List* list)
{
    ListNode* current = list->head;
    while (current != NULL) {
        printf("%d:%d, ", current->value, current->count);
        current = current->next;
    }
    printf("\n");
}

// удаление списка
void deleteList(List* list)
{
    ListNode* current = list->head;
    while (current != NULL) {
        ListNode* temprery = current;
        current = current->next;
        free(temprery);
    }
    list->head = NULL;
}