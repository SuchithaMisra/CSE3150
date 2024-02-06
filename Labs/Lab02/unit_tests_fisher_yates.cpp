#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "fisher_yates.h"


TEST_CASE("Fisher-Yates")
{
    SUBCASE("swap test")
    {
        int test_ary[] = {1, -1};
        int first = test_ary[0];
        int second = test_ary[1];

        swap(&first, &second);

        CHECK_EQ(first, -1);
        CHECK_EQ(second, 1);
    }

//NOTE many assertions b/c each testcase is run 1000+ times


/*
This test case shows 1 as the ratio since the list was well balanced, so the variable 
to keep track of well balanced list got incremented
*/
    SUBCASE("fisher_yates test--> Even size array --> balanced ratio")
    {
        const int length = 80; //arry size
        const int num_tests = 1000; // Number of tests

        int well_balanced_count = 0; // Counter for well-balanced lists

        for (int test_num = 0; test_num < num_tests; ++test_num)
        {
            int test_ary[length];

            for (int i = 0; i < length; ++i) // initializing array
                test_ary[i] = i;

            int original[length]; // keeps track of original numbers order (for reference later)
            std::copy(test_ary, test_ary + length, original);

            fisher_yates(test_ary, length, rand); // calling fisher_yates function

            CHECK_EQ(length, 80); // checking length

            bool is_well_balanced = true;

            for (int i = 0; i < length; ++i) // checking to see all elements are still in array
            {
                if (std::find(test_ary, test_ary + length, original[i]) == test_ary + length)
                {
                    is_well_balanced = false;
                    break;
                }
            }

            CHECK_FALSE(std::equal(test_ary, test_ary + length, original)); // checking if "shuffle happened"

            if (is_well_balanced)
                well_balanced_count++; //adds 1 if ratio is balanced 
        }

        double well_balanced_ratio = static_cast<double>(well_balanced_count) / num_tests;

        std::cout << "Apparent ratio of well-balanced lists: " << well_balanced_ratio << std::endl;
        CHECK(well_balanced_ratio == 1.0); // checking ratio to ensure list was balanced 
        std::cout << "Total number of runs: " << num_tests << std::endl;

    }
}

/*
This test case shows 0 as the ratio since the list wasn't well balanced, so the variable 
to keep track of well balanced list didn't increment 

last test ensures ratio is less than 1
*/
TEST_CASE("Odd Array Size --> Ratio less than 1")
{
    const int length = 15; // Odd array size
    const int num_tests = 1000;

    int well_balanced_count = 0;

    for (int test_num = 0; test_num < num_tests; ++test_num)
    {
        int test_ary[length]; // Initializing array 

        fisher_yates(test_ary, length, rand); //calling function
    }

    double well_balanced_ratio = static_cast<double>(well_balanced_count) / num_tests;

    INFO("Well-balanced ratio for odd array: " << well_balanced_ratio);
    std::cout << "Apparent ratio non-well-balanced lists: " << well_balanced_ratio / num_tests << std::endl;
    CHECK(well_balanced_ratio < 1.0); // checking ratio is actually less than 1 
    std::cout << "Total number of runs: " << num_tests << std::endl;
}
