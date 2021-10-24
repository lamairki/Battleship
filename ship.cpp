#include "ship.hpp"

Ship::Ship(Ship::shipType sT, int nH, char sC) {
    this-> shipClass = sT;
    this-> shipChar = sC;
    this-> numHoles = nH;
    this-> numHits = 0;
    this-> shipStatus = FLOATING;
}

void Ship::isHit() {
    this-> numHits += 1;
    if (this-> numHits == s.numHoles) {
        this-> shipStatus = SUNK;
    }
}
			
Ship::shipState Ship::isSunk(Ship &s) {
    return s.shipStatus;
}

int Ship::getNumHoles() {
    return this-> numHoles;
}