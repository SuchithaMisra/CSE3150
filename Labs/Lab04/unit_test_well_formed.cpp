#include "doctest.h"
#include "gen_permutation.h"
#include "well_formed.h"

bool isWellFormed(const std::vector<int>& sequence) {
    int balance = 0;
    for (int symbol : sequence) {
        balance += symbol;
        if (balance < 0) {
            return false; 
        }
    }
    return balance == 0; 
}

TEST_CASE("Testing permuteWellFormed") { // Changed test case name
    SUBCASE("Handles empty input") {
        std::vector<int> emptyInput;
        auto result = permuteWellFormed(emptyInput); // Changed function name
        CHECK(result.empty() == true);
    }

    SUBCASE("Skips sequence starting with -1") {
        std::vector<int> startsWithNegativeOne = {-1, 1, -1, 1, -1};
        auto result = permuteWellFormed(startsWithNegativeOne); // Changed function name
        CHECK(result.empty() == true);
    }

    SUBCASE("Rearranges list") {
        std::vector<int> input = {1,-1,-1,1,1,-1,1,-1,-1}; 
        auto result = permuteWellFormed(input); // Changed function name
        std::vector<int> expected = {1,1,-1,1,-1,-1,1,-1}; 

        CHECK(result == expected);
    }

    SUBCASE("well-balanced list") {
        std::vector<int> complexInput = {1, 1, 1, -1, -1, 1, -1, -1, -1};
        auto result = permuteWellFormed(complexInput); // Changed function name
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
