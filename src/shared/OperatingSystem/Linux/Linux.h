//
// Created by cest on 29/03/21.
//
#include "../OperatingSystem.h"

#ifndef UABC_LINUX_H
#define UABC_LINUX_H

class LinuxConsole: public OperatingSystemConsole {
public:
    void clear() const override {
        system("clear");
    }
};

class Linux: public OperatingSystem {
public:
    OperatingSystemConsole* createConsole() const override {
        return new LinuxConsole();
    }
};


#endif //UABC_LINUX_H
