//
// Created by mfbut on 3/10/2019.
//

#ifndef BATTLESHIP_ENDGAME_H
#define BATTLESHIP_ENDGAME_H
#include "Move.h"

namespace BattleShip{
class EndGame : public Move{
 public:
  // Constructor for End game with the current player
  EndGame(Player& moveMaker);
  // Performs the end of game logic
  virtual void enact(Model& model, View& view) override;
  // Checks if the end of game is valid or not
  virtual bool isValid() const override;
};
}

#endif //BATTLESHIP_ENDGAME_H
