//
// Created by mfbut on 3/9/2019.
//

#ifndef BATTLESHIP_GAMEATTRIBUTES_H
#define BATTLESHIP_GAMEATTRIBUTES_H
#include <istream>
#include <map>
namespace BattleShip {
class GameAttributes {
 public:
  // Constructor to intialize GameAttributes with the default configuration located in DefaultConfiguration.txt
  GameAttributes();
  // Constructor to intialize GameAttributes with given number of rows and cols
  GameAttributes(int numRows, int numCols);
  // Constructor to intialize GameAttributes with given number of rows and cols through an input stream
  GameAttributes(std::istream& in);

  // Returns the number of rows in the board
  int getNumRows() const;
  // Sets the number of rows in the board
  void setNumRows(int numRows);

  // Returns the number of cols in the board
  int getNumCols() const;
  // Sets the number of cols in the board
  void setNumCols(int numCols);

  // Returns the size of a ship specified by a character
  int getShipSize(const char ShipChar) const;
  // Returns the map relating the names of the ship to their length
  const std::map<char, int>& getShipAttributes() const;

 private:
  int numRows, numCols;
  std::map<char, int> shipAttributes;
};

std::istream& operator>>(std::istream& in, GameAttributes& gameAttributes);

}
#endif //BATTLESHIP_GAMEATTRIBUTES_H
