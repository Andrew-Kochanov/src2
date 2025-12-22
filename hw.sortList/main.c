#include "sortList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool testDeleteEmptyNode()
{
    List* list = newList();
    return !deleteNode(list, 123313);
}

bool testDeleteNode()
{
    List* list = newList();
    insert(list, 5);
    return deleteNode(list, 5);
}

bool testSorted1(){
    List* list = newList();
    insert(list, 5);
    insert(list, 6);
    insert(list, -1111);
    int array[] = {-1111, 5, 6};
    return equalToArray(list, array, 3);
}

bool testSorted2(){
    List* list = newList();
    insert(list, 5);
    insert(list, 6);
    insert(list, -1111);
    int array[] = {-1111, 5};
    return !equalToArray(list, array, 3);
}

bool test()
{
    return (testSorted1() && testDeleteEmptyNode() && testSorted2() && testDeleteNode());
}

int main(int argc, char** argv)
{

    if (argc == 2 && strcmp(argv[1], "--test") == 0) {
        if (!test()) {
            printf("Test failed\n");
            return 1;
        } else {
            printf("Test passed\n");
            return 0;
        }
    }

    List* list = newList();
    int value = 0;

    const char* helpMassage = "Ведите номер операции: 0 - выйти, 1 - добавить значение, 2 - удалить значение, 3 - распечатать список: ";
    int operation = 0;
    do {
        printf("%s", helpMassage);
        int operation = 0;
        scanf("%d", &operation);
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
    } while (operation != 0);
    printf("Вы вышли\n");
    deleteList(list);
    return 0;
}