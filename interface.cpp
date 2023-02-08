#include "interface.h"

void Interface::board(){
    int tRow, tCol;
    getmaxyx(stdscr, tRow, tCol);

    int startRow = (tRow - BOARD_H) / 2;
    int startCol = (tCol - BOARD_W) / 2;

    WINDOW *board = newwin(BOARD_H, BOARD_W, startRow, startCol);
    refresh();

    box(board, 0, 0);
    wrefresh(board);
}

void Interface::text(){
    
}