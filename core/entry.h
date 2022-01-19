//
// Created by gilmar on 1/19/22.
//

#ifndef PHANTOMVK_ENTRY_H
#define PHANTOMVK_ENTRY_H

#include "application.h"

int main(int argc, char** argv) {
    auto app = ph::Application::Get();

    app->run();

    return 0;
}

#endif //PHANTOMVK_ENTRY_H
