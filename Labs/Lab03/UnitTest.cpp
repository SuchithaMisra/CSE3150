#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "linked_list.h"
using namespace std;

struct helper * help;
struct helper * help_2;

struct node * linked_list_1 = build_linked_list(0);

const int TEST_DELETE = 28;
struct node * linked_list_2 = build_linked_list(TEST_DELETE);

const int TEST_SMALL = 5;
struct node * linked_list_3 = build_linked_list(TEST_SMALL);

const int TEST_LARGE = 342;
struct node * linked_list_4 = build_linked_list(TEST_LARGE);

int check_sum(int num){
    int sum=0;
     for(int i = 0 ; i < num ; i++){
         sum+= i;
     }
     return sum;
}

TEST_CASE("Testing build of list") {


  CHECK( linked_list_1 == NULL);
  CHECK( linked_list_2 != NULL); 

}

TEST_CASE("Test --> suming of list elements"){

  CHECK( sum_values_in_linked_list(linked_list_1, 0) == 0);
  CHECK( sum_values_in_linked_list(linked_list_3, TEST_SMALL) == 10);
  
}

TEST_CASE("Testing summing of list elements"){

  CHECK( sum_values_in_linked_list(linked_list_1, 0) == 0);
  CHECK( sum_values_in_linked_list(linked_list_2, TEST_DELETE) == check_sum(TEST_DELETE));
  CHECK( sum_values_in_linked_list(linked_list_4, TEST_LARGE) == check_sum(TEST_LARGE));
}

TEST_CASE("Testing deleting linked list") {
    CHECK( delete_linked_list(linked_list_1, 0) == 0);
    CHECK( delete_linked_list(linked_list_3, TEST_SMALL) == TEST_SMALL);
}


TEST_CASE("Test --> Pointer jump"){
  const int T1 = 10;
  struct node * l1 = build_linked_list(T1);
  help = change_pointers(l1, T1);
  CHECK ( l1->next->number == 9);
  int check_1 = help->reference->next->number;
  int check_2 = l1->next->number;
  CHECK ( help->reference->next->number == l1->next->number);

  const int T2 = 5;
  struct node * l2 = build_linked_list(T2);
  help_2 = change_pointers(l2, T2);
  CHECK (l2->next->number == 4);
  CHECK ( help_2->reference->next->number == l2->next->number);

}

TEST_CASE("testing freeing list with help struct"){

  delete_helper(help);
  delete_helper(help_2);

}