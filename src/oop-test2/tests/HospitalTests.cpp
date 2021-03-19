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

TEST(Hospital, itShouldCreateRooms) {
    Hospital* hospital = createHospital();
    string stdout = testing::internal::GetCapturedStdout();
    ASSERT_EQ(stdout, "How many rooms do you start hospital?");
    ASSERT_EQ(hospital->getSize(),5);
}

TEST(Room, itShouldCreateBeds) {
    Room room;
    ASSERT_TRUE(regex_match (room.toString(), regex("[123] bed(s)?") ));
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}