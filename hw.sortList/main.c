#include "../sortList/sortList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    List* list = newList();
    int value = 0;

    printf("Ведите номер операции: 0 - выйти, 1 - добавить значение, 2 - удалить значение, 3 - распечатать список: ");
    int operation = 0;
    scanf("%d", &operation);
    while (operation != 0) {
        if (operation == 1) {
            printf("Ведите, какое значение вставить: ");
            scanf("%d", &value);
            insert(list, value);
        } else if (operation == 2) {
            printf("Ведите, какое значение удалить: ");
            scanf("%d", &value);
            if (deleteNode(list, value)) {
                printf("Элемент удален\n");
            } else {
                printf("Удалить элемент невозможно\n");
            }
        } else if (operation == 3) {
            printList(list);
        } else {
            printf("Такой операции нет\n");
        }
        printf("Ведите номер операции: 0 - выйти, 1 - добавить значение, 2 - удалить значение, 3 - распечатать список: ");
        scanf("%d", &operation);
    }
    printf("Вы вышли\n");
    deleteList(list);
    return 0;
}