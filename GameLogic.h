#ifndef GAMELOGIC_H_INCLUDED
#define GAMELOGIC_H_INCLUDED

#include <vector>
#include <string>

class GameLogic{
private:
    //scores
    int playerOneScore = 0;
    int playerTwoScore = 0;

    int playerTurn = 1;

    std::vector<int> occupied;

    std::string field[3] = {"7|8|9", "4|5|6", "1|2|3"};

public:
    std::string* getField() { return field; }

    std::vector<int>* getOccupied() { return &occupied; }

    int getPlayerOneScore() {return playerOneScore;}
    int getPlayerTwoScore() {return playerTwoScore;}

    //reset the field
    bool Reset();

    int getPlayerTurn() { return playerTurn; }

    void setPlayerTurn(int nextPlayerTurn) { playerTurn = nextPlayerTurn; }

    int checkForWin();

    int changeField(int numberToChange, int player);

    void displayField();
};


#endif // GAMELOGIC_H_INCLUDED
