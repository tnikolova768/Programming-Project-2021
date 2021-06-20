#include "game.hpp"



using namespace std;


int main(){

    Human p1 = Human("human1");
    //Human p2 = Human("human2");
    //Game new_game(p1, p2);
    Game new_game1(p1);
    new_game1.start_game();

    // We start 2 different gamemodes depends on how many args we pass to the game object

}