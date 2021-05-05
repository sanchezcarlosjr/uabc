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
    ecosystem.feedback();
    vector<int> animals = stoi(stdoutMock.split("\\d"));
    stdoutMock.assert_eq({
                                 "\\d carnivores, \\d females, and \\d males.\n",
                                 "\\d herbivorous, \\d females, and \\d males.\n"
                         });
    ASSERT_EQ(animals[1] + animals[2], animals[0]);
    ASSERT_EQ(animals[4] + animals[5], animals[3]);
    ASSERT_EQ(animals[0] + animals[3], 10);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}