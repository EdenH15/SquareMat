//
// Created by eden on 4/20/25.
//Edenhassin@gmail.com

#ifndef SQUAREMAT_H
#define SQUAREMAT_H
#include <iostream>


namespace Matrix {
    class SquareMat {
    private:
        int size;
        double **matrix;

    public:
        SquareMat(int s);

        SquareMat(const SquareMat &other); // Copy Constructor
        SquareMat &operator=(const SquareMat &other); // Copy Assignment Operator
        ~SquareMat();

        int getSize() const;

        double sumM() const;

        SquareMat operator+(const SquareMat &other) const;

        SquareMat operator-(const SquareMat &other) const;

        SquareMat operator-() const;

        SquareMat operator*(const SquareMat &other) const;

        SquareMat operator*(double s) const;

        friend SquareMat operator*(double s, const SquareMat &mat);

        SquareMat operator%(const SquareMat &other) const;

        SquareMat operator%(double s) const;

        SquareMat operator/(double s) const;

        SquareMat operator^(int p) const;

        SquareMat &operator++();

        SquareMat operator++(int);

        SquareMat &operator--();

        SquareMat operator--(int);

        SquareMat operator~() const;

        double *operator[](int row);

        const double *operator[](int row) const;

        bool operator==(const SquareMat &other) const;

        bool operator!=(const SquareMat &other) const;

        bool operator<(const SquareMat &other) const;

        bool operator>(const SquareMat &other) const;

        bool operator<=(const SquareMat &other) const;

        bool operator>=(const SquareMat &other) const;

        double operator!() const;

        SquareMat &operator+=(const SquareMat &other);

        SquareMat &operator-=(const SquareMat &other);

        SquareMat &operator*=(const SquareMat &other);

        SquareMat &operator*=(double s);

        SquareMat &operator/=(double s);

        SquareMat &operator%=(const SquareMat &other);

        SquareMat &operator%=(double s);

        friend std::ostream &operator<<(std::ostream &os, const SquareMat &mat);
    };
}


#endif //SQUAREMAT_H
