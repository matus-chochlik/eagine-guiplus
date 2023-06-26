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

export module eagine.guiplus;

namespace eagine::guiplus {
//------------------------------------------------------------------------------
auto basic_imgui_c_api_check_version() noexcept -> bool {
#if EAGINE_HAS_IMGUI
    return IMGUI_CHECKVERSION();
#else
    return false;
#endif
}
//------------------------------------------------------------------------------
} // namespace eagine::guiplus

