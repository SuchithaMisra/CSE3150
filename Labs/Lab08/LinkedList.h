#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>
#include <memory>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::shared_ptr<T>& p) {
    return os << p.get() << " shared_ptr count: [" << p.use_count() << "]";
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::weak_ptr<T>& p) {
    auto sp = p.lock(); // lock() creates a temporary shared_ptr
    return os << sp.get() << " weak_ptr to shared_ptr count: [" << (sp ? sp.use_count() : 0) << "]";
}

// LinkedList class definition
struct LinkedList {
public:
    struct Node {
        int data;
        std::shared_ptr<Node> next;
        Node(int data, std::shared_ptr<Node> ptr = nullptr);
    };

    struct CopyNode {
        std::weak_ptr<Node> weak_node_ptr;
    };

    LinkedList();
    ~LinkedList();

    void build_node_list(int k);
    CopyNode* build_copyNodes_weak_ptrs();
    void delete_node_shared_ptr_list();
    void print_node_list_shared_ptrs();
    void print_node_array_weak_ptrs(CopyNode* copyNodes, int size);

    int getNodeCount() const;

private:
    std::shared_ptr<Node> root;
    int nodeCount;
};

#endif 