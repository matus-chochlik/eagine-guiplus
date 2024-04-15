/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
/// https://www.boost.org/LICENSE_1_0.txt
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
    using vec4_type = ImVec4;
    using glfw_window_type = GLFWwindow;
    using context_type = ImGuiContext;
    using font_type = ImFont;
    using font_config_type = ImFontConfig;
    using font_atlas_type = ImFontAtlas;
    using draw_data_type = ImDrawData;
    using io_type = ImGuiIO;
    using style_type = ImGuiStyle;
    using cond_type = ImGuiCond;
    using enum_type = int;
    using mouse_button_type = ImGuiMouseButton;
    using window_flags_type = ImGuiWindowFlags;
    using child_flags_type = ImGuiChildFlags;
    using focused_flags_type = ImGuiFocusedFlags;
    using hovered_flags_type = ImGuiHoveredFlags;
    using selectable_flags_type = ImGuiSelectableFlags;
    using slider_flags_type = ImGuiSliderFlags;
    using combo_flags_type = ImGuiComboFlags;
    using color_edit_flags_type = ImGuiColorEditFlags;
    using mem_alloc_func = ImGuiMemAllocFunc;
    using mem_free_func = ImGuiMemFreeFunc;
#else
    static constexpr bool has_api = false;

    struct vec2_type {
        constexpr vec2_type() noexcept = default;
        constexpr vec2_type(float, float) noexcept = default;
    };
    struct vec4_type {
        constexpr vec4_type() noexcept = default;
        constexpr vec4_type(float, float, float, float) noexcept = default;
    };
    using glfw_window_type = nothing_t;
    using context_type = nothing_t;
    using font_type = nothing_t;
    using font_config_type = nothing_t;
    using font_atlas_type = nothing_t;
    using draw_data_type = nothing_t;
    using io_type = nothing_t;
    using style_type = nothing_t;
    using cond_type = nothing_t;
    using enum_type = int;
    using mouse_button_type = nothing_t;
    using window_flags_type = int;
    using child_flags_type = int;
    using focused_flags_type = int;
    using hovered_flags_type = int;
    using selectable_flags_type = int;
    using slider_flags_type = int;
    using combo_flags_type = int;
    using color_edit_flags_type = int;
    using mem_alloc_func = void* (*)(std::size_t sz, void*);
    using mem_free_func = void (*)(std::size_t sz, void*);
#endif
};
//------------------------------------------------------------------------------
} // namespace eagine::guiplus

