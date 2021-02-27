//
// Created by cest on 27/02/21.
//

#ifndef UABC_SIMULATOR_H
#define UABC_SIMULATOR_H

enum Money {
    LOW = 0,
    MIDDLE = 1,
    HIGH = 2
};

enum Age {
    CHILD = 0,
    ADULT = 1,
    ELDERLY = 2
};

enum Power {
    CITIZEN = 0,
    LOCAL_GOVERNMENT = 1,
    STATE_GOVERNMENT = 2,
    FEDERAL_GOVERNMENT = 3
};

struct MotivationToAttentionIt {
    Money money;
    Age age;
    Power power;
};


class Simulator {
public:
    static string createPatient(MotivationToAttentionIt motivation) {
        if (
                motivation.age == ELDERLY &&
                motivation.money == HIGH &&
                motivation.power >= FEDERAL_GOVERNMENT) {
            return "URGENT-IMPORTANT";
        }
        if (
                motivation.age <= ELDERLY &&
                motivation.money == HIGH &&
                motivation.power < FEDERAL_GOVERNMENT
                ) {
            return "IMPORTANT";
        }
        if (
                motivation.age == ELDERLY &&
                motivation.money < HIGH &&
                motivation.power < FEDERAL_GOVERNMENT
                ) {
            return "URGENT-NO_IMPORTANT";
        }
        return "NO_URGENT-NO_IMPORTANT";
    }
};


#endif //UABC_SIMULATOR_H
