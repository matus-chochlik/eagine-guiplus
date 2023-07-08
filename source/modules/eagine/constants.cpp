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

export module eagine.guiplus:constants;
import std;
import eagine.core.types;
import eagine.core.memory;
import eagine.core.valid_if;
import eagine.core.c_api;
import :config;
import :enum_types;
import :c_api;

namespace eagine {
//------------------------------------------------------------------------------
export template <>
struct within_limits<guiplus::imgui_window_flag, guiplus::imgui_types::enum_type> {
    auto check(guiplus::imgui_types::enum_type) const noexcept -> bool;
};
//------------------------------------------------------------------------------
namespace guiplus {
export auto imgui_enum_by_name(const string_view name) noexcept
  -> optionally_valid<imgui_types::enum_type>;
//------------------------------------------------------------------------------
export template <typename ApiTraits>
struct basic_imgui_constants {
public:
    using enum_type_i = std::type_identity<int>;
    template <int value>
    using enum_type_c = std::integral_constant<int, value>;

    template <typename ClassList, typename Constant, typename Tag = nothing_t>
    using opt_constant = c_api::opt_constant<ClassList, Constant, Tag>;

    basic_imgui_constants(ApiTraits&, basic_imgui_c_api<ApiTraits>&);

    /// @var config_nav_enable_keyboard
    /// @imguiconstwrap{ConfigFlags_NavEnableKeyboard}
    opt_constant<
      mp_list<imgui_config_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiConfigFlags_NavEnableKeyboard>>
#else
      enum_type_i>
#endif
      config_nav_enable_keyboard;

    /// @var config_nav_enable_gamepad
    /// @imguiconstwrap{ConfigFlags_NavEnableGamepad}
    opt_constant<
      mp_list<imgui_config_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiConfigFlags_NavEnableGamepad>>
#else
      enum_type_i>
#endif
      config_nav_enable_gamepad;

    /// @var config_nav_enable_set_mouse_pos
    /// @imguiconstwrap{ConfigFlags_NavEnableSetMousePos}
    opt_constant<
      mp_list<imgui_config_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiConfigFlags_NavEnableSetMousePos>>
#else
      enum_type_i>
#endif
      config_nav_enable_set_mouse_pos;

    /// @var config_nav_no_capture_keyboard
    /// @imguiconstwrap{ConfigFlags_NavNoCaptureKeyboard}
    opt_constant<
      mp_list<imgui_config_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiConfigFlags_NavNoCaptureKeyboard>>
#else
      enum_type_i>
#endif
      config_nav_no_capture_keyboard;

    /// @var config_no_mouse
    /// @imguiconstwrap{ConfigFlags_NavNoMouse}
    opt_constant<
      mp_list<imgui_config_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiConfigFlags_NoMouse>>
#else
      enum_type_i>
#endif
      config_no_mouse;

    /// @var config_no_mouse_cursor_change
    /// @imguiconstwrap{ConfigFlags_NoMouseCursorChange}
    opt_constant<
      mp_list<imgui_config_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiConfigFlags_NoMouseCursorChange>>
#else
      enum_type_i>
#endif
      config_no_mouse_cursor_change;

    /// @var config_nav_is_srgb
    /// @imguiconstwrap{ConfigFlags_IsSRGB}
    opt_constant<
      mp_list<imgui_config_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiConfigFlags_IsSRGB>>
#else
      enum_type_i>
#endif
      config_nav_is_srgb;

    /// @var config_nav_is_touch_screen
    /// @imguiconstwrap{ConfigFlags_IsTouchScreen}
    opt_constant<
      mp_list<imgui_config_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiConfigFlags_IsTouchScreen>>
#else
      enum_type_i>
#endif
      config_nav_is_touch_screen;

    /// @var window_no_title_bar
    /// @imguiconstwrap{WindowFlags_NoTitleBar}
    opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiWindowFlags_NoTitleBar>>
#else
      enum_type_i>
#endif
      window_no_title_bar;

    /// @var window_no_resize
    /// @imguiconstwrap{WindowFlags_NoResize}
    opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiWindowFlags_NoResize>>
#else
      enum_type_i>
#endif
      window_no_resize;

    /// @var window_no_move
    /// @imguiconstwrap{WindowFlags_NoMove}
    opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiWindowFlags_NoMove>>
#else
      enum_type_i>
#endif
      window_no_move;

    /// @var window_no_scrollbar
    /// @imguiconstwrap{WindowFlags_NoScrollbar}
    opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiWindowFlags_NoScrollbar>>
#else
      enum_type_i>
#endif
      window_no_scrollbar;

