#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include "doctest.h"
#include "fisher_yates.h"
#include "prefix_sum.h"
#include "gen_permutation.h"
#include "well_formed.h"

using namespace std;

//fisher_yates.cpp
TEST_CASE("Testing fisher_yates function") {

    SUBCASE("fisher-yates basic test") {
        int array[] = {1, 2, 3, 4, 5};
        fisher_yates(array, 5, [](){ return 0; }); 
        CHECK(array[0] == 1);
        CHECK(array[1] == 2);
        CHECK(array[2] == 3);
        CHECK(array[3] == 4);
        CHECK(array[4] == 5);
    }

    SUBCASE("fisher-yates swap test") {
        int a = 3, b = 5;
        swap(&a, &b);
        CHECK(a == 5);
        CHECK(b == 3);
    }
}

//prefix_sum.cpp
int nums_0[] = {};
int nums_1[] = {5, -10, 15, 20};
int nums_2[] = {2, 2, -2, -2};
int nums_3[] = {-3, -3, 3, 3};

TEST_CASE("Edge cases") {
  CHECK(prefix_sum(nums_0,sizeof(nums_0)/sizeof(nums_0[0])) == 0);  
  CHECK(non_negative_sum(nums_0,sizeof(nums_0)/sizeof(nums_0[0])) );  
  CHECK(non_positive_sum(nums_0,sizeof(nums_0)/sizeof(nums_0[0])) );  
}

TEST_CASE("Testing prefix_sum function") {
  
  CHECK(prefix_sum(nums_1,sizeof(nums_1)/sizeof(nums_1[0])) == 30); 

  SUBCASE("non-negative sum") {
    CHECK_FALSE( non_negative_sum(nums_3,sizeof(nums_3)/sizeof(nums_3[0]))  );
    CHECK( non_negative_sum(nums_2,sizeof(nums_2)/sizeof(nums_2[0]))  );
  }

  SUBCASE("non-positive sum") {
    CHECK( non_positive_sum(nums_3,sizeof(nums_3)/sizeof(nums_3[0]))  );
    CHECK_FALSE( non_positive_sum(nums_2,sizeof(nums_2)/sizeof(nums_2[0]))  );
  }  
}

// gen_permutations.cpp
TEST_CASE("Testing calculate_min_prefix") { 
    SUBCASE("positive numbers") {
        int array[] = {1, 2, 3, 4, 5};
        CHECK(calculate_min_prefix(array, 5) == 0); 
    }
    SUBCASE("Mixed numbers") {
        int array[] = {3, -2, 1, -5, 2};
        CHECK(calculate_min_prefix(array, 5) == -3); 
    }
    SUBCASE("negative numbers") {
        int array[] = {-1, -2, -3, -4, -5};
        CHECK(calculate_min_prefix(array, 5) == -15); 
    }
    SUBCASE("Empty array") {
        int array[] = {};
        CHECK(calculate_min_prefix(array, 0) == 0); 
    }
}

TEST_CASE("find_min_prefix_index") { 
    SUBCASE("Empty array") {
        int array[] = {};
        CHECK(find_min_prefix_index(array, 0) == 0); 
    }
    SUBCASE("Single") {
        int array[] = {3, -2, 1, -5, 2};
        CHECK(find_min_prefix_index(array, 5) == 3); 
    }
    SUBCASE("Multiple") {
        int array[] = {1, -2, -3, 4, -2, -1};
        CHECK(find_min_prefix_index(array, 6) == 2); 
    }
    SUBCASE("No negative prefix sum") {
        int array[] = {2, 3, 5, 1};
        CHECK(find_min_prefix_index(array, 4) == 0); 
    }
}

// well_formed.cpp
TEST_CASE("Testing generate_well_formed_sequence") { 
    SUBCASE("empty input") {
        std::vector<int> emptyInput;
        auto result = generate_well_formed_sequence(emptyInput); 
        CHECK(result.empty() == true);
    }

    SUBCASE("Skips sequence") {
        std::vector<int> startsWithNegativeOne = {-1, 1, -1, 1, -1};
        auto result = generate_well_formed_sequence(startsWithNegativeOne);
        CHECK(result.empty() == true);
    }

    SUBCASE("Rearrange list") {
        std::vector<int> input = {1,-1,-1,1,1,-1,1,-1,-1}; 
        auto result = generate_well_formed_sequence(input); 
        std::vector<int> expected = {1,1,-1,1,-1,-1,1,-1}; 

        CHECK(result == expected);
    }

    SUBCASE("well-balanced list") {
        std::vector<int> complexInput = {1, 1, 1, -1, -1, 1, -1, -1, -1};
        auto result = generate_well_formed_sequence(complexInput); 
        int balance = 0;
        bool isWellFormed = true;
        for (int symbol : result) {
            balance += symbol;
            if (balance < 0) {
                isWellFormed = false;
                break; 
            }
        }
        CHECK(isWellFormed == true);
        CHECK(balance == 0);
    }
}