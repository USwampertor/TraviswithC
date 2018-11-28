#include <cstdio>
#include <gtest/gtest.h>
using namespace std;
int main(int argc, char **argv) {
  printf("Hello from Travis C output \n");
  ::testing::InitGoogleTest(&argc,argv);
  ::testing::GTEST_FLAG(filter) = "Basic_Test*";
  return RUN_ALL_TESTS();
}

TEST(Math, Basic_Test) {
  EXPECT_TRUE(1 == 1);
}