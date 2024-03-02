#include "int_vector.h"
#include <fstream>
#include <vector>

using namespace std;

vector<int_vector> readIntVectorsFromFile(const string& filename) {
    vector<int_vector> my_int_vector;

    ifstream in_file(filename);

    if (!in_file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return my_int_vector;
    }

    int id = 0;
    int from, to;
    while (in_file >> from >> to) {
        int_vector one_int_vector = int_vector(id++, from, to);
        my_int_vector.push_back(one_int_vector);
    }

    in_file.close();

    return my_int_vector;
}

int_vector::int_vector(const int_vector &iv) : id(iv.id), from(iv.from), to(iv.to) {
}

int_vector::int_vector() : id(-1), from(0), to(0) {
}

int_vector::int_vector(int id, int from, int to) : id(id), from(from), to(to) {
}
