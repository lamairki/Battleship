#ifndef         __HPP_SHIP__
#define         __HPP_SHIP__

	class Ship {

		public:

			char shipChar;

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

			Ship(shipType sT, int nH, char sC);
			bool isHit(Ship &s);
			shipState isSunk(Ship &s);
			int getNumHoles();
			
		private:

			shipType shipClass;
			int numHoles;
			int numHits;
			shipState shipStatus;

	};

#endif