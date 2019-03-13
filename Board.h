//
// Created by mfbut on 3/10/2019.
//

#ifndef BATTLESHIP_BOARD_H
#define BATTLESHIP_BOARD_H
#include <string>
#include <vector>
#include "ShipPlacement.h"
#include "Cell.h"

namespace BattleShip {
class Board {
 public:
  // Constructor to intitialize rows, cols and blankChar
  Board(int numRows, int numCols, char blankChar);
  // Constructor to intitialize rows and cols
  Board(int numRows, int numCols);

  // Returns the bool value of if we can place a ship at a particular position or not
  bool canPlaceShipAt(const ShipPlacement& shipPlacement) const;

  // Returns the total number of rows of the board
  int getNumRows() const;
  // Returns the total number of cols of the board
  int getNumCols() const;

  // Gets the hidden version of the opponents board visible to opposite player
  std::vector<std::string> getHiddenVersion() const;
  // Gets the visible version of the players board visible to current player
  std::vector<std::string> getVisibleVersion() const;

  // Add ship to the current board with a specified ship character
  void AddShip(char shipChar, const ShipPlacement& shipPlacement);
  // Checks if the row and col is in the current window or not
  bool inBounds(int row, int col) const;

  // Returns the cell reference at (i,j)
  Cell& at(int i, int j);
  // Returns the constant cell reference at (i,j)
  const Cell& at(int i, int j) const;


 protected:
  // Returns the boolean value whether the Ship placement is within bounds or not
  bool inBounds(const ShipPlacement& shipPlacement) const;

  // Checks if value is between low and high inclusive of low and high
  bool between(int value, int low, int high) const;
  // Returns the boolean value of whether or not you can place the ship there
  bool spacesAreEmpty(const ShipPlacement& shipPlacement) const;

  //members
  std::vector<std::vector<Cell>> boardState;
  const char blankChar; 
  int numRows, numCols;
};
}

#endif //BATTLESHIP_BOARD_H
