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

namespace eagine::guiplus {
//------------------------------------------------------------------------------
export template <typename ApiTraits>
struct basic_imgui_constants {
public:
    using int_type_i = std::type_identity<int>;
    template <int value>
    using int_type_c = std::integral_constant<int, value>;

    basic_imgui_constants(ApiTraits&, basic_imgui_c_api<ApiTraits>&);

    /// @var window_no_title_bar
    /// @imguiconstwrap{WindowFlags_NoTitleBar}
    c_api::opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      int_type_c<ImGuiWindowFlags_NoTitleBar>>
#else
      int_type_i>
#endif
      window_no_title_bar;

    /// @var window_no_resize
    /// @imguiconstwrap{WindowFlags_NoResize}
    c_api::opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      int_type_c<ImGuiWindowFlags_NoResize>>
#else
      int_type_i>
#endif
      window_no_resize;

    /// @var window_no_move
    /// @imguiconstwrap{WindowFlags_NoMove}
    c_api::opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      int_type_c<ImGuiWindowFlags_NoMove>>
#else
      int_type_i>
#endif
      window_no_move;

    /// @var window_no_scrollbar
    /// @imguiconstwrap{WindowFlags_NoScrollbar}
    c_api::opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      int_type_c<ImGuiWindowFlags_NoScrollbar>>
#else
      int_type_i>
#endif
      window_no_scrollbar;

    /// @var window_no_scroll_with_mouse
    /// @imguiconstwrap{WindowFlags_NoScrollWithMouse}
    c_api::opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      int_type_c<ImGuiWindowFlags_NoScrollWithMouse>>
#else
      int_type_i>
#endif
      window_no_scroll_with_mouse;

    /// @var window_no_collapse
    /// @imguiconstwrap{WindowFlags_NoCollapse}
    c_api::opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      int_type_c<ImGuiWindowFlags_NoCollapse>>
#else
      int_type_i>
#endif
      window_no_collapse;

    /// @var window_always_auto_resize
    /// @imguiconstwrap{WindowFlags_AlwaysAutoResize}
    c_api::opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      int_type_c<ImGuiWindowFlags_AlwaysAutoResize>>
#else
      int_type_i>
#endif
      window_always_auto_resize;

    /// @var window_no_background
    /// @imguiconstwrap{WindowFlags_NoBackground}
    c_api::opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      int_type_c<ImGuiWindowFlags_NoBackground>>
#else
      int_type_i>
#endif
      window_no_background;

    /// @var window_no_saved_settings
    /// @imguiconstwrap{WindowFlags_NoSavedSettings}
    c_api::opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      int_type_c<ImGuiWindowFlags_NoSavedSettings>>
#else
      int_type_i>
#endif
      window_no_saved_settings;

    /// @var window_no_mouse_inputs
    /// @imguiconstwrap{WindowFlags_NoMouseInputs}
    c_api::opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      int_type_c<ImGuiWindowFlags_NoMouseInputs>>
#else
      int_type_i>
#endif
      window_no_mouse_inputs;

    /// @var window_menu_bar
    /// @imguiconstwrap{WindowFlags_MenuBar}
    c_api::opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      int_type_c<ImGuiWindowFlags_MenuBar>>
#else
      int_type_i>
#endif
      window_menu_bar;

    /// @var window_horizontal_scrollbar
    /// @imguiconstwrap{WindowFlags_HorizontalScrollbar}
    c_api::opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      int_type_c<ImGuiWindowFlags_HorizontalScrollbar>>
#else
      int_type_i>
#endif
      window_horizontal_scrollbar;

    /// @var window_no_focus_on_appearing
    /// @imguiconstwrap{WindowFlags_NoFocusOnAppearing}
    c_api::opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      int_type_c<ImGuiWindowFlags_NoFocusOnAppearing>>
#else
      int_type_i>
#endif
      window_no_focus_on_appearing;

    /// @var window_no_bring_to_front_on_focus
    /// @imguiconstwrap{WindowFlags_NoBringToFrontOnFocus}
    c_api::opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      int_type_c<ImGuiWindowFlags_NoBringToFrontOnFocus>>
#else
      int_type_i>
#endif
      window_no_bring_to_front_on_focus;

