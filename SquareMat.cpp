//
// Created by eden on 4/20/25.
// Edenhassin@gmail.com

#include "SquareMat.h"
#include <stdexcept>
#include <cmath>


namespace Matrix {
    SquareMat::SquareMat(int s):size(s) {
        matrix = new double*[size];
        for (int i = 0; i < size; i++) {
            matrix[i] = new double[size];
        }

    }
    SquareMat::~SquareMat() {
        for (int i = 0; i < size; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    SquareMat::SquareMat(const SquareMat &other):size(other.size) {
        matrix = new double*[size];
        for (int i = 0; i < size; i++) {
            matrix[i] = new double[size];
            for (int j = 0; j < size; j++) {
                matrix[i] = other.matrix[i];
            }
        }
    }

    SquareMat& SquareMat::operator=(const SquareMat& other) {
        if (this != &other) {
            for (int i = 0; i < size; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;

            size = other.size;
            matrix = new double*[size];

            for (int i = 0; i < size; ++i) {
                matrix[i] = new double[size];
                for (int j = 0; j < size; ++j) {
                    matrix[i][j] = other.matrix[i][j];
                }
            }
        }
        return *this;
    }


    SquareMat SquareMat::operator+(const SquareMat& other) const {
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

    SquareMat SquareMat::operator-(const SquareMat& other) const {
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

    SquareMat SquareMat::operator-() const{
        SquareMat result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.matrix[i][j] = -matrix[i][j];
            }
        }
        return result;
    }

    SquareMat SquareMat::operator*(const SquareMat& other) const {
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
    SquareMat operator*(double s, const SquareMat& mat) {
        SquareMat result(mat.getSize());
        for (int i = 0; i < mat.getSize(); i++) {
            for (int j = 0; j < mat.getSize(); j++) {
                result.matrix[i][j] = s * mat.matrix[i][j];
            }
        }
        return result;
    }

    SquareMat SquareMat::operator%(const SquareMat& other) const {
        if (size != other.getSize()) {
            throw std::invalid_argument("Matrices must have the same size");
        }
        SquareMat result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.matrix[i][j]= matrix[i][j]*other.matrix[i][j];
            }
        }
        return result;

    }

    SquareMat SquareMat::operator%(double s) const {
        SquareMat result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.matrix[i][j] = fmod(matrix[i][j],s);
            }
        }
        return result;
    }


    int SquareMat::getSize() const {
        return size;
    }




}
