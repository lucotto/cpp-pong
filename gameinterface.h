#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include <curses.h>

#include "const.h"
#include "player.h"

class Player;

class GameInterface{
    public:
        GameInterface();

        void board();
        void text();
        void key();
        void player(Player &p1, Player &p2);

        int getBoardStartRow();
        int getBoardStartCol();

    private:
        int termRow;
        int termCol;

        int boardStartRow;
        int boardStartCol;

        int key1StartRow;
        int key1StartCol;
        int key2StartRow;
        int key2StartCol;
};

#endif