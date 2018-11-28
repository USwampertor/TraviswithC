#include <cstdio>
#include <gtest/gtest.h>
#include <iostream>
using namespace std;

struct Fixture : public ::testing::Test {
  virtual void SetUp() {
    fails = 0;
  }

  virtual void TearDown() {
    if (fails > 0) {
      std::cerr << "Fixture::TearDown sees failures" << std::endl;
    }
  }

  unsigned fails;
};


int main(int argc, char **argv) {

  printf("Hello from Travis C output \n");
  ::testing::InitGoogleTest(&argc,argv);
  RUN_ALL_TESTS();
  std::cout << fails;
}

TEST_F(Fixture, bar) {
    EXPECT_EQ(1,1);
    fails += ::testing::Test::HasFailure();
}