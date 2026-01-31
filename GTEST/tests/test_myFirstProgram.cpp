#include <gtest/gtest.h>
#include "myFirstProgram.h"

TEST(MY_PROGRAM, Saket1) {
    EXPECT_EQ(1, 1);
}

TEST(MY_PROGRAM, Saket2 ) {
    EXPECT_EQ(1, 1);
}

TEST(MY_PROGRAM, subtest1)
{
    ASSERT_TRUE(1 == 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
