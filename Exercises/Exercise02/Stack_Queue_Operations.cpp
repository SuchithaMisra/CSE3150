#include "Stack_Queue_Operations.h"

using namespace std;

void StackOperations::pushFromFile(const std::string& filename) {
    std::ifstream file(filename);
    int value;  
    while (file >> value) {
        StackQueueItem item = {value};
        stack.push(item);
    }
}

StackQueueItem StackOperations::pop() {
    if (stack.empty())
        throw std::runtime_error("Stack is empty");

    StackQueueItem item = stack.top();
    stack.pop();

    return item;
}

void QueueOperations::pushFromFile(const std::string& filename) {
    std::ifstream file(filename);
    int value;
    while (file >> value) {
        StackQueueItem item = {value};
        queue.push(item);
    }
}

StackQueueItem QueueOperations::pop() {
    if (queue.empty())
        throw std::runtime_error("Queue is empty");

    StackQueueItem item = queue.front();
    queue.pop();

    return item;
}
