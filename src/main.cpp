#include <iostream>
#include <new>
#include <SFML/Graphics.hpp>
#include "application.h"



int main() {
    Application *app = new Application();
    app->Run();
    delete app;
    return 0;
}
