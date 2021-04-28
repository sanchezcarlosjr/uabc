//
// Created by cest on 29/03/21.
//
#include "../OperatingSystem.h"
#ifndef UABC_WINDOWS_H
#define UABC_WINDOWS_H

class WindowsConsole: public OperatingSystemConsole {
public:
    void clear() const override {
        system("cls");
    }
};

class Windows: public OperatingSystem {
public:
    OperatingSystemConsole* createConsole() const override {
        return new WindowsConsole();
    }
};


#endif //UABC_WINDOWS_H
