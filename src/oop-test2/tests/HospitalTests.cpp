#include <gtest/gtest.h>
#include "../src/Hospital.h"
#include "../src/Room.h"
#include <regex>

Hospital* createHospital(string str="5") {
    Hospital* hospital;
    testing::internal::CaptureStdout();
    istringstream input(str);
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


TEST(Hospital, itShouldCreateRooms) {
    Hospital* hospital = createHospital();
    string stdout = testing::internal::GetCapturedStdout();
    ASSERT_EQ(stdout, "How many rooms do you start hospital?");
    ASSERT_EQ(hospital->getSize(),5);
}

TEST(Room, itShouldCreateBeds) {
    Room room;
    string message = room.toString();
    vector<string> vector = matches(message, "[123]");
    string expected = "[123] bed(s)?:";
    expected += "( Available){"+vector[0]+"}";
    ASSERT_TRUE(regex_match (message, regex(expected)));
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}