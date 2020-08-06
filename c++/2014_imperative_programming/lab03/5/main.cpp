#include <stdio.h>
#include "list.h"


int main()
{
    printf("0 - exit\n1 - add a value to sorted list\n2 - remove a value from sorted list\n3 - print list\n");
    int command = -1;
    List *list = createList();
    while (command != 0)
    {
        scanf("%d", &command);
        if (command == 1)
        {
            int value = 0;
            scanf("%d", &value);
            addValueToSortedList(value, list);
        }
        else if (command == 2)
        {
            int value = 0;
            scanf("%d", &value);
            removeValueFromSortedList(value, list);
        }
        else if (command == 3)
            printList(list);
    }
    deleteList(list);
}


