#include "read.h"
#include "logic_matrix.h"
#include <ostream>
#include <iostream>

using namespace std;
int main() {
    Matrix D1, D0, Dminus1;
    AdjacencyMatrices(D1, D0, Dminus1);  // Initialize 
    Expensive_Digraph(D1, D0, Dminus1);  // computation algorithm

    // Print
    cout << "Matrix D1:" << endl;
    PrintMatrix(D1);
    
    cout << "Matrix D0:" << endl;
    PrintMatrix(D0);

    cout << "Matrix Dminus1:" << endl;
    PrintMatrix(Dminus1);
    
    return 0;
}