    /// @var window_no_scroll_with_mouse
    /// @imguiconstwrap{WindowFlags_NoScrollWithMouse}
    opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiWindowFlags_NoScrollWithMouse>>
#else
      enum_type_i>
#endif
      window_no_scroll_with_mouse;

    /// @var window_no_collapse
    /// @imguiconstwrap{WindowFlags_NoCollapse}
    opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiWindowFlags_NoCollapse>>
#else
      enum_type_i>
#endif
      window_no_collapse;

    /// @var window_always_auto_resize
    /// @imguiconstwrap{WindowFlags_AlwaysAutoResize}
    opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiWindowFlags_AlwaysAutoResize>>
#else
      enum_type_i>
#endif
      window_always_auto_resize;

    /// @var window_no_background
    /// @imguiconstwrap{WindowFlags_NoBackground}
    opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiWindowFlags_NoBackground>>
#else
      enum_type_i>
#endif
      window_no_background;

    /// @var window_no_saved_settings
    /// @imguiconstwrap{WindowFlags_NoSavedSettings}
    opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiWindowFlags_NoSavedSettings>>
#else
      enum_type_i>
#endif
      window_no_saved_settings;

    /// @var window_no_mouse_inputs
    /// @imguiconstwrap{WindowFlags_NoMouseInputs}
    opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiWindowFlags_NoMouseInputs>>
#else
      enum_type_i>
#endif
      window_no_mouse_inputs;

    /// @var window_menu_bar
    /// @imguiconstwrap{WindowFlags_MenuBar}
    opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiWindowFlags_MenuBar>>
#else
      enum_type_i>
#endif
      window_menu_bar;

    /// @var window_horizontal_scrollbar
    /// @imguiconstwrap{WindowFlags_HorizontalScrollbar}
    opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiWindowFlags_HorizontalScrollbar>>
#else
      enum_type_i>
#endif
      window_horizontal_scrollbar;

    /// @var window_no_focus_on_appearing
    /// @imguiconstwrap{WindowFlags_NoFocusOnAppearing}
    opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiWindowFlags_NoFocusOnAppearing>>
#else
      enum_type_i>
#endif
      window_no_focus_on_appearing;

    /// @var window_no_bring_to_front_on_focus
    /// @imguiconstwrap{WindowFlags_NoBringToFrontOnFocus}
    opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiWindowFlags_NoBringToFrontOnFocus>>
#else
      enum_type_i>
#endif
      window_no_bring_to_front_on_focus;

    /// @var window_always_vertical_scrollbar
    /// @imguiconstwrap{WindowFlags_AlwaysVerticalScrollbar}
    opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiWindowFlags_AlwaysVerticalScrollbar>>
#else
      enum_type_i>
#endif
      window_always_vertical_scrollbar;

    /// @var window_always_horizontal_scrollbar
    /// @imguiconstwrap{WindowFlags_AlwaysHorizontalScrollbar}
    opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiWindowFlags_AlwaysHorizontalScrollbar>>
#else
      enum_type_i>
#endif
      window_always_horizontal_scrollbar;

    /// @var window_always_use_window_padding
    /// @imguiconstwrap{WindowFlags_AlwaysUseWindowPadding}
    opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiWindowFlags_AlwaysUseWindowPadding>>
#else
      enum_type_i>
#endif
      window_always_use_window_padding;

    /// @var window_no_nav_inputs
    /// @imguiconstwrap{WindowFlags_NoNavInputs}
    opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiWindowFlags_NoNavInputs>>
#else
      enum_type_i>
#endif
      window_no_nav_inputs;

    /// @var window_no_nav_focus
    /// @imguiconstwrap{WindowFlags_NoNavFocus}
    opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiWindowFlags_NoNavFocus>>
#else
      enum_type_i>
#endif
      window_no_nav_focus;

    /// @var window_unsaved_document
    /// @imguiconstwrap{WindowFlags_UnsavedDocument}
    opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiWindowFlags_UnsavedDocument>>
#else
      enum_type_i>
#endif
      window_unsaved_document;

    /// @var window_no_nav
    /// @imguiconstwrap{WindowFlags_NoNav}
    opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiWindowFlags_NoNav>>
#else
      enum_type_i>
#endif
      window_no_nav;

    /// @var window_no_decoration
    /// @imguiconstwrap{WindowFlags_NoDecoration}
    opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiWindowFlags_NoDecoration>>
#else
      enum_type_i>
#endif
      window_no_decoration;

