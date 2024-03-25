// Necessary ibraries to include
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Read values from file into matrices
void readMatricesFromFile(std::vector<std::vector<int>>& matrix1, std::vector<std::vector<int>>& matrix2) {
    std::ifstream inputFile("matrix_input.txt");
    if (!inputFile.is_open()) { // In case file couldn't open
        std::cerr << "Error opening file: matrix_input.txt" << std::endl;
        return;
    }
    // Find N
    int N;
    inputFile >> N;
    // Initialize the matrices
    matrix1.resize(N, std::vector<int>(N));
    matrix2.resize(N, std::vector<int>(N));

    // Read matrix data and store it in the arrays
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            inputFile >> matrix1[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            inputFile >> matrix2[i][j];
        }
    }

    inputFile.close();
}

// Print matrices
void printMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    // Print matrix 1
    std::cout << "Matrix 1:" << std::endl;
    for (const auto& row : matrix1) {
        for (int val : row) {
            std::cout << std::setw(3) << val << ' '; // setw(3) is to align the output
        }
        std::cout << std::endl;
    }

    // Print matrix 2
    std::cout << "\nMatrix 2:" << std::endl;
    for (const auto& row : matrix2) {
        for (int val : row) {
            std::cout << std::setw(3) << val << ' ';
        }
        std::cout << std::endl;
    }
}

// Add two matrices and place the result in a third matrix; print the result
void addMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()) { // In case sizes mismatch
        std::cerr << "Error: Matrices are not the same size" << std::endl;
        return;
    }

    std::vector<std::vector<int>> resultMatrix(matrix1.size(), std::vector<int>(matrix1[0].size()));
    // Do the adding
    for (int i = 0; i < matrix1.size(); ++i) {
        for (int j = 0; j < matrix1[0].size(); ++j) {
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Print the result matrix
    std::cout << "\nAddition of Matrices:" << std::endl;
    for (const auto& row : resultMatrix) {
        for (int val : row) {
            std::cout << std::setw(3) << val << ' ';
        }
        std::cout << std::endl;
    }
}

// Multiply two matrices and place the result in a third matrix; print the result
void multiplyMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()) { // In case sizes mismatch
        std::cerr << "Error: Matrices are not the same size" << std::endl;
        return;
    }

    std::vector<std::vector<int>> resultMatrix(matrix1.size(), std::vector<int>(matrix1[0].size()));
    // Do the multiplying
    for (int i = 0; i < matrix1.size(); ++i) {
        for (int j = 0; j < matrix1[0].size(); ++j) {
            for (int k = 0; k < matrix1[0].size(); ++k) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Print the result matrix
    std::cout << "\nMultiplication of Matrices:" << std::endl;
    for (const auto& row : resultMatrix) {
        for (int val : row) {
            std::cout << std::setw(3) << val << ' ';
        }
        std::cout << std::endl;
    }
}

// Subtract the second matrix from the first matrix and place the result in a third matrix; print the result
void subtractMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()) { // In case sizes mismatch
        std::cerr << "Error: Matrices are not the same size" << std::endl;
        return;
    }

    std::vector<std::vector<int>> resultMatrix(matrix1.size(), std::vector<int>(matrix1[0].size()));
    // Do the subtracting
    for (int i = 0; i < matrix1.size(); ++i) {
        for (int j = 0; j < matrix1[0].size(); ++j) {
            resultMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    // Print the result matrix
    std::cout << "\nSubtraction of Matrices:" << std::endl;
    for (const auto& row : resultMatrix) {
        for (int val : row) {
            std::cout << std::setw(3) << val << ' ';
        }
        std::cout << std::endl;
    }
}

// Update an element of the first matrix; print the result
void updateMatrix(std::vector<std::vector<int>>& matrix, int row, int col, int value) {
    if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size()) { // Check validity of row and column
        std::cerr << "Error: Invalid row or column" << std::endl;
        return;
    }
    // Update the value at the given location
    matrix[row][col] = value;

    // Print the updated matrix
    std::cout << "\nUpdated Matrix:" << std::endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << std::setw(3) << val << ' ';
        }
        std::cout << std::endl;
    }
}

// Get the max value of the first matrix
void findMaxInMatrix(const std::vector<std::vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) { // If matrix is empty, there couldn't be a max value
        std::cerr << "Error: Empty matrix" << std::endl;
        return;
    }
    // Set max value as first value in matrix
    int maxVal = matrix[0][0];
    // Update max value whenever a larger number is found
    for (const auto& row : matrix) {
        for (int val : row) {
            if (val > maxVal) {
                maxVal = val;
            }
        }
    }

    std::cout << "\nMax value in the matrix: " << maxVal << std::endl;
}

// Transpose the first matrix; print the result
void transposeMatrix(const std::vector<std::vector<int>>& matrix) {
    std::vector<std::vector<int>> transposedMatrix(matrix[0].size(), std::vector<int>(matrix.size()));
    // Switch rows and columns
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }

    // Print the transposed matrix
    std::cout << "\nTransposed Matrix:" << std::endl;
    for (const auto& row : transposedMatrix) {
        for (int val : row) {
            std::cout << std::setw(3) << val << ' ';
        }
        std::cout << std::endl;
    }
}


int main() { // This is to test all 8 functions on the sample input
    std::vector<std::vector<int>> matrix1, matrix2;
    readMatricesFromFile(matrix1, matrix2);

    printMatrices(matrix1, matrix2);
    addMatrices(matrix1, matrix2);
    multiplyMatrices(matrix1, matrix2);
    subtractMatrices(matrix1, matrix2);
  
    updateMatrix(matrix1, 1, 1, 15);
    findMaxInMatrix(matrix1);
    transposeMatrix(matrix1);

    return 0;
}
