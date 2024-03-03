#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "lambda.h"

TEST_CASE("perfect numbers") {
    CHECK(is_perfect(6) == true);
    CHECK(is_perfect(28) == true);
    CHECK(is_perfect(496) == true);
    CHECK(is_perfect(8128) == true);
}

TEST_CASE("imperfect numbers") {
    CHECK(is_perfect(7) == false);
    CHECK(is_perfect(15) == false);
    CHECK(is_perfect(564) == false);
    CHECK(is_perfect(5434) == false);
}

TEST_CASE("negative numbers") {
    CHECK(is_perfect(-6) == false);
    CHECK(is_perfect(-19) == false);
    CHECK(is_perfect(-873) == false);
}

TEST_CASE("zero") {
    CHECK(is_perfect(0) == false);
}

TEST_CASE("large numbers") {
    CHECK(is_perfect(675423) == false);
    CHECK(is_perfect(123456789) == false);
}
