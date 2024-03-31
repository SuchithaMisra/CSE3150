#ifndef MATRIX_MODIFIED_H
#define MATRIX_MODIFIED_H

#include <vector>

class MatrixModified {
public:
    MatrixModified(int size); 
    void initialize(const std::vector<std::vector<int>>& D_minus_1, const std::vector<std::vector<int>>& D_0, const std::vector<std::vector<int>>& D_1);
    MatrixModified multiply(const MatrixModified& other) const;
    void normalize(int n);
    double getElement(int row, int col) const;

private:
    std::vector<std::vector<double>> data;
    int size;
    double fractionalPart(double value) const;
    int truncate(double value) const;
    bool detectNegativeOneEdge(double edgeCost, int n) const;
    bool detectPositiveOneEdge(double edgeCost, int n) const;
    bool detectZeroEdge(double edgeCost, int n) const;
};

#endif
