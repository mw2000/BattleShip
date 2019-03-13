//
// Created by mfbut on 3/9/2019.
//

#ifndef BATTLESHIP_PLAYER_H
#define BATTLESHIP_PLAYER_H
#include <functional>
#include <string>
#include <memory>
#include <map>
#include "Move.h"
#include "GameAttributes.h"
#include "View.h"
#include "Board.h"
#include "AttackResult.h"

namespace BattleShip {
class View; //forward declaration
class Move;
class Model;
class Player {
 public:
  Player(const GameAttributes& gameAttributes, View& view);

  // Returns the player name
  const std::string& getName() const;
  // Sets the player name 
  void setName(const std::string& name);
  // Returns the constant board 
  const Board& getBoard() const;
  // Returns the board
  Board& getBoard();
  // Returns the player Id
  const int getId() const;

  //for hashing
  bool operator==(const Player& rhs) const;
  bool operator!=(const Player& rhs) const;

  virtual std::unique_ptr<BattleShip::Move> getMove() = 0;
  //Function to place the ships in the respective positions
  virtual void placeShips() = 0;
  virtual void initializeName() = 0;
  // Returns the boolean value of whether all of a players ships have sunken or not
  virtual bool allShipsSunk() const;

  // Returns the result of an attack by the player at a particular row and col
  virtual BattleShip::AttackResult fireAt(int row, int col);

  // Gets the current player's opponent
  Player& getOpponent();
  // Gets the current player's opponent as a constant
  const Player& getOpponent() const;
  void setOpponent(Player& opponent);

 protected:
  // Returns the boolean value of whether a particular ship of the player has been hit or not
  virtual bool hit(char shipChar);
  static int num_instances;
  const int id;
  std::string name;
  std::map<char, int> shipHealths;
  View& view;
  Board board;
  Player* opponent;
};

}

namespace std{
template <>
class hash<BattleShip::Player&>{
  std::size_t operator()(const BattleShip::Player& player) const{
    return player.getId();
  }
};
}


#endif //BATTLESHIP_PLAYER_H
