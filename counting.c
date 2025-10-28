#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

// элемент списка
typedef struct ListNode {
    // значение
    int value;
    // ссылка на следующую "ячейку"
    struct ListNode* next;
} ListNode;

typedef struct List
{
    ListNode* head;
    ListNode* tail;
} List;

// структура списка
ListNode* new(int value)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->value = value;
    node->next = NULL;
    return node;
}

// Проверка на пустоту
int isEmpty(List* list) {
    return list->head == NULL;
}

// положить элемент в соответствии с сортировкой
void insert(List* list, int value)
{
    ListNode* newNode = new(value);

    if (is_empty(list)) {
        new_node->next = newNode;
        list->head = newNode;
        list->tail = newNode;
    } else {
        // Новый элемент указывает на голову
        new_node->next = list->head; 
        // Старый хвост указывает на новый элемент
        list->tail->next = newNode; 
        // Обновляем хвост
        list->tail = newNode;       
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

int main(int argc, char** argv)
{
    int n = 0;
    printf("Введите количество войнов: ");
    scanf("%d", &n);
    int m = 0;
    printf("Введите, какого по счету война будут убивать: ")
    scanf("d", %m);
    List* wariors ={NULL};
    for (int ind = 1; ind < n + 1; ind++){
        insert(wariors, ind);
    }

    int count = 1;
    while(){
        current = list->head;
        if (count % m == 0){
            ListNode* temprery = current;
            current = current->next;
            deleteNode(list, temprery->value);
            count = 0;
        } else{
            current = current->next;
        }
        n--;
        count++;
        
    }
    printf()

    deleteList(list);
    return 0;
}