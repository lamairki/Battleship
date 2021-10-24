#ifndef         __HPP_GAME__
#define         __HPP_GAME__

    class Game {
        public: 
            Game();
            void setShips();
            fire();


        private:
            int playerShipsRemain;
            int NPCShipsRemain;
            Board::Board playersBoard;
            Board::Board playersIndicatorBoard;
            Board::Board NPCBoard;
            Board::Board NPCIndicatorBoard;






    }


#endif