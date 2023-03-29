#include <iostream>
#include <stdexcept>
#include "game.hpp"
#include "player.hpp"
using namespace std;

namespace ariel
{
    
    Game::Game(Player& p1, Player& p2): player1(p1), player2(p2) 
    {
      this->player1=p1;
      this->player2=p2;
      this->ifStart=false;
    }
    void Game::playTurn()
    {
    }
    void Game::printLastTurn()
    {
    }
    void Game::playAll()
    {
    }
    void Game::printWiner()
    {
    }
    void Game::printLog()
    {
    }
    void Game::printStats()
    {
    }
    bool Game::getIfStart()
    {
      return this->ifStart;
    }
    void Game::setIfStart(bool ifStart)
    {
      this->ifStart=ifStart;
    }
}
