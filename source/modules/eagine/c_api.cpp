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
    /// @brief The font type.
    using font_type = typename imgui_types::font_type;
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
    /// @brief The selectable item flags type.
    using selectable_flags_type = typename imgui_types::selectable_flags_type;
    /// @brief The combo item flags type.
    using combo_flags_type = typename imgui_types::combo_flags_type;

    /// @brief Alias for the API traits policy type passed as template argument.
    using api_traits = ApiTraits;

    template <typename Result, typename... U>
    constexpr auto check_result(Result res, U&&...) const noexcept {
        return res;
    }

    template <typename Result, typename Info, c_api::result_validity Validity>
    static constexpr auto collapse(
      c_api::result<Result, Info, Validity>&& r) noexcept {
        return r.collapsed(
          [](bool value) { return value; },
          [](auto& info) { info.set_unknown_error(); });
    }

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
      OpenGL3_Init{"ImGui_ImplOpenGL3_Init", *this};

    /// @var OpenGL3_Shutdown
    /// @imguifuncwrap{OpenGL3_Shutdown}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_IMPL_FUNC(OpenGL3_Shutdown)>
      OpenGL3_Shutdown{"ImGui_ImplOpenGL3_Shutdown", *this};

    /// @var OpenGL3_NewFrame
    /// @imguifuncwrap{OpenGL3_NewFrame}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_IMPL_FUNC(OpenGL3_NewFrame)>
      OpenGL3_NewFrame{"ImGui_ImplOpenGL3_NewFrame", *this};

    /// @var OpenGL3_RenderDrawData
    /// @imguifuncwrap{OpenGL3_RenderDrawData}
    imgui_api_function<
      void(draw_data_type*),
      GUIPLUS_IMGUI_STATIC_IMPL_FUNC(OpenGL3_RenderDrawData)>
      OpenGL3_RenderDrawData{"ImGui_ImplOpenGL3_RenderDrawData", *this};

    /// @var Glfw_InitForOpenGL
    /// @imguifuncwrap{Glfw_InitForOpenGL}
    imgui_api_function<
      bool(glfw_window_type*, bool),
      GUIPLUS_IMGUI_STATIC_IMPL_FUNC(Glfw_InitForOpenGL)>
      Glfw_InitForOpenGL{"ImGui_ImplGlfw_InitForOpenGL", *this};

    /// @var Glfw_Shutdown
    /// @imguifuncwrap{Glfw_Shutdown}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_IMPL_FUNC(Glfw_Shutdown)>
      Glfw_Shutdown{"ImGui_ImplGlfw_Shutdown", *this};

    /// @var Glfw_NewFrame
    /// @imguifuncwrap{Glfw_NewFrame}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_IMPL_FUNC(Glfw_NewFrame)>
      Glfw_NewFrame{"ImGui_ImplGlfw_NewFrame", *this};

    /// @var CreateContext
    /// @imguifuncwrap{CreateContext}
    imgui_api_function<
      context_type*(font_atlas_type*),
      GUIPLUS_IMGUI_STATIC_FUNC(CreateContext)>
      CreateContext{"CreateContext", *this};

    /// @var GetCurrentContext
    /// @imguifuncwrap{GetCurrentContext}
    imgui_api_function<
      context_type*(),
      GUIPLUS_IMGUI_STATIC_FUNC(GetCurrentContext)>
      GetCurrentContext{"GetCurrentContext", *this};

    /// @var SetCurrentContext
    /// @imguifuncwrap{SetCurrentContext}
    imgui_api_function<
      void(context_type*),
      GUIPLUS_IMGUI_STATIC_FUNC(SetCurrentContext)>
      SetCurrentContext{"SetCurrentContext", *this};

    /// @var GetVersion
    /// @imguifuncwrap{GetVersion}
    imgui_api_function<const char*(), GUIPLUS_IMGUI_STATIC_FUNC(GetVersion)>
      GetVersion{"GetVersion", *this};

    /// @var GetDrawData
    /// @imguifuncwrap{GetDrawData}
    imgui_api_function<draw_data_type*(), GUIPLUS_IMGUI_STATIC_FUNC(GetDrawData)>
      GetDrawData{"GetDrawData", *this};

    /// @var GetIO
    /// @imguifuncwrap{GetIO}
    imgui_api_function<io_type&(), GUIPLUS_IMGUI_STATIC_FUNC(GetIO)> GetIO{
      "GetIO",
      *this};

    /// @var GetStyle
    /// @imguifuncwrap{GetStyle}
    imgui_api_function<style_type&(), GUIPLUS_IMGUI_STATIC_FUNC(GetStyle)>
      GetStyle{"GetStyle", *this};

    /// @var NewFrame
    /// @imguifuncwrap{NewFrame}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_FUNC(NewFrame)> NewFrame{
      "NewFrame",
      *this};

    /// @var EndFrame
    /// @imguifuncwrap{EndFrame}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_FUNC(EndFrame)> EndFrame{
      "EndFrame",
      *this};

    /// @var Render
    /// @imguifuncwrap{Render}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_FUNC(Render)> Render{
      "Render",
      *this};

    /// @var ShowDemoWindow
    /// @imguifuncwrap{ShowDemoWindow}
    imgui_api_function<void(bool*), GUIPLUS_IMGUI_STATIC_FUNC(ShowDemoWindow)>
      ShowDemoWindow{"ShowDemoWindow", *this};

    /// @var ShowMetricsWindow
    /// @imguifuncwrap{ShowMetricsWindow}
    imgui_api_function<void(bool*), GUIPLUS_IMGUI_STATIC_FUNC(ShowMetricsWindow)>
      ShowMetricsWindow{"ShowMetricsWindow", *this};

    /// @var ShowDebugLogWindow
    /// @imguifuncwrap{ShowDebugLogWindow}
    imgui_api_function<void(bool*), GUIPLUS_IMGUI_STATIC_FUNC(ShowDebugLogWindow)>
      ShowDebugLogWindow{"ShowDebugLogWindow", *this};

    /// @var ShowStackToolWindow
    /// @imguifuncwrap{ShowStackToolWindow}
    imgui_api_function<
      void(bool*),
      GUIPLUS_IMGUI_STATIC_FUNC(ShowStackToolWindow)>
      ShowStackToolWindow{"ShowStackToolWindow", *this};

    /// @var ShowAboutWindow
    /// @imguifuncwrap{ShowAboutWindow}
    imgui_api_function<void(bool*), GUIPLUS_IMGUI_STATIC_FUNC(ShowAboutWindow)>
      ShowAboutWindow{"ShowAboutWindow", *this};

    /// @var StyleColorsDark
    /// @imguifuncwrap{StyleColorsDark}
    imgui_api_function<
      void(style_type*),
      GUIPLUS_IMGUI_STATIC_FUNC(StyleColorsDark)>
      StyleColorsDark{"StyleColorsDark", *this};

    /// @var StyleColorsLight
    /// @imguifuncwrap{StyleColorsLight}
    imgui_api_function<
      void(style_type*),
      GUIPLUS_IMGUI_STATIC_FUNC(StyleColorsLight)>
      StyleColorsLight{"StyleColorsLight", *this};

    /// @var StyleColorsClassic
    /// @imguifuncwrap{StyleColorsClassic}
    imgui_api_function<
      void(style_type*),
      GUIPLUS_IMGUI_STATIC_FUNC(StyleColorsClassic)>
      StyleColorsClassic{"StyleColorsClassic", *this};

    /// @var Begin
    /// @imguifuncwrap{Begin}
    imgui_api_function<
      bool(const char* name, bool*, window_flags_type),
      GUIPLUS_IMGUI_STATIC_FUNC(Begin)>
      Begin{"Begin", *this};

    /// @var End
    /// @imguifuncwrap{End}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_FUNC(End)> End{"End", *this};

    /// @var BeginChild
    /// @imguifuncwrap{BeginChild}
    imgui_api_function<
      bool(const char* name, const vec2_type&, bool, window_flags_type),
      GUIPLUS_IMGUI_STATIC_FUNC(BeginChild)>
      BeginChild{"BeginChild", *this};

    /// @var EndChild
    /// @imguifuncwrap{EndChild}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_FUNC(EndChild)> EndChild{
      "EndChild",
      *this};

    /// @var BeginGroup
    /// @imguifuncwrap{BeginGroup}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_FUNC(BeginGroup)> BeginGroup{
      "BeginGroup",
      *this};

    /// @var EndGroup
    /// @imguifuncwrap{EndGroup}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_FUNC(EndGroup)> EndGroup{
      "EndGroup",
      *this};

    /// @var BeginDisabled
    /// @imguifuncwrap{BeginDisabled}
    imgui_api_function<void(bool), GUIPLUS_IMGUI_STATIC_FUNC(BeginDisabled)>
      BeginDisabled{"BeginDisabled", *this};

    /// @var EndDisabled
    /// @imguifuncwrap{EndDisabled}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_FUNC(EndDisabled)>
      EndDisabled{"EndDisabled", *this};

    /// @var BeginPopup
    /// @imguifuncwrap{BeginPopup}
    imgui_api_function<
      bool(const char* name, window_flags_type),
      GUIPLUS_IMGUI_STATIC_FUNC(BeginPopup)>
      BeginPopup{"BeginPopup", *this};

    /// @var BeginPopupModal
    /// @imguifuncwrap{BeginPopupModal}
    imgui_api_function<
      bool(const char* name, bool*, window_flags_type),
      GUIPLUS_IMGUI_STATIC_FUNC(BeginPopupModal)>
      BeginPopupModal{"BeginPopupModal", *this};

    /// @var EndPopup
    /// @imguifuncwrap{EndPopup}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_FUNC(EndPopup)> EndPopup{
      "EndPopup",
      *this};

    /// @var IsWindowAppearing
    /// @imguifuncwrap{IsWindowAppearing}
    imgui_api_function<bool(), GUIPLUS_IMGUI_STATIC_FUNC(IsWindowAppearing)>
      IsWindowAppearing{"IsWindowAppearing", *this};

    /// @var IsWindowCollapsed
    /// @imguifuncwrap{IsWindowCollapsed}
    imgui_api_function<bool(), GUIPLUS_IMGUI_STATIC_FUNC(IsWindowCollapsed)>
      IsWindowCollapsed{"IsWindowCollapsed", *this};

    /// @var IsWindowFocused
    /// @imguifuncwrap{IsWindowFocused}
    imgui_api_function<
      bool(focused_flags_type),
      GUIPLUS_IMGUI_STATIC_FUNC(IsWindowFocused)>
      IsWindowFocused{"IsWindowFocused", *this};

    /// @var IsWindowHovered
    /// @imguifuncwrap{IsWindowHovered}
    imgui_api_function<
      bool(hovered_flags_type),
      GUIPLUS_IMGUI_STATIC_FUNC(IsWindowHovered)>
      IsWindowHovered{"IsWindowHovered", *this};

    /// @var GetWindowWidth
    /// @imguifuncwrap{GetWindowWidth}
    imgui_api_function<float(), GUIPLUS_IMGUI_STATIC_FUNC(GetWindowWidth)>
      GetWindowWidth{"GetWindowWidth", *this};

    /// @var GetWindowHeight
    /// @imguifuncwrap{GetWindowHeight}
    imgui_api_function<float(), GUIPLUS_IMGUI_STATIC_FUNC(GetWindowHeight)>
      GetWindowHeight{"GetWindowHeight", *this};

    /// @var SetNextWindowPos
    /// @imguifuncwrap{SetNextWindowPos}
    imgui_api_function<
      void(const vec2_type&, cond_type, const vec2_type&),
      GUIPLUS_IMGUI_STATIC_FUNC(SetNextWindowPos)>
      SetNextWindowPos{"SetNextWindowPos", *this};

    /// @var SetNextWindowSize
    /// @imguifuncwrap{SetNextWindowSize}
    imgui_api_function<
      void(const vec2_type&, cond_type),
      GUIPLUS_IMGUI_STATIC_FUNC(SetNextWindowSize)>
      SetNextWindowSize{"SetNextWindowSize", *this};

    /// @var SetNextWindowContentSize
    /// @imguifuncwrap{SetNextWindowContentSize}
    imgui_api_function<
      void(const vec2_type&),
      GUIPLUS_IMGUI_STATIC_FUNC(SetNextWindowContentSize)>
      SetNextWindowContentSize{"SetNextWindowContentSize", *this};

    /// @var SetNextWindowCollapsed
    /// @imguifuncwrap{SetNextWindowCollapsed}
    imgui_api_function<
      void(bool, cond_type),
      GUIPLUS_IMGUI_STATIC_FUNC(SetNextWindowCollapsed)>
      SetNextWindowCollapsed{"SetNextWindowCollapsed", *this};

    /// @var SetNextWindowFocus
    /// @imguifuncwrap{SetNextWindowFocus}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_FUNC(SetNextWindowFocus)>
      SetNextWindowFocus{"SetNextWindowFocus", *this};

    /// @var SetNextWindowScroll
    /// @imguifuncwrap{SetNextWindowScroll}
    imgui_api_function<
      void(const ImVec2&),
      GUIPLUS_IMGUI_STATIC_FUNC(SetNextWindowScroll)>
      SetNextWindowScroll{"SetNextWindowScroll", *this};

    /// @var GetScrollMaxX
    /// @imguifuncwrap{GetScrollMaxX}
    imgui_api_function<float(), GUIPLUS_IMGUI_STATIC_FUNC(GetScrollMaxX)>
      GetScrollMaxX{"GetScrollMaxX", *this};

    /// @var GetScrollMaxY
    /// @imguifuncwrap{GetScrollMaxY}
    imgui_api_function<float(), GUIPLUS_IMGUI_STATIC_FUNC(GetScrollMaxY)>
      GetScrollMaxY{"GetScrollMaxY", *this};

    /// @var GetScrollX
    /// @imguifuncwrap{GetScrollX}
    imgui_api_function<float(), GUIPLUS_IMGUI_STATIC_FUNC(GetScrollX)>
      GetScrollX{"GetScrollX", *this};

    /// @var GetScrollY
    /// @imguifuncwrap{GetScrollY}
    imgui_api_function<float(), GUIPLUS_IMGUI_STATIC_FUNC(GetScrollY)>
      GetScrollY{"GetScrollY", *this};

    /// @var SetScrollX
    /// @imguifuncwrap{SetScrollX}
    imgui_api_function<void(float), GUIPLUS_IMGUI_STATIC_FUNC(SetScrollX)>
      SetScrollX{"SetScrollX", *this};

    /// @var SetScrollY
    /// @imguifuncwrap{SetScrollY}
    imgui_api_function<void(float), GUIPLUS_IMGUI_STATIC_FUNC(SetScrollY)>
      SetScrollY{"SetScrollY", *this};

    /// @var SetScrollHereX
    /// @imguifuncwrap{SetScrollHereX}
    imgui_api_function<void(float), GUIPLUS_IMGUI_STATIC_FUNC(SetScrollHereX)>
      SetScrollHereX{"SetScrollHereX", *this};

    /// @var SetScrollHereY
    /// @imguifuncwrap{SetScrollHereY}
    imgui_api_function<void(float), GUIPLUS_IMGUI_STATIC_FUNC(SetScrollHereY)>
      SetScrollHereY{"SetScrollHereY", *this};

    /// @var PushFont
    /// @imguifuncwrap{PushFont}
    imgui_api_function<void(font_type*), GUIPLUS_IMGUI_STATIC_FUNC(PushFont)>
      PushFont{"PushFont", *this};

    /// @var PopFont
    /// @imguifuncwrap{PopFont}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_FUNC(PopFont)> PopFont{
      "PopFont",
      *this};

    /// @var PushItemWidth
    /// @imguifuncwrap{PushItemWidth}
    imgui_api_function<void(float), GUIPLUS_IMGUI_STATIC_FUNC(PushItemWidth)>
      PushItemWidth{"PushItemWidth", *this};

    /// @var PopItemWidth
    /// @imguifuncwrap{PopItemWidth}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_FUNC(PopItemWidth)>
      PopItemWidth{"PopItemWidth", *this};

    /// @var GetFont
    /// @imguifuncwrap{GetFont}
    imgui_api_function<font_type*(), GUIPLUS_IMGUI_STATIC_FUNC(GetFont)> GetFont{
      "GetFont",
      *this};

    /// @var GetFontSize
    /// @imguifuncwrap{GetFontSize}
    imgui_api_function<float(), GUIPLUS_IMGUI_STATIC_FUNC(GetFontSize)>
      GetFontSize{"GetFontSize", *this};

    /// @var GetCursorPos
    /// @imguifuncwrap{GetCursorPos}
    imgui_api_function<vec2_type(), GUIPLUS_IMGUI_STATIC_FUNC(GetCursorPos)>
      GetCursorPos{"GetCursorPos", *this};

    /// @var GetCursorPosX
    /// @imguifuncwrap{GetCursorPosX}
    imgui_api_function<float(), GUIPLUS_IMGUI_STATIC_FUNC(GetCursorPosX)>
      GetCursorPosX{"GetCursorPosX", *this};

    /// @var GetCursorPosY
    /// @imguifuncwrap{GetCursorPosY}
    imgui_api_function<float(), GUIPLUS_IMGUI_STATIC_FUNC(GetCursorPosY)>
      GetCursorPosY{"GetCursorPosY", *this};

    /// @var GetCursorScreenPos
    /// @imguifuncwrap{GetCursorScreenPos}
    imgui_api_function<vec2_type(), GUIPLUS_IMGUI_STATIC_FUNC(GetCursorScreenPos)>
      GetCursorScreenPos{"GetCursorScreenPos", *this};

    /// @var Spacing
    /// @imguifuncwrap{Spacing}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_FUNC(Spacing)> Spacing{
      "Spacing",
      *this};

    /// @var Separator
    /// @imguifuncwrap{Separator}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_FUNC(Separator)> Separator{
      "Separator",
      *this};

    /// @var NewLine
    /// @imguifuncwrap{NewLine}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_FUNC(NewLine)> NewLine{
      "NewLine",
      *this};

    /// @var SameLine
    /// @imguifuncwrap{SameLine}
    imgui_api_function<void(float, float), GUIPLUS_IMGUI_STATIC_FUNC(SameLine)>
      SameLine{"SameLine", *this};

    /// @var Indent
    /// @imguifuncwrap{Indent}
    imgui_api_function<void(float), GUIPLUS_IMGUI_STATIC_FUNC(Indent)> Indent{
      "Indent",
      *this};

    /// @var Unindent
    /// @imguifuncwrap{Unindent}
    imgui_api_function<void(float), GUIPLUS_IMGUI_STATIC_FUNC(Unindent)>
      Unindent{"Unindent", *this};

    /// @var BeginTooltip
    /// @imguifuncwrap{BeginTooltip}
    imgui_api_function<bool(), GUIPLUS_IMGUI_STATIC_FUNC(BeginTooltip)>
      BeginTooltip{"BeginTooltip", *this};

    /// @var EndTooltip
    /// @imguifuncwrap{EndTooltip}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_FUNC(EndTooltip)> EndTooltip{
      "EndTooltip",
      *this};

    /// @var TextUnformatted
    /// @imguifuncwrap{TextUnformatted}
    imgui_api_function<
      void(const char*, const char*),
      GUIPLUS_IMGUI_STATIC_FUNC(TextUnformatted)>
      TextUnformatted{"TextUnformatted", *this};

    /// @var Button
    /// @imguifuncwrap{Button}
    imgui_api_function<
      bool(const char*, const vec2_type&),
      GUIPLUS_IMGUI_STATIC_FUNC(Button)>
      Button{"Button", *this};

    /// @var SmallButton
    /// @imguifuncwrap{SmallButton}
    imgui_api_function<bool(const char*), GUIPLUS_IMGUI_STATIC_FUNC(SmallButton)>
      SmallButton{"SmallButton", *this};

    /// @var Checkbox
    /// @imguifuncwrap{Checkbox}
    imgui_api_function<
      bool(const char*, bool*),
      GUIPLUS_IMGUI_STATIC_FUNC(Checkbox)>
      Checkbox{"Checkbox", *this};

    /// @var RadioButton
    /// @imguifuncwrap{RadioButton}
    imgui_api_function<
      bool(const char*, bool),
      GUIPLUS_IMGUI_STATIC_FUNC(RadioButton)>
      RadioButton{"RadioButton", *this};

    /// @var ProgressBar
    /// @imguifuncwrap{ProgressBar}
    imgui_api_function<
      void(float, const vec2_type&, const char*),
      GUIPLUS_IMGUI_STATIC_FUNC(ProgressBar)>
      ProgressBar{"ProgressBar", *this};

    /// @var Bullet
    /// @imguifuncwrap{Bullet}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_FUNC(Bullet)> Bullet{
      "Bullet",
      *this};

    /// @var SetItemDefaultFocus
    /// @imguifuncwrap{SetItemDefaultFocus}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_FUNC(SetItemDefaultFocus)>
      SetItemDefaultFocus{"SetItemDefaultFocus", *this};

    /// @var Selectable
    /// @imguifuncwrap{Selectable}
    imgui_api_function<
      bool(const char*, bool, selectable_flags_type, const vec2_type&),
      GUIPLUS_IMGUI_STATIC_FUNC(Selectable)>
      Selectable{"Selectable", *this};

    /// @var BeginCombo
    /// @imguifuncwrap{BeginCombo}
    imgui_api_function<
      bool(const char*, const char*, combo_flags_type),
      GUIPLUS_IMGUI_STATIC_FUNC(BeginCombo)>
      BeginCombo{"BeginCombo", *this};

    /// @var EndCombo
    /// @imguifuncwrap{EndCombo}
    imgui_api_function<void(), GUIPLUS_IMGUI_STATIC_FUNC(EndCombo)> EndCombo{
      "EndCombo",
      *this};

    /// @var DestroyContext
    /// @imguifuncwrap{DestroyContext}
    imgui_api_function<
      void(context_type*),
      GUIPLUS_IMGUI_STATIC_FUNC(DestroyContext)>
      DestroyContext{"DestroyContext", *this};

    basic_imgui_c_api(api_traits& traits)
      : _traits{traits} {
        basic_imgui_c_api_check_version();
    }

    auto traits() noexcept -> api_traits& {
        return _traits;
    }

private:
};
//------------------------------------------------------------------------------
} // namespace eagine::guiplus
