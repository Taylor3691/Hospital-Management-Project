#include "App.h"

App::App(int argc, char** argv)
    : _argc(argc), _argv(argv) {}

void App::config() {
}

int App::run() {
    QApplication a(_argc, _argv);

    HomeView view;
    view.show();

    return a.exec();
}
