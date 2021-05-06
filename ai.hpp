#ifndef AI_HPP
#define AI_HPP

#include "player.hpp"

class AI: public Player{

public:
    AI(Sign sym, std::string name): Player(name){};
    virtual int make_turn();
    virtual int bestMove(std::string field[][3], std::string ai);
    int minimax(std::string board[][3], int depth, bool isMaximazing);
    std::string checkWinner(std::string field[][3]);
};




#endif  