#include "cyclicList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    // Количество воинов
    int n = 0;
    // какого война будут убивать
    int m = 0;

    while (n <= 0 || m <= 0) {
        printf("Введите количество войнов: ");
        scanf("%d", &n);
        printf("Введите, какого по счету война будут убивать: ");
        scanf("%d", &m);
    }

    List* warriors = newList();
    for (int ind = 1; ind < n + 1; ind++) {
        insert(warriors, ind);
    }

    ListNode* current = warriors->head;
    int count = 1;
    while (getSize(warriors) > 1) {
        // Если дошли до m-го воина
        if (count == m) {
            ListNode* toRemove = current;
            current = current->next;
            deleteNode(warriors, toRemove->value);
            // Сбрасываем счетчик
            count = 1;
        } else {
            // Переходим к следующему воину
            current = current->next;
            count++;
        }
    }
    printf("Последний выживший был под номером: ");
    printList(warriors);
    deleteList(warriors);
    return 0;
}