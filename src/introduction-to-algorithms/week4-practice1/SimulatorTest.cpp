#include <gtest/gtest.h>
#include <typeinfo>
#include <string>
using namespace std;
#include "Simulator.h"

TEST(SimulatorTest, itShouldCreateAnPatient){
    string priorityPatient = Simulator::createPatient({
        HIGH,
        ELDERLY,
        FEDERAL_GOVERNMENT
    });
    EXPECT_EQ(priorityPatient, "URGENT-IMPORTANT");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}