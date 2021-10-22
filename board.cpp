#include "board.hpp"

Board::Board() {
    Array<Array<char, 10> 10> board;
    this-> carrier = Ship(CARRIER, 5);
    this-> battleship = Ship(BATTLESHIP, 4);
    this-> cruiser = Ship(CRUISER, 3);
    this-> submarine = Ship(SUBMARINE, 3);
    this-> destroyer = Ship(DESTROYER, 2);
}

bool Board::placeShip(Ship &s, int row, int col, direction d) {
    switch(d) {
        case NORTH: 
            for (int r = row; r > (row - s.getNumHoles()); r--) {
                board[col][r] = s.shipChar;
            }
        case WEST:
            for (int c = col; c > (col - s.getNumHoles()); c--) {
                board[c][row] = s.shipChar;
            }
        case EAST:
            for (int c = col; c < (col + s.getNumHoles()); c++) {
                board[c][row] = s.shipChar;
            }
        case SOUTH:
            for (int r = row; r < (row - s.getNumHoles()); r++) {
                board[col][r] = s.shipChar;
            }
    }
}