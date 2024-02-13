#include <iostream>
#include "linked_list.h"

int main() {
    // building LL with 5 elements
    const int num_elements = 5;
    struct node *list = build_linked_list(num_elements);
    
    // Print LL
    std::cout << "Linked List: ";
    print_linked_list(list, num_elements);
    std::cout << std::endl;
    
    // add all the values in LL
    int sum = sum_values_in_linked_list(list, num_elements);
    std::cout << "Sum of values in the linked list: " << sum << std::endl;
    
    // Delete LL
    int deleted = delete_linked_list(list, num_elements);
    std::cout << "Deleted " << deleted << " nodes from the linked list." << std::endl;

    return 0;
}
