//
// Created by gilmar on 1/20/22.
//

#include "window.h"

#include <utility>

#include "core/log.h"

PHANTOMVK_BEGIN
    Window::Window(std::string title, int width, int height) :
            title(std::move(title)), width(width), height(height) {
        initialize();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        nativeWindow = glfwCreateWindow(this->width, this->height, this->title.c_str(), nullptr, nullptr);
    }

    Window::~Window() {
        shutdown();
    }

    void Window::initialize() {
        static int glfw = glfwInit();
        if (!glfw) {
            Log::CoreFatal("Cannot initialize GLFW!");
        }

        if (!glfwVulkanSupported())
        {
            Log::CoreFatal("Missing vulkan support!");
        }
    }

    void Window::shutdown() {
        glfwDestroyWindow(nativeWindow);
    }

    GLFWwindow *Window::getNativeWindow() {
        return nativeWindow;
    }

PHANTOMVK_END

