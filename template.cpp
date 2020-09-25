 
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template<class T>
class Matrix{
    size_t ROW,COL;
    vector<vector<T>> mat;
public:
    Matrix(size_t N, size_t M, float populate = 1){
        this->ROW = N;
        this->COL = M;
        this->mat = vector<vector<T>> (ROW,vector<T> (COL,populate));
    }

    Matrix(vector<vector<T>> initial){
        this->ROW = initial.size();
        this->COL = initial[0].size();
        this->mat = initial;
    }

    Matrix(size_t N){
        this->ROW = N;
        this->COL = N;
        this->mat = vector<vector<T>> (ROW,vector<T> (COL,1));
    }

    void __init(string tag) {
        for(int i = 0; i < ROW; i++){
            for(int j = 0; j < COL; j++){
                   cout << tag << " " << j+1 << "? ";
                   cin  >> this->mat[i][j];
            }
        }
    }

    void __init(vector<vector<string>> tags, bool negative = 0) {
        for(int i = 0; i < ROW; i++){
            for(int j = 0; j < COL; j++){
                if (tags[i][j] != "") {
                   cout << tags[i][j] << " ";
                   cin  >> this->mat[i][j];
                   if (negative) {
                     this->mat[i][j] = -this->mat[i][j];
                   }
                }
            }
        }
    }

    void __display(string tag = ""){
      cout << tag;
        for(int i = 0; i < ROW; ++i){
            for(int j = 0; j < COL; ++j){
                cout << this->mat[i][j] << " ";
            }
            cout << " ";
        }
    }

    Matrix<T> reducer(function<T(T accumulator, T actualValue)> callback) {
	T acc = 0;
	 for(int i = 0; i < ROW; ++i){
            for(int j = 0; j < COL; ++j){
               acc = callback(acc, this->mat[i][j]);
            }
        }
	Matrix <T>temp(1,1,acc);
	return temp;
    }

   Matrix<T> map(function<T(T actual, int i, int j)> callback) {
        for(int i = 0; i < ROW; ++i){
            for(int j = 0; j < COL; ++j){
               this->mat[i][j] = callback(this->mat[i][j],i,j);
            }
        }
        return this;
   }

   Matrix<T> filter(function<T(T currentValue, int i, int j)> isValidValue) {
	Matrix <T>temp(1, COL, 0);
	int k = 0;
	 for(int i = 0; i < ROW; ++i){
            for(int j = 0; j < COL; ++j){
		if (isValidValue(this->mat[i][j],i,j)) {
			temp.mat[0][k] = this->mat[i][j];
			k++;
		}
            }
        }
        return temp;
   }

    T sum() {
      T auxiliar = 0;
       for(int i = 0; i < ROW; ++i){ 
            for(int j = 0; j < COL; ++j){
                 auxiliar += this->mat[i][j];
            }
       }
       return auxiliar;
    }
  
    Matrix<T> operator*(const Matrix &rhs)const{
        if(this->COL != rhs.ROW){
            throw "MATRIX MULTIPLICATION CANNOT HAPPEN WITH THE GIVEN MATRICES";
        }
        Matrix<T> result(this->ROW,rhs.COL);
        for(int _i = 0; _i < this->ROW; _i++){
            for(int _j = 0; _j < rhs.COL; _j++){
                result.mat[_i][_j] = 0;
                for(int _k = 0; _k < this->COL; ++_k){
                    result.mat[_i][_j] += (this->mat[_i][_k]*rhs.mat[_k][_j]);
                }
            }
        }
        return result;
    }
    Matrix<T> operator*(const float scalar) const {
        Matrix<T> result(this->ROW,this->COL);
        for(int _i = 0; _i < this->ROW; _i++){
            for(int _j = 0; _j < this->COL; _j++){
                result.mat[_i][_j] = 0;
                for(int _k = 0; _k < this->COL; ++_k){
                    result.mat[_i][_j] = (this->mat[_i][_k]*scalar);
                }
            }
        }
        return result;
    }
    Matrix<T> power(int n){
        if(n == 0)return Matrix<T>(this->ROW, this->COL,1);
        if(n == 1)return *this;
        Matrix p = power(n/2);
        p = p*p;
        if(n%2)p = p*(*this);
        return p;
    }
};

template<class T>
Matrix<T> matrix(vector<vector<string>> tags, bool negative = 0) {
  Matrix<T> temp(tags.size(), tags[0].size());
  temp.__init(tags, negative);
  return temp;
}


template<class T>
Matrix<T> matrix(vector<vector<T>> init) {
  Matrix<T> temp(init);
  return temp;
}

template<class T>
Matrix<T> matrix(size_t N = 1, size_t M = 1, float populate = 1) {
  Matrix<T> temp(N, M, populate);
  return temp;
}

template<class T>
Matrix<T> matrix(size_t N = 1, size_t M = 1, string tag = "") {
  Matrix<T> temp(N, M);
  temp.__init(tag);
  return temp;
}

template<class T>
T print(string tag) {
    T var;
    cout << tag;
    cin>>var;
    return var;
}


int main() {
	
	return 0;
}
