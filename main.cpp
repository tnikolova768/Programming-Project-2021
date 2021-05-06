#include "game.hpp"



using namespace std;


int main(){

    Human p1 = Human("Space");
    Human p2 = Human("Stinky");
    //Game new_game(p1, p2);
    Game new_game1(p1);
    new_game1.start_game();

}