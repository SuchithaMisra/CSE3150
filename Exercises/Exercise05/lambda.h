#ifndef LAMBDA_H
#define LAMBDA_H

#include <vector>
#include <algorithm>

bool is_perfect(int number) {
    int sum = 1;
    for(int i = 2; i < number; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }
    return sum == number;
}

#endif
