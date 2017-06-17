#ifndef GAMELOGIC_H_INCLUDED
#define GAMELOGIC_H_INCLUDED

#include <vector>
#include <string>

class GameLogic{
private:
    //scores
    int playerOne = 0;
    int playerTwo = 0;
    std::vector<int> occupied;
    std::string field[3] = {"7|8|9", "4|5|6", "1|2|3"};

public:
//    int getScore() { return score; }
  //  void setScore(int s) { score = s; }

    std::string* getField() { return field; }

    //start the game
    void Play();

    //reset the field and the scores if someone has a score of 3(meaning he wins)
    bool Reset();

    int checkField();

    int changeField(int numberToChange, int player);

    void clearScr();

    void displayField();
};


#endif // GAMELOGIC_H_INCLUDED
