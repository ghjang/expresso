#ifndef EXPRESSO_PLACE_HOLDER_DEF_H
#define EXPRESSO_PLACE_HOLDER_DEF_H


#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/iteration/local.hpp>

#include "expresso/expression.h"


#ifndef PLACE_HOLDER_MAX_SIZE
#   define PLACE_HOLDER_MAX_SIZE 8
#endif // PLACE_HOLDER_MAX_SIZE

#define ET_place_holder(z, n, unused) \
            inline constexpr struct terminal BOOST_PP_CAT(_, n){};


namespace expresso
{
#   define BOOST_PP_LOCAL_MACRO(n)     ET_place_holder(~, n, ~)
#   define BOOST_PP_LOCAL_LIMITS       (1, PLACE_HOLDER_MAX_SIZE)
#   include BOOST_PP_LOCAL_ITERATE()
} // namespace expresso


#undef BOOST_PP_LOCAL_LIMITS
#undef BOOST_PP_LOCAL_MACRO
#undef ET_place_holder


#endif // EXPRESSO_PLACE_HOLDER_DEF_H
