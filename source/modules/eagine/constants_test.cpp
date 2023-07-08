
/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <eagine/testing/unit_begin.hpp>
import std;
import eagine.core;
import eagine.guiplus;
//------------------------------------------------------------------------------
void constants_enum_by_name(auto& s) {
    eagitest::case_ test{s, 1, "ImGui enum by name"};
    std::set<eagine::guiplus::imgui_types::enum_type> distinct;

    const auto check{[&](eagine::string_view name) {
        if(auto value{eagine::guiplus::imgui_enum_by_name(name)}) {
            distinct.insert(*value);
        } else {
            test.fail(name);
        }
    }};
    check("window_no_title_bar");
    check("window_no_resize");
    check("window_no_move");
    check("window_no_scrollbar");
    check("window_no_scroll_with_mouse");
    check("window_no_collapse");
    check("window_always_auto_resize");
    check("window_no_background");
    check("window_no_saved_settings");
    check("window_no_mouse_inputs");
    check("window_menu_bar");
    check("window_horizontal_scrollbar");
    check("window_no_focus_on_appearing");
    check("window_no_bring_to_front_on_focus");
    check("window_always_vertical_scrollbar");
    check("window_always_horizontal_scrollbar");
    check("window_always_use_window_padding");
    check("window_no_nav_inputs");
    check("window_no_nav_focus");
    check("window_unsaved_document");
    check("window_no_nav");
    check("window_no_decoration");
    check("window_no_inputs");

    test.check_equal(distinct.size(), 23U, "constant count");
}
//------------------------------------------------------------------------------
auto main(int argc, const char** argv) -> int {
    eagitest::suite test{argc, argv, "constants", 1};
    test.once(constants_enum_by_name);
    return test.exit_code();
}
//------------------------------------------------------------------------------
#include <eagine/testing/unit_end.hpp>
