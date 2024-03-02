#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "int_vector.h"

TEST_CASE("Test output") {
    std::vector<int_vector> result = readVectorsFromFile("vectors_2D.txt");

    CHECK(result.size() == 5); 

    CHECK(result[0].id == 0);
    CHECK(result[0].from == 1);
    CHECK(result[0].to == 2);

    CHECK(result[4].id == 4);
    CHECK(result[4].from == 9);
    CHECK(result[4].to == 11);
}

TEST_CASE("valid file") {
    std::vector<int_vector> result = readVectorsFromFile("VectorTest_file1.txt");
    CHECK(result.size() == 6); 

    SUBCASE("Original file") {
        std::vector<int_vector> result = readVectorsFromFile("vectors_2D.txt");
    CHECK(result.size() == 5); 
    }
}

TEST_CASE("empty file") {
    std::vector<int_vector> result = readVectorsFromFile("VectorTest_file2.txt");
    CHECK(result.empty());
}

TEST_CASE("one vector") {
    std::vector<int_vector> result = readVectorsFromFile("VectorTest_file3.txt");
    REQUIRE(result.size() == 1);
    CHECK(result[0].id == 0);
}

TEST_CASE("Read from a non-existent file") {
    std::vector<int_vector> result = readVectorsFromFile("Fakefile.txt");
    CHECK(result.empty());
}

