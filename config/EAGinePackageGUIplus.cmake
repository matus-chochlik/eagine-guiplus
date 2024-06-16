#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#  https://www.boost.org/LICENSE_1_0.txt
#
# Package specific options
#  Debian
#   Dependencies
set(CXX_RUNTIME_PKGS "libc6,libc++1-17")
set(CPACK_DEBIAN_GUIPLUS-EXAMPLES_PACKAGE_DEPENDS "${CXX_RUNTIME_PKGS},libsystemd0,zlib1g")
set(CPACK_DEBIAN_GUIPLUS-DEV_PACKAGE_DEPENDS "eagine-core-dev (>= @EAGINE_VERSION@)")
#   Descriptions
set(CPACK_DEBIAN_GUIPLUS-EXAMPLES_DESCRIPTION "EAGine GUIplus examples.")
set(CPACK_DEBIAN_GUIPLUS-DEV_DESCRIPTION "C++ wrapper for ImGui.")

