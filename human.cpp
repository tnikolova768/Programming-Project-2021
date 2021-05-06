#include "human.hpp"
#include <unistd.h>



int Human::make_turn(){
    int place;
    //std::cout << "am i here" << std::endl;
    //sleep(3);
    std::cout << "Choose place to put '" << getsymbol() << "': " << std::endl;
    std::cin >> place;

    return place;
}

int Human::bestMove(std::string field[][3], std::string ai) {
    return 0;
}
