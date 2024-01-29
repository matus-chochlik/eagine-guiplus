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

export module eagine.guiplus:objects;
import eagine.core.types;
import eagine.core.identifier;
import eagine.core.c_api;
import :config;

namespace eagine::guiplus {
//------------------------------------------------------------------------------
export template <identifier_value Id>
using imgui_lib_tag = static_message_id<"imgui", Id>;

/// @brief Tag type denoting ImGui context object.
/// @ingroup imgui_api_wrap
/// @see imgui_context
export using imgui_context_tag = imgui_lib_tag<"Context">;

/// @brief Tag type denoting ImGui draw data object.
/// @ingroup imgui_api_wrap
/// @see imgui_draw_data
export using imgui_draw_data_tag = imgui_lib_tag<"DrawData">;

/// @brief Tag type denoting ImGui font config object.
/// @ingroup imgui_api_wrap
/// @see imgui_font_config
export using imgui_font_config_tag = imgui_lib_tag<"FontConfig">;

/// @brief Tag type denoting ImGui font object.
/// @ingroup imgui_api_wrap
/// @see imgui_font
export using imgui_font_tag = imgui_lib_tag<"Font">;

/// @brief Tag type denoting ImGui font atlas object.
/// @ingroup imgui_api_wrap
/// @see imgui_font_atlas
export using imgui_font_atlas_tag = imgui_lib_tag<"FontAtlas">;

/// @brief Tag type denoting ImGui style object.
/// @ingroup imgui_api_wrap
/// @see imgui_style
export using imgui_style_tag = imgui_lib_tag<"Style">;
//------------------------------------------------------------------------------
/// @brief Alias for ImGui context handle wrapper.
/// @ingroup imgui_api_wrap
export using imgui_context =
  c_api::basic_handle<imgui_context_tag, imgui_types::context_type*, nullptr>;

/// @brief Alias for owned ImGui context handle wrapper.
/// @ingroup imgui_api_wrap
export using owned_imgui_context = c_api::
  basic_owned_handle<imgui_context_tag, imgui_types::context_type*, nullptr>;
//------------------------------------------------------------------------------
/// @brief Alias for ImGui draw data handle wrapper.
/// @ingroup imgui_api_wrap
export using imgui_draw_data =
  c_api::basic_handle<imgui_draw_data_tag, imgui_types::draw_data_type*, nullptr>;
//------------------------------------------------------------------------------
/// @brief Alias for ImGui font config handle wrapper.
/// @ingroup imgui_api_wrap
export using imgui_font_config = c_api::
  basic_handle<imgui_font_config_tag, imgui_types::font_config_type*, nullptr>;

/// @brief Alias for ImGui font handle wrapper.
/// @ingroup imgui_api_wrap
export using imgui_font =
  c_api::basic_handle<imgui_font_tag, imgui_types::font_type*, nullptr>;

/// @brief Alias for ImGui font atlas handle wrapper.
/// @ingroup imgui_api_wrap
export using imgui_font_atlas = c_api::
  basic_handle<imgui_font_atlas_tag, imgui_types::font_atlas_type*, nullptr>;
//------------------------------------------------------------------------------
/// @brief Alias for ImGui style handle wrapper.
/// @ingroup imgui_api_wrap
export using imgui_style =
  c_api::basic_handle<imgui_style_tag, imgui_types::style_type*, nullptr>;
//------------------------------------------------------------------------------
} // namespace eagine::guiplus

