/*
    Tic-Tac-Toe console based game for two players
    Created by Miroslav Stratiev
*/

#include <iostream>
#include <windows.h>
#include "GameLogic.h"

void Play();
void playerEnterNumber(GameLogic *TicTacToe, int playerTurn);
void clearScr();

int main()
{
    Play();
}

void Play(){
    GameLogic TicTacToe;
    int enteredNumber;
    TicTacToe.displayField();
    do{
        if(TicTacToe.getOccupied()->size() == 9){
            std::cout << "Draw! Score is P1:" << TicTacToe.getPlayerOneScore() << "-P2:" << TicTacToe.getPlayerTwoScore()<< std::endl;
            TicTacToe.Reset();
        }
        if(TicTacToe.getPlayerTurn() == 1){
            playerEnterNumber(&TicTacToe, 1);
            clearScr();
            TicTacToe.displayField();
            if(TicTacToe.checkForWin() != 0){
                TicTacToe.Reset();
                std::cout << "Player 1 wins the round! Score is P1:" << TicTacToe.getPlayerOneScore() << "-P2:" << TicTacToe.getPlayerTwoScore() << std::endl;
            }
            TicTacToe.setPlayerTurn(2);
        }

        else {
            playerEnterNumber(&TicTacToe, 2);
            clearScr();
            TicTacToe.displayField();
            if(TicTacToe.checkForWin() != 0){
                std::cout << "Player 2 wins the round! Score is P1:" << TicTacToe.getPlayerOneScore() << "-P2:" << TicTacToe.getPlayerTwoScore() << std::endl;
                TicTacToe.Reset();
            }
            TicTacToe.setPlayerTurn(1);
        }
    } while(TicTacToe.getPlayerOneScore() != 3 && TicTacToe.getPlayerTwoScore() != 3);
}

void clearScr(){
    system("cls||clear");
}

void playerEnterNumber(GameLogic *TicTacToe, int playerTurn){
    int enteredNumber;
    if(playerTurn == 1) std::cout << "Player "<< playerTurn << " enter a number to replace with X: ";
    else std::cout << "Player "<< playerTurn << " enter a number to replace with O: ";

    std::cin >> enteredNumber;

    while(TicTacToe->changeField(enteredNumber, playerTurn) != 1){
        std::cout << "Enter a valid number: ";
        std::cin >> enteredNumber;
    }
}
