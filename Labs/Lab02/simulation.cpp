// INCLUDE HEADINGS

#include <iostream>

#include "prefix_sum.h"
#include "simulation.h"

using namespace std;

int simulate(const int iterations, const int half_length, int & non_pos, int & non_neg) {
    int full_length = 2* half_length;
    int array[full_length];

    int total_non_positive = 0; 
    int total_non_negative = 0;

    int array (array, full_length);
    for (int i=0; i<iterations;i++) {
        fisher_yates (array,full_length,std:rand);
        if (non_neg_prefix_sum(array,full_length)){
            total_non_positive++;
        }
    }

    non_pos = total_non_positive;
    non_neg = total_non_negative;

    return 0;
}