/// @example guiplus/001_imgui_hello.cpp
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

namespace eagine {

static void run_loop(main_ctx& ctx, GLFWwindow* window, int width, int height) {
    using eagine::ok;
    using namespace eagine::guiplus;

    glClearColor(0.3F, 0.9F, 0.3F, 0.0F);
    glClearDepth(1);

    const imgui_api gui{ctx};

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
                if(gui.begin("example", show_window).or_false()) {
                    gui.text_unformatted("Hello World!");
                    gui.new_line();
                    if(gui.button("Bye!").or_true()) {
                        show_window = false;
                    }
                    gui.same_line();
                    gui.help_marker("closes this window");
                    gui.end();
                }
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

static void init_and_run(main_ctx& ctx) {
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
            run_loop(ctx, window, width, height);
        } else {
            throw std::runtime_error("Error creating GLFW window");
        }
    }
}

auto main(main_ctx& ctx) -> int {
    try {
        init_and_run(ctx);
        return 0;
    } catch(const std::runtime_error& sre) {
        std::cerr << "Runtime error: " << sre.what() << std::endl;
    } catch(const std::exception& se) {
        std::cerr << "Unknown error: " << se.what() << std::endl;
    }
    return 1;
}

} // namespace eagine

auto main(int argc, const char** argv) -> int {
    return eagine::default_main(argc, argv, eagine::main);
}
