#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "LinkedList.h"

TEST_CASE("Testing LinkedList initialization") {
    LinkedList list;

    SUBCASE("Test empty list initialization") {
        CHECK(list.getNodeCount() == 0);
        list.print_node_list_shared_ptrs();  
    }
}

TEST_CASE("Testing adding nodes to the list") {
    LinkedList list;

    SUBCASE("Adding 3 nodes to the list") {
        list.build_node_list(3);
        CHECK(list.getNodeCount() == 3);
    }

    SUBCASE("Check node connectivity and count increment") {
        list.build_node_list(4);
        auto copyNodes = list.build_copyNodes_weak_ptrs();
        for (int i = 0; i < 4; i++) {
            CHECK(!copyNodes[i].weak_node_ptr.expired()); 
            auto lockedNode = copyNodes[i].weak_node_ptr.lock();
            CHECK(lockedNode != nullptr);  
            CHECK(lockedNode->data == i); 
        }
        delete[] copyNodes; 
    }
}

TEST_CASE("Testing deleting nodes from the list") {
    LinkedList list;

    SUBCASE("Deleting 2 nodes from the list") {
        list.build_node_list(2);
        REQUIRE(list.getNodeCount() == 2);  
        list.delete_node_shared_ptr_list();
        CHECK(list.getNodeCount() == 0);  
    }
}

TEST_CASE("Testing weak pointers after deletion") {
    LinkedList list;

    SUBCASE("Adding 6 nodes, deleting them, and checking weak pointers") {
        list.build_node_list(6);
        auto copyNodes = list.build_copyNodes_weak_ptrs();
        list.delete_node_shared_ptr_list();

        for (int i = 0; i < 6; i++) {
            CHECK(copyNodes[i].weak_node_ptr.expired());  
        }
        delete[] copyNodes;
    }
}
