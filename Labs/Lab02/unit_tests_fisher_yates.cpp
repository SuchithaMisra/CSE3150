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

    SUBCASE("fisher_yates test")
    {
        const int length = 10;
        int test_ary[length];

        for (int i = 0; i < length; ++i)  //initializing array 
            test_ary[i] = i;

        int original[length]; //keeps track of original numbers order (for refernce later)
        std::copy(test_ary, test_ary + length, original);

        fisher_yates(test_ary, length, rand);  // calling fisher_yates function 

        CHECK_EQ(length, 10); //chekcing length 

        for (int i = 0; i < length; ++i)  //checking to see all elements are still in array
            CHECK(std::find(test_ary, test_ary + length, original[i]) != test_ary + length);

        CHECK_FALSE(std::equal(test_ary, test_ary + length, original));  //checking to see if "shuffle happend"
    }
}
