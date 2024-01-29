/// @example guiplus/001_imgui_about.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
/// https://www.boost.org/LICENSE_1_0.txt
///

#include <GLFW/glfw3.h>

import std;
import eagine.core;
import eagine.guiplus;

static void run_loop(GLFWwindow* window, int width, int height) {
    using eagine::ok;
    using namespace eagine::guiplus;

    glClearColor(0.3F, 0.3F, 0.9F, 0.0F);
    glClearDepth(1);

    const imgui_api gui;

    if(gui.create_context) {
        if(const ok context{gui.create_context()}) {
            const auto cleanup_context{gui.destroy_context.raii(context)};
            gui.glfw_init_for_opengl(window, true);
            const auto cleanup_glfw{gui.glfw_shutdown.raii()};
            gui.opengl3_init("#version 150");
            const auto cleanup_opengl{gui.opengl3_shutdown.raii()};

            bool show_window = true;
            while(show_window) {
                glfwPollEvents();

                if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
                    glfwSetWindowShouldClose(window, 1);
                    break;
                }

                if(glfwWindowShouldClose(window)) {
                    break;
                }

                int new_width, new_height;
                glfwGetWindowSize(window, &new_width, &new_height);
                if((width != new_width) or (height != new_height)) {
                    width = new_width;
                    height = new_height;
                }

                glViewport(0, 0, width, height);
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                gui.opengl3_new_frame();
                gui.glfw_new_frame();
                gui.new_frame();
                gui.show_about_window(show_window);
                gui.end_frame();
                gui.render();
                if(const ok draw_data{gui.get_draw_data()}) {
                    gui.opengl3_render_draw_data(draw_data);
                }

                glfwSwapBuffers(window);
            }
        }
    } else {
        std::cout << "missing required API" << std::endl;
    }
}

static void init_and_run() {
    if(not glfwInit()) {
        throw std::runtime_error("GLFW initialization error");
    } else {
        const auto ensure_glfw_cleanup{eagine::finally(glfwTerminate)};

        glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);
        glfwWindowHint(GLFW_RED_BITS, 8);
        glfwWindowHint(GLFW_BLUE_BITS, 8);
        glfwWindowHint(GLFW_GREEN_BITS, 8);
        glfwWindowHint(GLFW_ALPHA_BITS, 0);
        glfwWindowHint(GLFW_DEPTH_BITS, 24);
        glfwWindowHint(GLFW_STENCIL_BITS, 0);

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        int width = 1024, height = 768;

        if(auto window{glfwCreateWindow(
             width, height, "GUIplus ImGui demo", nullptr, nullptr)}) {
            glfwMakeContextCurrent(window);
            run_loop(window, width, height);
        } else {
            throw std::runtime_error("Error creating GLFW window");
        }
    }
}

auto main() -> int {
    try {
        init_and_run();
        return 0;
    } catch(const std::runtime_error& sre) {
        std::cerr << "Runtime error: " << sre.what() << std::endl;
    } catch(const std::exception& se) {
        std::cerr << "Unknown error: " << se.what() << std::endl;
    }
    return 1;
}
