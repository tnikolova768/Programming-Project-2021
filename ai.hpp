#ifndef AI_HPP
#define AI_HPP

#include "player.hpp"


// AI наследява обикновенния Player, тоест има същите атрибути

class AI: public Player{

public:
    AI(std::string name): Player(name){}; // конструктор за играч
    virtual int make_turn(); // прави се ход в играта
    virtual int bestMove(std::string field[][3], std::string ai); // търси най-благоприятния ход за компютъра
    int minimax(std::string board[][3], int depth, bool isMaximazing); // алгоритъм за търсене в дълбочина
    std::string checkWinner(std::string field[][3]); // проверява, дали имаме победител 
};




#endif  