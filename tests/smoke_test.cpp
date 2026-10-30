#include <catch2/catch_test_macros.hpp>

#include <shmbus/version.hpp>

TEST_CASE("library headers are reachable", "[smoke]") {
  REQUIRE(shmbus::kVersionMajor == 0);
}
