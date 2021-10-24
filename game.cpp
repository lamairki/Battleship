#include <iostream>
#include "game.hpp"
#include "board.hpp"
#include "ship.hpp"

Game::Game() {
    this-> playersBoard = Board();
    this-> playersIndicatorBoard = Board();
    this-> NPCBoard = Board();
    this-> NPCIndicatorBoard = Board();

    this-> playerShipsRemain = 5;
    this-> NPCShipsRemain = 5;

    
}