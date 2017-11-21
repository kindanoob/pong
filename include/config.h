#ifndef CONFIG_H_
#define CONFIG_H_

#include <SFML/Graphics.hpp>


const int kWindowWidth = 800;
const int kWindowHeight = 600;
const sf::String kWindowTitle = "Pong";
const sf::Vector2i kWindowPosition = sf::Vector2i(100, 100);

const int kBallRadius = 10;
const int kPaddleWidth = 10;
const int kPaddleHeight = 80;
const double kPaddleDy = 0.35;
const double kBallDx = 0.4;
const double kBallDy = 0.4;

const int kResetDuration = 500;//in milliseconds

const unsigned int kMenuTextSize = 30;
const unsigned int kScoreTextSize = 30;
const unsigned int kGameOverTextSize = 40;
const unsigned int kPressAnyKeyTextSize = 25;

const int kMatchWinnerScore = 10;

const int kStartMatchDelay = 750;//in milliseconds


const std::string kFontsPath = "resources/fonts/";
const std::string kTexturesPath = "resources/textures/";


//const int kFieldWidth = kWindowWidth * 0.8;
//const int kFieldHeight = kWindowHeight * 0.8;
const int kFieldWidth = 600;
const int kFieldHeight = 400;
const int kFieldBorderThickness = 0;
const int kOffsetX = (kWindowWidth - kFieldWidth) / 2;
const int kOffsetY = (kWindowHeight - kFieldHeight) / 2;

const double kTimeAdjustmentCoeff =  1 * 800.0;


#endif // CONFIG_H_