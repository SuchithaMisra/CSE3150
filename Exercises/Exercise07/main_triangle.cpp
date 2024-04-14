#include <iostream>
#include "Triangle3d.h"

using namespace std;

int main() {
    Point3d p1(1.0, 1.0, 1.0);
    Point3d p2(2.0, 3.0, 2.0);
    Point3d p3(-1.0, 0.0, 2.0);

    Triangle3d triangle(p1, p2, p3);

    cout << "Distance between points p1 & p2 --> " << triangle.pointDistance(p1, p2) << endl;
    cout << "Should be the sqrt(10) = sqrt(1^2 + 2^2 + 1^2)" << endl;

    cout << "Area of triangle --> " << triangle.getArea() << endl;

    return 0;
}