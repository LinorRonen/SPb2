#include <iostream>
#include "player.hpp"

namespace ariel
{

    class Game
    {
        private:
        
        Player& player1;

        Player& player2;

        bool ifStart;

        public:
        
        void playTurn();

        void printLastTurn();

        void playAll();

        void printWiner();

        void printLog();

        void printStats();

        bool getIfStart();

        void setIfStart(bool ifStart);

        Game(Player& player1, Player& player2);

    };
}

