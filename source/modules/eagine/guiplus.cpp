/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
export module eagine.guiplus;

export import :config;
export import :enum_types;
export import :objects;
export import :constants;
export import :from_string;
export import :result;
export import :api_traits;
export import :c_api;
export import :api;

namespace eagine::guiplus {
//------------------------------------------------------------------------------
export template <typename ImGuiApiTraits>
class basic_gui_utils {
public:
    basic_imgui_api<ImGuiApiTraits> imgui;
};
//------------------------------------------------------------------------------
export using gui_utils = basic_gui_utils<imgui_api_traits>;
//------------------------------------------------------------------------------
} // namespace eagine::guiplus

