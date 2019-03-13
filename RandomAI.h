//
// Created by mfbut on 3/11/2019.
//

#ifndef BATTLESHIP_RANDOMAI_H
#define BATTLESHIP_RANDOMAI_H
#include <vector>
#include <algorithm>
#include "AiPlayer.h"

namespace BattleShip {
class RandomAI  : public AiPlayer{
 public:
  // Constructor for Random AI with game attributes and a view
  RandomAI(const GameAttributes& gameAttributes, View& view);
  // Gets the AI's move
  virtual std::unique_ptr<Move> getMove() override;
 protected:
  std::vector<std::pair<int, int>> firingLocations;
};
}

#endif //BATTLESHIP_RANDOMAI_H
