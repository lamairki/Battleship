#include "ship.h"

Ship::Ship(Ship::shipType sT, int nH, char sC) {
    this-> shipClass = sT;
    this-> shipChar = sC;
    this-> numHoles = nH;
    this-> numHits = 0;
    this-> shipStatus = FLOATING;
}

bool Ship::isHit(Ship &s) {
    s.numHits += 1;
    if (s.numHits == s.numHoles) {
        s.shipStatus = SUNK;
    }
}
			
Ship::shipState Ship::isSunk(Ship &s) {
    return s.shipStatus;
}

Ship::getNumHoles() {
    return this-> numHoles;
}