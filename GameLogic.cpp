#include "GameLogic.h"

#include <iostream>
#include <algorithm>


bool GameLogic::Reset(){
    field[0] = "7|8|9";
    field[1] = "4|5|6";
    field[2] = "1|2|3";
    occupied.clear();
}

int GameLogic::checkForWin(){
    field[0].find("X|X|X");
    if(field[0].find("X|X|X") != field[0].npos //horizontal 1
       || field[1].find("X|X|X") != field[1].npos //horizontal 2
       || field[2].find("X|X|X") != field[2].npos //horizontal 3
       || (field[0][0] == 'X' && field[1][2] == 'X' && field[2][4] == 'X') //diagonal 1
       || (field[0][4] == 'X' && field[1][2] == 'X' && field[2][0] == 'X') //diagonal 2
       || (field[0][0] == 'X' && field[1][0] == 'X' && field[2][0] == 'X') //vertical 1
       || (field[0][2] == 'X' && field[1][2] == 'X' && field[2][2] == 'X') //vertical 2
       || (field[0][4] == 'X' && field[1][4] == 'X' && field[2][4] == 'X')){ //vertical 3

            playerOneScore++;
            return 1;
       }
    else if(field[0].find("O|O|O") != field[0].npos //horizontal 1
        || field[1].find("O|O|O") != field[1].npos //horizontal 2
        || field[2].find("O|O|O") != field[2].npos //horizontal 3
        || (field[0][0] == 'O' && field[1][2] == 'O' && field[2][4] == 'O') //diagonal 1
        || (field[0][4] == 'O' && field[1][2] == 'O' && field[2][0] == 'O') //diagonal 2
        || (field[0][0] == 'O' && field[1][0] == 'O' && field[2][0] == 'O') //vertical 1
        || (field[0][2] == 'O' && field[1][2] == 'O' && field[2][2] == 'O') //vertical 2
        || (field[0][4] == 'O' && field[1][4] == 'O' && field[2][4] == 'O')){ //vertical 3

            playerTwoScore++;
            return 2;
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
    default:
        return 0;
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
    return 1;
}

void GameLogic::displayField(){
    for(int i = 0; i < 3; i++){
        std::cout << field[i] << std::endl;
    }
    std::cout << std::endl;
}
