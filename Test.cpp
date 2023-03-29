#include "doctest.h"
#include "iostream"
#include <cstring>
#include <stdexcept>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("Before the game starts: we will check that each player has 26 cards and 0 victory cards.")
{
    Player player1("Linor");
    Player player2("Liam");
    Game game(player1,player2);
    CHECK(player1.stacksize()==26);
    CHECK(player2.stacksize()==26);
    CHECK(player1.cardesTaken()==0);
    CHECK(player2.cardesTaken()==0);
   
}
TEST_CASE("Before the game starts: a case in which the first player does not have a name.")
{
    Player player1("");
    Player player2("Inbal");
    CHECK_THROWS(Game(player1,player2));
    
}
TEST_CASE("Before the game starts: a case in which the second player does not have a name.")
{
    Player player1("Inbar");
    Player player2("");
    CHECK_THROWS(Game(player1,player2));
}
TEST_CASE("Before the game starts: a case where the name of the first player was mistake typed twice.")
{
    Player player1("LinorLinor");
    Player player2("Noy");
    CHECK_THROWS(Game(player1,player2));
}
TEST_CASE("Before the game starts: a case where the name of the second player was mistake typed twice.")
{
    Player player1("Linor");
    Player player2("NoyNoy");
    CHECK_THROWS(Game(player1,player2));
}
TEST_CASE("Before the game starts: a case in which the first and second players do not have a name.")
{
    Player player5("");
    Player player6("");
    CHECK_THROWS(Game(player5,player6));
}
TEST_CASE("Before the game starts: try to print the last turn stats before the game starts.")
{
    Player player1("Yaniv");
    Player player2("Tal");
    Game game(player1,player2);
    if(game.getIfStart()==false)
    {
        CHECK_THROWS(game.printLastTurn());
    }   
}
TEST_CASE("Before the game starts: try to print all the turns played one line per turn before the game starts.")
{
    Player player1("Yaniv");
    Player player2("Tal");
    Game game(player1,player2);
    if(game.getIfStart()==false)
    {
        CHECK_THROWS(game.printLog());
    }   
}
TEST_CASE("Before the game starts: try to print the name of the winner before the game starts.")
{
    Player player1("Yaniv");
    Player player2("Tal");
    Game game(player1,player2);
    if(game.getIfStart()==false)
    {
        CHECK_THROWS(game.printWiner());
    }   
}
TEST_CASE("Before the game starts: checking that there is no the same player twice(the same object).")
{
    Player player("Eden");
    CHECK_THROWS(Game(player,player));
}
TEST_CASE("After the game starts:1 turn.")
{
    Player player1("Dafna");
    Player player2("Noam");
    Game game(player1,player2);
    game.playTurn();
    bool t1 = (player1.stacksize()<=25);
    bool t2 = (player2.stacksize()<=25);
    bool t1Andt2 = (t1 && t2);
    CHECK(t1Andt2);
}
TEST_CASE("After the game starts: test after 1 turn.")
{
    Player player1("Noy");
    Player player2("Michal");
    Game game(player1,player2);
    game.playTurn();
    bool t1 = ( (player1.stacksize() + player2.stacksize())<=50);
    CHECK(t1);
}
TEST_CASE("After the game starts: test after 1 turn.")
{
    Player player1("Nova");
    Player player2("Liron");
    Game game(player1,player2);
    game.playTurn();
    bool t1 = ( (player1.cardesTaken()+ player2.cardesTaken())<=2);
    CHECK(t1);
}

TEST_CASE("After the game starts: test after 5 turns.")
{
    Player player1("May");
    Player player2("Adi");
    Game game(player1,player2);
    for (int i=0;i<5;i++) 
    {
        game.playTurn();
    }
    bool t1 = (player1.stacksize()<=21);
    bool t2 = (player2.stacksize()<=21);
    bool t1Andt2 = (t1 && t2);
    CHECK(t1Andt2);
}
TEST_CASE("After the game starts : test after 3 turns.")
{
    Player player1("May");
    Player player2("Adi");
    Game game(player1,player2);
    game.playTurn();
    game.playTurn();
    game.playTurn();
    bool t1 = (player1.stacksize()<=23);
    bool t2 = (player2.stacksize()<=23);
    bool t1Andt2 = (t1 && t2);
    CHECK(t1Andt2);
}
TEST_CASE("After the game starts : test after 20 turns.")
{
    Player player1("Dafna");
    Player player2("Noam");
    Game game(player1,player2);
    for (int i=0;i<20;i++) 
    {
        game.playTurn();
    }
    bool t1 = (player1.stacksize()<=6);
    bool t2 = (player2.stacksize()<=6);
    bool t1Andt2 = (t1 && t2);
    CHECK(t1Andt2);
}
TEST_CASE("After the game ends: the players try to play another turn.")
{
    Player player1("Yaniv");
    Player player2("Tal");
    Game game(player1,player2);
    game.playAll();
    CHECK_THROWS(game.playTurn());
}
TEST_CASE("After the game ends: check the stacksize.")
{
    Player player1("Yaniv");
    Player player2("Tal");
    Game game(player1,player2);
    game.playAll();
    CHECK(player1.stacksize()==0);
    CHECK(player2.stacksize()==0);
}
TEST_CASE("After the game ends: we will check that the total number of victory cards does not exceed 52.")
{
    Player player1("Yaniv");
    Player player2("Tal");
    Game game(player1,player2);
    game.playAll();
    bool t1= (player1.cardesTaken()<=52);
    CHECK(t1);  
}
TEST_CASE("After the game ends: trying to start and end the game before getting cards again.")
{
    Player player1("Yaniv");
    Player player2("Tal");
    Game game(player1,player2);
    game.playAll();
    CHECK_THROWS(game.playAll());
}




