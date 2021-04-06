/*
        Shared
        Created by Carlos Sanchez
        Created at 26/02/21
*/
#include "DataStructure/DataStructure.h"
#include <iostream>

using namespace std;
int main() {
    List<int> list;
    list.factory(5)
    ->forEach([](int item) {
        cout << item << "\n";
    });
    return 0;
}