    /// @var window_always_vertical_scrollbar
    /// @imguiconstwrap{WindowFlags_AlwaysVerticalScrollbar}
    c_api::opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      int_type_c<ImGuiWindowFlags_AlwaysVerticalScrollbar>>
#else
      int_type_i>
#endif
      window_always_vertical_scrollbar;

    /// @var window_always_horizontal_scrollbar
    /// @imguiconstwrap{WindowFlags_AlwaysHorizontalScrollbar}
    c_api::opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      int_type_c<ImGuiWindowFlags_AlwaysHorizontalScrollbar>>
#else
      int_type_i>
#endif
      window_always_horizontal_scrollbar;

    /// @var window_always_use_window_padding
    /// @imguiconstwrap{WindowFlags_AlwaysUseWindowPadding}
    c_api::opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      int_type_c<ImGuiWindowFlags_AlwaysUseWindowPadding>>
#else
      int_type_i>
#endif
      window_always_use_window_padding;

    /// @var window_no_nav_inputs
    /// @imguiconstwrap{WindowFlags_NoNavInputs}
    c_api::opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      int_type_c<ImGuiWindowFlags_NoNavInputs>>
#else
      int_type_i>
#endif
      window_no_nav_inputs;

    /// @var window_no_nav_focus
    /// @imguiconstwrap{WindowFlags_NoNavFocus}
    c_api::opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      int_type_c<ImGuiWindowFlags_NoNavFocus>>
#else
      int_type_i>
#endif
      window_no_nav_focus;

    /// @var window_unsaved_document
    /// @imguiconstwrap{WindowFlags_UnsavedDocument}
    c_api::opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      int_type_c<ImGuiWindowFlags_UnsavedDocument>>
#else
      int_type_i>
#endif
      window_unsaved_document;

    /// @var window_no_nav
    /// @imguiconstwrap{WindowFlags_NoNav}
    c_api::opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      int_type_c<ImGuiWindowFlags_NoNav>>
#else
      int_type_i>
#endif
      window_no_nav;

    /// @var window_no_decoration
    /// @imguiconstwrap{WindowFlags_NoDecoration}
    c_api::opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      int_type_c<ImGuiWindowFlags_NoDecoration>>
#else
      int_type_i>
#endif
      window_no_decoration;

    /// @var window_no_inputs
    /// @imguiconstwrap{WindowFlags_NoInputs}
    c_api::opt_constant<
      mp_list<imgui_window_flag>,
#if EAGINE_HAS_IMGUI
      int_type_c<ImGuiWindowFlags_NoInputs>>
#else
      int_type_i>
#endif
      window_no_inputs;

    /// @var viewport_is_platform_window
    /// @imguiconstwrap{ViewportFlags_IsPlatformWindow}
    c_api::opt_constant<
      mp_list<imgui_viewport_flag>,
#if EAGINE_HAS_IMGUI
      int_type_c<ImGuiViewportFlags_IsPlatformWindow>>
#else
      int_type_i>
#endif
      viewport_is_platform_window;

    /// @var viewport_is_platform_monitor
    /// @imguiconstwrap{ViewportFlags_IsPlatformMonitor}
    c_api::opt_constant<
      mp_list<imgui_viewport_flag>,
#if EAGINE_HAS_IMGUI
      int_type_c<ImGuiViewportFlags_IsPlatformMonitor>>
#else
      int_type_i>
#endif
      viewport_is_platform_monitor;

    /// @var viewport_owned_by_app
    /// @imguiconstwrap{ViewportFlags_OwnedByApp}
    c_api::opt_constant<
      mp_list<imgui_viewport_flag>,
#if EAGINE_HAS_IMGUI
      int_type_c<ImGuiViewportFlags_OwnedByApp>>
#else
      int_type_i>
#endif
      viewport_owned_by_app;
};
//------------------------------------------------------------------------------
template <typename ApiTraits>
basic_imgui_constants<ApiTraits>::basic_imgui_constants(
  ApiTraits& traits,
  basic_imgui_c_api<ApiTraits>& api)
  : window_no_title_bar{"WindowFlags_NoTitleBar", traits, api}
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
} // namespace eagine::guiplus

