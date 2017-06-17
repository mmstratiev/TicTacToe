#include "GameLogic.h"

#include <iostream>
#include <algorithm>

void GameLogic::Play(){
    bool swapPlayers = true;
    int enteredNumber = -1;
    int whoWon;


    displayField();
    while(1){
        if(swapPlayers){
            std::cout << "Player One, enter a number to replace with X: ";
            std::cin >> enteredNumber;
            while(changeField(enteredNumber, 1) != 1) {
                std::cout << "Invalid input. Try again: ";
                std::cin >> enteredNumber;
            }
            swapPlayers = false;
        }
        else{
            std::cout << "Player Two, enter a number to replace with O: ";
            std::cin >> enteredNumber;
            while(changeField(enteredNumber, 2) != 1) {
                std::cout << "Invalid input. Try again: ";
                std::cin >> enteredNumber;
            }
            swapPlayers = true;
        }

        if(checkField() == 1){
                playerOne++;
            if(Reset()){
                whoWon = 1;
                break;
            }
            clearScr();
            displayField();
            std::cout << "Player 1 wins the round! Score is P1:" << playerOne << "-P2:" << playerTwo << std::endl;
        }
        else if(checkField() == 2){
            playerTwo++;
            if(Reset()){
                whoWon = 2;
                break;
            }
            clearScr();
            displayField();
            std::cout << "Player 2 wins the round! Score is P1:" << playerOne << "-P2:" << playerTwo << std::endl;
        }
        else if(checkField() == -1){
            Reset();
            clearScr();
            displayField();
            std::cout << "Draw! Score is P1:" << playerOne << "-P2:" << playerTwo << std::endl;

        }
    }
    if(whoWon == 1) {
        std::cout << "Player 1 wins!" << std::endl;
    }
    else if(whoWon == 2){
        std::cout << "Player 2 wins!" << std::endl;
    }
}

bool GameLogic::Reset(){
    field[0] = "7|8|9";
    field[1] = "4|5|6";
    field[2] = "1|2|3";
    occupied.clear();

    if(playerOne == 3 || playerTwo == 3){
        playerOne = 0;
        playerTwo = 0;
        return true;
    }
    return false;
}

int GameLogic::checkField(){
    field[0].find("X|X|X");
    if(field[0].find("X|X|X") != field[0].npos
       || field[1].find("X|X|X") != field[1].npos
       || field[2].find("X|X|X") != field[2].npos
       || (field[0][0] == 'X' && field[1][2] == 'X' && field[2][4] == 'X') //diagonal 1
       || (field[0][4] == 'X' && field[1][2] == 'X' && field[2][0] == 'X') //diagonal 2
       || (field[0][0] == 'X' && field[1][0] == 'X' && field[2][0] == 'X') //vertical 1
       || (field[0][2] == 'X' && field[1][2] == 'X' && field[2][2] == 'X') //vertical 2
       || (field[0][4] == 'X' && field[1][4] == 'X' && field[2][4] == 'X')){ //vertical 3

            return 1;
       }
    else if(field[0].find("O|O|O") != field[0].npos
        || field[1].find("O|O|O") != field[1].npos
        || field[2].find("O|O|O") != field[2].npos
        || (field[0][0] == 'O' && field[1][2] == 'O' && field[2][4] == 'O') //diagonal 1
        || (field[0][4] == 'O' && field[1][2] == 'O' && field[2][0] == 'O') //diagonal 2
        || (field[0][0] == 'O' && field[1][0] == 'O' && field[2][0] == 'O') //vertical 1
        || (field[0][2] == 'O' && field[1][2] == 'O' && field[2][2] == 'O') //vertical 2
        || (field[0][4] == 'O' && field[1][4] == 'O' && field[2][4] == 'O')){

            return 2;
        }
    else if(occupied.size() == 9){
        return -1;
    }
    return 0;
}

int GameLogic::changeField(int numberToChange, int player) {
    if(std::find(occupied.begin(), occupied.end(), numberToChange) != occupied.end()){
        return -1;
    }
    occupied.push_back(numberToChange);

    if(player == 1){
        switch(numberToChange){
    case 1:
        field[2][0] = 'X';
        break;
    case 2:
        field[2][2] = 'X';
        break;
    case 3:
        field[2][4] = 'X';
        break;
    case 4:
        field[1][0] = 'X';
        break;
    case 5:
        field[1][2] = 'X';
        break;
    case 6:
        field[1][4] = 'X';
        break;
    case 7:
        field[0][0] = 'X';
        break;
    case 8:
        field[0][2] = 'X';
        break;
    case 9:
        field[0][4] = 'X';
        break;
        }
    }
    else{
        switch(numberToChange){
    case 1:
        field[2][0] = 'O';
        break;
    case 2:
        field[2][2] = 'O';
        break;
    case 3:
        field[2][4] = 'O';
        break;
    case 4:
        field[1][0] = 'O';
        break;
    case 5:
        field[1][2] = 'O';
        break;
    case 6:
        field[1][4] = 'O';
        break;
    case 7:
        field[0][0] = 'O';
        break;
    case 8:
        field[0][2] = 'O';
        break;
    case 9:
        field[0][4] = 'O';
        break;
    default:
        return 0;
        }
    }
    clearScr();
    displayField();
    return 1;
}

void GameLogic::clearScr(){
    system("cls||clear");
}

void GameLogic::displayField(){
    for(int i = 0; i < 3; i++){
        std::cout << field[i] << std::endl;
    }
    std::cout << std::endl;
}
