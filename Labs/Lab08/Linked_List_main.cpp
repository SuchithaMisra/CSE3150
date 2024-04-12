#include "LinkedList.h"
#include <iostream>

using namespace std;

int main() {
    LinkedList list;

    cout << "Building a linked list: 10 nodes." << endl;
    list.build_node_list(10);

    cout << "Linked list prior to deletion:" << endl;
    list.print_node_list_shared_ptrs();

    LinkedList::CopyNode* copyNodes = list.build_copyNodes_weak_ptrs();
    if (!copyNodes) {
        cout << "Error: Can't create CopyNode array" << endl; //error case
        return 1;  
    }

    cout << "\nCopyNode array prior to list deletion --> weak pointers are valid:" << endl;
    list.print_node_array_weak_ptrs(copyNodes, list.getNodeCount());

    cout << "\nDeletion of main linked list." << endl;
    list.delete_node_shared_ptr_list();

    cout << "\nCopyNode array post list deletion --> weak pointers are expired:" << endl;
    list.print_node_array_weak_ptrs(copyNodes, list.getNodeCount());

    delete[] copyNodes;  
    copyNodes = nullptr;  

    return 0;
}