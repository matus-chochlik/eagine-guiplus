/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
export module eagine.guiplus:result;
import eagine.core.types;
import eagine.core.memory;
import eagine.core.c_api;

namespace eagine::guiplus {
//------------------------------------------------------------------------------
export class imgui_no_result_info {
public:
    constexpr auto error_code(const anything) noexcept -> auto& {
        return *this;
    }

    constexpr auto message() const noexcept -> string_view {
        return {"ImGui function not available"};
    }

    constexpr auto set_unknown_error() noexcept -> auto& {
        return *this;
    }
};
//------------------------------------------------------------------------------
export class imgui_result_info {
public:
    constexpr imgui_result_info() noexcept = default;
    constexpr imgui_result_info(imgui_no_result_info) noexcept {}

    explicit constexpr operator bool() const noexcept {
        return true;
    }

    constexpr auto error_code(const unsigned long ec) noexcept -> auto& {
        return *this;
    }

    constexpr auto set_unknown_error() noexcept -> auto& {
        return *this;
    }

    auto message() const noexcept -> string_view {
        return {"unknown ImGui error"};
    }
};
//------------------------------------------------------------------------------
export template <typename Result>
using imgui_no_result = c_api::no_result<Result, imgui_no_result_info>;
//------------------------------------------------------------------------------
export template <typename Result>
using imgui_result = c_api::result<Result, imgui_result_info>;
//------------------------------------------------------------------------------
export template <typename Result>
using imgui_opt_result = c_api::opt_result<Result, imgui_result_info>;
//------------------------------------------------------------------------------
} // namespace eagine::guiplus

