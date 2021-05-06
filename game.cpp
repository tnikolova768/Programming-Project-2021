#include "game.hpp"
#include <unistd.h>


void Game::check_name(std::string name) {
    if (name == "COMPUTER") {
        std::cout << "Invalid player name" << std::endl;
        exit(0);
    }
}



Game::Game(Player& player){
    srand(time(NULL));
    //AI* computer = new AI(X, "COMPUTER");
    //player_1 = computer;
    //player.setSymbolToO();
    //player_2 = &player;
    int order = rand()%(2 - 1 + 1) + 1;
    if(order == 1) {
        player.setSymbolToX();
        check_name(player.getName());
        player_1 = &player;
        
        AI* computer = new AI("COMPUTER");
        computer->setSymbolToO();
        //std::cout << "In const" << computer->getsymbol() << std::endl;
        //sleep(3);
        player_2 = computer;
        
        
    } else {
        AI* computer = new AI("COMPUTER");
        computer->setSymbolToX();
        player_1 = computer;

        player.setSymbolToO();
        player_2 = &player;
        
        
    }
}

Game::Game(Player& player1, Player& player2){
    srand(time(NULL));
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


void Game::start_game() {
    
    system("clear");
    std::cout << "Starting the game" << std::endl << std::endl;
    init_field();
    print_field();

    bool found = false;
    int place;


    while(1) {
        //----------------PLAYER 1----------------------------------------
        std::cout << "Player " << player_1->getName() << " is playing now!" << std::endl;
        //sleep(2);
        while(found == false) {
            if (player_1->getName() != "COMPUTER")
                place = player_1->make_turn();
            else {
                place = player_1->bestMove(field, player_1->getsymbol());
                
            }
            //std::cout << "Place = " << std::endl;
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
            
            //system("clear");
            std::cout << "GAME OVER" << std::endl;
            //check_winner();
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

        if(check_winner()) {
            std::cout << "GAME OVER" << std::endl;
            print_field();
            play_again();
        }
    }
}

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
