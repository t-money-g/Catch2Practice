//
// Created by tyoun on 10/24/2021.
//
// Using arrays exploring a few applications of arrays.


#ifndef GAMEENTRY_H
#define GAMEENTRY_H

#include<string>

class GameEntry {
public:
    GameEntry(const std::string& n="", int s =0);
    std::string getName()  const;
    int getScore() const;
private:
    std::string name;
    int score;
};


#endif //GAMEENTRY_H
