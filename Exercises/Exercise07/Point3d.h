#ifndef _POINT_3D_H_
#define _POINT_3D_H_

#include <iostream>

using namespace std;

struct Point3d { 
   private:
        double x;
        double y;
        double z;
   public:
    Point3d();
    Point3d(const Point3d & p3d);
    Point3d(double all);
    Point3d(double x, double y, double z);
    ~Point3d();
    double get_x() const { return x; }
    double get_y() const { return y; }
    double get_z() const { return z; }
    void set_x(int x_in) { x = x_in; }
    void set_y(int y_in) { y = y_in; }
    void set_z(int z_in) { z = z_in; }
};
#endif