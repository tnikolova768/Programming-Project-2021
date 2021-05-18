#ifndef GAME_HPP
#define GAME_HPP
#include "player.hpp"
#include "ai.hpp"
#include "human.hpp"


class Game{
    std::string field[3][3]; // полето за игра
    
    Player* player_1; // двамата играчи
    Player* player_2;

    void init_field(); // генериране на полето
    void print_field(); // принтиране на състоянието на полето
    bool check_winner(); // проверка, дали имаме победител
    
public:
    Game(Player& player); // singleplay
    Game(Player& player1, Player& player2); // multiplayer

    void start_game(); // стартиране на играта
    void play_again(); // повторно стартиране и изчистване на полето
    void check_name(std::string name); // проверка, дали е спазено правилото за име

};

#endif