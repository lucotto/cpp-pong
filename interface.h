#ifndef INTERFACE_H
#define INTERFACE_H

#include <curses.h>

#include "const.h"

class Interface{
    public:
        Interface();

        void board();
        void text();
        void key();

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