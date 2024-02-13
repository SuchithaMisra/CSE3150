// pointer_jump.h
#ifndef POINTER_JUMP_H
#define POINTER_JUMP_H

#include <vector>

struct Node {
    Node* next;
};

class PointerJump {
public:
    static void initializeLinkedList(std::vector<Node*>& nodes);
    static void performJumping(Node* head);
};

#endif // POINTER_JUMP_H
