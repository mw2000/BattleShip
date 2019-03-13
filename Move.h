//
// Created by mfbut on 3/9/2019.
//

#ifndef BATTLESHIP_MOVE_H
#define BATTLESHIP_MOVE_H
#include "Player.h"
#include "Model.h"
#include "View.h"

namespace BattleShip {
class Player;
class AiPlayer;
class HumanPlayer;
class Model;
class View;

class Move {
 public:
  Move();
  // Constructor for Move class which takes in the current player as its property
  Move(Player& moveMaker);
  // Performs the current move
  virtual void enact(Model& model, View& view) = 0;
  // Checks whether the current move is valid or not
  virtual bool isValid() const = 0;

 protected:
  Player& moveMaker;
};
}

#endif //BATTLESHIP_MOVE_H
