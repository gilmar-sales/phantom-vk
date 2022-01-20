//
// Created by gilmar on 1/20/22.
//

#ifndef PHANTOMVK_WINDOW_H
#define PHANTOMVK_WINDOW_H

#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>

#include "core/core.h"

PHANTOMVK_BEGIN
    class Window {
    public:
        Window(std::string title, int width, int height);

        ~Window();

        GLFWwindow *getNativeWindow();

    private:
        static void initialize();

        void shutdown();

        GLFWwindow *nativeWindow;
        std::string title;
        int width;
        int height;
    };
PHANTOMVK_END

#endif //PHANTOMVK_WINDOW_H
