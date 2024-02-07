#include <iostream>

#include "prefix_sum.h"


int prefix_sum(int ary[],int length) {
    int sum=0;
    for (int i=0; i<length; i++) {
        sum += ary[i];  //only generates sum (i.e last prefix sum)
    }

    return sum;
}

// non_positive_prefix_sum --> checks if sum is negative 

bool non_pos_prefix_sum(int ary[],int length) {
    bool negative_found = false;  // initalizing to false

    if(length == 1 && ary[0] < 0) {  //edge case, if only 1 element & < 0 --> negative number
        negative_found = true;
    }
    int sum=0;  //initializing sum 
    for (int i=0; i<length; i++) {
        sum = prefix_sum(ary,i);  
        if (sum<0){ //if sum is LESS than 0 i.e negative
            negative_found = true;  //update variable to be true
            break;
        }
    }

    return negative_found; 

}

//non_neg_prefix_sum --> checks if prefix_sum is positive

bool non_neg_prefix_sum(int ary[],int length) {
    bool positive_found = false;

    if (length == 1 && ary[0]>0){ //edge case, if only 1 element and value is > 0 --> positive number
        positive_found = true;
    }

    int sum=0;
    for (int i=0; i<length; i++) {
        sum = prefix_sum(ary,i); 
        if (sum>0){
            positive_found = true;
            break;
        }
    }

    return positive_found; 

}

