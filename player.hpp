#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

enum Sign {
    O, X 
};

class Player{
    std::string name;
    Sign symbol;
public:
    Player(std::string name);

    std::string getsymbol();

    std::string getName();
    void setSymbolToO();
    void setSymbolToX();

    virtual int make_turn() = 0;
    virtual int bestMove(std::string field[][3], std::string ai) = 0;

};

#endif