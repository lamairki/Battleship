#ifndef         __HPP_BOARD__
#define         __HPP_BOARD__

	class Board {

		const int BOARD_HEIGHT = 10;
		const int BOARD_WIDTH = 10;

		public:

		enum rowNames {
			A,
			B,
			C,
			D,
			E,
			F,
			G,
			H,
			I,
			J
		};

		enum direction {
			NORTH,
			EAST,
			WEST,
			SOUTH
		};

		Board();
		bool placeShip(Ship &s, int row, int col, direction d);
		char hitMiss(int row, int col);




		private:

			int shipsRemain;
			bool gameOver;
			Ship carrier;
			Ship battleship;
			Ship Cruiser;
			Ship submarine;
			Ship destroyer;


	}

#endif