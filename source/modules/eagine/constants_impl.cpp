/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
module;

#if __has_include(<imgui.h>)
#include <imgui.h>
#define EAGINE_HAS_IMGUI 1
#else
#define EAGINE_HAS_IMGUI 0
#endif

module eagine.guiplus;
import std;
import eagine.core.types;
import eagine.core.memory;
import eagine.core.container;
import eagine.core.valid_if;

namespace eagine {
//------------------------------------------------------------------------------
auto within_limits<guiplus::imgui_window_flag, guiplus::imgui_types::enum_type>::
  check(guiplus::imgui_types::enum_type x) const noexcept -> bool {
    switch(x) {
#if EAGINE_HAS_IMGUI
        case ImGuiWindowFlags_NoTitleBar:
        case ImGuiWindowFlags_NoResize:
        case ImGuiWindowFlags_NoMove:
        case ImGuiWindowFlags_NoScrollbar:
        case ImGuiWindowFlags_NoScrollWithMouse:
        case ImGuiWindowFlags_NoCollapse:
        case ImGuiWindowFlags_AlwaysAutoResize:
        case ImGuiWindowFlags_NoBackground:
        case ImGuiWindowFlags_NoSavedSettings:
        case ImGuiWindowFlags_NoMouseInputs:
        case ImGuiWindowFlags_MenuBar:
        case ImGuiWindowFlags_HorizontalScrollbar:
        case ImGuiWindowFlags_NoFocusOnAppearing:
        case ImGuiWindowFlags_NoBringToFrontOnFocus:
        case ImGuiWindowFlags_AlwaysVerticalScrollbar:
        case ImGuiWindowFlags_AlwaysHorizontalScrollbar:
        case ImGuiWindowFlags_AlwaysUseWindowPadding:
        case ImGuiWindowFlags_NoNavInputs:
        case ImGuiWindowFlags_NoNavFocus:
        case ImGuiWindowFlags_UnsavedDocument:
        case ImGuiWindowFlags_NoNav:
        case ImGuiWindowFlags_NoDecoration:
        case ImGuiWindowFlags_NoInputs:
            return true;
#endif
        default:
            return false;
    }
}
//------------------------------------------------------------------------------
auto within_limits<guiplus::imgui_slider_flag, guiplus::imgui_types::enum_type>::
  check(guiplus::imgui_types::enum_type x) const noexcept -> bool {
    switch(x) {
#if EAGINE_HAS_IMGUI
        case ImGuiSliderFlags_AlwaysClamp:
        case ImGuiSliderFlags_Logarithmic:
        case ImGuiSliderFlags_NoRoundToFormat:
        case ImGuiSliderFlags_NoInput:
            return true;
#endif
        default:
            return false;
    }
}
//------------------------------------------------------------------------------
auto within_limits<
  guiplus::imgui_viewport_flag,
  guiplus::imgui_types::enum_type>::check(guiplus::imgui_types::enum_type x)
  const noexcept -> bool {
    switch(x) {
#if EAGINE_HAS_IMGUI
        case ImGuiViewportFlags_IsPlatformWindow:
        case ImGuiViewportFlags_IsPlatformMonitor:
        case ImGuiViewportFlags_OwnedByApp:
            return true;
#endif
        default:
            return false;
    }
}
//------------------------------------------------------------------------------
namespace guiplus {
//------------------------------------------------------------------------------
auto map_imgui_enum_by_name() noexcept {
    return basic_lc_identifier_trie<imgui_types::enum_type>()
#if EAGINE_HAS_IMGUI
      .add("window_no_title_bar", ImGuiWindowFlags_NoTitleBar)
      .add("window_no_resize", ImGuiWindowFlags_NoResize)
      .add("window_no_move", ImGuiWindowFlags_NoMove)
      .add("window_no_scrollbar", ImGuiWindowFlags_NoScrollbar)
      .add("window_no_scroll_with_mouse", ImGuiWindowFlags_NoScrollWithMouse)
      .add("window_no_collapse", ImGuiWindowFlags_NoCollapse)
      .add("window_always_auto_resize", ImGuiWindowFlags_AlwaysAutoResize)
      .add("window_no_background", ImGuiWindowFlags_NoBackground)
      .add("window_no_saved_settings", ImGuiWindowFlags_NoSavedSettings)
      .add("window_no_mouse_inputs", ImGuiWindowFlags_NoMouseInputs)
      .add("window_menu_bar", ImGuiWindowFlags_MenuBar)
      .add("window_horizontal_scrollbar", ImGuiWindowFlags_HorizontalScrollbar)
      .add("window_no_focus_on_appearing", ImGuiWindowFlags_NoFocusOnAppearing)
      .add(
        "window_no_bring_to_front_on_focus",
        ImGuiWindowFlags_NoBringToFrontOnFocus)
      .add(
        "window_always_vertical_scrollbar",
        ImGuiWindowFlags_AlwaysVerticalScrollbar)
      .add(
        "window_always_horizontal_scrollbar",
        ImGuiWindowFlags_AlwaysHorizontalScrollbar)
      .add(
        "window_always_use_window_padding",
        ImGuiWindowFlags_AlwaysUseWindowPadding)
      .add("window_no_nav_inputs", ImGuiWindowFlags_NoNavInputs)
      .add("window_no_nav_focus", ImGuiWindowFlags_NoNavFocus)
      .add("window_unsaved_document", ImGuiWindowFlags_UnsavedDocument)
      .add("window_no_nav", ImGuiWindowFlags_NoNav)
      .add("window_no_decoration", ImGuiWindowFlags_NoDecoration)
      .add("window_no_inputs", ImGuiWindowFlags_NoInputs)
      .add("slider_always_clamp", ImGuiSliderFlags_AlwaysClamp)
      .add("slider_logarithmic", ImGuiSliderFlags_Logarithmic)
      .add("slider_no_round_to_format", ImGuiSliderFlags_NoRoundToFormat)
      .add("slider_no_input", ImGuiSliderFlags_NoInput)
      .add("viewport_is_platform_window", ImGuiViewportFlags_IsPlatformWindow)
      .add("viewport_is_platform_monitor", ImGuiViewportFlags_IsPlatformMonitor)
      .add("viewport_owned_by_app", ImGuiViewportFlags_OwnedByApp)
#endif
      ;
}
//------------------------------------------------------------------------------
auto imgui_enum_by_name(const string_view name) noexcept
  -> optionally_valid<imgui_types::enum_type> {
    if(not name.empty()) [[likely]] {
        static const auto enums{map_imgui_enum_by_name()};
        if(auto found{enums.find(name)}) [[likely]] {
            return {*found, true};
        }
    }
    return {};
}
//------------------------------------------------------------------------------
} // namespace guiplus
} // namespace eagine

