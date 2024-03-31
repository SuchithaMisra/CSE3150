#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Matrix_Modified.h" 

TEST_CASE("Matrix initialization and operations") {
    int n = 4; 

    std::vector<std::vector<int>> input_matrix1 = {{0, 1, 0, -1}, {-1, 0, 1, 0}, {0, -1, 0, 1}, {1, 0, -1, 0}};
    std::vector<std::vector<int>> input_matrix2 = {{1, 0, -1, 0}, {0, -1, 0, 1}, {-1, 0, 1, 0}, {0, 1, 0, -1}};
    std::vector<std::vector<int>> input_matrix3 = {{-1, 0, 1, 0}, {0, 1, 0, -1}, {1, 0, -1, 0}, {0, -1, 0, 1}};

    Matrix_Modified m(n, input_matrix1, input_matrix2, input_matrix3); 

    SUBCASE("Initialization") {
        CHECK(m.getElementAt(0, 1) == 3 * (n + 1)); 
        CHECK(m.getElementAt(1, 0) == 1.0 / (3 * (n + 1))); 
    }

    SUBCASE("Multiplication") {
        Matrix_Modified result = m.multiplyMatrices(m); 
        result.normalizeMatrix(n);
        CHECK(result.getElementAt(0, 0) == 0); 
    }

    SUBCASE("Normalization") {
        Matrix_Modified result = m.multiplyMatrices(m); 
        result.normalizeMatrix(n); 
        CHECK(result.getElementAt(0, 0) == 0); 
    }
}
