#ifndef         __HPP_SHIP__
#define         __HPP_SHIP__

#include <string>

	class Ship {

		public:
			enum shipType {
					CARRIER,
					BATTLESHIP,
					CRUISER,
					SUBMARINE,
					DESTROYER
				};

			enum shipState {
				FLOATING,
				SUNK
			};
			Ship();
			Ship(shipType sT, int nH, char sC);
			void isHit();
			shipState isSunk(Ship &s);
			int getNumHoles() const ;
			char shipChar;
			std::string getShipType() const ;
			char getShipChar() const ;
			
		private:

			shipType shipClass;
			int numHoles;
			int numHits;
			shipState shipStatus;

	};

#endif