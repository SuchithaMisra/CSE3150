#include <iostream>
#include "Stack_Queue_Operations.h"

using namespace std;

int main() {
    // Creating an instance 
    StackOperations stackOps;
    QueueOperations queueOps;

    // Push elements from a file to the stack
    std::string stackFile = "test_input.txt"; 
    try {
        stackOps.pushFromFile(stackFile);
    } catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1; // Exit program with error
    }

    // Pop elements from the stack and print them
    std::cout << "Popping elements from the stack:\n";
    while (!stackOps.isEmpty()) {
        StackQueueItem item = stackOps.pop();
        std::cout << "Popped: " << item.value << std::endl;
    }

    // Push elements from a file to the queue
    std::string queueFile = "test_input.txt"; 
    try {
        queueOps.pushFromFile(queueFile);
    } catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1; // Exit program with error
    }

    // Pop elements from the queue and print them
    std::cout << "Popping elements from the queue:\n";
    while (!queueOps.isEmpty()) {
        StackQueueItem item = queueOps.pop();
        std::cout << "Popped: " << item.value << std::endl;
    }

    return 0;
}
