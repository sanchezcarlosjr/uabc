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


TEST(Hospital, itShouldCreateRooms) {
    Hospital* hospital = createHospital(1);
    string stdout = testing::internal::GetCapturedStdout();
    string expected= "How many rooms do you start hospital?\n"
                     "His hospital shows next distribution:\n"
                     "Room [1]: 2 beds Available\n"
                     "Available beds: 1";
    ASSERT_EQ(stdout, expected);
    ASSERT_EQ(hospital->getSize(),1);
}

TEST(Room, itShouldCreateBeds) {
    Room room;
    string message = room.toString();
    vector<string> vector = matches(message, "[123]");
    string expected = "[123] bed(s)?:";
    expected += "( Available){"+vector[0]+"}";
    ASSERT_TRUE(regex_match (message, regex(expected)));
    ASSERT_EQ(room.getAvailableBeds(), stoi(vector[0]));
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}