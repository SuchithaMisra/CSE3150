#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_

struct node {
 int number;
 struct node * next;
};

struct helper {
    struct node * reference;
    struct helper * next_helper;
};

struct node * build_linked_list(int elements);
void print_linked_list(struct node * list, int elements);
int delete_linked_list(struct node * list, int elements);
int sum_values_in_linked_list(struct node * list, int elements);
struct helper * change_pointers(struct node * head, int elements);
void delete_helper(struct helper * help);

#endif