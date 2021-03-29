//
// Created by cest on 29/03/21.
//

#ifndef UABC_OPERATINGSYSTEM_H
#define UABC_OPERATINGSYSTEM_H
class OperatingSystemConsole {
public:
    virtual void clear() const = 0;
};

class OperatingSystem {
public:
    virtual OperatingSystemConsole *createConsole() const = 0;
};


#endif //UABC_OPERATINGSYSTEM_H
