#include <iostream>
#include <new>
#include "display.h"


Display::Display() {
    std::cout << "Display()" << std::endl;
    window_ = new sf::RenderWindow(sf::VideoMode(kWindowWidth, kWindowHeight), kWindowTitle, sf::Style::Default);
    window_->setPosition(kWindowPosition);
    is_fullscreen_ = false;
    SetVerticalSync(true);
}

Display::~Display() {
    std::cout << "~Display()" << std::endl;
}


void Display::Clear() {
    window_->clear(sf::Color::White);
};

void Display::Draw(const sf::Drawable& drawable) {
    window_->draw(drawable);
}

void Display::DisplayWindow() {
    window_->display();
};

void Display::CheckWindowEvents() {
    sf::Event event;
    while (window_->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window_->close();            
        }
    }
};

bool Display::IsOpen() {
    return window_->isOpen();
};


void Display::Destroy() {
    delete this;
}


void Display::SetVerticalSync(bool b) {
    window_->setVerticalSyncEnabled(b);
}
