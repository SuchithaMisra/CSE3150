#include <iostream>
#include <vector>
#include <algorithm>
#include "lambda.h"

int main() {
    std::vector<int> numbers = {6, 28, 496, 8128};

    std::for_each(numbers.begin(), numbers.end(), [](const int& number) {
        if (is_perfect(number)) {
            std::cout << number << " is Perfect!" << std::endl;
        } else {
            std::cout << number << " is Imperfect!" << std::endl;
        }
    });

    return 0;
}