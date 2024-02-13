#include <iostream>
#include "linked_list.h"

using namespace std;


struct node * build_linked_list(int elements){
    struct node * list_head = NULL;
    if (elements == 0) return list_head;
    struct node * prev = list_head;
    for (int i =0 ; i< elements; i++){
        struct node * newNode = new node;
        newNode->number = i;
        newNode->next = NULL;
        if (list_head == NULL){
            list_head = newNode;
        }
        else {
            prev->next = newNode;
        }
        prev=newNode;
    }

    return list_head;
}

void print_linked_list(struct node * list, int elements){
    cout << "Executing print" << endl;
    struct node * cur = list;
    while(cur != NULL){
        cout << cur->number << " ";
        cur = cur->next;
    }
}

int delete_linked_list(struct node * list, int elements){
  int deleted = 0;
  if (elements == 0) return deleted;
  struct node * prev = list;
  struct node * nxt = NULL;
  while (prev != NULL){
      nxt = prev->next;
      delete prev;
      prev = nxt; 
      deleted++;
  }
  return deleted;
}

int sum_values_in_linked_list(struct node * list, int elements){
  int sum = 0;
  struct node * cur = list;
  while (cur != NULL){
    sum += cur->number;
    cur = cur->next;
  }
  return sum;
}

struct helper * change_pointers(struct node * head, int elements){

  struct helper * help;
  struct helper * prev_helper = NULL;

  struct node * cur = head;
  struct node * last;
  int position = 0;
  while(position < elements){
    last = cur;
    cur = cur->next;
    position++;
  }
  cout << "last element: " << last->number << endl;
  
  //last element 
  position = 0;
  cur = head;
  while(position < elements){
    if (prev_helper == NULL){
      help = new helper;
      help->reference = cur;
      help->next_helper = NULL;
      prev_helper = help;
    } 
    else {
      struct helper * temp_helper = new helper;
      temp_helper->reference = cur;
      temp_helper->next_helper = NULL;
      prev_helper->next_helper = temp_helper;
      prev_helper = temp_helper;
    }
    
    //create a temp node that stores the next node
    struct node * temp = cur->next;
    
    cur->next = last;
    cur = temp;
    position++;

  }

  return help;
}

void delete_helper(struct helper * help){

  while(help->next_helper != NULL){
    free(help->reference);
    struct helper * temp = help;
    help = help->next_helper;
    free(temp);
  }

  free(help->reference);
  free(help);

}