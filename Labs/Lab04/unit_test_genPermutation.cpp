#include "doctest.h"
#include "gen_permutation.h"

TEST_CASE("Testing get_lowest_prefix_sum_value") {
    SUBCASE("positive numbers") {
        int array[] = {1, 2, 3, 4, 5};
        CHECK(get_lowest_prefix_sum_value(array, 5) == 0);
    }
    SUBCASE("Mixed numbers") {
        int array[] = {3, -2, 1, -5, 2};
        CHECK(get_lowest_prefix_sum_value(array, 5) == -3);
    }
    SUBCASE("negative numbers") {
        int array[] = {-1, -2, -3, -4, -5};
        CHECK(get_lowest_prefix_sum_value(array, 5) == -15);
    }
    SUBCASE("Empty array") {
        int array[] = {};
        CHECK(get_lowest_prefix_sum_value(array, 0) == 0);
    }
}

TEST_CASE("index_of_lowest_prefix_sum_element") {
    SUBCASE("Single valley") {
        int array[] = {3, -2, 1, -5, 2};
        CHECK(index_of_lowest_prefix_sum_element(array, 5) == 3);
    }
    SUBCASE("Multiple") {
        int array[] = {1, -2, -3, 4, -2, -1};
        CHECK(index_of_lowest_prefix_sum_element(array, 6) == 2);
    }
    SUBCASE("No negative prefix sum") {
        int array[] = {2, 3, 5, 1};
        CHECK(index_of_lowest_prefix_sum_element(array, 4) == 0);
    }
    SUBCASE("Empty array") {
        int array[] = {};
        CHECK(index_of_lowest_prefix_sum_element(array, 0) == 0);
    }
}

