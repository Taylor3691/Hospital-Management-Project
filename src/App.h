#ifndef APP_H
#define APP_H

#include <QApplication>
#include "views/HomeView.h"

class App {
private:
    int _argc;
    char** _argv;

public:
    App(int argc, char** argv);

public:
    int run();
};

#endif // !APP_H
