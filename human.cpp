#include "human.hpp"
#include <unistd.h>


// Each turn, the player is choosing a place between 1-9
int Human::make_turn(){
    int place;
    std::cout << "Choose place to put '" << getsymbol() << "': " << std::endl;
    std::cin >> place;

    return place;
}

// This function is only for the AI player
int Human::bestMove(std::string field[][3], std::string ai) {
    return 0;
}
