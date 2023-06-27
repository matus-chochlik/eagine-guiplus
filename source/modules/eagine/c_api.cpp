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

export module eagine.guiplus:c_api;
import eagine.core.types;
import eagine.core.memory;
import eagine.core.c_api;
import :config;
import :result;

#ifndef GUIPLUS_IMGUI_STATIC_FUNC
#if EAGINE_HAS_IMGUI
#define GUIPLUS_IMGUI_STATIC_FUNC(NAME) &ImGui::NAME
#define GUIPLUS_IMGUI_STATIC_IMPL_FUNC(NAME) &ImGui_Impl##NAME
#else
#define GUIPLUS_IMGUI_STATIC_FUNC(NAME) nullptr
#define GUIPLUS_IMGUI_STATIC_IMPL_FUNC(NAME) nullptr
#endif
#endif

namespace eagine::guiplus {
//------------------------------------------------------------------------------
auto basic_imgui_c_api_check_version() noexcept -> bool;
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

    /// @brief The GUI 2d vector type.
    using vec2_type = typename imgui_types::vec2_type;
    /// @brief The GLFW window handle type.
    using glfw_window_type = typename imgui_types::glfw_window_type;
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
    /// @brief The condition type.
    using cond_type = typename imgui_types::cond_type;
    /// @brief The window flags type.
    using window_flags_type = typename imgui_types::window_flags_type;
    /// @brief The focus flags type.
    using focused_flags_type = typename imgui_types::focused_flags_type;
    /// @brief The hover flags type.
    using hovered_flags_type = typename imgui_types::hovered_flags_type;

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

    /// @var OpenGL3_Init
    /// @imguifuncwrap{OpenGL3_Init}
    imgui_api_function<
      bool(const char*),
      GUIPLUS_IMGUI_STATIC_IMPL_FUNC(OpenGL3_Init)>
      OpenGL3_Init;

    /// @var OpenGL3_Shutdown
    /// @imguifuncwrap{OpenGL3_Shutdown}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_IMPL_FUNC(OpenGL3_Shutdown)>
      OpenGL3_Shutdown;

    /// @var OpenGL3_NewFrame
    /// @imguifuncwrap{OpenGL3_NewFrame}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_IMPL_FUNC(OpenGL3_NewFrame)>
      OpenGL3_NewFrame;

    /// @var OpenGL3_RenderDrawData
    /// @imguifuncwrap{OpenGL3_RenderDrawData}
    imgui_api_function<
      void(draw_data_type*),
      GUIPLUS_IMGUI_STATIC_IMPL_FUNC(OpenGL3_RenderDrawData)>
      OpenGL3_RenderDrawData;

    /// @var Glfw_InitForOpenGL
    /// @imguifuncwrap{Glfw_InitForOpenGL}
    imgui_api_function<
      bool(glfw_window_type*, bool),
      GUIPLUS_IMGUI_STATIC_IMPL_FUNC(Glfw_InitForOpenGL)>
      Glfw_InitForOpenGL;

    /// @var Glfw_Shutdown
    /// @imguifuncwrap{Glfw_Shutdown}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_IMPL_FUNC(Glfw_Shutdown)>
      Glfw_Shutdown;

    /// @var Glfw_NewFrame
    /// @imguifuncwrap{Glfw_NewFrame}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_IMPL_FUNC(Glfw_NewFrame)>
      Glfw_NewFrame;

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

    /// @var GetVersion
    /// @imguifuncwrap{GetVersion}
    imgui_api_function<const char*(), GUIPLUS_IMGUI_STATIC_FUNC(GetVersion)>
      GetVersion;

    /// @var GetDrawData
    /// @imguifuncwrap{GetDrawData}
    imgui_api_function<draw_data_type*(), GUIPLUS_IMGUI_STATIC_FUNC(GetDrawData)>
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

    /// @var ShowDemoWindow
    /// @imguifuncwrap{ShowDemoWindow}
    imgui_api_function<void(bool*), GUIPLUS_IMGUI_STATIC_FUNC(ShowDemoWindow)>
      ShowDemoWindow;

    /// @var ShowMetricsWindow
    /// @imguifuncwrap{ShowMetricsWindow}
    imgui_api_function<void(bool*), GUIPLUS_IMGUI_STATIC_FUNC(ShowMetricsWindow)>
      ShowMetricsWindow;

    /// @var ShowDebugLogWindow
    /// @imguifuncwrap{ShowDebugLogWindow}
    imgui_api_function<void(bool*), GUIPLUS_IMGUI_STATIC_FUNC(ShowDebugLogWindow)>
      ShowDebugLogWindow;

    /// @var ShowStackToolWindow
    /// @imguifuncwrap{ShowStackToolWindow}
    imgui_api_function<
      void(bool*),
      GUIPLUS_IMGUI_STATIC_FUNC(ShowStackToolWindow)>
      ShowStackToolWindow;

    /// @var ShowAboutWindow
    /// @imguifuncwrap{ShowAboutWindow}
    imgui_api_function<void(bool*), GUIPLUS_IMGUI_STATIC_FUNC(ShowAboutWindow)>
      ShowAboutWindow;

    /// @var StyleColorsDark
    /// @imguifuncwrap{StyleColorsDark}
    imgui_api_function<
      void(style_type*),
      GUIPLUS_IMGUI_STATIC_FUNC(StyleColorsDark)>
      StyleColorsDark;

    /// @var StyleColorsLight
    /// @imguifuncwrap{StyleColorsLight}
    imgui_api_function<
      void(style_type*),
      GUIPLUS_IMGUI_STATIC_FUNC(StyleColorsLight)>
      StyleColorsLight;

