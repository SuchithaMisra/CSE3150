#include "doctest.h"
#include "gen_permutation.h"

TEST_CASE("Testing min_prefix") {
    SUBCASE("positive numbers") {
        int array[] = {1, 2, 3, 4, 5};
        CHECK(min_prefix(array, 5) == 0);
    }
    SUBCASE("Mixed numbers") {
        int array[] = {3, -2, 1, -5, 2};
        CHECK(min_prefix(array, 5) == -3);
    }
    SUBCASE("negative numbers") {
        int array[] = {-1, -2, -3, -4, -5};
        CHECK(min_prefix(array, 5) == -15);
    }
    SUBCASE("Empty array") {
        int array[] = {};
        CHECK(min_prefix(array, 0) == 0);
    }
}

TEST_CASE("min_prefix_index") {
    SUBCASE("Single valley") {
        int array[] = {3, -2, 1, -5, 2};
        CHECK(min_prefix_index(array, 5) == 3);
    }
    SUBCASE("Multiple") {
        int array[] = {1, -2, -3, 4, -2, -1};
        CHECK(min_prefix_index(array, 6) == 2);
    }
    SUBCASE("No negative prefix sum") {
        int array[] = {2, 3, 5, 1};
        CHECK(min_prefix_index(array, 4) == 0);
    }
    SUBCASE("Empty array") {
        int array[] = {};
        CHECK(min_prefix_index(array, 0) == 0);
    }
}
