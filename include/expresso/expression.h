#ifndef EXPRESSO_EXPRESSION_H
#define EXPRESSO_EXPRESSION_H


#include <type_traits>


namespace expresso
{
    struct terminal
    { };

    template <typename Left, typename OpTag, typename Right>
    struct non_terminal
    { };


    template <typename T>
    struct is_terminal
            : std::conditional_t<
                    std::is_same<std::decay_t<T>, terminal>::value,
                    std::true_type,
                    std::false_type
              >
    { };

    template <typename T>
    inline constexpr auto is_terminal_v = is_terminal<T>::value;


    namespace detail
    {
        template <typename T>
        struct is_non_terminal_impl : std::false_type
        { };

        template <typename Left, typename OpTag, typename Right>
        struct is_non_terminal_impl<non_terminal<Left, OpTag, Right>>
                    : std::true_type
        { };
    } // namespace detail

    template <typename T>
    struct is_non_terminal : detail::is_non_terminal_impl<std::decay_t<T>>
    { };

    template <typename T>
    inline constexpr auto is_non_terminal_v = is_non_terminal<T>::value;
} // namespace expresso


#endif // EXPRESSO_EXPRESSION_H
