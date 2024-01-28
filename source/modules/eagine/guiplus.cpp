/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
/// https://www.boost.org/LICENSE_1_0.txt
///
export module eagine.guiplus;

import eagine.core.memory;
import eagine.core.math;
import eagine.core.resource;
import eagine.core.main_ctx;
export import :config;
export import :enum_types;
export import :objects;
export import :constants;
export import :from_string;
export import :result;
export import :api_traits;
export import :c_api;
export import :api;

namespace eagine::guiplus {
//------------------------------------------------------------------------------
export template <typename ImGuiApiTraits>
class basic_gui_utils : public main_ctx_object {
public:
    basic_gui_utils(main_ctx_parent parent) noexcept
      : main_ctx_object{"GuiUtils", parent} {}

    basic_imgui_api<ImGuiApiTraits> imgui;

    auto add_subtitle_font(
      const string_view file_path,
      float size_pixels) noexcept -> bool;

    auto add_subtitle_font(
      const embedded_resource& resource,
      float size_pixels) noexcept -> bool;

    auto text_overlay(const string_view title, const float x, const float y)
      const noexcept -> bool;

    template <int N, bool V>
        requires(N >= 2 and N <= 3)
    auto text_overlay(
      const string_view title,
      const math::vector<float, N, V>& pos) const noexcept -> bool {
        return text_overlay(title, pos.x(), pos.y());
    }

private:
    guiplus::imgui_font _subtitle_font;
};
//------------------------------------------------------------------------------
template <typename ImGuiApiTraits>
auto basic_gui_utils<ImGuiApiTraits>::add_subtitle_font(
  const string_view file_path,
  float size_pixels) noexcept -> bool {
    _subtitle_font = imgui.add_font_from_file_ttf(file_path, size_pixels);
    return bool(_subtitle_font);
}
//------------------------------------------------------------------------------
template <typename ImGuiApiTraits>
auto basic_gui_utils<ImGuiApiTraits>::add_subtitle_font(
  const embedded_resource& resource,
  float size_pixels) noexcept -> bool {
    _subtitle_font = imgui.add_font_from_resource(
      main_context(), "Subtitle", resource, size_pixels);
    return bool(_subtitle_font);
}
//------------------------------------------------------------------------------
template <typename ImGuiApiTraits>
auto basic_gui_utils<ImGuiApiTraits>::text_overlay(
  const string_view title,
  const float x,
  const float y) const noexcept -> bool {
    return imgui.text_overlay(title, x, y);
}
//------------------------------------------------------------------------------
export using gui_utils = basic_gui_utils<imgui_api_traits>;
//------------------------------------------------------------------------------
} // namespace eagine::guiplus

