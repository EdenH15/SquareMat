//
// Created by eden on 4/20/25.
// Edenhassin@gmail.com

#include "SquareMat.h"
#include <stdexcept>
#include <cmath>


namespace Matrix {
    // Constructor: Initializes a square matrix with given size
    SquareMat::SquareMat(int s): size(s) {
        matrix = new double *[size];
        for (int i = 0; i < size; i++) {
            matrix[i] = new double[size];
        }
    }

    // Destructor: Deallocates memory used by the matrix
    SquareMat::~SquareMat() {
        for (int i = 0; i < size; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    // Copy constructor: Creates a new matrix as a copy of another one
    SquareMat::SquareMat(const SquareMat &other): size(other.size) {
        matrix = new double *[size];
        for (int i = 0; i < size; i++) {
            matrix[i] = new double[size];
            for (int j = 0; j < size; j++) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }

    // Assignment operator: Copies matrix data from another object
    SquareMat &SquareMat::operator=(const SquareMat &other) {
        if (this != &other) {
            for (int i = 0; i < size; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;

            size = other.size;
            matrix = new double *[size];

            for (int i = 0; i < size; ++i) {
                matrix[i] = new double[size];
                for (int j = 0; j < size; ++j) {
                    matrix[i][j] = other.matrix[i][j];
                }
            }
        }
        return *this;
    }


    SquareMat SquareMat::operator+(const SquareMat &other) const {
        if (size != other.getSize()) {
            throw std::invalid_argument("Matrices must have the same size");
        }

        SquareMat result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return result;
    }

    SquareMat SquareMat::operator-(const SquareMat &other) const {
        if (size != other.getSize()) {
            throw std::invalid_argument("Matrices must have the same size");
        }

        SquareMat result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
            }
        }
        return result;
    }

    //Negates all elements of the matrix
    SquareMat SquareMat::operator-() const {
        SquareMat result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.matrix[i][j] = -matrix[i][j];
            }
        }
        return result;
    }

