#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "lambda.h"

TEST_CASE("perfect numbers") {
    std::vector<int> perfect_numbers = {6, 28, 496, 8128};

    std::for_each(perfect_numbers.begin(), perfect_numbers.end(), [](int number) {
        CHECK(is_perfect(number) == true);
    });
}

TEST_CASE("imperfect numbers") {
    std::vector<int> imperfect_numbers = {7, 15, 564, 5434};

    std::for_each(imperfect_numbers.begin(), imperfect_numbers.end(), [](int number) {
        CHECK(is_perfect(number) == false);
    });
}

TEST_CASE("negative numbers") {
    std::vector<int> negative_numbers = {-6, -19, -873};

    std::for_each(negative_numbers.begin(), negative_numbers.end(), [](int number) {
        CHECK(is_perfect(number) == false);
    });
}

TEST_CASE("zero") {
    CHECK(is_perfect(0) == false);
}

TEST_CASE("large numbers") {
    std::vector<int> large_numbers = {675423, 123456789};

    std::for_each(large_numbers.begin(), large_numbers.end(), [](int number) {
        CHECK(is_perfect(number) == false);
    });
}
