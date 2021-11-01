#include <iostream>
#include <iomanip>
#include <random>
#include "game.hpp"
#include "board.hpp"
#include "ship.hpp"

Game::Game() {
    this-> playersBoard = Board();
    this-> NPCBoard = Board();

    this-> playerShipsRemain = 5;
    this-> NPCShipsRemain = 5;

    
}

std::ostream& operator<<(std::ostream& os, const Board board) {
    std::cout << "   A  B  C  D  E  F  G  H  I  J" << std::endl;
    for (int r = Board::A; r <= Board::J; r++) {
        std::cout << r << "  ";
        for (int c = 0; c < 10; c++) {
            std::cout << board.upperBoard[r][c] << "  ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << std::endl;

    std::cout << "   A  B  C  D  E  F  G  H  I  J" << std::endl;
    for (int r = Board::A; r <= Board::J; r++) {
        std::cout << r << "  ";
        for (int c = 0; c < 10; c++) {
            std::cout << board.lowerBoard[r][c] << "  ";
        }
        std::cout << std::endl;
    }

    return os;
}

int main(int argc, char** argv) {
    Game currentGame = Game();
    bool shipPlaced = false;
    bool NPCShipPlaced = currentGame.NPCBoard.placeNPCShips();
    char colChar;
    int col;
    int row;
    char direction;
    char userFireStatus;
    char NPCFireStatus;
    bool gameOver = false;
    Board::direction orientation;
    std::cout << currentGame.playersBoard << std::endl;
    for (int i = 0; i < 5; i++) {
        shipPlaced = false;
        while(! shipPlaced) {
            std::cout << "Place your " << currentGame.playersBoard.boardShips[i].getShipType() << "." << std::endl;
            std::cout << "Select a collumn (A - J):" << std::endl;
            std::cin >> colChar;
            if (colChar >= 'A' && colChar <= 'J') {
                col = colChar - 'A';
            }
            if (colChar >= 'a' && colChar <= 'j') {
                col = colChar - 'a';
            }
            std::cout << "Select a row (0 - 9):" << std::endl;
            std::cin >> row;
            std::cout << "Select a direction ([N]orth, [S]outh, [E]ast, or [W]est):" << std::endl;
            std::cin >> direction;
            if (direction == 'N' || direction == 'n') {
                orientation = Board::direction::NORTH;
            }
            if (direction == 'S' || direction == 's') {
                orientation = Board::direction::SOUTH;
            }
            if (direction == 'E' || direction == 'e') {
                orientation = Board::direction::EAST;
            }
            if (direction == 'W' || direction == 'w') {
                orientation = Board::direction::WEST;
            }
            shipPlaced = currentGame.playersBoard.placeShip(currentGame.playersBoard.boardShips.at(i), row, col, orientation);
            if (! shipPlaced) {
                std::cout << "Your " << currentGame.playersBoard.boardShips[i].getShipType() << " will not fit there, please try again." << std::endl;
            }
        }
        std::cout << currentGame.playersBoard << std::endl;
    }
    while (! gameOver) {
        userFireStatus = currentGame.userFire(currentGame.NPCBoard, currentGame.playersBoard);
        currentGame.notifyUserFire(userFireStatus);
        gameOver = currentGame.gameOverCheck(currentGame.NPCBoard);
        NPCFireStatus = currentGame.NPCFire(currentGame.playersBoard, currentGame.NPCBoard);
        currentGame.notifyNPCFire(NPCFireStatus);
        gameOver = currentGame.gameOverCheck(currentGame.playersBoard);
        std::cout << currentGame.playersBoard << std::endl;
    }
}

char Game::userFire(Board &attacked, Board &attacker) {
    int row = 0;
    char colChar;
    int col = 0;

    std::cout << "What column would you like to fire at?" << std::endl;
    std::cin >> colChar;
    if (colChar >= 'A' && colChar <= 'J') {
                col = colChar - 'A';
            }
            if (colChar >= 'a' && colChar <= 'j') {
                col = colChar - 'a';
            }
    std::cout << "What row would you like to fire at?" << std::endl;
    std::cin >> row;
    char fireStatus = attacked.hitMiss(row, col);
    attacker.upperBoard[row][col] = fireStatus;
    return fireStatus;
    
}

char Game::NPCFire(Board &attacked, Board &attacker) {
    int row = 0;
    char colChar;
    int col = 0;
    char fireStatus = 'a';
    while (fireStatus == 'a') {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0,9);

        row = dis(gen);
        col = dis(gen);
        fireStatus = attacked.hitMiss(row, col);
    }
    attacker.upperBoard[row][col] = fireStatus;
    return fireStatus;
    
}

bool Game::gameOverCheck(Board &checkBoard) {
    int shipsSunk = 0;
    for (int i = 0; i < 5; i++) {
        if (checkBoard.boardShips.at(i).isSunk(checkBoard.boardShips.at(i))) {
            shipsSunk++;
        }
    }
    if (shipsSunk == 5) {
        return true;
    }
    return false;
}

void Game::notifyUserFire(char fireStatus) {
    switch (fireStatus) {
            case 'x':
                std::cout << "Drats! That's a miss!" << std::endl;
                break;
            case 'c':
                if (this->NPCBoard.carrier.isSunk(this->NPCBoard.carrier)){
                    std::cout << "You sank their Carrier!!" << std::endl;
                }
                else {
                    std::cout << "You hit their Carrier!" << std::endl;
                }
                break;
            case 'b':
                if (this->NPCBoard.battleship.isSunk(this->NPCBoard.battleship)){
                    std::cout << "You sank their Battleship!!" << std::endl;
                }
                else {
                    std::cout << "You hit their Battleship!" << std::endl;
                }
                break;
            case 'r':
                if (this->NPCBoard.cruiser.isSunk(this->NPCBoard.cruiser)){
                    std::cout << "You sank their Cruiser!!" << std::endl;
                }
                else {
                    std::cout << "You hit their Cruiser!" << std::endl;
                }
                break;
            case 's':
                if (this->NPCBoard.submarine.isSunk(this->NPCBoard.submarine)){
                    std::cout << "You sank their Submarine!!" << std::endl;
                }
                else {
                    std::cout << "You hit their Submarine!" << std::endl;
                }
                break;
            case 'd':
                if (this->NPCBoard.destroyer.isSunk(this->NPCBoard.destroyer)){
                    std::cout << "You sank their Destroyer!!" << std::endl;
                }
                else {
                    std::cout << "You hit their Destroyer!" << std::endl;
                }
                break;
            case 'e':
                std::cout << "Something went wrong" << std::endl;
                break;

        }
}



void Game::notifyNPCFire(char fireStatus) {
    switch (fireStatus) {
            case 'x':
                std::cout << "They missed!!!" << std::endl;
                break;
            case 'c':
                if (this->playersBoard.carrier.isSunk(this->playersBoard.carrier)){
                    std::cout << "They sank your Carrier..." << std::endl;
                }
                else {
                    std::cout << "They hit your Carrier..." << std::endl;
                }
                break;
            case 'b':
                if (this->playersBoard.battleship.isSunk(this->playersBoard.battleship)){
                    std::cout << "They sank your Battleship..." << std::endl;
                }
                else {
                    std::cout << "They hit your Battleship..." << std::endl;
                }
                break;
            case 'r':
                if (this->playersBoard.cruiser.isSunk(this->playersBoard.cruiser)){
                    std::cout << "They sank your Cruiser..." << std::endl;
                }
                else {
                    std::cout << "they hit your Cruiser..." << std::endl;
                }
                break;
            case 's':
                if (this->playersBoard.submarine.isSunk(this->playersBoard.submarine)){
                    std::cout << "They sank your Submarine..." << std::endl;
                }
                else {
                    std::cout << "They hit your Submarine..." << std::endl;
                }
                break;
            case 'd':
                if (this->playersBoard.destroyer.isSunk(this->playersBoard.destroyer)){
                    std::cout << "They sank your Destroyer..." << std::endl;
                }
                else {
                    std::cout << "They hit your Destroyer..." << std::endl;
                }
                break;
            case 'e':
                std::cout << "Something went wrong..." << std::endl;
                break;

        }
}





