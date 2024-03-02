#include <iostream>
#include <algorithm>
#include <vector>
#include "int_vector.h"

using namespace std;

int main() {
    string filename = "vectors_2D.txt"; // Default filename if no other is given 

    vector<int_vector> my_int_vector = readVectorsFromFile(filename);

    //sort function
    sort(my_int_vector.begin(), my_int_vector.end(), [](const int_vector &left, const int_vector &right) {
        return left.id > right.id;
    });

    // Output format 
    for (const auto &vect : my_int_vector) {
        cout << vect.id << ": " << vect.from << " " << vect.to << endl;
    }

    return 0;
}
