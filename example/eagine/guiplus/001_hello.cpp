/// @example guiplus/001_hello.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <GLFW/glfw3.h>

import std;
import eagine.core;
import eagine.guiplus;

static void run_loop(GLFWwindow* window, int width, int height) {
    using namespace eagine::guiplus;
    (void)window;
    (void)width;
    (void)height;

    glClearColor(0.3F, 0.3F, 0.9F, 0.0F);
    glClearDepth(1);

    while(true) {
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

        glfwSwapBuffers(window);
    }
}

static void init_and_run() {
    if(not glfwInit()) {
        throw std::runtime_error("GLFW initialization error");
    } else {
        const auto ensure_glfw_cleanup = eagine::finally(glfwTerminate);

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

        int width = 800, height = 600;

        GLFWwindow* window =
          glfwCreateWindow(width, height, "GUIplus example", nullptr, nullptr);

        if(not window) {
            throw std::runtime_error("Error creating GLFW window");
        } else {
            glfwMakeContextCurrent(window);
            // const eagine::guiplus::api_initializer gui_api_init;
            glGetError();
            run_loop(window, width, height);
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
