#include "Ecosystem.h"
#include "../../shared/Test/StdoutMock.h"
#include <gtest/gtest.h>

TEST(EcosystemTest, InitState) {
    StdoutMock stdoutMock;
    Ecosystem ecosystem;
    ecosystem.feedback();
    stdoutMock.assert_eq({
        "6 carnivores, 4 females, and 2 males.\n",
        "4 herbivorous, 2 females, and 2 males.\n"
    });
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}