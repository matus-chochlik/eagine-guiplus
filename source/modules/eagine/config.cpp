/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
module;
#if __has_include(<imgui.h>)
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <imgui.h>
#define EAGINE_HAS_IMGUI 1
#else
#define EAGINE_HAS_IMGUI 0
#endif

export module eagine.guiplus:config;
import eagine.core.types;
import eagine.core.math;

namespace eagine::guiplus {
//------------------------------------------------------------------------------
export struct imgui_types {
#if EAGINE_HAS_IMGUI
    static constexpr bool has_api = true;

    using vec2_type = ImVec2;
    using glfw_window_type = GLFWwindow;
    using context_type = ImGuiContext;
    using font_type = ImFont;
    using font_atlas_type = ImFontAtlas;
    using draw_data_type = ImDrawData;
    using io_type = ImGuiIO;
    using style_type = ImGuiStyle;
    using cond_type = ImGuiCond;
    using mouse_button_type = ImGuiMouseButton;
    using window_flags_type = ImGuiWindowFlags;
    using focused_flags_type = ImGuiFocusedFlags;
    using hovered_flags_type = ImGuiHoveredFlags;
    using selectable_flags_type = ImGuiSelectableFlags;
    using combo_flags_type = ImGuiComboFlags;
#else
    static constexpr bool has_api = false;

    struct vec2_type {
        constexpr vec2_type() noexcept = default;
        constexpr vec2_type(float, float) noexcept = default;
    };
    using glfw_window_type = nothing_t;
    using context_type = nothing_t;
    using font_type = nothing_t;
    using font_atlas_type = nothing_t;
    using draw_data_type = nothing_t;
    using io_type = nothing_t;
    using style_type = nothing_t;
    using cond_type = nothing_t;
    using mouse_button_type = nothing_t;
    using window_flags_type = int;
    using focused_flags_type = int;
    using hovered_flags_type = int;
    using selectable_flags_type = int;
    using combo_flags_type = int;
#endif
};
//------------------------------------------------------------------------------
} // namespace eagine::guiplus

