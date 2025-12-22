#include "sortList.h"
#include <stdio.h>
#include <stdlib.h>

// элемент списка
typedef struct ListNode {
    // значение
    int value;
    // ссылка на следующую "ячейку"
    struct ListNode* next;
} ListNode;

typedef struct List {
    ListNode* head;
    int size;
} List;

List* newList()
{
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;
    return list;
}

// положить элемент в соответствии с сортировкой
void insert(List* list, int value)
{
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->value = value;
    newNode->next = NULL;

    // Если список пуст или новый элемент меньше головы
    if (list->head == NULL || value < list->head->value) {
        newNode->next = list->head;
        list->head = newNode;
        list->size++;
        return;
    }

    // поиск того, куда вставить новый элемент
    ListNode* current = list->head;
    while (current->next != NULL && current->next->value < value) {
        current = current->next;
    }

    // вставка
    newNode->next = current->next;
    current->next = newNode;
    list->size++;
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
        list->size--;
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
    list->size--;
    return true;
}

// вывод списка
void printList(List* list)
{
    ListNode* current = list->head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

bool isEmpty(List* list){
    return list->head == NULL;
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
    free(list);
}

bool equalToArray(List* list, int* array, int arrayLength){
    ListNode* current = list->head;
    int i = 0;
    if (list->size != arrayLength){
        return false;
    }

    while (i < arrayLength) {
        if (current-> value != array[i]){
            return false;
        }
        current = current->next;
        i++;
    }
    return true;
}