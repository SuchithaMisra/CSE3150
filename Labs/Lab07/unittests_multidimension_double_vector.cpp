#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "multidimension_double_vector.h" 
#include "distance.h"
#include <algorithm>
#include <vector>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846 
#endif

using namespace std;

TEST_CASE("Testing --> 3D vectors") {
    DoubleVector v1({3, 4, 0}, 1); 
    DoubleVector v2({6, 8, 0}, 2); 

    SUBCASE("Test dot_product function") {
        CHECK(dot_product(v1, v1) == doctest::Approx(25.0).epsilon(0.001));
        CHECK(dot_product(v1, v2) == doctest::Approx(50.0).epsilon(0.001));
    }

    SUBCASE("magnitude function on 3D vectors") {
        CHECK(magnitude(v1) == doctest::Approx(5.0).epsilon(0.001)); 
        CHECK(magnitude(v2) == doctest::Approx(10.0).epsilon(0.001)); 
    }

    SUBCASE("cosine_distance function on 3D vectors") {
        CHECK(cosine_distance(v1, v1) == doctest::Approx(0.0).epsilon(0.001));
        CHECK(cosine_distance(v1, v2) == doctest::Approx(0.0).epsilon(0.001));
    }
}

TEST_CASE("sorting 3D vector pairs by cosine distance") {
    // Create some 3D vectors with IDs
    DoubleVector v1({1, 2}, 1);
    DoubleVector v2({2, 4}, 2);
    DoubleVector v3({-1, -2}, 3);
    DoubleVector v4({0, 1}, 4);
    std::vector<MyDistance> distances;

    distances.push_back({1, 2, cosine_distance(v1, v2)});
    distances.push_back({1, 3, cosine_distance(v1, v3)});
    distances.push_back({1, 4, cosine_distance(v1, v4)});
    distances.push_back({2, 3, cosine_distance(v2, v3)});

    sort(distances.begin(), distances.end(),
              [](const MyDistance& a, const MyDistance& b) {
                  return a.cosine_distance < b.cosine_distance;
              });
    for (size_t i = 0; i < distances.size() - 1; ++i) {
        CHECK(distances[i].cosine_distance <= distances[i + 1].cosine_distance);
    }
}

TEST_CASE("vector operations --> 5D vectors") {
    DoubleVector v1({1, 2, 3, 4, 5}, 1);
    DoubleVector v2({5, 4, 3, 2, 1}, 2);
    DoubleVector v3({2, 3, 4, 5, 6}, 3);
    DoubleVector v4({-1, -1, -1, -1, -1}, 4);

    SUBCASE("dot_product function on 5D vectors") {
        CHECK(dot_product(v1, v1) == doctest::Approx(55).epsilon(0.001));
        CHECK(dot_product(v1, v2) == doctest::Approx(35).epsilon(0.001));
    }

    SUBCASE("Test magnitude function on 5D vectors") {
        CHECK(magnitude(v1) == doctest::Approx(sqrt(55)).epsilon(0.001));
        CHECK(magnitude(v4) == doctest::Approx(sqrt(5)).epsilon(0.001));
    }

    SUBCASE("cosine_distance function on 5D vectors") {
        double expected_cos_distance = acos(dot_product(v1, v2) / (magnitude(v1) * magnitude(v2)));
        CHECK(cosine_distance(v1, v2) == doctest::Approx(expected_cos_distance).epsilon(0.001));
        CHECK(cosine_distance(v1, v1) == doctest::Approx(0.0).epsilon(0.001));
    }
}

TEST_CASE("sorting 5D vector pairs by cosine distance") {
    // Create some 5D vectors with IDs
    DoubleVector v1({1, 2, 3, 4, 5}, 1);
    DoubleVector v2({5, 4, 3, 2, 1}, 2);
    DoubleVector v3({2, 3, 4, 5, 6}, 3);
    DoubleVector v4({-1, -1, -1, -1, -1}, 4);
    std::vector<MyDistance> distances;

    distances.push_back({1, 2, cosine_distance(v1, v2)});
    distances.push_back({1, 3, cosine_distance(v1, v3)});
    distances.push_back({1, 4, cosine_distance(v1, v4)});
    distances.push_back({2, 3, cosine_distance(v2, v3)});

    sort(distances.begin(), distances.end(),
              [](const MyDistance& a, const MyDistance& b) {
                  return a.cosine_distance < b.cosine_distance;
              });

    for (size_t i = 0; i < distances.size() - 1; ++i) {
        CHECK(distances[i].cosine_distance <= distances[i + 1].cosine_distance);
    }
}