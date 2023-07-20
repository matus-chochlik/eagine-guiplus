# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

eagine_add_module(
	eagine.guiplus PARTITION config
	IMPORTS
		eagine.core.types
		eagine.core.math
	PRIVATE_INCLUDE_DIRECTORIES
		"${CMAKE_CURRENT_SOURCE_DIR}/../../../submodules/imgui"
)

eagine_add_module(
	eagine.guiplus PARTITION enum_types
	IMPORTS
		config
		eagine.core.types
		eagine.core.identifier
		eagine.core.c_api
)

eagine_add_module(
	eagine.guiplus PARTITION objects
	IMPORTS
		config
		eagine.core.types
		eagine.core.identifier
		eagine.core.c_api
	PRIVATE_INCLUDE_DIRECTORIES
		"${CMAKE_CURRENT_SOURCE_DIR}/../../../submodules/imgui"
)

eagine_add_module(
	eagine.guiplus PARTITION result
	IMPORTS
		eagine.core.types
		eagine.core.memory
		eagine.core.c_api
)

eagine_add_module(
	eagine.guiplus PARTITION api_traits
	IMPORTS
		result
		eagine.core.memory
		eagine.core.c_api
)

eagine_add_module(
	eagine.guiplus PARTITION c_api
	IMPORTS
		config result
		eagine.core.types
		eagine.core.memory
		eagine.core.c_api
	PRIVATE_INCLUDE_DIRECTORIES
		"${CMAKE_CURRENT_SOURCE_DIR}/../../../submodules/imgui"
)

eagine_add_module(
	eagine.guiplus PARTITION constants
	IMPORTS
		config enum_types c_api
		eagine.core.types
		eagine.core.memory
		eagine.core.valid_if
		eagine.core.c_api
	PRIVATE_INCLUDE_DIRECTORIES
		"${CMAKE_CURRENT_SOURCE_DIR}/../../../submodules/imgui"
)

eagine_add_module(
	eagine.guiplus PARTITION from_string
	IMPORTS
		enum_types constants
		eagine.core.types
		eagine.core.memory
		eagine.core.string
		eagine.core.valid_if
)

eagine_add_module(
	eagine.guiplus PARTITION api
	IMPORTS
		config enum_types
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
	SOURCES
		constants
		c_api
	IMPORTS
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
