#ifndef TRIANGLE_3D_H
#define TRIANGLE_3D_H

#include "triangle_3D.h"
#include <cmath>

class Triangle3d {
private:
    Point3d p1, p2, p3;

public:
    Triangle3d(const Point3d& p1, const Point3d& p2, const Point3d& p3)
        : p1(p1), p2(p2), p3(p3) {}

    double distance(const Point3d& a, const Point3d& b) const {
        return std::sqrt(std::pow(a.get_x() - b.get_x(), 2) +
                         std::pow(a.get_y() - b.get_y(), 2) +
                         std::pow(a.get_z() - b.get_z(), 2));
    }

    double area() const {
        double d12 = distance(p1, p2);
        double d13 = distance(p1, p3);
        double d23 = distance(p2, p3);
        double s = (d12 + d13 + d23) / 2;
        return std::sqrt(s * (s - d12) * (s - d13) * (s - d23));
    }
};

#endif