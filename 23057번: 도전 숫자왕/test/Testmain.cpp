#include "gtest/gtest.h"
#include "../cpp/src/main.h"

#include <vector>
using namespace std;

TEST(CountMissingTest, SampleTest1) {
    vector<int> cards = {1, 2, 3};
    EXPECT_EQ(countMissing(cards), 0);
}

TEST(CountMissingTest, SampleTest2) {
    vector<int> cards = {1, 3, 4};
    EXPECT_EQ(countMissing(cards), 2);
}

TEST(CountMissingTest, SingleCardTest) {
    vector<int> cards = {5};
    EXPECT_EQ(countMissing(cards), 4);
}

TEST(CountMissingTest, DuplicateCardTest) {
    vector<int> cards = {2, 2};
    EXPECT_EQ(countMissing(cards), 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
