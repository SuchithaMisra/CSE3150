#ifndef STACK_QUEUE_OPERATIONS_H
#define STACK_QUEUE_OPERATIONS_H

#include <stack>
#include <queue>
#include <fstream>
#include <stdexcept>

struct StackQueueItem {
    int value;
};

class StackOperations {
public:
    void pushFromFile(const std::string& filename);
    StackQueueItem pop();
private:
    std::stack<StackQueueItem> stack;
};

class QueueOperations {
public:
    void pushFromFile(const std::string& filename);
    StackQueueItem pop();
private:
    std::queue<StackQueueItem> queue;
};

#endif
