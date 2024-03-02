#ifndef _INT_VECTOR_H_
#define _INT_VECTOR_H_

#include <iostream>
#include <vector>  
#include <string>  

using namespace std;

struct int_vector {
    int id;
    int from;
    int to;

    int_vector(const int_vector &iv);
    int_vector();
    int_vector(int id, int from, int to);
};

vector<int_vector> readIntVectorsFromFile(const string& filename);

#endif
