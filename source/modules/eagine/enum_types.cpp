/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
/// https://www.boost.org/LICENSE_1_0.txt
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
/// @brief Typed enumeration for ImGui mouse button constants.
/// @ingroup imgui_api_wrap
export struct imgui_mouse_button_flag
  : imgui_int_class<imgui_mouse_button_flag, "MouseButtn"> {
    using enum_class::enum_class;
};
//------------------------------------------------------------------------------
/// @brief Typed enumeration for ImGui config flags constants.
/// @ingroup imgui_api_wrap
export struct imgui_config_flag
  : imgui_int_class<imgui_config_flag, "ConfigFlag"> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for ImGui window flags constants.
/// @ingroup imgui_api_wrap
export struct imgui_window_flag
  : imgui_int_class<imgui_window_flag, "WindowFlag"> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for ImGui hovered flags constants.
/// @ingroup imgui_api_wrap
export struct imgui_hovered_flag
  : imgui_int_class<imgui_hovered_flag, "HoverdFlag"> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for ImGui focused flags constants.
/// @ingroup imgui_api_wrap
export struct imgui_focused_flag
  : imgui_int_class<imgui_focused_flag, "FocusdFlag"> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for ImGui selectable flags constants.
/// @ingroup imgui_api_wrap
export struct imgui_selectable_flag
  : imgui_int_class<imgui_selectable_flag, "SlctblFlag"> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for ImGui viewport flags constants.
/// @ingroup imgui_api_wrap
export struct imgui_viewport_flag
  : imgui_int_class<imgui_viewport_flag, "VwportFlag"> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for ImGui slider flags constants.
/// @ingroup imgui_api_wrap
export struct imgui_slider_flag
  : imgui_int_class<imgui_slider_flag, "SliderFlag"> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for ImGui combo flags constants.
/// @ingroup imgui_api_wrap
export struct imgui_combo_flag
  : imgui_int_class<imgui_combo_flag, "ComboFlag"> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for ImGui color_edit flags constants.
/// @ingroup imgui_api_wrap
export struct imgui_color_edit_flag
  : imgui_int_class<imgui_color_edit_flag, "ClrEdtFlag"> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for ImGui condition constants.
/// @ingroup imgui_api_wrap
export struct imgui_cond : imgui_int_class<imgui_cond, "Condition"> {
    using enum_class::enum_class;
};
//------------------------------------------------------------------------------
} // namespace eagine::guiplus
