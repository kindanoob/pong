# pong

Implementation of the pong game in C++ using SFML

Requirements: 1) C++11, 2) SFML 2.3.2

The program was tested on Ubuntu 16.04 LTS Xenial, gcc 5.4.0.

Instructions:

1) For an out-of-place build: create a build directory (mkdir build)
2) Change directory to the created build directory (cd build)
3) Create build files with CMake in the build directory (cmake ..)
4) Build the project (e.g. for Unix makefiles it is achieved by using "make" command in the terminal)
5) Launch the executable file "pong".
6) The goal of the game is to score points. A point is scored when the player fails to return the ball back to the opponent.
7) In the beginning of each round the ball is randomly sent in one of the four possible directions (top-left, bottom-left, top-right, bottom-right).
8) Keyboard controls. Press "Up" key arrow to move your paddle upwards, press "Down" arrow key to move your paddle downwards.
9) The winner of the game is the one who scores ten points first.
10) Computer opponent may seem hard to beat at first but should be manageable after some practice.

Reference to the history of the pong game: https://en.wikipedia.org/wiki/Pong

The project is still in the development stage and there are many things yet to be implemented.
