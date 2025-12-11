#include "sortList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    List* list = newList();
    int value = 0;

    int nul = 0;
    deleteNode(list, nul);

    char numbers[1000];
    printf("Введите набор чисел:\n");
    fgets(numbers, sizeof(numbers), stdin);
    char* token = strtok(numbers, " ");
    while (token != NULL) {
        int number = atoi(token);
        insert(list, number);
        token = strtok(NULL, " ");
    }
    printList(list);
    deleteList(list);

    return 0;
}