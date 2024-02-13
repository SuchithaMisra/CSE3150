// main.cpp
#include <iostream>
#include <vector>
#include "pointer_jump.h"

int main() {
    std::vector<Node*> nodes(5); // For example, creating 5 nodes

    for (auto& node : nodes) {
        node = new Node();
    }

    PointerJump::initializeLinkedList(nodes);
    PointerJump::performJumping(nodes.front());

    std::cout << "Jumping done!" << std::endl;

    // Deallocating memory
    for (auto& node : nodes) {
        delete node;
    }

    return 0;
}
