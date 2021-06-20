#ifndef GAME_HPP
#define GAME_HPP
#include "player.hpp"
#include "ai.hpp"
#include "human.hpp"


class Game{
    std::string field[3][3]; // playing field
    
    Player* player_1; // 2 players
    Player* player_2;

    void init_field(); // generate the field
    void print_field(); // print the current state of the game
    bool check_winner(); // check if there is a winner
    
public:
    Game(Player& player); // singleplay
    Game(Player& player1, Player& player2); // multiplayer

    void start_game(); // start the game
    void play_again(); // play again?
    void check_name(std::string name); // COMPUTER username is forbidden

};

#endif