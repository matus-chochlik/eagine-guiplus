/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
/// https://www.boost.org/LICENSE_1_0.txt
///
export module eagine.guiplus:api_traits;

import std;
import eagine.core.memory;
import eagine.core.c_api;
import :result;

namespace eagine::guiplus {
//------------------------------------------------------------------------------
export class imgui_api_traits : public c_api::default_traits {
public:
    template <typename R>
    using no_result = imgui_no_result<R>;
    template <typename R>
    using result = imgui_result<R>;
    template <typename R>
    using opt_result = imgui_opt_result<R>;

    template <typename Result>
    using combined_result = c_api::combined_result<Result, imgui_result_info>;

    template <typename Api, typename Tag, typename Signature>
    auto link_function(
      Api&,
      const Tag,
      const string_view name,
      const std::type_identity<Signature>) -> std::add_pointer_t<Signature> {
        return reinterpret_cast<std::add_pointer_t<Signature>>(
          _link_function(name));
    }

private:
    using _any_fnptr_t = void (*)();

    auto _link_function(const string_view) -> _any_fnptr_t;
};
//------------------------------------------------------------------------------
} // namespace eagine::guiplus

