#include <iostream>
#include <cmath>

#include "Point3d.h"
#include "Triangle3d.h"

using namespace std;

std::ostream & operator<<(std::ostream &os, const Triangle3d & t) {
    os << "p1: (" << t.get_p1().get_x() << ", " << t.get_p1().get_y() << ", " << t.get_p1().get_z() << "), "
       << "p2: (" << t.get_p2().get_x() << ", " << t.get_p2().get_y() << ", " << t.get_p2().get_z() << "), "
       << "p3: (" << t.get_p3().get_x() << ", " << t.get_p3().get_y() << ", " << t.get_p3().get_z() << ")";
    return os;
};

Triangle3d::Triangle3d() : p1{0.0}, p2{0.0}, p3{0.0} {};
Triangle3d::Triangle3d(const Triangle3d & p3d) : p1(p3d.p1),p2(p3d.p2), p3(p3d.p3) {};
Triangle3d::Triangle3d(Point3d p1,Point3d p2, Point3d p3) :  p1{p1}, p2{p2}, p3{p3} {};
Triangle3d::~Triangle3d() {};

double square(double value) { return value * value; }

double Triangle3d::pointDistance(Point3d left, Point3d right) const {
    double radicand = square(left.get_x() -right.get_x()) + square(left.get_y() -right.get_y()) + square(left.get_z() -right.get_z());

    return sqrt(radicand);
}

double Triangle3d::getArea() const {
    // Calculateing distances between all points
    double d12 = pointDistance(p1, p2);
    double d13 = pointDistance(p1, p3);
    double d23 = pointDistance(p2, p3);

    // semi-perimeter calculation 
    double s = (d12 + d13 + d23) / 2.0;

    // Return the area 
    return sqrt(s * (s - d12) * (s - d13) * (s - d23));  //Heron's formula
}