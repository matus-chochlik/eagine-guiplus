# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
# https://www.boost.org/LICENSE_1_0.txt

eagine_add_module(
	eagine.guiplus
	COMPONENT guiplus-dev
	PARTITION config
	IMPORTS
		std
		eagine.core.types
		eagine.core.math
	PRIVATE_INCLUDE_DIRECTORIES
		"${CMAKE_CURRENT_SOURCE_DIR}/../../../submodules/imgui"
)

eagine_add_module(
	eagine.guiplus
	COMPONENT guiplus-dev
	PARTITION enum_types
	IMPORTS
		std config
		eagine.core.types
		eagine.core.identifier
		eagine.core.c_api
)

eagine_add_module(
	eagine.guiplus
	COMPONENT guiplus-dev
	PARTITION objects
	IMPORTS
		std config
		eagine.core.types
		eagine.core.identifier
		eagine.core.c_api
	PRIVATE_INCLUDE_DIRECTORIES
		"${CMAKE_CURRENT_SOURCE_DIR}/../../../submodules/imgui"
)

eagine_add_module(
	eagine.guiplus
	COMPONENT guiplus-dev
	PARTITION result
	IMPORTS
		std
		eagine.core.types
		eagine.core.memory
		eagine.core.c_api
)

eagine_add_module(
	eagine.guiplus
	COMPONENT guiplus-dev
	PARTITION api_traits
	IMPORTS
		std result
		eagine.core.memory
		eagine.core.c_api
)

eagine_add_module(
	eagine.guiplus
	COMPONENT guiplus-dev
	PARTITION c_api
	IMPORTS
		std config result
		eagine.core.types
		eagine.core.memory
		eagine.core.c_api
	PRIVATE_INCLUDE_DIRECTORIES
		"${CMAKE_CURRENT_SOURCE_DIR}/../../../submodules/imgui"
)

eagine_add_module(
	eagine.guiplus
	COMPONENT guiplus-dev
	PARTITION constants
	IMPORTS
		std config
		enum_types c_api
		eagine.core.types
		eagine.core.memory
		eagine.core.valid_if
		eagine.core.c_api
	PRIVATE_INCLUDE_DIRECTORIES
		"${CMAKE_CURRENT_SOURCE_DIR}/../../../submodules/imgui"
)

eagine_add_module(
	eagine.guiplus
	COMPONENT guiplus-dev
	PARTITION from_string
	IMPORTS
		std enum_types constants
		eagine.core.types
		eagine.core.memory
		eagine.core.string
		eagine.core.valid_if
)

eagine_add_module(
	eagine.guiplus
	COMPONENT guiplus-dev
	PARTITION api
	IMPORTS
		std config enum_types
		api_traits result
		c_api objects constants
		eagine.core.types
		eagine.core.memory
		eagine.core.string
		eagine.core.utility
		eagine.core.runtime
		eagine.core.math
		eagine.core.c_api
		eagine.core.resource
		eagine.core.main_ctx
)

eagine_add_module(
	eagine.guiplus
	COMPONENT guiplus-dev
	SOURCES
		constants
		c_api
	IMPORTS
		std
		eagine.core.types
		eagine.core.memory
		eagine.core.math
		eagine.core.container
		eagine.core.valid_if
		eagine.core.resource
		eagine.core.main_ctx
	PRIVATE_INCLUDE_DIRECTORIES
		"${CMAKE_CURRENT_SOURCE_DIR}/../../../submodules/imgui"
	PRIVATE_LINK_LIBRARIES
		imgui
		EAGine::Deps::GLFW3
	INTERFACE_LINK_LIBRARIES
		imgui
)

eagine_add_module_tests(
	eagine.guiplus
	UNITS
		constants
	IMPORTS
		eagine.core
)

eagine_add_license(guiplus-dev)
eagine_add_debian_changelog(guiplus-dev)

eagine_add_package_property(
	guiplus-dev
	GENERATOR DEBIAN
	VARIABLE PACKAGE_DEPENDS
	VALUE "eagine-core-dev (>= @EAGINE_VERSION@)")

eagine_add_package_property(
	guiplus-dev
	GENERATOR DEBIAN
	VARIABLE DESCRIPTION
	VALUE "C++ wrapper for ImGUI.")

