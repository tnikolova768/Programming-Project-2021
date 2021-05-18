#include "player.hpp"

// Конструктор за слагане на име на играча
Player::Player(std::string name){
    this->name = name;
}

// взимаме символа на играча
std::string Player::getsymbol(){
    if(symbol == 0)
        return "O";
    else
        return "X";        
}

// взимаме името на играча
std::string Player::getName(){
    return name;
}

// сетваме символа на играча
void Player::setSymbolToO() {
    this->symbol = O;
}

// сетваме символа на играча
void Player::setSymbolToX() {
    this->symbol = X;
}