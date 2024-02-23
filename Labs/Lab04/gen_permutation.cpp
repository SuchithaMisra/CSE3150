
#include <iostream>
#include <cstdlib>
#include "gen_permutation.h"
#include "prefix_sum.h"
#include "fisher_yates.h"

using namespace std;

void compute_permutation_of_array(int array[], int length){
    fisher_yates(array, length, std::rand);

}

int get_lowest_prefix_sum_value(const int array[], int length){
    int sum{0}, lowest_sum{0};

    for (int i = 0; i < length; i++){
        sum += array[i];
        if (sum < lowest_sum){
            lowest_sum = sum;
        }
    }
    return lowest_sum; 
}


int index_of_lowest_prefix_sum_element(const int array[], int length){
    int lowest_prefix_sum = get_lowest_prefix_sum_value(array, length);

    int sum{0}, index_of_first_lowest_ps{0};

    for (int i = 0; i < length; i++){
        sum += array[i];
        if (sum == lowest_prefix_sum){
            index_of_first_lowest_ps = i;
            break;
        }
    }

    return index_of_first_lowest_ps;
}