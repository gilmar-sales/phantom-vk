//
// Created by gilmar on 1/19/22.
//

#include "application.h"
#include "log.h"

PHANTOMVK_BEGIN
    Application::Application(const std::string& title, int width, int height) :
            title(title), width(width), height(height) {
        windows.emplace_back(title, width, height);
    }

    Application *Application::Get() {
        static Application *instance = CreateApplication();

        return instance;
    }

    void Application::run() {
        while (!glfwWindowShouldClose(getMainWindow().getNativeWindow())) {
            glfwPollEvents();
        }
    }

    Window &Application::getMainWindow() {
        return *windows.begin();
    }
PHANTOMVK_END
