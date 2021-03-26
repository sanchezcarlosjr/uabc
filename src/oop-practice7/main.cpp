/*
        Queue
        Created by Carlos Sanchez
        Created at 26/02/21
*/
#include "Streaming.h"
#include "Cinema.h"
#include "Restaurant.h"
#include <iostream>
using namespace std;

int main() {
    Cinema cinema("AMC Theaters");
    Streaming streaming("Netflix");
    Restaurant restaurant("Gordon Ramsay","Versailles located 17.1 km (10.6 mi) west-southwest from the centre of Paris","That's the way");
    cout << "Amount of companies " << streaming.getAmountOfCompanies() << "\n";
    cout << restaurant.toString() << "\n";
    cout << "\n" << streaming.toString();
    cout << "\n\n" << cinema.toString();
    return 0;
}
