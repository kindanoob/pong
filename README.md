# pong
Implementation of the pong game in C++ using SFML

Requirements: 1) C++11, 2) SFML 2.4.2

The program was tested on Ubuntu 16.04 LTS Xenial, gcc 5.4.0.

Instructions:
1) Update the makefile with the correct location of SFML_DIR (that is, the directory where SFML is located on your computer).
2) Build the project, using "make" command in the terminal.
3) Launch the executable file "pong".
4) The goal of the game is to score points. A point is scored when the player fails to return the ball back to the opponent.
5) In the beginning of each round the ball is randomly sent in one of the four possible directions (top-left, bottom-left, top-right, bottom-right).
6) Keyboard controls. Press "Up" key arrow to move your paddle upwards, press "Down" arrow key to move your paddle downwards.
7) The winner of the game is the one who scores ten points first.
8) Computer opponent may seem hard to beat at first but should be manageable after some practice.

Reference to the history of the pong game: https://en.wikipedia.org/wiki/Pong
