#include <iostream>
#include <string>
#include "player.hpp"
using namespace std;

namespace ariel
{

    int Player::cardesTaken(){return this->theCardesTaken;}

    int Player::stacksize(){return this->theStacksize;}

    string Player::getName(){return this->name;}

    bool Player::getIfWinner(){return this->ifWinner;}

    void Player::setIfWinner(bool state){this->ifWinner=state;}

    void Player::setStacksize(int size){this->theStacksize=size;}
    
    Player::Player(std::string name)
    {
        this->name=name;
        this->theCardesTaken=0;
        this->theStacksize=26;
        this->ifWinner=false;
    }
}
