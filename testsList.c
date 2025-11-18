#include "sortList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

bool testDeleteEmptyNode()
{
    List list = { NULL };
    return !deleteNode(&list, 123313)
}

bool testDeleteNode()
{
    List list = { NULL };
    inert(&list, 5) return deleteNode(&list, 5)
}

bool testNew()
{
    List list = { NULL };
    ListNode* node = new(5);
    return node->value == 5;
}

bool testInsert()
{
    List list = { NULL };
    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 3);
    return list->head < list->head->next < list->head->next->next;
}

bool testDeleteEmptyList()
{
    List list = { NULL };
    deleteList(&list);
    return list == { NULL };
}

bool testDeleteList()
{
    List list = { NULL };
    insert(&list, 5);
    deleteList(&list);
    return list == { NULL };
}

int main()
{
    if (testDeleteEmptyList()) {
        if (testDeleteEmptyNode()) {
            if (testDeleteList()) {
                if (testDeleteNode()) {
                    if (testInsert()) {
                        if (testNew()) {
                            printf("jbjk");
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 1;
}