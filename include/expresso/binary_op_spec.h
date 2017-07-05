#define n BOOST_PP_ITERATION()


//==============================================================================
    struct BIN_OP_NAME(n)
    { };


//==============================================================================
    template
    <
        typename Lhs,
        typename = std::enable_if_t<
                        !is_non_terminal_v<Lhs>
                            || (is_non_terminal_v<Lhs>
                                    && std::is_lvalue_reference<Lhs>::value)
                   >
    >
    auto operator BIN_OP_SYM(n) (Lhs && lhs, terminal const& rhs)
    {
        return non_terminal<
                    std::decay_t<Lhs>,
                    BIN_OP_NAME(n),
                    terminal
               >{};
    }

    template
    <
        typename Rhs,
        typename = std::enable_if_t<
                        !is_non_terminal_v<Rhs>
                            || (is_non_terminal_v<Rhs>
                                    && std::is_lvalue_reference<Rhs>::value)
                   >
    >
    auto operator BIN_OP_SYM(n) (terminal const& lhs, Rhs && rhs)
    {
        return non_terminal<
                    terminal,
                    BIN_OP_NAME(n),
                    std::decay_t<Rhs>
               >{};
    }

    auto operator BIN_OP_SYM(n) (terminal const& lhs, terminal const& rhs)
    {
        return non_terminal<
                    terminal,
                    BIN_OP_NAME(n),
                    terminal
               >{};
    }

    template
    <
        typename Lhs,
        typename Left, typename OpTag, typename Right,
        typename = std::enable_if_t<!is_non_terminal_v<Lhs>>
    >
    auto operator BIN_OP_SYM(n) (Lhs && lhs,
                                 non_terminal<Left, OpTag, Right> && rhs)
    {
        using lhs_t = std::decay_t<Lhs>;
        using rhs_t = std::decay_t<non_terminal<Left, OpTag, Right>>;
        return non_terminal<lhs_t, BIN_OP_NAME(n), rhs_t>{};
    }

    template
    <
        typename Left, typename OpTag, typename Right,
        typename Rhs,
        typename = std::enable_if_t<!is_non_terminal_v<Rhs>>
    >
    auto operator BIN_OP_SYM(n) (non_terminal<Left, OpTag, Right> && lhs,
                                 Rhs && rhs)
    {
        using lhs_t = std::decay_t<non_terminal<Left, OpTag, Right>>;
        using rhs_t = std::decay_t<Rhs>;
        return non_terminal<lhs_t, BIN_OP_NAME(n), rhs_t>{};
    }

    template
    <
        typename Left1, typename OpTag1, typename Right1,
        typename Left2, typename OpTag2, typename Right2
    >
    auto operator BIN_OP_SYM(n) (non_terminal<Left1, OpTag1, Right1> const& lhs,
                                 non_terminal<Left2, OpTag2, Right2> const& rhs)
    {
        using lhs_t = non_terminal<Left1, OpTag1, Right1>;
        using rhs_t = non_terminal<Left2, OpTag2, Right2>;
        return non_terminal<lhs_t, BIN_OP_NAME(n), rhs_t>{};
    }


//==============================================================================
#undef n
