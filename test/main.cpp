#include <gtest/gtest.h>

TEST(Dummy, AlwaysPasses) {
  ASSERT_TRUE(true);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

extern "C" {
void __ubsan_on_report() {
  FAIL() << "Encountered an undefined behavior sanitizer error";
}
void __asan_on_error() {
  FAIL() << "Encountered an address sanitizer error";
}
void __tsan_on_report() {
  FAIL() << "Encountered a thread sanitizer error";
}
}  // extern "C"