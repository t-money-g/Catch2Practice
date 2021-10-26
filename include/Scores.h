//
// Created by tyoun on 10/24/2021.
//

#ifndef SCORES_H
#define SCORES_H
#include "GameEntry.h"
#include <stdexcept>

class Scores {                      // stores game high scores
public:
    Scores(int maxEnt = 10);
    ~Scores();
    void add(const GameEntry& e);
    GameEntry remove(int i)
        noexcept(false);
private:
    int maxEntries;
    int numEntries;
    GameEntry* entries;
};
#endif //SCORES_H
