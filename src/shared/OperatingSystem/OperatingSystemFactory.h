//
// Created by cest on 29/03/21.
//
#include "OperatingSystem.h"
#ifndef UABC_OPERATINGSYSTEMFACTORY_H
#define UABC_OPERATINGSYSTEMFACTORY_H

class OperatingSystemFactory {
private:
    static OperatingSystemFactory* OPERATING_SYSTEM_FACTORY;
    const OperatingSystem* operatingSystem;
    OperatingSystemConsole* console;
    OperatingSystemFactory() {
        #ifdef _WIN32
            #include "Windows.h"
            this->operatingSystem = new Windows();
        #elif _WIN64
            #include "Windows.h"
        #elif __APPLE__ || __MACH__
                // TODO
        #elif __linux__
            #include "Linux.h"
            this->operatingSystem = new Linux();
        #endif
            this->console = this->operatingSystem->createConsole();
    }
public:
    static OperatingSystemFactory* getInstance() {
        if (OPERATING_SYSTEM_FACTORY == nullptr) {
            OPERATING_SYSTEM_FACTORY = new OperatingSystemFactory();
        }
        return OPERATING_SYSTEM_FACTORY;
    }
    OperatingSystemConsole* getConsole() {
        return this->console;
    }
};

OperatingSystemFactory* OperatingSystemFactory::OPERATING_SYSTEM_FACTORY = nullptr;
#endif //UABC_OPERATINGSYSTEMFACTORY_H
