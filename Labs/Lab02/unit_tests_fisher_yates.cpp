#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <algorithm> // for std::copy
#include <iterator>  // for std::begin

#include "fisher_yates.h"
#include "prefix_sum.h"



int identity_function() {
    return 0;
}

TEST_CASE("Fisher-Yates") {
    SUBCASE("swap test") {
        int test_ary[] = {1, -1};
        int first = test_ary[0];
        int second = test_ary[1];

        swap(&first, &second);

        CHECK_EQ(first, -1);
        CHECK_EQ(second, 1);
    };

    SUBCASE("swap test 2"){
        int first = 5, second = 10;
        int save_first = first, save_second = second;
        swap (&first, &second);

        CHECK(first == save_second);
        CHECK(second == save_first);
    };

}

TEST_CASE("Fisher-Yates Ratio"){
     SUBCASE("Fisher-Yates test") {
        int (*random_fcn) () = std::rand;
        int (*identity_fcn) () = &identity_function;

        int array[] = {1, 1, -1, -1};

        int successful_outcomes = 0;
        const int num_iterations = 1000; // Number of iterations

        for (int i = 0; i < num_iterations; i++) {
            int temp_array[sizeof(array) / sizeof(array[0])];
            std::copy(std::begin(array), std::end(array), std::begin(temp_array));

            fisher_yates(temp_array, sizeof(temp_array) / sizeof(temp_array[0]), random_fcn);

            if (non_neg_prefix_sum(temp_array, sizeof(temp_array) / sizeof(temp_array[0]))) {
                successful_outcomes++;
            }
        }

        double ratio = static_cast<double>(successful_outcomes) / num_iterations;
        std::cout << "Ratio of successful outcomes with array size 4: " << ratio << std::endl;
    };




    SUBCASE("Fisher-Yates test 2") {
        int (*random_fcn) () = std::rand;
        int (*identity_fcn) () = &identity_function;

        int array[] = {56, 21, -1, 0 , 2};

        int successful_outcomes = 0;
        const int num_iterations = 1000; // Number of iterations

        for (int i = 0; i < num_iterations; i++) {
            int temp_array[sizeof(array) / sizeof(array[0])];
            std::copy(std::begin(array), std::end(array), std::begin(temp_array));

            fisher_yates(temp_array, sizeof(temp_array) / sizeof(temp_array[0]), random_fcn);

            if (non_neg_prefix_sum(temp_array, sizeof(temp_array) / sizeof(temp_array[0]))) {
                successful_outcomes++;
            }
        }

        double ratio = static_cast<double>(successful_outcomes) / num_iterations;
        std::cout << "Ratio of successful outcomes with array size 5: " << ratio << std::endl;
    };


    SUBCASE("Fisher-Yates test 3") {
        int (*random_fcn) () = std::rand;
        int (*identity_fcn) () = &identity_function;

        int array[] = {3, -2};

        int successful_outcomes = 0;
        const int num_iterations = 1000; // Number of iterations

        for (int i = 0; i < num_iterations; i++) {
            int temp_array[sizeof(array) / sizeof(array[0])];
            std::copy(std::begin(array), std::end(array), std::begin(temp_array));

            fisher_yates(temp_array, sizeof(temp_array) / sizeof(temp_array[0]), random_fcn);

            if (non_neg_prefix_sum(temp_array, sizeof(temp_array) / sizeof(temp_array[0]))) {
                successful_outcomes++;
            }
        }

        double ratio = static_cast<double>(successful_outcomes) / num_iterations;
        std::cout << "Ratio of successful outcomes with array size 2: " << ratio << std::endl;
    };

}
