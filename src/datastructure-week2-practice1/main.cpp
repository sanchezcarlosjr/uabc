#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
    Matrix<int> A(2,2);
    Matrix<int> B(2,2,2);
    Matrix<int> C = A*B;
    C.__display();
    return 0;
}