    // Element-wise multiplication operator: Multiplies corresponding elements of two matrices
    SquareMat SquareMat::operator*(const SquareMat &other) const {
        if (size != other.getSize()) {
            throw std::invalid_argument("Matrices must have the same size");
        }
        SquareMat result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                double sum = 0;
                for (int k = 0; k < size; k++) {
                    sum += matrix[i][k] * other.matrix[k][j];
                }
                result.matrix[i][j] = sum;
            }
        }
        return result;
    }

    SquareMat SquareMat::operator*(double s) const {
        SquareMat result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.matrix[i][j] = matrix[i][j] * s;
            }
        }
        return result;
    }

    SquareMat operator*(double s, const SquareMat &mat) {
        SquareMat result(mat.getSize());
        for (int i = 0; i < mat.getSize(); i++) {
            for (int j = 0; j < mat.getSize(); j++) {
                result.matrix[i][j] = s * mat.matrix[i][j];
            }
        }
        return result;
    }

    SquareMat SquareMat::operator%(const SquareMat &other) const {
        if (size != other.getSize()) {
            throw std::invalid_argument("Matrices must have the same size");
        }
        SquareMat result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.matrix[i][j] = matrix[i][j] * other.matrix[i][j];
            }
        }
        return result;
    }

    SquareMat SquareMat::operator%(double s) const {
        SquareMat result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.matrix[i][j] = fmod(matrix[i][j], s);
            }
        }
        return result;
    }

    SquareMat SquareMat::operator/(double s) const {
        if (s == 0) {
            throw std::invalid_argument("Cannot divide by zero");
        }
        SquareMat result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.matrix[i][j] = matrix[i][j] / s;
            }
        }
        return result;
    }

    SquareMat SquareMat::operator^(int p) const {
        if (p < 0) {
            throw std::invalid_argument("p must be positive");
        }
        if (p == 0) {
            SquareMat idenMat(size);
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if (i == j) {
                        idenMat.matrix[i][j] = 1;
                    } else {
                        idenMat.matrix[i][j] = 0;
                    }
                }
            }
            return idenMat;
        }
        if (p == 1) {
            return *this;
        }
        SquareMat result = *this;
        for (int i = 1; i < p; i++) {
            result = result * (*this);
        }
        return result;
    }

    // Pre-increment operator: Increases all elements of the matrix by 1
    SquareMat &SquareMat::operator++() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                matrix[i][j] = matrix[i][j] + 1;
            }
        }
        return *this;
    }

    // Pre-decrement operator: Decreases all elements of the matrix by 1
    SquareMat &SquareMat::operator--() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                matrix[i][j] = matrix[i][j] - 1;
            }
        }
        return *this;
    }


    // Post-increment operator: Increases the matrix and returns the original
    SquareMat SquareMat::operator++(int) {
        SquareMat result = *this;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                matrix[i][j] = matrix[i][j] + 1;
            }
        }
        return result;
    }

    // Post-decrement operator: Decreases the matrix and returns the original
    SquareMat SquareMat::operator--(int) {
        SquareMat result = *this;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                matrix[i][j] = matrix[i][j] - 1;
            }
        }
        return result;
    }

    // Transpose operator
    SquareMat SquareMat::operator~() const {
        SquareMat result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.matrix[j][i] = matrix[i][j];
            }
        }
        return result;
    }

    double *SquareMat::operator[](int row) {
        if (row < 0 || row >= size)
            throw std::out_of_range("Row index out of bounds");
        return matrix[row];
    }

    const double *SquareMat::operator[](int row) const {
        if (row < 0 || row >= size)
            throw std::out_of_range("Row index out of bounds");
        return matrix[row];
    }


    bool SquareMat::operator==(const SquareMat &other) const {
        return sumM() == other.sumM();
    }

    bool SquareMat::operator!=(const SquareMat &other) const {
        return !(*this == other);
    }

    bool SquareMat::operator<(const SquareMat &other) const {
        return sumM() < other.sumM();
    }

    bool SquareMat::operator>(const SquareMat &other) const {
        return sumM() > other.sumM();
    }

    bool SquareMat::operator<=(const SquareMat &other) const {
        return *this < other || *this == other;
    }

    bool SquareMat::operator>=(const SquareMat &other) const {
        return *this > other || *this == other;
    }

    //Calculates the determinant of a square matrix
    double SquareMat::operator!() const {
        if (size == 1) {
            return matrix[0][0];
        }
        if (size == 2) {
            return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        }

        double det = 0;
        for (int col = 0; col < size; ++col) {
            SquareMat minor(size - 1);
            for (int i = 1; i < size; ++i) {
                int minorCol = 0;
                for (int j = 0; j < size; ++j) {
                    if (j == col) continue;
                    minor.matrix[i - 1][minorCol] = matrix[i][j];
                    minorCol++;
                }
            }
            double sign;
            if (col % 2 == 0) {
                sign = 1;
            } else {
                sign = -1;
            }
            det += sign * matrix[0][col] * !minor;
        }
        return det;
    }


    SquareMat &SquareMat::operator+=(const SquareMat &other) {
        if (size != other.size) {
            throw std::invalid_argument("Matrix must have the same size");
        }
        *this = *this + other;
        return *this;
    }

    SquareMat &SquareMat::operator-=(const SquareMat &other) {
        if (size != other.size) {
            throw std::invalid_argument("Matrix must have the same size");
        }
        *this = *this - other;
        return *this;
    }

    SquareMat &SquareMat::operator*=(const SquareMat &other) {
        if (size != other.size) {
            throw std::invalid_argument("Matrix must have the same size");
        }
        *this = *this * other;
        return *this;
    }

    SquareMat &SquareMat::operator*=(double s) {
        *this = *this * s;
        return *this;
    }

    SquareMat &SquareMat::operator/=(double s) {
        if (s == 0) {
            throw std::invalid_argument("Cannot divide by zero");
        }
        *this = *this / s;
        return *this;
    }

    SquareMat &SquareMat::operator%=(const SquareMat &other) {
        if (size != other.size) {
            throw std::invalid_argument("Matrix must have the same size");
        }
        *this = *this % other;
        return *this;
    }

    SquareMat &SquareMat::operator%=(const double s) {
        *this = *this % s;
        return *this;
    }

    // Print matrix to standard output
    std::ostream &operator<<(std::ostream &os, const SquareMat &mat) {
        for (int i = 0; i < mat.size; ++i) {
            for (int j = 0; j < mat.size; ++j) {
                os << mat.matrix[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }


    double SquareMat::sumM() const {
        double sum = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                sum += matrix[i][j];
            }
        }
        return sum;
    }

    int SquareMat::getSize() const {
        return size;
    }
}
