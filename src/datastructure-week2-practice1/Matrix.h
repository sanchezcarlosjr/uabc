//
// Created by cest on 14/02/21.
//
#include <vector>
using namespace std;
#ifndef UABC_MATRIX_H
#define UABC_MATRIX_H

template<class T>
class Matrix {
private:
    size_t ROW,COL;
    vector<vector<T>> matrix;
public:
    Matrix(size_t N, size_t M, float populate = 1){
        this->ROW = N;
        this->COL = M;
        this->matrix = vector<vector<T>> (ROW,vector<T> (COL,populate));
    }
    void __display(string tag = ""){
        cout << tag;
        for(int i = 0; i < ROW; ++i){
            for(int j = 0; j < COL; ++j){
                cout << this->matrix[i][j] << "\t";
            }
            cout << "\n";
        }
    }
    Matrix<T> operator*(const Matrix &rhs)const{
        if(this->COL != rhs.ROW){
            throw "MATRIX MULTIPLICATION CANNOT HAPPEN WITH THE GIVEN MATRICES";
        }
        Matrix<T> result(this->ROW,rhs.COL, 0);
        for(int i = 0; i < this->ROW; i++){
            for(int j = 0; j < rhs.COL; j++){
                for(int k = 0; k < this->COL; k++){
                    result.matrix[i][j] += (this->matrix[i][k]*rhs.matrix[k][j]);
                }
            }
        }
        return result;
    }
};


#endif //UABC_MATRIX_H
