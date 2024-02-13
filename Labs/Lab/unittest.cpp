// unittest.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "pointer_jump.h"

TEST_CASE("Test Pointer Jumping") {
    std::vector<Node*> nodes(5); // For example, creating 5 nodes

    for (auto& node : nodes) {
        node = new Node();
    }

    PointerJump::initializeLinkedList(nodes);
    PointerJump::performJumping(nodes.front());

    // Checking if all nodes point to the last node
    for (size_t i = 0; i < nodes.size() - 1; ++i) {
        CHECK(nodes[i]->next == nodes.back());
    }

    // Checking if the last node points to itself
    CHECK(nodes.back()->next == nodes.back());

    // Deallocating memory
    for (auto& node : nodes) {
        delete node;
    }
}
