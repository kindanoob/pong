#ifndef CONFIG_H_
#define CONFIG_H_

#include <SFML/Graphics.hpp>


constexpr int kWindowWidth = 800;
constexpr int kWindowHeight = 600;
const sf::String kWindowTitle = "Pong";
const sf::Vector2i kWindowPosition = sf::Vector2i(100, 100);

constexpr int kBallRadius = 10;
constexpr int kPaddleWidth = 10;
constexpr int kPaddleHeight = 80;
constexpr double kPaddleDy = 0.35;
constexpr double kBallDx = 0.4;
constexpr double kBallDy = 0.4;

constexpr int kResetDuration = 500;// in milliseconds

constexpr unsigned int kMenuTextSize = 30;
constexpr unsigned int kScoreTextSize = 30;
constexpr unsigned int kGameOverTextSize = 40;
constexpr unsigned int kPressAnyKeyTextSize = 25;

constexpr int kMatchWinnerScore = 5;

constexpr int kStartMatchDelay = 750;// in milliseconds


const std::string kFontsPath = "resources/fonts/";
const std::string kTexturesPath = "resources/textures/";


//const int kFieldWidth = kWindowWidth * 0.8;
//const int kFieldHeight = kWindowHeight * 0.8;
constexpr int kFieldWidth = 600;
constexpr int kFieldHeight = 400;
constexpr int kFieldBorderThickness = 0;
constexpr int kOffsetX = (kWindowWidth - kFieldWidth) / 2;
constexpr int kOffsetY = (kWindowHeight - kFieldHeight) / 2;

constexpr double kTimeAdjustmentCoeff =  1 * 800.0;


#endif // CONFIG_H_