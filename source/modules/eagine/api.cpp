/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
export module eagine.guiplus:api;

import std;
import eagine.core.types;
import eagine.core.memory;
import eagine.core.utility;
import eagine.core.c_api;
import :config;
import :api_traits;
import :result;
import :objects;
import :constants;
import :c_api;

namespace eagine::guiplus {
using c_api::adapted_function;
using c_api::simple_adapted_function;
//------------------------------------------------------------------------------
export template <typename ApiTraits>
class basic_imgui_operations : public basic_imgui_c_api<ApiTraits> {

public:
    using api_traits = ApiTraits;
    using imgui_api = basic_imgui_c_api<ApiTraits>;

    using vec2_type = typename imgui_types::vec2_type;
    using glfw_window_type = typename imgui_types::glfw_window_type;
    using context_type = typename imgui_types::context_type;
    using font_atlas_type = typename imgui_types::font_atlas_type;

    basic_imgui_operations(api_traits& traits)
      : imgui_api{traits} {}

    simple_adapted_function<
      &imgui_api::OpenGL3_Init,
      c_api::collapsed<bool>(string_view)>
      opengl3_init{*this};

    simple_adapted_function<&imgui_api::OpenGL3_Shutdown, void()>
      opengl3_shutdown{*this};

    simple_adapted_function<&imgui_api::OpenGL3_NewFrame, void()>
      opengl3_new_frame{*this};

    simple_adapted_function<
      &imgui_api::OpenGL3_RenderDrawData,
      void(imgui_draw_data_handle)>
      opengl3_render_draw_data{*this};

    simple_adapted_function<
      &imgui_api::Glfw_InitForOpenGL,
      c_api::collapsed<bool>(glfw_window_type*, bool)>
      glfw_init_for_opengl{*this};

    simple_adapted_function<&imgui_api::Glfw_Shutdown, void()> glfw_shutdown{
      *this};

    simple_adapted_function<&imgui_api::Glfw_NewFrame, void()> glfw_new_frame{
      *this};

    c_api::combined<
      simple_adapted_function<
        &imgui_api::CreateContext,
        owned_imgui_context_handle(imgui_font_atlas_handle)>,
      simple_adapted_function<
        &imgui_api::CreateContext,
        imgui_context_handle(c_api::defaulted)>>
      create_context{*this};

    simple_adapted_function<&imgui_api::GetCurrentContext, imgui_context_handle()>
      get_current_context{*this};

    simple_adapted_function<
      &imgui_api::SetCurrentContext,
      void(imgui_context_handle)>
      set_current_context{*this};

    simple_adapted_function<&imgui_api::GetVersion, string_view()> get_version{
      *this};

    simple_adapted_function<&imgui_api::GetDrawData, imgui_draw_data_handle()>
      get_draw_data{*this};

    simple_adapted_function<&imgui_api::NewFrame, void()> new_frame{*this};

    simple_adapted_function<&imgui_api::EndFrame, void()> end_frame{*this};

    simple_adapted_function<&imgui_api::Render, void()> render{*this};

    simple_adapted_function<
      &imgui_api::ShowDemoWindow,
      void(optional_reference<bool>)>
      show_demo_window{*this};

    simple_adapted_function<
      &imgui_api::ShowMetricsWindow,
      void(optional_reference<bool>)>
      show_metrics_window{*this};

    simple_adapted_function<
      &imgui_api::ShowDebugLogWindow,
      void(optional_reference<bool>)>
      show_debug_log_window{*this};

    simple_adapted_function<
      &imgui_api::ShowStackToolWindow,
      void(optional_reference<bool>)>
      show_stack_tool_window{*this};

    simple_adapted_function<
      &imgui_api::ShowAboutWindow,
      void(optional_reference<bool>)>
      show_about_window{*this};

    c_api::combined<
      simple_adapted_function<
        &imgui_api::DestroyContext,
        void(owned_imgui_context_handle)>,
      simple_adapted_function<&imgui_api::DestroyContext, void(c_api::defaulted)>>
      destroy_context{*this};
};
//------------------------------------------------------------------------------
export template <typename ApiTraits>
class basic_imgui_api
  : protected ApiTraits
  , public basic_imgui_operations<ApiTraits>
  , public basic_imgui_constants<ApiTraits> {
public:
    template <typename R>
    using combined_result = typename ApiTraits::template combined_result<R>;

    basic_imgui_api(ApiTraits traits)
      : ApiTraits{std::move(traits)}
      , basic_imgui_operations<ApiTraits>{*static_cast<ApiTraits*>(this)}
      , basic_imgui_constants<ApiTraits> {
        *static_cast<ApiTraits*>(this),
          *static_cast<basic_imgui_operations<ApiTraits>*>(this)
    }
    {}

    basic_imgui_api()
      : basic_imgui_api{ApiTraits{}} {}
};
//------------------------------------------------------------------------------
export template <std::size_t I, typename ApiTraits>
auto get(basic_imgui_api<ApiTraits>& x) noexcept ->
  typename std::tuple_element<I, basic_imgui_api<ApiTraits>>::type& {
    return x;
}

export template <std::size_t I, typename ApiTraits>
auto get(const basic_imgui_api<ApiTraits>& x) noexcept -> const
  typename std::tuple_element<I, basic_imgui_api<ApiTraits>>::type& {
    return x;
}
//------------------------------------------------------------------------------
export using imgui_api = basic_imgui_api<imgui_api_traits>;
} // namespace eagine::guiplus
// NOLINTNEXTLINE(cert-dcl58-cpp)
namespace std {
//------------------------------------------------------------------------------
export template <typename ApiTraits>
struct tuple_size<eagine::guiplus::basic_imgui_api<ApiTraits>>
  : public std::integral_constant<std::size_t, 2> {};

export template <typename ApiTraits>
struct tuple_element<0, eagine::guiplus::basic_imgui_api<ApiTraits>> {
    using type = eagine::guiplus::basic_imgui_operations<ApiTraits>;
};

export template <typename ApiTraits>
struct tuple_element<1, eagine::guiplus::basic_imgui_api<ApiTraits>> {
    using type = eagine::guiplus::basic_imgui_constants<ApiTraits>;
};
//------------------------------------------------------------------------------
} // namespace std

