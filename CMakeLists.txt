# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
# https://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 3.27)

project(
	EAGineGUIplus
	LANGUAGES CXX
	HOMEPAGE_URL https://github.com/matus-chochlik/eagine-guiplus
)
if(NOT EAGINE_CORE_ROOT)
	set(EAGINE_CORE_ROOT ${PROJECT_SOURCE_DIR}/submodules/eagine-core)
endif()
if(NOT EAGINE_CORE_BINARY_ROOT)
	set(EAGINE_CORE_BINARY_ROOT ${PROJECT_BINARY_DIR}/submodules/eagine-core)
endif()
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/config)
list(APPEND CMAKE_MODULE_PATH ${EAGINE_CORE_ROOT}/config)
file(STRINGS "${EAGINE_CORE_ROOT}/VERSION" EAGINE_VERSION)

add_subdirectory(submodules)

include(EAGineCoreCommon)
find_package(EAGineGLEW)
find_package(EAGineGLFW3)

add_library(
	imgui
	submodules/imgui/imgui.cpp
	submodules/imgui/imgui_draw.cpp
	submodules/imgui/imgui_widgets.cpp
	submodules/imgui/imgui_tables.cpp
	submodules/imgui/imgui_demo.cpp
	submodules/imgui/backends/imgui_impl_glfw.cpp
	submodules/imgui/backends/imgui_impl_opengl3.cpp
)
target_include_directories(
	imgui
	PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/submodules/imgui>"
)
if(UNIX AND NOT APPLE)
	target_link_libraries(
		imgui
		PUBLIC dl
	)
endif()

add_subdirectory(source)
add_subdirectory(example)
add_subdirectory(deploy)
