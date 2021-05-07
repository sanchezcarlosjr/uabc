#include "Ecosystem.h"
#include "../../shared/Test/StdoutMock.h"
#include "../../shared/DataStructure/Utils/ToString.h"
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

TEST(AnimalTest, itShouldBeStartInZero) {
    for (auto animal : Animal::byZone(CARNIVORE, FEMALE)) {
        ASSERT_EQ(animal, 0);
    }
    for (auto animal : Animal::byZone(CARNIVORE, MALE)) {
        ASSERT_EQ(animal, 0);
    }
    for (auto animal : Animal::byZone(HERBIVORE, FEMALE)) {
        ASSERT_EQ(animal, 0);
    }
    for (auto animal : Animal::byZone(HERBIVORE, MALE)) {
        ASSERT_EQ(animal, 0);
    }
}

TEST(AnimalTest, itShouldMoveWhenItStarts) {
    auto *carnivore = new Carnivore();
    ASSERT_TRUE(carnivore->getZone() >= 0 && carnivore->getZone() <= 3);
    ASSERT_EQ(Animal::byZone(CARNIVORE, carnivore->getSex())[carnivore->getZone()], 1);
    string actual = toString<int>(Animal::byZone(CARNIVORE, carnivore->getSex()));
    ASSERT_TRUE(regex_match(actual, regex("\\d \\d \\d \\d")));
    auto *herbivore = new Herbivore();
    ASSERT_EQ(Animal::byZone(HERBIVORE, herbivore->getSex())[herbivore->getZone()], 1);
    ASSERT_TRUE(herbivore->getZone() >= 0 && herbivore->getZone() <= 3);
    delete carnivore;
    delete herbivore;
}


TEST(AnimalTest, itShouldMoveAndChangeTotalByZone) {
    auto* carnivore = new Carnivore();
    int zone1 = carnivore->getZone();
    carnivore->move();
    ASSERT_TRUE(Animal::byZone(CARNIVORE, carnivore->getSex())[zone1] == 0 || zone1 == carnivore->getZone() );
    ASSERT_EQ(Animal::byZone(CARNIVORE, carnivore->getSex())[carnivore->getZone()], 1);
    delete carnivore;
}


//class MockObserver: public AnimalObserver {
//public:
//    void dieAnimal() override {
//    }
//    void bornAnimal(Animal *animal) override {}
//};
//
//TEST(AnimalTest, itShouldUpdateZone) {
//    auto* carnivore = new Carnivore();
//    int zone1 = carnivore->getZone();
//    carnivore->update(new MockObserver());
//    ASSERT_EQ(Animal::byZone(CARNIVORE, carnivore->getSex())[zone1], 0);
//    ASSERT_EQ(Animal::byZone(CARNIVORE, carnivore->getSex())[carnivore->getZone()], 1);
//}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}