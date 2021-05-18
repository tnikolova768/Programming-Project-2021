#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

// двата символа, които участват в играта

enum Sign {
    O, X 
};

// class Player, който съдържа атрибути, които ще бъдат наследени от Human и AI

class Player{
    std::string name;
    Sign symbol;
public:
    Player(std::string name);

    std::string getsymbol(); // взимаме символа на играча

    std::string getName(); // взимаме името на играча
    void setSymbolToO(); // сетваме символа на играча
    void setSymbolToX(); // сетваме символа на играча

    // тази функции ще бъде пренаписани в завивимост дали съм AI или Human
    virtual int make_turn() = 0; 
    virtual int bestMove(std::string field[][3], std::string ai) = 0;

};

#endif