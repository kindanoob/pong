# pong
![pong_screenshot](/resources/sfml_pong.png?raw=true "Pong")
Implementation of the pong game in C++ using SFML

Requirements: 1) C++14, 2) SFML 2.6.1, 3) CMake 3.22.1

The program was tested on Ubuntu 22.04 LTS Jammy, gcc 11.4.0.

Instructions for an out-or-place build:
1) Go to the directory containing the CMakeLists.txt file.
2) Run `cmake -S . -B build`. This will create a `build` directory and put CMake files there.
3) Go to the `build` directory.
4) Build the project (e.g. for Unix makefiles it is achieved by running `make` command in the terminal).
5) Launch the executable file "pong".
6) The goal of the game is to score points. A point is scored when the player fails to return the ball back to the opponent.
7) In the beginning of each round the ball is randomly sent in one of the four possible directions (top-left, bottom-left, top-right, bottom-right).
8) Keyboard controls. Press "Up" key arrow to move your paddle upwards, press "Down" arrow key to move your paddle downwards.
9) The winner of the game is the one who scores five points first.
10) Computer opponent may seem hard to beat at first but should be manageable after some practice.

Reference to the history of the pong game: https://en.wikipedia.org/wiki/Pong

The project is still in the development stage and there are many things yet to be implemented.
