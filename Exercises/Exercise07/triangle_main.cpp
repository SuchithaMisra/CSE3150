#include <iostream>
#include "Point3d.h"
#include "triangle_3D.h"

int main() {
    Point3d p1(0, 0, 0);
    Point3d p2(1, 0, 0);
    Point3d p3(0, 1, 0);

    Triangle3d triangle(p1, p2, p3);
    std::cout << "Area of the triangle: " << triangle.area() << std::endl;
    return 0;
}