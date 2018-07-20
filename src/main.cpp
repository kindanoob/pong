#include "application.h"
#include <iostream>
#include <SFML/Graphics.hpp>




int main() {
    Application *app = new Application();
    app->Run();
    delete app;
    return 0;
}