    /// @var window_no_inputs
    /// @imguiconstwrap{WindowFlags_NoInputs}
    opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiWindowFlags_NoInputs>>
#else
      enum_type_i>
#endif
      window_no_inputs;

    /// @var viewport_is_platform_window
    /// @imguiconstwrap{ViewportFlags_IsPlatformWindow}
    opt_constant<
      mp_list<imgui_viewport_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiViewportFlags_IsPlatformWindow>>
#else
      enum_type_i>
#endif
      viewport_is_platform_window;

    /// @var viewport_is_platform_monitor
    /// @imguiconstwrap{ViewportFlags_IsPlatformMonitor}
    opt_constant<
      mp_list<imgui_viewport_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiViewportFlags_IsPlatformMonitor>>
#else
      enum_type_i>
#endif
      viewport_is_platform_monitor;

    /// @var viewport_owned_by_app
    /// @imguiconstwrap{ViewportFlags_OwnedByApp}
    opt_constant<
      mp_list<imgui_viewport_flag>,
#if EAGINE_HAS_IMGUI
      enum_type_c<ImGuiViewportFlags_OwnedByApp>>
#else
      enum_type_i>
#endif
      viewport_owned_by_app;
};
//------------------------------------------------------------------------------
template <typename ApiTraits>
basic_imgui_constants<ApiTraits>::basic_imgui_constants(
  ApiTraits& traits,
  basic_imgui_c_api<ApiTraits>& api)
  : config_nav_enable_keyboard{"ConfigFlags_NavEnableKeyboard", traits, api}
  , config_nav_enable_gamepad{"ConfigFlags_NavEnableGamepad", traits, api}
  , config_nav_enable_set_mouse_pos{"ConfigFlags_NavEnableSetMousePos", traits, api}
  , config_nav_no_capture_keyboard{"ConfigFlags_NavNoCaptureKeyboard", traits, api}
  , config_no_mouse{"ConfigFlags_NoMouse", traits, api}
  , config_no_mouse_cursor_change{"ConfigFlags_NoMouseCursorChange", traits, api}
  , config_nav_is_srgb{"ConfigFlags_IsSRGB", traits, api}
  , config_nav_is_touch_screen{"ConfigFlags_IsTouchScreen", traits, api}
  , window_no_title_bar{"WindowFlags_NoTitleBar", traits, api}
  , window_no_resize{"WindowFlags_NoResize", traits, api}
  , window_no_move{"WindowFlags_NoMove", traits, api}
  , window_no_scrollbar{"WindowFlags_NoScrollbar", traits, api}
  , window_no_scroll_with_mouse{"WindowFlags_NoScrollWithMouse", traits, api}
  , window_no_collapse{"WindowFlags_NoCollapse", traits, api}
  , window_always_auto_resize{"WindowFlags_AlwaysAutoResize", traits, api}
  , window_no_background{"WindowFlags_NoBackground", traits, api}
  , window_no_saved_settings{"WindowFlags_NoSavedSettings", traits, api}
  , window_no_mouse_inputs{"WindowFlags_NoMouseInputs", traits, api}
  , window_menu_bar{"WindowFlags_MenuBar", traits, api}
  , window_horizontal_scrollbar{"WindowFlags_HorizontalScrollbar", traits, api}
  , window_no_focus_on_appearing{"WindowFlags_NoFocusOnAppearing", traits, api}
  , window_no_bring_to_front_on_focus{"WindowFlags_NoBringToFrontOnFocus", traits, api}
  , window_always_vertical_scrollbar{"WindowFlags_AlwaysVerticalScrollbar", traits, api}
  , window_always_horizontal_scrollbar{"WindowFlags_AlwaysHorizontalScrollbar", traits, api}
  , window_always_use_window_padding{"WindowFlags_AlwaysUseWindowPadding", traits, api}
  , window_no_nav_inputs{"WindowFlags_NoNavInputs", traits, api}
  , window_no_nav_focus{"WindowFlags_NoNavFocus", traits, api}
  , window_unsaved_document{"WindowFlags_UnsavedDocument", traits, api}
  , window_no_nav{"WindowFlags_NoNav", traits, api}
  , window_no_decoration{"WindowFlags_NoDecoration", traits, api}
  , window_no_inputs{"WindowFlags_NoInputs", traits, api}
  , viewport_is_platform_window{"ViewportFlags_IsPlatformWindow", traits, api}
  , viewport_is_platform_monitor{"ViewportFlags_IsPlatformMonitor", traits, api}
  , viewport_owned_by_app{"ViewportFlags_OwnedByApp", traits, api} {}
//------------------------------------------------------------------------------
} // namespace guiplus
} // namespace eagine

