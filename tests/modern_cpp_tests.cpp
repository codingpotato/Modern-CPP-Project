#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "variant"

template <class... Ts>
struct overload : Ts... {
  using Ts::operator()...;
};
template <class... Ts>
overload(Ts...)->overload<Ts...>;

TEST_CASE("variant get", "[variant]") {
  std::variant<int, std::string> n{1};
  REQUIRE(std::get<int>(n) == 1);
}

TEST_CASE("variant visit", "[variant]") {
  std::variant<int, std::string> n{100};
  std::visit(overload{[](int value) { REQUIRE(value == 100); },
                      [](const std::string &) { REQUIRE(false); }},
             n);
  std::variant<int, std::string> str{"string"};
  std::visit(
      overload{[](int) { REQUIRE(false); },
               [](const std::string &value) { REQUIRE(value == "string"); }},
      n);
}
