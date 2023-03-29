#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace ariel
{

    class Player
    {

        private:

        string name;

        int theCardesTaken;
        
        int theStacksize;

        bool ifWinner;


        public:

        int cardesTaken();
    
        int stacksize();

        void setStacksize(int size);

        string getName();

        bool getIfWinner();

        void setIfWinner(bool state);

        Player(std::string name);

    };
}






