#include "catch.hpp"

#include <type_traits>

#include "expresso/expresso.h"
using namespace expresso;


TEST_CASE("equal_to expressions", "[expresso]")
{
    static_assert(is_terminal_v<decltype(_1)>);

    auto expr0 = 1 == 1;
    static_assert(std::is_same<bool, decltype(expr0)>());

    auto expr1 = _1 == 1;
    auto expr2 = 1 == _1;
    auto expr3 = _1 == _1;
    static_assert(is_non_terminal_v<decltype(expr1)>);
    static_assert(is_non_terminal_v<decltype(expr2)>);
    static_assert(is_non_terminal_v<decltype(expr3)>);

    auto expr4 = _1 == 1 == 2;
    auto expr5 = 1 == (_1 == 2);
    static_assert(is_non_terminal_v<decltype(expr4)>);
    static_assert(is_non_terminal_v<decltype(expr5)>);

    // both sides are lvalue non_terminal.
    auto expr6 = expr4 == expr5;
    static_assert(is_non_terminal_v<decltype(expr6)>);

    auto const expr7 = expr6 == _1;
    static_assert(is_non_terminal_v<decltype(expr7)>);
}

TEST_CASE("complex expressions", "[expresso]")
{
    //auto expr0 = _1 + 1 && _2;

    // both sides are rvalue non_terminal.
    //auto expr1 = _1 + 1 && _2 - 2;
}
