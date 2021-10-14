#include <iostream>

using namespace std;

int sum(int x, int y) {
    return (x ^ y) + ((x & y) << 1);
}

int pow(int x, int i) {
    return x << i;
}

int main() {
    cout << pow(2,2) << endl;
    cout << sum(2,2) << endl;
    return 0;
}