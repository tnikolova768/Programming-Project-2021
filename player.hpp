#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

// the 2 symbols -> X and O

enum Sign {
    O, X 
};


// basic class Player
class Player{
    std::string name;
    Sign symbol;
public:
    Player(std::string name);

    std::string getsymbol(); // get the symbol of the player

    std::string getName(); // get the name of the player
    void setSymbolToO(); // setting the symbol
    void setSymbolToX(); // setting the symbol

    // virtual functions for Player and the AI class
    virtual int make_turn() = 0; 
    virtual int bestMove(std::string field[][3], std::string ai) = 0;

};

#endif