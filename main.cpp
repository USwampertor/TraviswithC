#include <cstdio>
#include <gtest/gtest.h>
#include <iostream>
using namespace std;

struct FAILURE_CHECKER {
  virtual void SetUp() {
    m_fails = 0;
  }

  virtual void TearDown() {
    if (m_fails > 0) {
      std::cerr << "Fixture::TearDown sees failures" << std::endl;
    }
  }

  int m_fails = 0;
};


int main(int argc, char **argv) {

  printf("Hello from Travis C output \n");
  ::testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}

TEST_F(FAILURE_CHECKER, Basic_Test) {
  EXPECT_TRUE(1 == 1);
  m_fails += ::testing::Test::HasFailure();
}