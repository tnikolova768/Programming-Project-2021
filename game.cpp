#include "game.hpp"
#include <unistd.h>

// username COMPUTER is forbidden
void Game::check_name(std::string name) {
    if (name == "COMPUTER") {
        std::cout << "Invalid player name" << std::endl;
        exit(0);
    }
}


// Create a single play game
Game::Game(Player& player){
    srand(time(NULL));
    // if one player is passed, we create AI and randomize who is first
    int order = rand()%(2 - 1 + 1) + 1;
    if(order == 1) {
        player.setSymbolToX();
        check_name(player.getName());
        player_1 = &player;
        
        AI* computer = new AI("COMPUTER");
        computer->setSymbolToO();
        player_2 = computer;
        
    } else {
        AI* computer = new AI("COMPUTER");
        computer->setSymbolToX();
        player_1 = computer;

        player.setSymbolToO();
        player_2 = &player;
    }
}


// multiplayer, we have 2 players passed as args
Game::Game(Player& player1, Player& player2){
    srand(time(NULL));
    // randomize who is first
    check_name(player1.getName());
    check_name(player2.getName());
    int order = rand()%(2 - 1 + 1) + 1;
    if (order == 1) {
        player1.setSymbolToX();
        player_1 = &player1;
        player2.setSymbolToO();
        player_2 = &player2;
    } else {
        player2.setSymbolToX();
        player_1 = &player2;
        player1.setSymbolToO();
        player_2 = &player1;
    }
}



// generate the field, matrix 3x3
void Game::init_field(){
    int count = 1;
    for(int i = 0; i < 3; i++){
        for(int k = 0; k < 3; k++){
            std::string ch = std::to_string(count);
            field[i][k] = ch;
            count++;
        }
    }
}



// Printing the current state of the game
void Game::print_field(){
    std::cout << "+---+---+---+" << std::endl;
    std::cout << "| ";
    for(int i = 0; i < 3; i++){
        for(int k = 0; k < 3; k++){
            std::cout << field[i][k] << " | ";
        }
        std::cout << std::endl;
        std::cout << "+---+---+---+" << std::endl;
        if(i != 2) {
            std::cout << "| ";
        }
    }
}


// check if there is a winner
bool Game::check_winner(){
    for(int i = 0; i < 3; i++) {
        if(field[i][0] == field[i][1]) {
            if(field[i][0] == field[i][2]) {
                system("clear");
                if(field[i][0] == player_1->getsymbol()) {
                    std::cout << "The winner is " << player_1->getName() << std::endl;
                } else {
                    std::cout << "The winner is " << player_2->getName() << std::endl;
                }
                return true;
            }
        }

        for(int k = 0; k < 3; k++) {
            if(field[i][k] == field[i+1][k]) {
                if(field[i][k] == field[i+2][k]) {
                    system("clear");
                    if(field[i][k] == player_1->getsymbol()) {
                        std::cout << "The winner is " << player_1->getName() << std::endl;
                    } else {
                        std::cout << "The winner is " << player_2->getName() << std::endl;
                    }
                    return true;
                }
            }
        }
        
                if(field[0][0] == field[1][1]) {
                    if(field[0][0] == field[2][2]) {
                        system("clear");
                        if(field[0][0] == player_1->getsymbol()) {
                            std::cout << "The winner is " << player_1->getName() << std::endl;
                        } else {
                            std::cout << "The winner is " << player_2->getName() << std::endl;
                        }
                        return true;
                    }
                }

                if(field[0][2] == field[1][1]) {
                    if(field[0][2] == field[2][0]) {
                        system("clear");
                        if(field[0][2] == player_1->getsymbol()) {
                            std::cout << "The winner is " << player_1->getName() << std::endl;
                        } else {
                            std::cout << "The winner is " << player_2->getName() << std::endl;
                        }
                        return true;
                    }
                }
    }
    bool tie = true;
    for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (field[i][j] != "X" && field[i][j] != "O") {
                        tie = false;
                        break;
                }
            }
   }
   if (tie) {
       system("clear");
       std::cout << "TIE" << std::endl;
       return true;
   }
        
    return false;
}




// start the game
void Game::start_game() {
    
    system("clear");
    std::cout << "Starting the game" << std::endl << std::endl;
    init_field();
    print_field();

    bool found = false;
    int place;

    // loop for the the game
    while(1) {
        //----------------PLAYER 1----------------------------------------
        std::cout << "Player " << player_1->getName() << " is playing now!" << std::endl;
        while(found == false) {
            if (player_1->getName() != "COMPUTER")
                place = player_1->make_turn();
            else {
                place = player_1->bestMove(field, player_1->getsymbol());
                
            }
            for(int i = 0; i < 3; i++) {
                for(int k = 0; k < 3; k++) {
                    if(field[i][k] == std::to_string(place)) {
                        field[i][k] = player_1->getsymbol();
                        found = true;
                    }
                }
            }
        }

        if (check_winner()) {
            std::cout << "GAME OVER" << std::endl;
            print_field();
            play_again();
        }
        //----------------------------PLAYER 2----------------------------------------------
        found = false;
        system("clear");
        print_field();

        std::cout << "Player " << player_2->getName() << " is playing now!" << std::endl;

        while (found == false) {
            if (player_2->getName() != "COMPUTER")
                place = player_2->make_turn();
            else {
                
                place = player_2->bestMove(field, player_2->getsymbol());
            }

            for (int i = 0; i < 3; i++) {
                for (int k = 0; k < 3; k++) {
                    if (field[i][k] == std::to_string(place)) {
                        field[i][k] = player_2->getsymbol();
                        found = true;
                    }
                }
            }
        }

        found = false;
        system("clear");
        print_field();
        // if there is a winner, the game is over
        if(check_winner()) {
            std::cout << "GAME OVER" << std::endl;
            print_field();
            play_again();
        }
    }
}



// function to start a new game, if needed
void Game::play_again() {
    std::string ans;
    std::cout << "Do you want to play again? (y/n)" << std::endl;
    while(std::cin >> ans) {
        if (ans == "y" || ans == "n") {
            break;
        } else {
            std::cout << "Invalid" << std::endl;
        }
    }
    if (ans == "y") {
        system("clear");
        start_game();
    } else {
        exit(0);
    }

}
