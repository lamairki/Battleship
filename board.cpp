#include <iostream>
#include <array>
#include <random>
#include "board.hpp"
#include "ship.hpp"

Board::Board() {

    this-> shipsRemain = 5;
    this-> carrier = Ship(Ship::CARRIER, 5, 'c');
    this-> battleship = Ship(Ship::BATTLESHIP, 4, 'b');
    this-> cruiser = Ship(Ship::CRUISER, 3, 'r');
    this-> submarine = Ship(Ship::SUBMARINE, 3, 's');
    this-> destroyer = Ship(Ship::DESTROYER, 2, 'd');
    this-> boardShips.push_back(carrier);
    this-> boardShips.push_back(battleship);
    this-> boardShips.push_back(cruiser);
    this-> boardShips.push_back(submarine);
    this-> boardShips.push_back(destroyer);
    
    for (int r = Board::A; r <= Board::J; r++) {
        for (int c = 0; c < BOARD_WIDTH; c++) {
            upperBoard[r][c] = 'o';
        }
    }

    for (int r = Board::A; r <= Board::J; r++) {
        for (int c = 0; c < BOARD_WIDTH; c++) {
            lowerBoard[r][c] = 'o';
        }
    }


    
}

bool Board::placeShip(const Ship &s, int row, int col, direction d) {
    switch(d) {
        case NORTH: 
            if (row - s.getNumHoles() >= 0) {
                for (int r = row; r > (row - s.getNumHoles()); r--) {
                    if (lowerBoard[r][col] != 'o') {
                        return false;
                    }
                }
                for (int r = row; r > (row - s.getNumHoles()); r--) {
                    this -> lowerBoard[r][col] = s.shipChar;
                }
                return true;
            }
            return false;
        case WEST:
            if (col - s.getNumHoles() >= 0) {
                for (int c = col; c > (col - s.getNumHoles()); c--) {
                    if (lowerBoard[row][c] != 'o') {
                        return false;
                    }
                }
                for (int c = col; c > (col - s.getNumHoles()); c--) {
                    this -> lowerBoard[row][c] = s.getShipChar();
                }
                return true;
            }
            return false;
        case EAST:
            if (col + s.getNumHoles() < 10) {
                for (int c = col; c < (col + s.getNumHoles()); c++) {
                    if (lowerBoard[row][c] != 'o') {
                        return false;
                    }                
                }
                for (int c = col; c < (col + s.getNumHoles()); c++) {
                    this -> lowerBoard[row][c] = s.getShipChar();
                }
                return true;
            }
            return false;
        case SOUTH:
            if (row + s.getNumHoles() < 10) {
                for (int r = row; r < (row + s.getNumHoles()); r++) {
                    if (lowerBoard[r][col] != 'o') {
                        return false;
                    }
                }
                for (int r = row; r < (row + s.getNumHoles()); r++) {
                    this-> lowerBoard[r][col] = s.getShipChar();
                }
                return true;
            }
            return false;
    }
    return false;
}

bool Board::placeNPCShips() {
    bool shipPlaced = false;
    int row = 0;
    int col = 0;
    int dirInt = 0;
    direction cardinal;
    for (int i = 0; i < 5; i++) {
        shipPlaced = false;
        while(! shipPlaced) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(0,9);
            std::random_device rdDir;
            std::mt19937 genDir(rdDir());
            std::uniform_int_distribution<> disDir(0,3);
            row = dis(gen);
            col = dis(gen);
            dirInt = disDir(genDir);
            if (dirInt == 0) {
                cardinal = NORTH;
            }
            if (dirInt == 1) {
                cardinal = EAST;
            }
            if (dirInt == 2) {
				cardinal = WEST;
            }
            if (dirInt == 3) {
                cardinal = SOUTH;
            }
            shipPlaced = this -> placeShip(this -> boardShips.at(i), row, col, cardinal);
        }
        
    }
    return shipPlaced;
}



char Board::hitMiss(int row, int col) {
    char indicatorChar = this -> lowerBoard[row][col];
    switch(indicatorChar) {
        case 'o':
            this -> lowerBoard[row][col] = 'x';
            return 'x';
        case 'c':
            this-> carrier.isHit();
            this -> lowerBoard[row][col] = 'X';
            return 'c';
        case 'b':
            this-> battleship.isHit();
            this -> lowerBoard[row][col] = 'X';
            return 'b';
        case 'r':
            this-> cruiser.isHit();
            this -> lowerBoard[row][col] = 'X';
            return 'r';
        case 's':
            this-> submarine.isHit();
            this -> lowerBoard[row][col] = 'X';
            return 's';
        case 'd':
            this-> destroyer.isHit();
            this -> lowerBoard[row][col] = 'X';
            return 'd';
        case 'x':
            return 'a';
    }
    return 'e';
}
