#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "triangle.h"

TEST_CASE("Testing Triangle3d area calculation") {
    Point3d p1(0, 0, 0);
    Point3d p2(1, 0, 0);
    Point3d p3(0, 1, 0);
    Triangle3d triangle(p1, p2, p3);

    CHECK(triangle.area() == doctest::Approx(0.5));
}