//
// Created by gilmar on 1/19/22.
//

#ifndef PHANTOMVK_APPLICATION_H
#define PHANTOMVK_APPLICATION_H

#include <string>

namespace ph {
    class Application {
    public:
        Application(std::string title, int width, int height);
        ~Application() = default;

        void run();

        static Application* Get();

    private:
        std::string title;
        int width;
        int height;
    };

    Application* CreateApplication();
} //namespace ph


#endif //PHANTOMVK_APPLICATION_H
