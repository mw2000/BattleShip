//
// Created by mfbut on 3/10/2019.
//

#ifndef BATTLESHIP_CELL_H
#define BATTLESHIP_CELL_H

namespace BattleShip {
class Cell {
 public:
  
  // Cell Constructor for setting the content of the Cell, the hidden marker, the hit marker and the miss Marker
  Cell(char contents, const char hiddenMarker, const char hitMarker, const char missMarker);
  // Cell Constructor for setting the content of the Cell and everything else is default
  Cell(char contents);

  // Return the content of the cell
  char getContents() const;
  // Sets the content of the cell
  void setContents(char contents);

  char getContentsIfHidden() const;
  char getContentsIfVisible() const;

  // Returns whether the cell has been fired at or not
  bool HasBeenFiredAt() const;
  // Sets the cell has been firedAt boolean
  void setHasBeenFiredAt(bool hasBeenFiredAt);

  // Returns whether the cell has a ship or not
  bool containsShip()const;

 protected:
  char contents;
  bool firedAt;
  const char hiddenMarker;
  const char hitMarker;
  const char missMarker;

};
}

#endif //BATTLESHIP_CELL_H
