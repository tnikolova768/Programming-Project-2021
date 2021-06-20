#include "player.hpp"

// Constructor for player name
Player::Player(std::string name){
    this->name = name;
}

// getsymbol of the player
std::string Player::getsymbol(){
    if(symbol == 0)
        return "O";
    else
        return "X";        
}

// get the name of the player
std::string Player::getName(){
    return name;
}

// set the symbol for the player
void Player::setSymbolToO() {
    this->symbol = O;
}

void Player::setSymbolToX() {
    this->symbol = X;
}