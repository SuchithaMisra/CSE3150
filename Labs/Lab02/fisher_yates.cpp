#include <iostream>

#include "fisher_yates.h"

void print_array(int ary[], int len) {
    for (int i=0; i < len; i++) {
        std::cout << ary[i] << " " ;
    }
    std::cout << std::endl;
}

int swap(int * first, int * second) {
    int temp = * first; // pointer to first
    *first = *second;
    *second = temp; 

    return 0;
}

void fisher_yates (int array[], const int length, int (*random_fcn)()) {
    for (int i=0; i<length -1;i++) {
        int rnd_location = random_fcn() % (length - i);
        swap(&array[i],&array[rnd_location + 1]);
    }
}
