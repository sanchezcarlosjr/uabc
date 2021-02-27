#include <gtest/gtest.h>
#include "PatientPrioritizer.h"

TEST(SimulatorTest, itShouldCreateAnPatient){
    PatientPrioritizer patientPrioritizer;
    patientPrioritizer.prioritize(new Patient());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}