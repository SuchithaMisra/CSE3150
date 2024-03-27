#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "double_vector.h" 
#include "distance.h"
#include <algorithm>
#include <vector>

#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846 
#endif

TEST_CASE("Testing vector operations") {
    double_vector v1(5, 6, 3);
    double_vector v2(9, 12, 4);

    SUBCASE("Test square function") {
        CHECK(square(4.0) == 16.0);
    }

    SUBCASE("Test dot_product function") {
        CHECK(dot_product(v1, v2) == 117.0);
    }

    SUBCASE("Test magnitude function") {
        CHECK(magnitude(v1) == doctest::Approx(7.81024967591));
    }

    SUBCASE("Cosine_distance function : Expected to be 0") {
        CHECK(cosine_distance(v1, v1) == doctest::Approx(0.0).epsilon(0.001));
    }
}

TEST_CASE("vector pair : cosine closeness") {
    // Create vertors with IDs
    double_vector v1(3, 2, 5);
    double_vector v2(6, 9, 6);
    double_vector v3(-2, -4, 7);
    double_vector v4(1, 7, 8);

    std::vector<my_distance> distances;


    distances.push_back({5, 6, cosine_distance(v1, v2)});
    distances.push_back({5, 7, cosine_distance(v1, v3)});
    distances.push_back({5, 8, cosine_distance(v1, v4)});
    distances.push_back({6, 7, cosine_distance(v2, v3)});
    distances.push_back({6, 8, cosine_distance(v2, v4)});
    distances.push_back({7, 8, cosine_distance(v3, v4)});

    std::sort(distances.begin(), distances.end(),
              [](const my_distance& a, const my_distance& b) {
                  return a.cos_distance < b.cos_distance;
              });

    CHECK(distances[0].cos_distance <= distances[1].cos_distance);
}