//
// Created by tyoun on 10/24/2021.
//


#include "Scores.h"
#include "GameEntry.h"

Scores::Scores(int maxEnt) {
    maxEntries = maxEnt;
    entries = new GameEntry[maxEntries];
    numEntries = 0;
}

void Scores::add(const GameEntry& e) {
    int newScore = e.getScore();
    if (numEntries == maxEntries) {
        if (numEntries == maxEntries) {
            if (newScore <= entries[maxEntries - 1].getScore())
                return;
        }
        else
            numEntries++;

        int i = numEntries - 2;
        while ( i >= 0 && newScore > entries[i].getScore()) {
            entries[i+1] = entries[i];
            i--;
        }
        entries[i+1] = e;
    }
}

GameEntry Scores::remove(int i) noexcept(false) {
    if((i < 0) || (i >= numEntries))
        throw std::out_of_range("Invalid index");
    GameEntry e = entries[i];
    for (int j = i + 1; j < numEntries; j++)
        entries[j-1] = entries[j];
    numEntries--;
    return e;
}

Scores::~Scores() {
    delete[] entries;
}