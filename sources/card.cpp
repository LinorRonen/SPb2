#include <iostream>
#include <string>
#include "card.hpp"
using namespace std;

namespace ariel
{
    Card::Card(int value, string suit) 
    {
      this->theValue=value;
      this->theShape=suit;
    }
}

