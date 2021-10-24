//
// Created by tyoun on 10/24/2021.
//

#include "Scores.h"
#include "GameEntry.h"

void TestScores() {
    GameEntry gameEntry = GameEntry("YOU WIN!", 3);
    GameEntry gameEntry2 =  GameEntry("YOU ARE wIN BUT NOT HIGHEST SCORE!", 1);
    GameEntry gameEntry3 =  GameEntry("YOU ARE wIN BUT.....?!", 2);

    Scores newScore = Scores(10);
    newScore.add(gameEntry);
    newScore.add(gameEntry2);
    newScore.add(gameEntry3);

}