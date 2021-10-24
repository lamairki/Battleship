#include "board.hpp"
#include "Ship.hpp"

Board::Board() {
    Array<Array<char, 10> 10> board;
    for (int r = Board::A; r <= Board::J; r++) {
        for (int c = 0; c <= BOARD_WIDTH; c++) {
            board[r][c] = 'o';
        }
    }
    this-> shipsRemain = 5;
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
            return true;
        case WEST:
            for (int c = col; c > (col - s.getNumHoles()); c--) {
                board[c][row] = s.shipChar;
            }
            return true;
        case EAST:
            for (int c = col; c < (col + s.getNumHoles()); c++) {
                board[c][row] = s.shipChar;
            }
            return true;
        case SOUTH:
            for (int r = row; r < (row + s.getNumHoles()); r++) {
                board[col][r] = s.shipChar;
            }
            return true;
    }
    return false;
}

char Board::hitMiss(int row, int col) {
    char indicatorChar = board[row][col];
    switch(indicatorChar) {
        case 'o':
            board[row][col] = 'x';
            return 'x';
        case 'c':
            this-> carrier.isHit();
            return 'c';
        case 'b':
            this-> battleship.isHit();
            return 'b';
        case 'r':
            this-> cruiser.isHit();
            return 'c';
        case 's':
            this-> submarine.isHit();
            return 's';
        case 'd':
            this-> destroyer.isHit();
            return 'd';
    }
}
