#include <stdbool.h>
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
} List;

// структура списка
ListNode* new(int value)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->value = value;
    node->next = NULL;
    return node;
}

// положить элемент в соответствии с сортировкой
void insert(List* list, int value)
{
    ListNode* newNode = new(value);

    // Если список пуст или новый элемент меньше головы
    if (list->head == NULL || value < list->head->value) {
        newNode->next = list->head;
        list->head = newNode;
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
        return 0;
    }

    // удаление элемента
    ListNode* temprery = current->next;
    current->next = temprery->next;
    free(temprery);
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
