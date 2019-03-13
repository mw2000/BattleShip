//
// Created by mfbut on 3/10/2019.
//

#ifndef BATTLESHIP_ATTACK_H
#define BATTLESHIP_ATTACK_H
#include "Move.h"
#include "Player.h"
namespace BattleShip {
class Attack : public Move {
 public:
  Attack(BattleShip::Player& attacker, int row, int col);
  // Performs the attack
  virtual void enact(Model& model, View& view) override;
  // Returns if the attack is valid or not
  virtual bool isValid() const override;
  // Returns the row of the attack
  const int getRow() const;
  // Returns the col of the attack
  const int getCol() const;
 protected:
  const int row, col;
  BattleShip::Player& attacker;

};
}

#endif //BATTLESHIP_ATTACK_H
