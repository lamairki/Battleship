#ifndef         __HPP_GAME__
#define         __HPP_GAME__

#include "board.hpp"

    class Game {
        public: 
            Game();
            void setShips();
            char userFire(Board &attacked, Board &attacker);
            char NPCFire(Board &attacked, Board &attacker);
            
            Board playersBoard;
            Board NPCBoard;
            bool gameOverCheck(Board &checkBoard);
            void notifyUserFire(char fireStatus);
            void notifyNPCFire(char fireStatus);

            


        private:
            int playerShipsRemain;
            int NPCShipsRemain;

            
            






    };


#endif