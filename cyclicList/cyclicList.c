#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// узел списка
typedef struct ListNode {
    // значение
    int value;
    // ссылка на следующий узел
    struct ListNode* next;
} ListNode;

typedef struct List {
    ListNode* head;
    ListNode* tail;
    // длина
    int size;
} List;

// создание нового списка
List* newList()
{
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Проверка на пустоту
bool isEmpty(List* list)
{
    return list->head == NULL || list == NULL;
}

// получение размера списка
int getSize(List* list)
{
    return list->size;
}

// вставка элемента
void insert(List* list, int value)
{
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->value = value;

    if (isEmpty(list)) {
        // первый элемент - указываем на себя самого
        newNode->next = newNode;
        list->head = newNode;
        list->tail = newNode;
    } else {
        // Новый элемент - указывает на голову
        newNode->next = list->head;
        // Старый хвост указывает на новый элемент
        list->tail->next = newNode;
        // Обновляем хвост
        list->tail = newNode;
    }

    list->size++;
}

// удаление элемента по значению
bool deleteNode(List* list, int value)
{
    // если список пустой
    if (isEmpty(list)) {
        return false;
    }

    ListNode* current = list->head;
    ListNode* prev = list->tail;

    int i = 0;
    while (i < list->size) {
        if (current->value == value) {
            // если удаляем единственный элемент
            if (list->size == 1) {
                free(current);
                list->head = NULL;
                list->tail = NULL;
            } else {
                // удаляем элемент
                prev->next = current->next;

                // если удаляем голову
                if (current == list->head) {
                    list->head = current->next;
                }

                // если удаляем хвост
                if (current == list->tail) {
                    list->tail = prev;
                }

                free(current);
            }

            list->size--;
            return true;
        }

        prev = current;
        current = current->next;
        i++;
    }

    return false;
}

// вывод списка
void printList(List* list)
{
    if (isEmpty(list)) {
        printf("Список пуст\n");
        return;
    }

    ListNode* current = list->head;
    printf("Список: ");

    int i = 0;
    while (i < list->size) {
        printf("%d ", current->value);
        current = current->next;
        i++;
    }

    printf("\n");
}

// удаление всего списка
void deleteList(List* list)
{
    if (isEmpty(list)) {
        free(list);
        return;
    }

    ListNode* current = list->head;

    int i = 0;
    while (i < list->size) {
        ListNode* temp = current;
        current = current->next;
        free(temp);
        i++;
    }

    list->size = 0;
    free(list);
}