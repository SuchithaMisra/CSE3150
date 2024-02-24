#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Stack_Queue_Operations.h"

using namespace std;

TEST_CASE("Stack Test") {
    StackOperations stackOps;
    stackOps.pushFromFile("test_input.txt");

    int sum = 0; //initialize sum
    try {  // pop's elements from the stack
        while (true) {  //till no exception occur
            StackQueueItem item = stackOps.pop(); // pops element off stack
            sum += item.value; //keep adding sum of popped elements 
        }
    } catch (const std::exception& e) { //error is thown if no elements on stack 
        CHECK(sum >= 0); // checks if sum is non-negtive value 
    }
}

TEST_CASE("Queue Test") {
    QueueOperations queueOps;
    queueOps.pushFromFile("test_input.txt");

    int sum = 0;
    try {
        while (true) {
            StackQueueItem item = queueOps.pop();
            sum += item.value;
        }
    } catch (const std::exception& e) {
        CHECK(sum >= 0);
    }
}

TEST_CASE("Stack Test --> Single line") {
    StackOperations stackOps;
    stackOps.pushFromFile("single_input.txt");

    int sum = 0; //initialize sum
    try {  // pop's elements from the stack
        while (true) {  //till no exception occur
            StackQueueItem item = stackOps.pop(); // pops element off stack
            sum += item.value; //keep adding sum of popped elements 
        }
    } catch (const std::exception& e) { //error is thown if no elements on stack 
        CHECK(sum >= 0); // checks if sum is non-negtive value 
    }
}

TEST_CASE("Queue Test --> Single line") {
    QueueOperations queueOps;
    queueOps.pushFromFile("single_input.txt");

    int sum = 0;
    try {
        while (true) {
            StackQueueItem item = queueOps.pop();
            sum += item.value;
        }
    } catch (const std::exception& e) {
        CHECK(sum >= 0);
    }
}

TEST_CASE("Stack Test -- Exception Handling --> Empty txt file") {
    StackOperations stackOps;
    stackOps.pushFromFile("empty_input.txt");

    int sum = 0;
    CHECK_NOTHROW([&]() {  //check if the code inside the lambda function does not throw any exceptions
        while (true) {
            try {
                StackQueueItem item = stackOps.pop();
                sum += item.value;
            } catch (const std::runtime_error& e) {
                // Exception caught, breaking out of loop
                break;
            }
        }
    }());
    CHECK(sum >= 0);
}

TEST_CASE("Queue Test -- Exception Handling --> Empty txt file") {
    QueueOperations queueOps;
    queueOps.pushFromFile("empty_input.txt");

    int sum = 0;
    CHECK_NOTHROW([&]() {
        while (true) {
            try {
                StackQueueItem item = queueOps.pop();
                sum += item.value;
            } catch (const std::runtime_error& e) {
                // Exception caught, breaking out of loop
                break;
            }
        }
    }());
    CHECK(sum >= 0);
}
