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

export module eagine.guiplus:c_api;
import eagine.core.types;
import eagine.core.memory;
import eagine.core.c_api;
import :config;
import :result;

#ifndef GUIPLUS_IMGUI_STATIC_FUNC
#if EAGINE_HAS_IMGUI
#define GUIPLUS_IMGUI_STATIC_FUNC(NAME) &ImGui::CreateContext
#else
#define GUIPLUS_IMGUI_STATIC_FUNC(NAME) nullptr
#endif
#endif

namespace eagine::guiplus {
//------------------------------------------------------------------------------
/// @brief Class wrapping the C-functions from the IMGui API.
/// @ingroup imgui_api_wrap
/// @see basic_imgui_constants
/// @see basic_imgui_operations
export template <typename ApiTraits>
class basic_imgui_c_api {
    ApiTraits& _traits;

public:
    using this_api = basic_imgui_c_api;

    /// @brief The GUI context type.
    using context_type = typename imgui_types::context_type;
    /// @brief The font atlas type.
    using font_atlas_type = typename imgui_types::font_atlas_type;
    /// @brief The draw data type.
    using draw_data_type = typename imgui_types::draw_data_type;
    /// @brief The I/O type.
    using io_type = typename imgui_types::io_type;
    /// @brief The style type.
    using style_type = typename imgui_types::style_type;

    /// @brief Alias for the API traits policy type passed as template argument.
    using api_traits = ApiTraits;

    /// @brief Alias for ImGui C/C++-API function wrapper template.
    template <
      typename Signature,
      c_api::function_ptr<api_traits, nothing_t, Signature> Function>
    using imgui_api_function = c_api::opt_function<
      api_traits,
      nothing_t,
      Signature,
      Function,
      imgui_types::has_api,
      bool(Function)>;

    /// @var CreateContext
    /// @imguifuncwrap{CreateContext}
    imgui_api_function<
      context_type*(font_atlas_type*),
      GUIPLUS_IMGUI_STATIC_FUNC(CreateContext)>
      CreateContext;

    /// @var GetCurrentContext
    /// @imguifuncwrap{GetCurrentContext}
    imgui_api_function<
      context_type*(),
      GUIPLUS_IMGUI_STATIC_FUNC(GetCurrentContext)>
      GetCurrentContext;

    /// @var SetCurrentContext
    /// @imguifuncwrap{SetCurrentContext}
    imgui_api_function<
      void(context_type*),
      GUIPLUS_IMGUI_STATIC_FUNC(SetCurrentContext)>
      SetCurrentContext;

    /// @var GetDrawData
    /// @imguifuncwrap{GetDrawData}
    imgui_api_function<draw_data_type&(), GUIPLUS_IMGUI_STATIC_FUNC(GetDrawData)>
      GetDrawData;

    /// @var GetIO
    /// @imguifuncwrap{GetIO}
    imgui_api_function<io_type&(), GUIPLUS_IMGUI_STATIC_FUNC(GetIO)> GetIO;

    /// @var GetStyle
    /// @imguifuncwrap{GetStyle}
    imgui_api_function<style_type&(), GUIPLUS_IMGUI_STATIC_FUNC(GetStyle)>
      GetStyle;

    /// @var NewFrame
    /// @imguifuncwrap{NewFrame}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_FUNC(NewFrame)> NewFrame;

    /// @var EndFrame
    /// @imguifuncwrap{EndFrame}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_FUNC(EndFrame)> EndFrame;

    /// @var Render
    /// @imguifuncwrap{Render}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_FUNC(Render)> Render;

    /// @var DestroyContext
    /// @imguifuncwrap{DestroyContext}
    imgui_api_function<
      void(context_type*),
      GUIPLUS_IMGUI_STATIC_FUNC(DestroyContext)>
      DestroyContext;

    basic_imgui_c_api(api_traits& traits);

    auto traits() noexcept -> api_traits& {
        return _traits;
    }
};
//------------------------------------------------------------------------------
template <typename ApiTraits>
basic_imgui_c_api<ApiTraits>::basic_imgui_c_api(api_traits& traits)
  : _traits{traits}
  , CreateContext{"CreateContext", *this}
  , GetCurrentContext{"GetCurrentContext", *this}
  , SetCurrentContext{"SetCurrentContext", *this}
  , GetDrawData{"GetDrawData", *this}
  , GetIO{"GetIO", *this}
  , GetStyle{"GetStyle", *this}
  , NewFrame{"NewFrame", *this}
  , EndFrame{"EndFrame", *this}
  , Render{"Render", *this}
  , DestroyContext{"DestroyContext", *this} {}
//------------------------------------------------------------------------------
} // namespace eagine::guiplus
