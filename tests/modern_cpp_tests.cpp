#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "variant"

TEST_CASE("variant", "[variant]") {
  std::variant<int, std::string> n{1};
  REQUIRE(std::get<int>(n) == 1);
}