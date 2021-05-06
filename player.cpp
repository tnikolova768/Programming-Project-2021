#include "player.hpp"


Player::Player(std::string name){
    this->name = name;
}

std::string Player::getsymbol(){
    if(symbol == 0)
        return "O";
    else
        return "X";        
}

std::string Player::getName(){
    return name;
}

void Player::setSymbolToO() {
    this->symbol = O;
}

void Player::setSymbolToX() {
    this->symbol = X;
}