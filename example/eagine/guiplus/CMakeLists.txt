# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
add_custom_target(eagine-guiplus-examples ALL)
set_target_properties(
	eagine-guiplus-examples
	PROPERTIES FOLDER "Example/GUIplus"
)

function(eagine_install_example TARGET_NAME)
	install(
		TARGETS ${TARGET_NAME}
		DESTINATION share/eagine/example/guiplus
	)
endfunction()

function(eagine_example_common EXAMPLE_NAME)
	add_executable(
		guiplus-${EXAMPLE_NAME}
		EXCLUDE_FROM_ALL
		"${EXAMPLE_NAME}.cpp"
		${ARGN}
	)
	target_compile_options(
		guiplus-${EXAMPLE_NAME}
		PRIVATE $<$<BOOL:${EAGINE_CLANGXX_COMPILER}>:-Wno-unreachable-code>
	)
	eagine_add_exe_analysis(guiplus-${EXAMPLE_NAME})
	eagine_target_modules(
		guiplus-${EXAMPLE_NAME}
		std
		eagine.core
		eagine.guiplus
	)
	target_link_libraries(
		guiplus-${EXAMPLE_NAME}
		PRIVATE
			EAGine::Deps::GLEW
			EAGine::Deps::GLFW3
	)
	add_dependencies(eagine-guiplus-examples guiplus-${EXAMPLE_NAME})

	set_target_properties(
		guiplus-${EXAMPLE_NAME}
		PROPERTIES FOLDER "Example/GUIplus"
	)
	eagine_install_example(guiplus-${EXAMPLE_NAME})
endfunction()

eagine_example_common(001_imgui_hello)
eagine_example_common(001_imgui_about)
eagine_example_common(002_imgui_demo)
eagine_example_common(003_imgui_time_progress)
eagine_example_common(004_imgui_background)
eagine_example_common(005_imgui_system_load)
eagine_example_common(006_imgui_font_resource)

eagine_embed_target_resources(
	TARGET guiplus-006_imgui_font_resource
	RESOURCES
		Expectativ "${CMAKE_CURRENT_SOURCE_DIR}/expectative.ttf"
	ENABLE_SEARCH
)

