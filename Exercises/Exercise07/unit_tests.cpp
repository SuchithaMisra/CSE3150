#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "triangle.h"

TEST_CASE("Testing Triangle area calculation") {
    Point3d p1(0, 0, 0);
    Point3d p2(1, 0, 0);
    Point3d p3(0, 1, 0);
    Triangle3d triangle(p1, p2, p3);

    CHECK(triangle.area() == doctest::Approx(0.5));
}
TEST_CASE("Testing Triangle with equilateral triangle") {
    Point3d p1(0, 0, 0);
    Point3d p2(1, 0, 0);
    Point3d p3(0.5, std::sqrt(3)/2, 0); // Equilateral triangle
    Triangle3d triangle(p1, p2, p3);

    CHECK(triangle.area() == doctest::Approx(0.5));
}

TEST_CASE("Testing Triangle with right-angled triangle") {
    Point3d p1(0, 0, 0);
    Point3d p2(3, 0, 0);
    Point3d p3(0, 4, 0); // Right-angled triangle with sides 3, 4, 5
    Triangle3d triangle(p1, p2, p3);

    CHECK(triangle.area() == doctest::Approx(6));
}

TEST_CASE("Testing Triangle with degenerate triangle") {
    Point3d p1(0, 0, 0);
    Point3d p2(0, 0, 0); // Degenerate triangle with two points overlapping
    Point3d p3(0, 1, 0);
    Triangle3d triangle(p1, p2, p3);

    CHECK(triangle.area() == 0); // Degenerate triangle has zero area
}