#include "catch.hpp"

#include <type_traits>

#include "expresso/expresso.h"
using namespace expresso;


TEST_CASE("equal_to expressions", "[expresso]")
{
    auto expr0 = 1 == 1;
    static_assert(std::is_same<bool, decltype(expr0)>());

    auto expr1 = _1 == 1;
    auto expr2 = 1 == _1;
    auto expr3 = _1 == _1;

    auto expr4 = _1 == 1 == 2;
    auto expr5 = 1 == (_1 == 2);

    auto expr6 = expr4 == expr5;
}

