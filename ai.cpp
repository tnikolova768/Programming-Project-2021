#include "ai.hpp"
#include <algorithm>
#include <unistd.h>


int AI::make_turn() {
        return 0;
}


// function to find the most favorable path for the AI player
// we are passing the field and the symbol as args
int AI::bestMove(std::string field[][3], std::string ai){
        int bestScore = -999999;
        std::string past;
        int move;
        
        for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                        if (field[i][j] != "O" && field[i][j] != "X") {
                                past = field[i][j];
                                field[i][j] = this->getsymbol();
                                int score = minimax(field, 0, false);
                                field[i][j] = past;
                                if (score > bestScore) {
                                        bestScore = score;
                                        move = stoi(past);
                                }
                        }
                }
        }

        return move;
}


// the minimax algorithm
// depth - how deep are we going to search for best path
// we are also passing the board
// isMaximazing is the AI (MAX VALUE) -> true, if its the player we are looking for MIN VALUE so we are passing -> false
int AI::minimax(std::string board[][3], int depth, bool isMaximazing) {
        std::string past;
        std::string res = checkWinner(board);
        if (this->getsymbol() == "O") {
                if (res) {
                        if (res == "X") {
                                return -1;
                        } else if (res == "O") {
                                return 1;
                        } else if (res == "tie") {
                                return 0;
                        }
                }
        } else {
               if (res) {
                        if (res == "X") {
                                return 1;
                        } else if (res == "O") {
                                return -1;
                        } else if (res == "tie") {
                                return 0;
                        }
                } 
        } 

        
        
        if (isMaximazing) {
        int bestScore = -999999; 
                for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                                if (board[i][j] != "O" && board[i][j] != "X") {
                                        past = board[i][j];
                                        board[i][j] = this->getsymbol();
                                        int score = minimax(board, depth+1, false);
                                        board[i][j] = past;
                                        bestScore = std::max(score, bestScore); 
                                }
                        }
                }
                return bestScore;
        } else {
                std::string human;
                
                if (this->getsymbol() == "O") {
                        human = "X";
                } else {
                        human = "O";
                }

                int bestScore =  999999; 
                for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                                if (board[i][j] != "O" && board[i][j] != "X") {
                                        past = board[i][j];
                                        board[i][j] = human;
                                        int score = minimax(board, depth+1, true);
                                        board[i][j] = past;
                                        bestScore = std::min(score, bestScore); 
                                }
                        }
                }
                return bestScore;  
        }
        
}

// check if the game has finished
std::string AI::checkWinner(std::string field[][3]) {
    for (int i = 0; i < 3; i++) {
        if (field[i][0] == field[i][1]) {
            if (field[i][0] == field[i][2]) {
                return field[i][0]; 
            }
        }

        for (int k = 0; k < 3; k++) {
            if (field[i][k] == field[i+1][k]) {
                if (field[i][k] == field[i+2][k]) {
                    return field[i][k];
                }
            }
        }
        
                if(field[0][0] == field[1][1]) {
                    if(field[0][0] == field[2][2]) {
                        return field[0][0];
                    }
                }

                if(field[0][2] == field[1][1]) {
                    if(field[0][2] == field[2][0]) {
                        return field[0][2]; 
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
        return "tie";
   }

    return false;
}