#include <iostream>
#include "priority_queue.h"
#include "priority_queue_test.h"


int main()
{
    PriorityQueueTest test;
    QTest::qExec(&test);
    return 0;
}
