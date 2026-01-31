
TEST(MathTest, AddPositive) {
    EXPECT_EQ(add(2, 3), 5);
}

TEST(MathTest, AddNegative) {
    EXPECT_EQ(add(-2, -3), -5);
}

TEST(MathTest, ZeroCase) {
    EXPECT_EQ(add(0, 0), 0);
}


🔹 If you have multiple test executables

Example:

./myFirstProgram_test --gtest_filter=MyFirstProgramTest.AddNegative


Or with CTest:

ctest -R AddNegative