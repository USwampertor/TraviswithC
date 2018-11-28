#include <cstdio>
#include <gtest/gtest.h>
using namespace std;
int main(int argc, char **argv) {
  printf("Hello from Travis C output \n");
  ::testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}

TEST(Math, Basic_Test) {
  EXPECT_TRUE(1 == 1);
  printf(::testing::Test::HasFailure());
}