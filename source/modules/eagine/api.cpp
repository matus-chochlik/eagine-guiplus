/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
export module eagine.guiplus:api;

import std;
import eagine.core.types;
import eagine.core.memory;
import eagine.core.utility;
import eagine.core.c_api;
import :config;
import :api_traits;
import :result;
import :constants;
import :c_api;

namespace eagine::guiplus {
//------------------------------------------------------------------------------
export template <typename ApiTraits>
class basic_imgui_operations : public basic_imgui_c_api<ApiTraits> {

public:
    using api_traits = ApiTraits;
    using imgui_api = basic_imgui_c_api<ApiTraits>;

    basic_imgui_operations(api_traits& traits)
      : imgui_api{traits} {}
};
//------------------------------------------------------------------------------
export template <typename ApiTraits>
class basic_imgui_api
  : protected ApiTraits
  , public basic_imgui_operations<ApiTraits>
  , public basic_imgui_constants<ApiTraits> {
public:
    template <typename R>
    using combined_result = typename ApiTraits::template combined_result<R>;

    basic_imgui_api(ApiTraits traits)
      : ApiTraits{std::move(traits)}
      , basic_imgui_operations<ApiTraits>{*static_cast<ApiTraits*>(this)}
      , basic_imgui_constants<ApiTraits> {
        *static_cast<ApiTraits*>(this),
          *static_cast<basic_imgui_operations<ApiTraits>*>(this)
    }
    {}

    basic_imgui_api()
      : basic_imgui_api{ApiTraits{}} {}
};
//------------------------------------------------------------------------------
export template <std::size_t I, typename ApiTraits>
auto get(basic_imgui_api<ApiTraits>& x) noexcept ->
  typename std::tuple_element<I, basic_imgui_api<ApiTraits>>::type& {
    return x;
}

export template <std::size_t I, typename ApiTraits>
auto get(const basic_imgui_api<ApiTraits>& x) noexcept -> const
  typename std::tuple_element<I, basic_imgui_api<ApiTraits>>::type& {
    return x;
}
//------------------------------------------------------------------------------
export using imgui_api = basic_imgui_api<imgui_api_traits>;
} // namespace eagine::guiplus
// NOLINTNEXTLINE(cert-dcl58-cpp)
namespace std {
//------------------------------------------------------------------------------
export template <typename ApiTraits>
struct tuple_size<eagine::guiplus::basic_imgui_api<ApiTraits>>
  : public std::integral_constant<std::size_t, 2> {};

export template <typename ApiTraits>
struct tuple_element<0, eagine::guiplus::basic_imgui_api<ApiTraits>> {
    using type = eagine::guiplus::basic_imgui_operations<ApiTraits>;
};

export template <typename ApiTraits>
struct tuple_element<1, eagine::guiplus::basic_imgui_api<ApiTraits>> {
    using type = eagine::guiplus::basic_imgui_constants<ApiTraits>;
};
//------------------------------------------------------------------------------
} // namespace std

