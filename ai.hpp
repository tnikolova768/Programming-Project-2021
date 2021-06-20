#ifndef AI_HPP
#define AI_HPP

#include "player.hpp"


// AI inheris the basic class Player and its attributes 

class AI: public Player{

public:
    AI(std::string name): Player(name){}; // constructor for player
    virtual int make_turn(); // one turn in game
    virtual int bestMove(std::string field[][3], std::string ai); // looking for the best path for the AI
    int minimax(std::string board[][3], int depth, bool isMaximazing); // minimax algorithm
    std::string checkWinner(std::string field[][3]); // check if there is a winner
};




#endif  