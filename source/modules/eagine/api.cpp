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
import eagine.core.math;
import eagine.core.c_api;
import :config;
import :enum_types;
import :api_traits;
import :result;
import :objects;
import :constants;
import :c_api;

namespace eagine::c_api {
//------------------------------------------------------------------------------
export template <>
struct make_args_map<
  0U,
  0U,
  mp_list<const char*, const char*>,
  mp_list<string_view>> {

    constexpr auto operator()(size_constant<0U> i, const string_view s)
      const noexcept {
        return s.data();
    }

    constexpr auto operator()(size_constant<1U> i, const string_view s)
      const noexcept {
        return s.data() + s.size();
    }
};

export template <
  std::size_t CI,
  std::size_t CppI,
  bool V,
  typename... CT,
  typename... CppT>
struct make_args_map<
  CI,
  CppI,
  mp_list<const typename guiplus::imgui_types::vec2_type&, CT...>,
  mp_list<math::vector<float, 2, V>, CppT...>>
  : make_args_map<CI + 1, CppI + 1, mp_list<CT...>, mp_list<CppT...>> {
    using make_args_map<CI + 1, CppI + 1, mp_list<CT...>, mp_list<CppT...>>::
    operator();

    static constexpr auto _conv(math::vector<float, 2, V> v) noexcept ->
      typename guiplus::imgui_types::vec2_type {
        return {v.x(), v.y()};
    }

    template <typename... P>
    constexpr auto operator()(size_constant<CI> i, P&&... p) const noexcept {
        return _conv(reorder_arg_map<CI, CppI>{}(i, std::forward<P>(p)...));
    }
};
} // namespace eagine::c_api
//------------------------------------------------------------------------------
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
    using selectable_flags_type = typename imgui_types::selectable_flags_type;
    using combo_flags_type = typename imgui_types::combo_flags_type;

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
      void(imgui_draw_data)>
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
        imgui_context(imgui_font_atlas)>,
      simple_adapted_function<
        &imgui_api::CreateContext,
        imgui_context(c_api::defaulted)>>
      create_context{*this};

    simple_adapted_function<&imgui_api::GetCurrentContext, imgui_context()>
      get_current_context{*this};

    simple_adapted_function<&imgui_api::SetCurrentContext, void(imgui_context)>
      set_current_context{*this};

    simple_adapted_function<&imgui_api::GetVersion, string_view()> get_version{
      *this};

    simple_adapted_function<&imgui_api::GetDrawData, imgui_draw_data()>
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

    simple_adapted_function<&imgui_api::StyleColorsDark, void(c_api::defaulted)>
      style_colors_dark{*this};

    simple_adapted_function<&imgui_api::StyleColorsLight, void(c_api::defaulted)>
      style_colors_light{*this};

    simple_adapted_function<
      &imgui_api::StyleColorsClassic,
      void(c_api::defaulted)>
      style_colors_classic{*this};

    c_api::combined<
      simple_adapted_function<
        &imgui_api::Begin,
        bool(
          string_view,
          optional_reference<bool>,
          c_api::enum_bitfield<imgui_window_flag>)>,
      simple_adapted_function<
        &imgui_api::Begin,
        bool(string_view, optional_reference<bool>, c_api::defaulted)>,
      simple_adapted_function<
        &imgui_api::Begin,
        imgui_context(string_view, c_api::defaulted, c_api::defaulted)>>
      begin{*this};

    simple_adapted_function<&imgui_api::End, void()> end{*this};

    simple_adapted_function<&imgui_api::BeginGroup, void()> begin_group{*this};
    simple_adapted_function<&imgui_api::EndGroup, void()> end_group{*this};

    simple_adapted_function<&imgui_api::BeginDisabled, void(bool)>
      begin_disabled{*this};
    simple_adapted_function<&imgui_api::EndDisabled, void()> end_disabled{
      *this};

    simple_adapted_function<&imgui_api::IsWindowAppearing, bool()>
      is_window_appearing{*this};

    simple_adapted_function<&imgui_api::IsWindowCollapsed, bool()>
      is_window_collapsed{*this};

    simple_adapted_function<
      &imgui_api::IsWindowFocused,
      bool(c_api::enum_bitfield<imgui_focused_flag>)>
      is_window_focused{*this};

    c_api::combined<
      simple_adapted_function<
        &imgui_api::IsWindowHovered,
        bool(c_api::enum_bitfield<imgui_hovered_flag>)>,
      simple_adapted_function<&imgui_api::IsWindowHovered, bool(c_api::defaulted)>>
      is_window_hovered{*this};

    c_api::combined<
      simple_adapted_function<
        &imgui_api::IsItemHovered,
        bool(c_api::enum_bitfield<imgui_hovered_flag>)>,
      simple_adapted_function<&imgui_api::IsItemHovered, bool(c_api::defaulted)>>
      is_item_hovered{*this};

    simple_adapted_function<&imgui_api::GetWindowWidth, float()>
      get_window_width{*this};

    simple_adapted_function<&imgui_api::GetWindowHeight, float()>
      get_window_height{*this};

    simple_adapted_function<
      &imgui_api::SetNextWindowSize,
      void(const vec2_type&, c_api::defaulted)>
      set_next_window_size{*this};

    simple_adapted_function<&imgui_api::PushItemWidth, void(float)>
      push_item_width{*this};
    simple_adapted_function<&imgui_api::PopItemWidth, void()> pop_item_width{
      *this};

    simple_adapted_function<&imgui_api::PushTextWrapPos, void(float)>
      push_text_wrap_pos{*this};
    simple_adapted_function<&imgui_api::PopTextWrapPos, void()>
      pop_text_wrap_pos{*this};

    simple_adapted_function<&imgui_api::GetFontSize, float()> get_font_size{
      *this};

    simple_adapted_function<&imgui_api::GetCursorPosX, float()> get_cursor_pos_x{
      *this};
    simple_adapted_function<&imgui_api::GetCursorPosY, float()> get_cursor_pos_y{
      *this};

    simple_adapted_function<&imgui_api::Spacing, void()> spacing{*this};

    simple_adapted_function<&imgui_api::Separator, void()> separator{*this};

    simple_adapted_function<&imgui_api::Bullet, void()> bullet{*this};

    simple_adapted_function<&imgui_api::NewLine, void()> new_line{*this};

    c_api::combined<
      simple_adapted_function<&imgui_api::SameLine, void(float, float)>,
      simple_adapted_function<
        &imgui_api::SameLine,
        void(c_api::substituted<0>, c_api::substituted<-1>)>>
      same_line{*this};

    simple_adapted_function<&imgui_api::Indent, void(float)> indent{*this};

    simple_adapted_function<&imgui_api::Unindent, void(float)> unindent{*this};

    simple_adapted_function<&imgui_api::BeginTooltip, bool()> begin_tooltip{
      *this};

    simple_adapted_function<&imgui_api::BeginItemTooltip, bool()>
      begin_item_tooltip{*this};

    simple_adapted_function<&imgui_api::EndTooltip, void()> end_tooltip{*this};

    c_api::combined<
      simple_adapted_function<
        &imgui_api::ProgressBar,
        void(float, math::vector<float, 2, true>, string_view)>,
      simple_adapted_function<
        &imgui_api::ProgressBar,
        void(float, math::vector<float, 2, false>, string_view)>,
      simple_adapted_function<
        &imgui_api::ProgressBar,
        bool(
          float,
          c_api::substituted<vec2_type(-std::numeric_limits<float>::min(), 0.F)>,
          string_view)>,
      simple_adapted_function<
        &imgui_api::ProgressBar,
        bool(
          float,
          c_api::substituted<vec2_type(-std::numeric_limits<float>::min(), 0.F)>,
          c_api::defaulted)>>
      progress_bar{*this};

    simple_adapted_function<&imgui_api::TextUnformatted, void(string_view)>
      text_unformatted{*this};

    c_api::combined<
      simple_adapted_function<
        &imgui_api::Button,
        bool(string_view, math::vector<float, 2, true>)>,
      simple_adapted_function<
        &imgui_api::Button,
        bool(string_view, math::vector<float, 2, false>)>,
      simple_adapted_function<
        &imgui_api::Button,
        bool(string_view, c_api::defaulted)>>
      button{*this};

    simple_adapted_function<&imgui_api::SmallButton, bool(string_view)>
      small_button{*this};

    simple_adapted_function<
      &imgui_api::Checkbox,
      bool(string_view, optional_reference<bool>)>
      checkbox{*this};

    simple_adapted_function<&imgui_api::RadioButton, bool(string_view, bool)>
      radio_button{*this};

    simple_adapted_function<&imgui_api::SetItemDefaultFocus, void()>
      set_item_default_focus{*this};

    c_api::combined<
      simple_adapted_function<
        &imgui_api::Selectable,
        bool(
          string_view,
          bool,
          c_api::enum_bitfield<imgui_selectable_flag>,
          math::vector<float, 2, true>)>,
      simple_adapted_function<
        &imgui_api::Selectable,
        bool(
          string_view,
          bool,
          c_api::enum_bitfield<imgui_selectable_flag>,
          math::vector<float, 2, false>)>,
      simple_adapted_function<
        &imgui_api::Selectable,
        bool(
          string_view,
          bool,
          c_api::enum_bitfield<imgui_selectable_flag>,
          c_api::defaulted)>,
      adapted_function<
        &imgui_api::Selectable,
        bool(string_view, bool),
        c_api::combined_map<
          c_api::trivial_arg_map<0, 2>,
          c_api::get_data_map<1, 1>,
          c_api::defaulted_arg_map<selectable_flags_type, 3>,
          c_api::defaulted_arg_map<vec2_type, 4>>>>
      selectable{*this};

    c_api::combined<
      adapted_function<
        &imgui_api::BeginCombo,
        bool(string_view, string_view, c_api::enum_bitfield<imgui_combo_flag>),
        c_api::combined_map<
          c_api::trivial_arg_map<0>,
          c_api::get_data_map<1, 1>,
          c_api::get_data_map<2, 2>,
          c_api::convert<combo_flags_type, c_api::trivial_arg_map<3>>>>,
      adapted_function<
        &imgui_api::BeginCombo,
        bool(string_view, string_view),
        c_api::combined_map<
          c_api::trivial_arg_map<0>,
          c_api::get_data_map<1, 1>,
          c_api::get_data_map<2, 2>,
          c_api::defaulted_arg_map<combo_flags_type, 3>>>>
      begin_combo{*this};

    c_api::combined<
      adapted_function<
        &imgui_api::PlotHistogram,
        void(string_view, span<const float>, float, float, vec2_type),
        c_api::combined_map<
          c_api::trivial_arg_map<0>,
          c_api::get_data_map<1, 1>,
          c_api::get_data_map<2, 2>,
          c_api::get_size_map<3, 2>,
          c_api::substituted_arg_map<0, 4>,
          c_api::defaulted_arg_map<const char*, 5>,
          c_api::reorder_arg_map<6, 3>,
          c_api::reorder_arg_map<7, 4>,
          c_api::reorder_arg_map<8, 5>,
          c_api::substituted_arg_map<sizeof(float), 9>>>,
      adapted_function<
        &imgui_api::PlotHistogram,
        void(string_view, span<const float>, float, float),
        c_api::combined_map<
          c_api::trivial_arg_map<0>,
          c_api::get_data_map<1, 1>,
          c_api::get_data_map<2, 2>,
          c_api::get_size_map<3, 2>,
          c_api::substituted_arg_map<0, 4>,
          c_api::defaulted_arg_map<const char*, 5>,
          c_api::reorder_arg_map<6, 3>,
          c_api::reorder_arg_map<7, 4>,
          c_api::defaulted_arg_map<vec2_type, 8>,
          c_api::substituted_arg_map<sizeof(float), 9>>>,
      adapted_function<
        &imgui_api::PlotHistogram,
        void(string_view, span<const float>),
        c_api::combined_map<
          c_api::trivial_arg_map<0>,
          c_api::get_data_map<1, 1>,
          c_api::get_data_map<2, 2>,
          c_api::get_size_map<3, 2>,
          c_api::substituted_arg_map<0, 4>,
          c_api::defaulted_arg_map<const char*, 5>,
          c_api::substituted_arg_map<0, 6>,
          c_api::substituted_arg_map<1, 7>,
          c_api::defaulted_arg_map<vec2_type, 8>,
          c_api::substituted_arg_map<sizeof(float), 9>>>>
      plot_histogram{*this};

    simple_adapted_function<&imgui_api::EndCombo, void()> end_combo{*this};

    c_api::combined<
      simple_adapted_function<&imgui_api::DestroyContext, void(imgui_context)>,
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

    template <typename... Args>
    auto format_append_into(
      std::string& dest,
      const string_view format_str,
      Args&&... args) const noexcept -> std::string& {
        std::vformat_to(
          std::back_inserter(dest),
          format_str,
          std::make_format_args(std::forward<Args>(args)...));
        return dest;
    }

    template <typename... Args>
    auto format_into(
      std::string& dest,
      const string_view format_str,
      Args&&... args) const noexcept -> std::string& {
        dest.clear();
        return format_append_into(
          dest, format_str, std::forward<Args>(args)...);
    }

    template <typename... Args>
    auto text_buffered(
      std::string& dest,
      const string_view format_str,
      Args&&... args) const noexcept -> bool {
        return bool(this->text_unformatted(
          format_into(dest, format_str, std::forward<Args>(args)...)));
    }

    auto set_config_flags(const c_api::enum_bitfield<imgui_config_flag> flags)
      const noexcept -> bool {
        return this->GetIO()
          .and_then([&](auto& io) -> tribool {
              // NOLINTNEXTLINE(hicpp-signed-bitwise)
              io.ConfigFlags |= static_cast<int>(flags);
              return true;
          })
          .or_false();
    }

    auto unset_config_flags(const c_api::enum_bitfield<imgui_config_flag> flags)
      const noexcept -> bool {
        return this->GetIO()
          .and_then([&](auto& io) -> tribool {
              // NOLINTNEXTLINE(hicpp-signed-bitwise)
              io.ConfigFlags &= ~static_cast<int>(flags);
              return true;
          })
          .or_false();
    }

    void help_marker(const string_view text) const noexcept {
        this->text_unformatted("(?)");
        if(this->begin_item_tooltip().or_false()) {
            this->push_text_wrap_pos(
              this->get_font_size().value_or(13.F) * 35.F);
            this->text_unformatted(text);
            this->pop_text_wrap_pos();
            this->end_tooltip();
        }
    }
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
namespace eagine::guiplus {
//------------------------------------------------------------------------------
export template <typename ApiTraits>
using basic_imgui_api_reference =
  c_api::basic_api_reference<basic_imgui_api<ApiTraits>>;

export using imgui_api_reference = basic_imgui_api_reference<imgui_api_traits>;
} // namespace eagine::guiplus

