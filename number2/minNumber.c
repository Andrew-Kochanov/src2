#include "sortList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int minNumber(int number)
{
    List* list = newList();

    int degree = 0;
    while (number > 0) {
        insert(list, number % 10);
        number = number / 10;
        degree++;
    }

    int tempDegree = 0;
    if (list->head->value == 0) {
        tempDegree += list->head->count;
    }

    int miniNumber = 0;
    ListNode* current = list->head;
    if (list->head->value == 0) {
        current = current->next;
        miniNumber += current->value * degree;
        degree--;
        degree = degree - tempDegree;
    }
    while (current != NULL) {
        miniNumber += current->value * degree;
        degree--;
    }
}

