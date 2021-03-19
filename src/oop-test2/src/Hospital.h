//
// Created by cest on 17/03/21.
//

#include "System/system.h"

#ifndef UABC_HOSPITAL_H
#define UABC_HOSPITAL_H

class Hospital {
private:
    int size = 0;
public:
    Hospital();

    void simulate();

    int getSize();
};


#endif //UABC_HOSPITAL_H
