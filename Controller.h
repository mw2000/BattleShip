//
// Created by mfbut on 3/9/2019.
//

#ifndef BATTLESHIP_CONTROLLER_H
#define BATTLESHIP_CONTROLLER_H
#include <memory>
#include <string>
#include "Model.h"
#include "View.h"
#include "Player.h"
#include "Move.h"
namespace BattleShip {
class Controller {
 public:
  Controller();
  // Sets up the game with a game configuration file and a seed
  void setupGame(const std::string& GameConfigurationFile, int seed);
  // Sets up the game with a game configuration file and a seed
  void setupGame(const std::string& GameConfigurationFile);
  // Sets up the game with default configurations
  void setupGame();
  // Starts the game
  void playGame();

 protected:
  bool hasBeenSetUp;
  Model model;
  std::unique_ptr<View> view;

};
}

#endif //BATTLESHIP_CONTROLLER_H
