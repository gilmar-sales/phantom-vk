//
// Created by gilmar on 1/19/22.
//

#ifndef PHANTOMVK_APPLICATION_H
#define PHANTOMVK_APPLICATION_H

#include "core/core.h"
#include "core/window.h"

PHANTOMVK_BEGIN

    class Application {
    public:
        Application(const std::string &title, int width, int height);

        ~Application() = default;

        void run();

        Window &getMainWindow();

        static Application *Get();

    private:
        std::vector<Window> windows;
        std::string title;
        int width;
        int height;
    };

    Application *CreateApplication();

PHANTOMVK_END


#endif //PHANTOMVK_APPLICATION_H
