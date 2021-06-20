#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "player.hpp"
#include "game.hpp"

// Human inheris the basic class Player and its attributes 
class Human: public Player{

public:
    Human(std::string name): Player(name){};
    virtual int make_turn();
    virtual int bestMove(std::string field[][3], std::string ai);
};

#endif