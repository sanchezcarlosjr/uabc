//
// Created by cest on 06/04/21.
//
#include <iostream>
#include <functional>
#include <chrono>
using namespace std::chrono;
using namespace std;
#ifndef UABC_TIMER_H
#define UABC_TIMER_H

void time(function<void()> func) {
    auto start = high_resolution_clock::now();
    cout << "Starting..."<< endl;
    func();
    cout << "It have finished... ";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    auto durationInSeconds = duration_cast<seconds>(stop - start);
    cout << duration.count() << " nanoseconds" << " (" << durationInSeconds.count() <<" seconds)"<<endl;
}
#endif //UABC_TIMER_H
