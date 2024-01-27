#include <gtest/gtest.h>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  argv[100] = 10;

  return RUN_ALL_TESTS();
}