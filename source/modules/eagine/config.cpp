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

export module eagine.guiplus:config;
import eagine.core.types;

namespace eagine::guiplus {
//------------------------------------------------------------------------------
export struct imgui_types {
#if EAGINE_HAS_IMGUI
    static constexpr bool has_api = true;

    using context_type = ImGui::ImGuiContext;
    using font_atlas_type = ImGui::ImGuiFontAtlas;
    using draw_data_type = ImGui::ImDrawData;
    using io_type = ImGui::ImGuiIO;
    using style_type = ImGui::ImGuiStyle;
#else
    static constexpr bool has_api = false;

    using context_type = nothing_t;
    using font_atlas_type = nothing_t;
    using draw_data_type = nothing_t;
    using io_type = nothing_t;
    using style_type = nothing_t;
#endif
};
//------------------------------------------------------------------------------
} // namespace eagine::guiplus

