#include "Matrix_Modified.h"
#include <iostream>

int main() {
    int matrix_size = 4;
    std::vector<std::vector<int>> input_matrix1 = {{0, 1, 0, -1}, {-1, 0, 1, 0}, {0, -1, 0, 1}, {1, 0, -1, 0}};
    std::vector<std::vector<int>> input_matrix2 = {{1, 0, -1, 0}, {0, -1, 0, 1}, {-1, 0, 1, 0}, {0, 1, 0, -1}};
    std::vector<std::vector<int>> input_matrix3 = {{-1, 0, 1, 0}, {0, 1, 0, -1}, {1, 0, -1, 0}, {0, -1, 0, 1}};
    
    Matrix_Modified graph(matrix_size, input_matrix1, input_matrix2, input_matrix3);
    Matrix_Modified result = graph.multiplyMatrices(graph);
    result.normalizeMatrix(matrix_size);
    
    for (int i = 0; i < matrix_size; ++i) {
        for (int j = 0; j < matrix_size; ++j) {
            std::cout << result.getElementAt(i, j) << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
