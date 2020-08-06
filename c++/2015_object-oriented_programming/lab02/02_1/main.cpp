#include "singly_linked_list_test.h"
#include "doubly_linked_list_test.h"


int main()
{
    SinglyLinkedListTest sTest;
    QTest::qExec(&sTest);
    DoublyLinkedListTest dTest;
    QTest::qExec(&dTest);
    return 0;
}
