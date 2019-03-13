//
// Created by mfbut on 3/10/2019.
//

#ifndef BATTLESHIP_SHIPPLACEMENT_H
#define BATTLESHIP_SHIPPLACEMENT_H

class ShipPlacement {
 public:
  // Default Constructor
  ShipPlacement();
  // Constructor which
  ShipPlacement(int rowStart, int colStart, int rowEnd, int colEnd);
  int rowStart, colStart;
  int rowEnd, colEnd;
 protected:
  // Throws exception if rowStart > rowEnd or colStart > colEnd
  void normalize();
};

#endif //BATTLESHIP_SHIPPLACEMENT_H
