#include "Matrix_Modified.h"
#include <cmath>

const double INFINITY_REPLACEMENT = 1e9;

Matrix_Modified::Matrix_Modified(int size) : size(size), matrixData(size, std::vector<double>(size, INFINITY_REPLACEMENT)) {}

Matrix_Modified::Matrix_Modified(int size, const std::vector<std::vector<int>>& matrix1, 
                                 const std::vector<std::vector<int>>& matrix2,
                                 const std::vector<std::vector<int>>& matrix3)
    : size(size), matrixData(size, std::vector<double>(size, INFINITY_REPLACEMENT)) {
    initializeMatrix(matrix1);
}

void Matrix_Modified::initializeMatrix(const std::vector<std::vector<int>>& inputData) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (inputData[i][j] == 0) {
                matrixData[i][j] = 1;
            } else if (inputData[i][j] == 1) {
                matrixData[i][j] = 3 * (size + 1);
            } else if (inputData[i][j] == -1) {
                matrixData[i][j] = 1.0 / (3 * (size + 1));
            }
        }
    }
}

Matrix_Modified Matrix_Modified::multiplyMatrices(const Matrix_Modified& other) const {
    Matrix_Modified result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            double sum = 0;
            for (int k = 0; k < size; ++k) {
                double multiplication = matrixData[i][k] * other.matrixData[k][j];
                sum += multiplication;
            }
            result.matrixData[i][j] = sum;
        }
    }
    return result;
}

void Matrix_Modified::normalizeMatrix(int n) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (detectNegativeEdge(matrixData[i][j], n)) {
                matrixData[i][j] = -1;
            } else if (detectPositiveEdge(matrixData[i][j], n)) {
                matrixData[i][j] = 1;
            } else if (detectZeroEdge(matrixData[i][j], n)) {
                matrixData[i][j] = 0;
            } else {
                matrixData[i][j] = INFINITY_REPLACEMENT;
            }
        }
    }
}

double Matrix_Modified::fractionalPart(double value) const {
    return value - std::trunc(value);
}

int Matrix_Modified::truncate(double value) const {
    return static_cast<int>(value);
}

bool Matrix_Modified::detectNegativeEdge(double edgeCost, int n) const {
    double check = (3 * (n + 1)) * fractionalPart(edgeCost);
    return check >= 1 && check < 2 * n;
}

bool Matrix_Modified::detectPositiveEdge(double edgeCost, int n) const {
    int check = truncate(edgeCost / (3 * (n + 1)));
    return check >= 1 && check < 2 * n;
}

bool Matrix_Modified::detectZeroEdge(double edgeCost, int n) const {
    int check = truncate(edgeCost) % (3 * (n + 1));
    return check > 0 && check < 3 * n;
}

double Matrix_Modified::getElementAt(int row, int col) const {
    return matrixData[row][col];
}
