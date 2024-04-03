#include <iostream>
#include <cmath>

#include "multidimension_double_vector.h"

using namespace std;

double square(const double &d){
    return d*d;
}

double dot_product(const DoubleVector &one, const DoubleVector &two) {
    double result = 0.0;
    for (size_t i = 0; i < one.components.size(); i++) {
        result += one.components[i] * two.components[i];
    }
    return result;
}

double magnitude(const DoubleVector &my_vector) {
    double sum = 0.0;
    for (double val : my_vector.components) {
        sum += square(val);
    }
    return sqrt(sum);
}

double cosine_distance(const DoubleVector &one, const DoubleVector &two) {
    double dot = dot_product(one, two);
    double magOne = magnitude(one);
    double magTwo = magnitude(two);
    double cos_similarity = dot / (magOne * magTwo);
    // Ensure vaid result
    cos_similarity = max(-1.0, min(1.0, cos_similarity));
    return acos(cos_similarity);
}
