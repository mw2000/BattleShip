//
// Created by mfbut on 3/9/2019.
//

#ifndef BATTLESHIP_STANDARDVIEW_H
#define BATTLESHIP_STANDARDVIEW_H
#include <iostream>
#include <utility>
#include "PlayerConfiguration.h"
#include "View.h"

namespace BattleShip  {
class StandardView : public View{
 public:
  // Default Constructor
  StandardView();
  // Constructor for initializing in and out stream
  StandardView(std::istream& in, std::ostream& out);
  // Creates a player configuration and returns it
  virtual PlayerConfiguration getPlayerConfiguration() override;
  // Returns the given player's name
  virtual std::string getPlayerName(int i) override;
  virtual ShipPlacement getShipPlacement(const Player& player, char shipChar, int shipLen) override;
  // Updates board after placing a ship
  virtual void updateShipPlacementView(const Player& player) override;
  // Gets the attackers firing coordinates
  virtual std::pair<int, int> getFiringCoordinate(const BattleShip::Player& attacker) override;
  // Print the winner of the game
  virtual void showWinner(const Player& winner) override;
  // Prints the result of the attack
  virtual void showResultOfAttack(const BattleShip::Player& attacker,
                                    const BattleShip::AttackResult& attackResult) override;
  
  virtual void showPlayersBoard(const Player& player) override;
  // Show a player's placement board
  virtual void showPlacementBoard(const Player& player) override;
 protected:
  // Print the board
  void printBoard(const std::vector<std::string>& board);
  // Print the placement board visible to the user
  void printBoardAsVisible(const Board& board);
  // Print the firing board not visible to the user
  void printBoardAsObscured(const Board& board);
 public:
  // Returns the Ai Choice via swtich case
  virtual int getAiChoice() override;
 protected:
  // Clear the given input by the user
  void clearInput();

  std::istream& in;
  std::ostream& out;
};
}

#endif //BATTLESHIP_STANDARDVIEW_H
