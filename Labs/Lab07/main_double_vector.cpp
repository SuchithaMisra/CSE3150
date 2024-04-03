#include <vector>
#include <iomanip> 
#include "multidimension_double_vector.h"
#include "distance.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream> 

using namespace std;

int main() {
    vector<DoubleVector> my_double_vector;
    vector<MyDistance> all_pairs_distances;

    ifstream in_file("vectors.txt"); 
    if (!in_file.is_open()) {
        cerr << "Failed to open file." << endl;
        return 1; // Exit with error code
    }

    string line;
    int id = 0;

//reading vectors 
    while (getline(in_file, line)) {
        istringstream iss(line);
        vector<double> components;
        double value;

        while (iss >> value) {
            components.push_back(value);
        }

        if (components.size() >= 2) { 
            my_double_vector.emplace_back(components, id++);
        }
    }

    for (size_t i = 0; i < my_double_vector.size(); ++i) {
        for (size_t j = 0; j < my_double_vector.size(); ++j) {
            if (i != j) {
                double dist = cosine_distance(my_double_vector[i], my_double_vector[j]);
                all_pairs_distances.emplace_back(i, j, dist);
            }
        }
    }

    sort(all_pairs_distances.begin(), all_pairs_distances.end(), [](const MyDistance &a, const MyDistance &b) {
        if (a.cosine_distance == b.cosine_distance)
            return a.id1 == b.id1 ? a.id2 < b.id2 : a.id1 < b.id1;
        return a.cosine_distance < b.cosine_distance;
    });

//printing 
    cout << "Vector Pairs (Ordered by Cosine Closeness):" << endl;
    for (const auto& pair : all_pairs_distances) {
        cout << pair.id1 << "," << pair.id2 << " : ";
        cout << fixed << setprecision(4) << pair.cosine_distance << endl;
    }

    in_file.close();
    return 0;
}