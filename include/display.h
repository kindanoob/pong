#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "config.h"
#include <SFML/Graphics.hpp>

class Display {
public:
    Display();
    ~Display();
    void Clear();
    void Draw(const sf::Drawable& drawable);
    void DisplayWindow();
    void CheckWindowEvents();
    bool IsOpen();
    void Destroy();    
    void SetVerticalSync(bool b);
    sf::RenderWindow *window_ = nullptr;
    bool is_fullscreen_ = false;

};

#endif // DISPLAY_H_
