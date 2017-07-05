#ifndef EXPRESSO_BINARY_OP_H
#define EXPRESSO_BINARY_OP_H


#include <type_traits>

#include "expresso/expression.h"


namespace expresso
{
    struct equal_to_t
    { };

    template <typename Lhs>
    auto operator == (Lhs && lhs, terminal const& rhs)
    {
        return non_terminal<
                    std::decay_t<Lhs>,
                    equal_to_t,
                    terminal
               >{};
    }

    template <typename Rhs>
    auto operator == (terminal const& lhs, Rhs && rhs)
    {
        return non_terminal<
                    terminal,
                    equal_to_t,
                    std::decay_t<Rhs>
               >{};
    }

    auto operator == (terminal const& lhs, terminal const& rhs)
    {
        return non_terminal<
                    terminal,
                    equal_to_t,
                    terminal
               >{};
    }

    template
    <
        typename Lhs,
        typename Left, typename OpTag, typename Right
    >
    auto operator == (Lhs && lhs,
                      non_terminal<Left, OpTag, Right> && rhs)
    {
        using lhs_t = std::decay_t<Lhs>;
        using rhs_t = std::decay_t<non_terminal<Left, OpTag, Right>>;
        return non_terminal<lhs_t, equal_to_t, rhs_t>{};
    }

    template
    <
        typename Left, typename OpTag, typename Right,
        typename Rhs
    >
    auto operator == (non_terminal<Left, OpTag, Right> && lhs,
                      Rhs && rhs)
    {
        using lhs_t = std::decay_t<non_terminal<Left, OpTag, Right>>;
        using rhs_t = std::decay_t<Rhs>;
        return non_terminal<lhs_t, equal_to_t, rhs_t>{};
    }

    template
    <
        typename Left1, typename OpTag1, typename Right1,
        typename Left2, typename OpTag2, typename Right2
    >
    auto operator == (non_terminal<Left1, OpTag1, Right1> const& lhs,
                      non_terminal<Left2, OpTag2, Right2> const& rhs)
    {
        using lhs_t = non_terminal<Left1, OpTag1, Right1>;
        using rhs_t = non_terminal<Left2, OpTag2, Right2>;
        return non_terminal<lhs_t, equal_to_t, rhs_t>{};
    }
} // namespace expresso


#endif // EXPRESSO_BINARY_OP_H
