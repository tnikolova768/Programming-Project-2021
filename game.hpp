#ifndef GAME_HPP
#define GAME_HPP
#include "player.hpp"
#include "ai.hpp"
#include "human.hpp"


class Game{
    std::string field[3][3];
    
    Player* player_1;
    Player* player_2;

    void init_field();
    void print_field();
    bool check_winner();
    
public:
    Game(Player& player);
    Game(Player& player1, Player& player2);

    void start_game();
    void play_again();
    void check_name(std::string name);

};

#endif