#ifndef EXPRESSO_EXPRESSION_H
#define EXPRESSO_EXPRESSION_H


namespace expresso
{
    struct terminal
    { };

    template <typename Left, typename OpTag, typename Right>
    struct non_terminal
    { };
} // namespace expresso


#endif // EXPRESSO_EXPRESSION_H
