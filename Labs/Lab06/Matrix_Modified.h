#ifndef MATRIX_MODIFIED_H
#define MATRIX_MODIFIED_H

#include <vector>

class Matrix_Modified {
public:
    Matrix_Modified(int size);
    Matrix_Modified(int size, const std::vector<std::vector<int>>& matrix1, 
                    const std::vector<std::vector<int>>& matrix2,
                    const std::vector<std::vector<int>>& matrix3);
    void initializeMatrix(const std::vector<std::vector<int>>& data);
    Matrix_Modified multiplyMatrices(const Matrix_Modified& other) const;
    void normalizeMatrix(int n);
    double getElementAt(int row, int col) const;

private:
    std::vector<std::vector<double>> matrixData;
    int size;
    double fractionalPart(double value) const;
    int truncate(double value) const;
    bool detectNegativeEdge(double edgeCost, int n) const;
    bool detectPositiveEdge(double edgeCost, int n) const;
    bool detectZeroEdge(double edgeCost, int n) const;
};

#endif
