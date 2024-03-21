#include <iostream>
#include <fstream>
#include <iomanip>

const int max_size = 100;

void readMatricesFromFile(int matrixA[max_size][max_size], int matrixB[max_size][max_size], int& size, const char* filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error: Unable to open the file." << std::endl;
        exit(1);
    }

    inFile >> size;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            inFile >> matrixA[i][j];
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            inFile >> matrixB[i][j];
        }
    }

    inFile.close();
}
void printMatrix(int matrix[max_size][max_size], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(2) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void addMatrices(int result[max_size][max_size], int matrixA[max_size][max_size], int matrixB[max_size][max_size], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void multiplyMatrices(int result[max_size][max_size], int matrixA[max_size][max_size], int matrixB[max_size][max_size], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void subtractMatrices(int result[max_size][max_size], int matrixA[max_size][max_size], int matrixB[max_size][max_size], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}
void updateMatrixElement(int matrix[max_size][max_size], int size, int row, int col, int newValue) {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        matrix[row][col] = newValue;
    } else {
        std::cerr << "Error: Invalid row or column index." << std::endl;
    }
}
int getMaxValue(const int matrix[max_size][max_size], int size) {
    int maxValue = matrix[0][0];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] > maxValue) {
                maxValue = matrix[i][j];
            }
        }
    }
    return maxValue;
}
void transposeMatrix(int matrix[max_size][max_size], int size) {
    int temp;
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}



int main() {
    int size;
    int matrixA[max_size][max_size];
    int matrixB[max_size][max_size];
    int result[max_size][max_size];

    readMatricesFromFile(matrixA, matrixB, size, "matrix_input.txt");

    std::cout << "Mark Maloney" << std::endl;
    std::cout << "Lab #6: Matrix manipulation" << std::endl;

    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrixA, size);

    std::cout << "Matrix B:" << std::endl;
    printMatrix(matrixB, size);

    addMatrices(result, matrixA, matrixB, size);
    std::cout << "Matrix Sum (A + B):" << std::endl;
    printMatrix(result, size);

    multiplyMatrices(result, matrixA, matrixB, size);
    std::cout << "Matrix Product (A * B):" << std::endl;
    printMatrix(result, size);

    subtractMatrices(result, matrixA, matrixB, size);
    std:: cout << "Matrix Difference (A - B):" << std::endl;
    printMatrix(result, size);
    int row;
    int col;
    int number;
    std::cout << "Enter row of new number:";
    std::cin >> row;
    std::cout << "Enter column of new number:";
    std::cin >> col;
    std::cout << "Enter new number:";
    std::cin >> number;
    updateMatrixElement(matrixA, size, row, col, number);
    std::cout << "Matrix A after updating element ("<< row << "," << col << ") with value " << number << ":" << std::endl;
    printMatrix(matrixA, size);

    int maxVal = getMaxValue(matrixA, size);
    std::cout << "Max value in Matrix A: " << maxVal << std::endl;

    transposeMatrix(matrixA, size);
    std::cout << "Transposed Matrix A:" << std::endl;
    printMatrix(matrixA, size);

    return 0;
}