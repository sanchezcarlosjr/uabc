#include "Ecosystem.h"
#include "../../shared/Test/StdoutMock.h"
#include <gtest/gtest.h>

vector<int> stoi(const vector<string> &strings) {
    vector<int> integers;
    integers.reserve(strings.size());
    for (const string &str: strings) {
        integers.push_back(stoi(str));
    }
    return integers;
}

TEST(EcosystemTest, InitState) {
    StdoutMock stdoutMock;
    Ecosystem ecosystem;
    vector<int> animals = stoi(stdoutMock.split("\\d"));
    stdoutMock.assert_eq({
                                 "Initial population\n",
                                 "\\d carnivores, \\d females, and \\d males.\n",
                                 "\\d herbivorous, \\d females, and \\d males.\n"
                         });
    ASSERT_EQ(animals[1] + animals[2], animals[0]);
    ASSERT_EQ(animals[4] + animals[5], animals[3]);
    ASSERT_EQ(animals[0] + animals[3], 10);
}

TEST(AnimalTest, itShouldBeInSomeZoneInBetween0To4) {
    Animal* carnivore = new Carnivore();
    ASSERT_TRUE(carnivore->getZone() >= 1 && carnivore->getZone() <= 4);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}