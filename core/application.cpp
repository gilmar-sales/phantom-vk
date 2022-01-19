//
// Created by gilmar on 1/19/22.
//

#include "application.h"
#include <iostream>

namespace ph {
    Application::Application(std::string title, int width, int height) :
            title(std::move(title)), width(width), height(height) {
    }

    Application *Application::Get() {
        static Application* instance = CreateApplication();

        return instance;
    }

    void Application::run() {
        std::cout << title << std::endl;
    }
} //namespace ph
