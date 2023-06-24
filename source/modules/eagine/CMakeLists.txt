# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

eagine_add_module(
	eagine.guiplus
	SOURCES
	IMPORTS
		eagine.core.memory
)

eagine_add_module_tests(
	eagine.guiplus
	UNITS
	IMPORTS
		eagine.core
)