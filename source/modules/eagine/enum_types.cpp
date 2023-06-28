/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
export module eagine.guiplus:enum_types;
import eagine.core.types;
import eagine.core.identifier;
import eagine.core.c_api;
import :config;

namespace eagine::guiplus {
//------------------------------------------------------------------------------
/// @brief Typed wrapper class for ImGui enum constants/values.
/// @ingroup imgui_api_wrap
///
/// This wrapper uses the specified Id to group various ImGui  constants logically
/// belonging together and prevents accidental mismatches and use of ImGui constants
/// from unrelated groups. For example using a config attribute constant in place
/// of context attribute constants. Such mismatches result in compilation errors.
export template <typename Self, identifier_value Id>
using imgui_int_class = c_api::enum_class<Self, int, "ImGui", Id>;
//------------------------------------------------------------------------------
/// @brief Typed enumeration for ImGui window flags constants.
/// @ingroup imgui_api_wrap
export struct window_flag : imgui_int_class<window_flag, "WindowFlag"> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for ImGui hovered flags constants.
/// @ingroup imgui_api_wrap
export struct hovered_flag : imgui_int_class<hovered_flag, "HoverdFlag"> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for ImGui focused flags constants.
/// @ingroup imgui_api_wrap
export struct focused_flag : imgui_int_class<focused_flag, "FocusdFlag"> {
    using enum_class::enum_class;
};
//------------------------------------------------------------------------------
} // namespace eagine::guiplus
