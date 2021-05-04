#include <iostream>
#include <cmath>
using namespace std;


int main() {
    int i=8;
    int j=0;
    while (j < log2(i)+1) {
	cout << ++j << "\n";
	// c=c/2;
	//cout << c << "\n";
    }
    cout << "Finished\n";
}


