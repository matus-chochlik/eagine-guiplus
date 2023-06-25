/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
export module eagine.guiplus:constants;

import :c_api;

namespace eagine::guiplus {
//------------------------------------------------------------------------------
export template <typename ApiTraits>
struct basic_imgui_constants {
public:
    basic_imgui_constants(ApiTraits&, basic_imgui_c_api<ApiTraits>&) {}
};
//------------------------------------------------------------------------------
} // namespace eagine::guiplus
