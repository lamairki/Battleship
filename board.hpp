#ifndef         __HPP_BOARD__
#define         __HPP_BOARD__

#include "ship.hpp"
#include <array>
#include <vector>

	class Board {

		

		public:

			char upperBoard[10][10];
			char lowerBoard[10][10];

			int BOARD_HEIGHT = 10;
			int BOARD_WIDTH = 10;

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
			bool placeShip(const Ship &s, int row, int col, direction d);
			char hitMiss(int row, int col);
			Ship carrier;
			Ship battleship;
			Ship cruiser;
			Ship submarine;
			Ship destroyer;
			std::vector<Ship> boardShips;
			bool placeNPCShips();
			

		private:

			friend class Game;
			

			int shipsRemain;
			bool gameOver;
			


	};

#endif