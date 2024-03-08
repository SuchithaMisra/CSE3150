#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include <limits>  
#include <stdexcept>

#include "read.h"

const int INF = std::numeric_limits<int>::max(); 

// Type alias
using Matrix = std::vector<std::vector<int>>;

// Function to read matrix from stream
Matrix ReadMatrixFromStream(std::istream& in) {
    Matrix matrix;
    std::string line;

    // Read and parse matrix dimensions
    while (getline(in, line)) {
        std::istringstream lineStream(line);
        std::vector<int> row;
        int value;

        while (lineStream >> value) {
            row.push_back(value == 2 ? INF : value);
        }

        // Check if all rows have the same number of columns
        if (!matrix.empty() && row.size() != matrix[0].size()) {
            throw std::runtime_error("Matrix row size mismatch");
        }

        matrix.push_back(row);
    }

    // Check if file is empty
    if (matrix.empty()) {
        throw std::runtime_error("Empty matrix input");
    }

    return matrix;
}

// Function to open file and read matrix
Matrix ReadMatrixFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    return ReadMatrixFromStream(file);
}

// Function to initialize D1, D0, and Dminus1 matrices from files
void AdjacencyMatrices(Matrix& D1, Matrix& D0, Matrix& Dminus1) {
    D1 = ReadMatrixFromFile("D1.txt");
    D0 = ReadMatrixFromFile("D0.txt");
    Dminus1 = ReadMatrixFromFile("Dminus1.txt");
}

// Function to print the matrix
void PrintMatrix(const Matrix& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            if (elem == std::numeric_limits<int>::max()) {
                std::cout << "INF" << "\t";
            } else {
                std::cout << elem << "\t";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