    /// @var StyleColorsClassic
    /// @imguifuncwrap{StyleColorsClassic}
    imgui_api_function<
      void(style_type*),
      GUIPLUS_IMGUI_STATIC_FUNC(StyleColorsClassic)>
      StyleColorsClassic;

    /// @var Begin
    /// @imguifuncwrap{Begin}
    imgui_api_function<
      bool(const char* name, bool*, window_flags_type),
      GUIPLUS_IMGUI_STATIC_FUNC(Begin)>
      Begin;

    /// @var End
    /// @imguifuncwrap{End}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_FUNC(End)> End;

    /// @var IsWindowAppearing
    /// @imguifuncwrap{IsWindowAppearing}
    imgui_api_function<bool(), GUIPLUS_IMGUI_STATIC_FUNC(IsWindowAppearing)>
      IsWindowAppearing;

    /// @var IsWindowCollapsed
    /// @imguifuncwrap{IsWindowCollapsed}
    imgui_api_function<bool(), GUIPLUS_IMGUI_STATIC_FUNC(IsWindowCollapsed)>
      IsWindowCollapsed;

    /// @var IsWindowFocused
    /// @imguifuncwrap{IsWindowFocused}
    imgui_api_function<
      bool(focused_flags_type),
      GUIPLUS_IMGUI_STATIC_FUNC(IsWindowFocused)>
      IsWindowFocused;

    /// @var IsWindowHovered
    /// @imguifuncwrap{IsWindowHovered}
    imgui_api_function<
      bool(hovered_flags_type),
      GUIPLUS_IMGUI_STATIC_FUNC(IsWindowHovered)>
      IsWindowHovered;

    /// @var GetWindowWidth
    /// @imguifuncwrap{GetWindowWidth}
    imgui_api_function<float(), GUIPLUS_IMGUI_STATIC_FUNC(GetWindowWidth)>
      GetWindowWidth;

    /// @var GetWindowHeight
    /// @imguifuncwrap{GetWindowHeight}
    imgui_api_function<float(), GUIPLUS_IMGUI_STATIC_FUNC(GetWindowHeight)>
      GetWindowHeight;

    /// @var SetNextWindowPos
    /// @imguifuncwrap{SetNextWindowPos}
    imgui_api_function<
      void(const vec2_type&, cond_type, const vec2_type&),
      GUIPLUS_IMGUI_STATIC_FUNC(SetNextWindowPos)>
      SetNextWindowPos;

    /// @var SetNextWindowSize
    /// @imguifuncwrap{SetNextWindowSize}
    imgui_api_function<
      void(const vec2_type&, cond_type),
      GUIPLUS_IMGUI_STATIC_FUNC(SetNextWindowSize)>
      SetNextWindowSize;

    /// @var SetNextWindowContentSize
    /// @imguifuncwrap{SetNextWindowContentSize}
    imgui_api_function<
      void(const vec2_type&),
      GUIPLUS_IMGUI_STATIC_FUNC(SetNextWindowContentSize)>
      SetNextWindowContentSize;

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

private:
};
//------------------------------------------------------------------------------
template <typename ApiTraits>
basic_imgui_c_api<ApiTraits>::basic_imgui_c_api(api_traits& traits)
  : _traits{traits}
  , OpenGL3_Init{"ImGui_ImplOpenGL3_Init", *this}
  , OpenGL3_Shutdown{"ImGui_ImplOpenGL3_Shutdown", *this}
  , OpenGL3_NewFrame{"ImGui_ImplOpenGL3_NewFrame", *this}
  , OpenGL3_RenderDrawData{"ImGui_ImplOpenGL3_RenderDrawData", *this}
  , Glfw_InitForOpenGL{"ImGui_ImplGlfw_InitForOpenGL", *this}
  , Glfw_Shutdown{"ImGui_ImplGlfw_Shutdown", *this}
  , Glfw_NewFrame{"ImGui_ImplGlfw_NewFrame", *this}
  , CreateContext{"CreateContext", *this}
  , GetCurrentContext{"GetCurrentContext", *this}
  , SetCurrentContext{"SetCurrentContext", *this}
  , GetVersion{"GetVersion", *this}
  , GetDrawData{"GetDrawData", *this}
  , GetIO{"GetIO", *this}
  , GetStyle{"GetStyle", *this}
  , NewFrame{"NewFrame", *this}
  , EndFrame{"EndFrame", *this}
  , Render{"Render", *this}
  , ShowDemoWindow{"ShowDemoWindow", *this}
  , ShowMetricsWindow{"ShowMetricsWindow", *this}
  , ShowDebugLogWindow{"ShowDebugLogWindow", *this}
  , ShowStackToolWindow{"ShowStackToolWindow", *this}
  , ShowAboutWindow{"ShowAboutWindow", *this}
  , StyleColorsDark{"StyleColorsDark", *this}
  , StyleColorsLight{"StyleColorsLight", *this}
  , StyleColorsClassic{"StyleColorsClassic", *this}
  , Begin{"Begin", *this}
  , End{"End", *this}
  , IsWindowAppearing{"IsWindowAppearing", *this}
  , IsWindowCollapsed{"IsWindowCollapsed", *this}
  , IsWindowFocused{"IsWindowFocused", *this}
  , IsWindowHovered{"IsWindowHovered", *this}
  , GetWindowWidth{"GetWindowWidth", *this}
  , GetWindowHeight{"GetWindowHeight", *this}
  , SetNextWindowPos{"SetNextWindowPos", *this}
  , SetNextWindowSize{"SetNextWindowSize", *this}
  , SetNextWindowContentSize{"SetNextWindowContentSize", *this}
  , DestroyContext{"DestroyContext", *this} {
    basic_imgui_c_api_check_version();
}
//------------------------------------------------------------------------------
} // namespace eagine::guiplus
