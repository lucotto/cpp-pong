#ifndef PLAYERS_H
#define PLAYERS_H

#include <vector>
#include <windows.h>

#include "gameinterface.h"

class GameInterface;

class Player{
    public:
        Player(GameInterface &gameInterface, char upKey, char downKey);

        void move();

        COORD getBarPiece(int num);
        int getLen() {return this->len;}

    private:
        std::vector<COORD> bar;
        int len, vel;
        char upKey, downKey;
        int score;
        
        GameInterface &gameinterface;
};

#endif