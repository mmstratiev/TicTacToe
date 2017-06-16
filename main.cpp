#include <iostream>
#include <windows.h>
#include "GameLogic.h"
/*
    Tic-Tac-Toe console based game for two players
    Created by Miroslav Stratiev
*/

/*
TO DO:
Create a GameLogic class with methods to start game with two players, reset game
Create a Field(class?). Maybe char[][] part of GameLogic class?
Later Create a Menu class to start game with a simple AI or another player(OPTIONAL CLASS)
*/

int main()
{
    GameLogic TicTacToe;

    TicTacToe.Play();
 /*   for(int i = 0; i < 3; i++){
        std::cout << TicTacToe.getField()[i] << std::endl;;
    }

    int a;
    std::cin >> a;
    if(a == 1){
        TicTacToe.getField()[2][0] = 'X';
    }
    clearScr();
    for(int i = 0; i < 3; i++){
        std::cout << TicTacToe.getField()[i] << std::endl;;
    }
    TicTacToe.Reset();
    for(int i = 0; i < 3; i++){
        std::cout << TicTacToe.getField()[i] << std::endl;;
    }

    return 0;*/
}
