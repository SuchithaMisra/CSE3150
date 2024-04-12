#include "LinkedList.h"

using namespace std;

LinkedList::Node::Node(int data, std::shared_ptr<Node> ptr) : data(data), next(ptr) {}
LinkedList::LinkedList() : root(nullptr), nodeCount(0) {}
LinkedList::~LinkedList() {
    delete_node_shared_ptr_list();
}

void LinkedList::build_node_list(int totalNumber) {
    std::shared_ptr<Node> lastNode = root;

    while (lastNode && lastNode->next) {
        lastNode = lastNode->next;
    }

    for (int i = 0; i < totalNumber; ++i) {
        auto newNode = std::make_shared<Node>(nodeCount++, nullptr);
        if (!lastNode) {
            root = newNode;  
        } else {
            lastNode->next = newNode;
        }
        lastNode = newNode;
    }
}

LinkedList::CopyNode * LinkedList::build_copyNodes_weak_ptrs() {
    if (nodeCount == 0) {
        return nullptr;
    }

    auto array = new CopyNode[nodeCount];
    auto current = root;
    for (int i = 0; i < nodeCount; ++i) {
        array[i].weak_node_ptr = current;
        current = current->next;
    }
    return array;
}

int LinkedList::getNodeCount() const {
    return nodeCount;
}

void LinkedList::delete_node_shared_ptr_list() {
    std::shared_ptr<Node> current = root; 
    while (current != nullptr) {
        std::shared_ptr<Node> next = current->next;
        std::cout << current.get() << " shared_ptr count: [" << current.use_count() - 1 << "]" << std::endl;
        current.reset(); 
        current = next; 
    }
    root.reset(); 
    nodeCount = 0; 
}

void LinkedList::print_node_list_shared_ptrs() {
    auto current = root;
    std::cout << "Begin : print_node_list_shared_ptrs" << std::endl;
    while (current) {
        std::cout << reinterpret_cast<void*>(current.get()) << " shared_ptr count: [" << current.use_count() << "]" << std::endl;
        current = current->next;
    }
    std::cout << "End : print_node_list_shared_ptrs" << std::endl;
}


void LinkedList::print_node_array_weak_ptrs(CopyNode* copyNodes, int size) {
    cout << "print_node_array_weak_ptrs START" << endl;
    
    if (!copyNodes) {
        cout << "CopyNode array is nullptr : not initialized or already deleted" << endl;
    } else {
        bool allExpired = true;
        for (int i = 0; i < size; ++i) {
            auto sp = copyNodes[i].weak_node_ptr.lock();
            if (sp) {
                cout << reinterpret_cast<void*>(sp.get()) << " weak_ptr to shared_ptr count: [" << sp.use_count() << "]" << endl;
                allExpired = false;
            } else {
                cout << "Node [" << i << "] weak_ptr is expired." << endl;
            }
        }

        if (allExpired) {
            cout << "weak_ptrs have expired, shared_ptrs are deleted." << endl;
        }
    }
    
}