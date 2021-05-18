#include "human.hpp"
#include <unistd.h>


// Игране на ход, всеки играч си избира цифра, където да постави символа си
int Human::make_turn(){
    int place;
    std::cout << "Choose place to put '" << getsymbol() << "': " << std::endl;
    std::cin >> place;

    return place;
}

// Човекът няма функция да търси за най-добър ход
int Human::bestMove(std::string field[][3], std::string ai) {
    return 0;
}
