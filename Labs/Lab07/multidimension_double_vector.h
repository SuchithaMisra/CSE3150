#ifndef _MULTIDIMENSION_VECTOR_H_
#define _MULTIDIMENSION_VECTOR_H_

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct DoubleVector {
    vector<double> components;
    int id;
    DoubleVector() : id(0) {}
    DoubleVector(const vector<double>& components, int id) : components(components), id(id) {}
};

double square(const double &d);
double dot_product(const DoubleVector &one, const DoubleVector &two);
double magnitude(const DoubleVector &my_vector);
double cosine_distance(const DoubleVector &one, const DoubleVector &two);

#endif