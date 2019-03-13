//
// Created by mfbut on 3/9/2019.
//

#ifndef BATTLESHIP_MODEL_H
#define BATTLESHIP_MODEL_H


#include <vector>
#include <memory>
#include "View.h"
#include "Player.h"
#include "GameAttributes.h"
namespace BattleShip {
class Move;
class Player;
class View;
class Model {

 public:
  Model();
  // Get the currrent attacking player
  Player& getAttackingPlayer();
  // Get the currrent attacking player as constant
  const Player& getAttackingPlayer() const;

  // Get the currrent defending player
  Player& getDefendingPlayer();
  // Get the currrent defending player as a constant
  const Player& getDefendingPlayer() const;

  // Checks whether the game is over or not
  bool isGameOver() const;
  // Switches the players turn
  void changeTurn();
  // Loads the game configuration from a filepath
  void loadGameConfigurationFromFile(const std::string& gameConfigurationFile);
  template <typename PlayerType>
  // Adds a player to the game
  void addPlayer(View& view);

  // Ends the game
  void endGame();
  // Gets the next move of either of the players
  std::unique_ptr<Move> getNextMove();

  // Gets the winner
  Player& getWinner();

  // Set the players as each other's opponents
  void SetOpponents();

  // Gets the players vector
  std::vector<std::unique_ptr<Player>> getPlayers();


 protected:
  GameAttributes gameAttributes;
  std::vector<std::unique_ptr<Player>> players;
  int playerTurn;
  bool forcedGameOver;
};

template<typename PlayerType>
void BattleShip::Model::addPlayer(View& view) {
  std::unique_ptr<PlayerType> player = std::make_unique<PlayerType>(gameAttributes, view);
  player->initializeName();
  player->placeShips();
  players.push_back(std::move(player));
}

}
#endif //BATTLESHIP_MODEL_H
