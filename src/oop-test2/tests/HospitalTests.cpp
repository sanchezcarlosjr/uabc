#include <gtest/gtest.h>
#include "../src/Hospital.h"
#include "../src/Room.h"
#include <regex>

Hospital* createHospital(int size=5) {
    Hospital* hospital;
    testing::internal::CaptureStdout();
    istringstream input(to_string(size));
    cin.rdbuf(input.rdbuf());
    hospital = new Hospital();
    return hospital;
}

vector<string> matches(string s, string regularExpression) {
    vector<string> vector;
    smatch m;
    regex e (regularExpression);
    while (std::regex_search (s,m,e)) {
        for (auto x:m) vector.push_back(x);
        s = m.suffix().str();
    }
    return vector;
}

vector<string> getCapturedStdout() {
    string actual = testing::internal::GetCapturedStdout();
    return matches(actual, ".*\n");
}

TEST(Hospital, itShouldCreateRooms) {
    Hospital* hospital = createHospital(3);
    string stdout = testing::internal::GetCapturedStdout();
    vector<string> vector = matches(stdout, ".*\n");
    ASSERT_EQ(vector[0], "How many rooms do you start hospital?\n");
    ASSERT_EQ(vector[1], "His hospital shows next distribution:\n");
    ASSERT_TRUE(regex_match (vector[2], regex("Room \\[\\d\\].*\n")));
    ASSERT_TRUE(regex_match (vector[3], regex("Room \\[\\d\\].*\n")));
    ASSERT_TRUE(regex_match (vector[4], regex("Room \\[\\d\\].*\n")));
    ASSERT_TRUE(regex_match (vector[5], regex("Available beds: \\d\n")));
    ASSERT_EQ(vector.back(), "Press any key to continue...\n");
    ASSERT_EQ(hospital->getSize(),3);
}

TEST(Room, itShouldCreateBeds) {
    Room room;
    string message = room.toString();
    vector<string> vector = matches(message, "[123]");
    string expected = "[123] bed(s)?:";
    expected += "( Available){"+vector[0]+"}";
    ASSERT_TRUE(regex_match (message, regex(expected)));
}

TEST(Hospital, itShouldSimulate) {
    Hospital* hospital = createHospital();
    getCapturedStdout();
    testing::internal::CaptureStdout();
    hospital->simulate();
    string actual = testing::internal::GetCapturedStdout();
    vector<string> vector = matches(actual, ".*\n");
    ASSERT_EQ(vector[0], "Day\tIncome\t Outcome\tAvailable\n");
    ASSERT_EQ(vector.back(), "Press any key to continue...\n");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}