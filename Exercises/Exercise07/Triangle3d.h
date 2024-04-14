#ifndef _TRIANGLE_3D_H_
#define _TRIANGLE_3D_H_

#include <iostream>
#include "Point3d.h"

using namespace std;

struct Triangle3d {

    Triangle3d();
    Triangle3d(const Triangle3d & p3d);
    Triangle3d(Point3d p1, Point3d p2, Point3d p3);
    ~Triangle3d();

    double getArea() const;

private:
    Point3d p1;
    Point3d p2;
    Point3d p3;

public:
    const Point3d & get_p1() const { return p1; }
    const Point3d & get_p2() const { return p2; }
    const Point3d & get_p3() const { return p3; }

    double pointDistance(const Point3d left, const Point3d right) const;
};

#endif