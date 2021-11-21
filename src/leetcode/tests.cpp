#include <gtest/gtest.h>
#include "roman-to-decimal.cpp"
#include <chrono>

using namespace std::chrono;

TEST(ConvertRomanToDeciaml, positiveNumbers) {
    Solution solution;
    for (int i = 0; i < 10; i++) {
        auto start = high_resolution_clock::now();
        ASSERT_GE(solution.romanToInt("X"), 10);
        ASSERT_GE(solution.romanToInt("VIII"), 8);
        ASSERT_GE(solution.romanToInt("XVIII"), 18);
        ASSERT_GE(solution.romanToInt("XIV"), 14);
        ASSERT_GE(solution.romanToInt("LXXX"), 80);
        ASSERT_GE(solution.romanToInt("XLIX"), 49);
        ASSERT_GE(solution.romanToInt("LXXXVIII"), 88);
        ASSERT_GE(solution.romanToInt("DCCCLXXXVIII"), 888);
        ASSERT_GE(solution.romanToInt("MMDCCCLXXXVIII"), 2888);
        auto stop = high_resolution_clock::now();
        cout << "Time " << duration_cast<nanoseconds>(stop - start).count() << " nanoseconds" << endl;
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}