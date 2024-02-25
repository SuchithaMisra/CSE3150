#include <iostream>
#include <cstdlib>
#include "gen_permutation.h"
#include "prefix_sum.h"
#include "fisher_yates.h" // Added fisher_yates.h

using namespace std;

void generate_permutation(int array[], int length){
    fisher_yates(array, length, std::rand); // Corrected the call to fisher_yates
}

int calculate_min_prefix(const int array[], int length){ 
    int sum{0}, min_sum{0}; 

    for (int i = 0; i < length; i++){
        sum += array[i];
        if (sum < min_sum){
            min_sum = sum;
        }
    }
    return min_sum; 
}

int find_min_prefix_index(const int array[], int length){ 
    int min_prefix_val = calculate_min_prefix(array, length);

    int sum{0}, index{0};

    for (int i = 0; i < length; i++){
        sum += array[i];
        if (sum == min_prefix_val){
            index = i;
            break;
        }
    }

    return index;
}
