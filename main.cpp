//Edenhassin@gmail.com

#include "SquareMat.h"
#include <iostream>

using namespace Matrix;
using namespace std;

int main() {
    SquareMat A(2);
    SquareMat B(2);


    A[0][0] = 1;  A[0][1] = 2;
    A[1][0] = 3;  A[1][1] = 4;

    B[0][0] = 5;  B[0][1] = 6;
    B[1][0] = 7;  B[1][1] = 8;



    cout<<"Matrix A:"<<endl;
    std::cout << A;
    cout<<"Matrix B:"<<endl;
    std::cout << B;


    cout<<"A + B:"<<endl;
    std::cout << (A + B);


    cout<<"A - B:"<<endl;
    std::cout << (A - B);


    cout<<"A * B:"<<endl;
    std::cout << (A * B);

    cout<<"A * 2:"<<endl;
    std::cout << (A * 2);

    cout<<"2 * B:"<<endl;
    std::cout << (2 * B);


    cout<<"A % B:"<<endl;
    std::cout << (A % B);


    cout<<"A % 2:"<<endl;
    std::cout << (A % 2);


    cout<<"A / 2:"<<endl;
    std::cout << (A / 2);

    cout<<"A ^ 2:"<<endl;
    std::cout << (A ^ 2);


    cout<<"~A:"<<endl;
    std::cout << (~A);


    cout<<"Determinant of A(!):"<<endl;
    std::cout << !A << std::endl;

    ++A;
    cout<<"++A:"<<endl;
    std::cout << A;


    B--;
    cout<<"B--:"<<endl;
    std::cout << B;

    std::cout << "A == B?: " << (A == B) << std::endl;
    std::cout << "A != B?: " << (A != B) << std::endl;
    std::cout << "A > B?:  " << (A > B)  << std::endl;
    std::cout << "A < B?:  " << (A < B)  << std::endl;


    A += B;
    cout<<"A += B:"<<endl;
    std::cout << A;

    A -= B;
    cout<<"A -= B:"<<endl;
    std::cout << A;

    A *= B;
    cout<<"A *= B:"<<endl;
    std::cout << A;

    A /= 2;
    cout<<"A /= 2:"<<endl;
    std::cout << A;

    A %= B;
    cout<<"A %= B:"<<endl;
    std::cout << A;

    return 0;
}

