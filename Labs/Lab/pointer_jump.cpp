// pointer_jump.cpp
#include "pointer_jump.h"

void PointerJump::initializeLinkedList(std::vector<Node*>& nodes) {
    if (nodes.empty()) return;

    for (size_t i = 0; i < nodes.size() - 1; ++i) {
        nodes[i]->next = nodes[i + 1];
    }

    // Set the last node to point to itself
    nodes.back()->next = nodes.back();
}

void PointerJump::performJumping(Node* head) {
    if (!head) return;

    Node* lastNode = head;
    while (lastNode->next != lastNode) {
        Node* current = head;
        while (current->next != lastNode) {
            current = current->next;
        }
        current->next = lastNode;
        lastNode = lastNode->next;
    }
}
