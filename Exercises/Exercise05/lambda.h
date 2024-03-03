#ifndef LAMBDA_H
#define LAMBDA_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

auto is_perfect = [](int number) -> bool {
    int sum = 1;
    for(int i = 2; i < number - 1; i++) {
        if (0 == number % i) {
            sum += i;
        }
    }
    return sum == number;
};

#endif
