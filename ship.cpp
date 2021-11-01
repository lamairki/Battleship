#include "ship.hpp"

Ship::Ship() {
    
}

Ship::Ship(shipType sT, int nH, char sC) {
    this-> shipClass = sT;
    this-> shipChar = sC;
    this-> numHoles = nH;
    this-> numHits = 0;
    this-> shipStatus = FLOATING;
}

void Ship::isHit() {
    this-> numHits += 1;
    if (this-> numHits == this-> numHoles) {
        this-> shipStatus = SUNK;
    }
}
			
Ship::shipState Ship::isSunk(Ship &s) {
    return s.shipStatus;
}

int Ship::getNumHoles() const {
    return this-> numHoles;
}

char Ship::getShipChar() const {
    return this-> shipChar;
}

std::string Ship::getShipType() const {
    switch (this -> shipClass) {
        case CARRIER: return "Carrier";
        case BATTLESHIP: return "Battleship";
		case CRUISER: return "Cruiser";
		case SUBMARINE: return "Submarine";
		case DESTROYER: return "Destroyer";
    }
}