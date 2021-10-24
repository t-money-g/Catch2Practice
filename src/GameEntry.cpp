//
// Created by tyoun on 10/24/2021.

#include "GameEntry.h"
#include <string>

using std::string;

GameEntry::GameEntry(const std::string &n, int s)
:name(n), score(s) { }

string GameEntry::getName() const { return name; }
int GameEntry::getScore() const { return score; }

