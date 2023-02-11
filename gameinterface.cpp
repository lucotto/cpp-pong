#include "gameinterface.h"

GameInterface::GameInterface(){
    int row, col;
    getmaxyx(stdscr, row, col);

    this->termRow = row;
    this->termCol = col;

    this->boardStartRow = (this->termRow - BOARD_H) / 2;
    this->boardStartCol = (this->termCol - BOARD_W) / 2;

    this->key1StartRow = (this->termRow - KEY_H) / 2;
    this->key1StartCol = 5;
    this->key2StartRow = (this->termRow - KEY_H) / 2;
    this->key2StartCol = this->termCol - KEY_W - 5;
}

void GameInterface::board(){
    WINDOW *board = newwin(BOARD_H, BOARD_W, this->boardStartRow, this->boardStartCol);
    refresh();

    box(board, 0, 0);
    wrefresh(board);
}

void GameInterface::text(){
    int titleRow = this->boardStartRow - 4;
    int titleCol = this->boardStartCol + (BOARD_W - 4) / 2;
    int player1Row = this->boardStartRow - 1;
    int player1Col = this->boardStartCol;
    int player1ScoreRow = this->boardStartRow + BOARD_H;
    int player1ScoreCol = this->boardStartCol;
    int player2Row = this->boardStartRow - 1;
    int player2Col = this->boardStartCol + BOARD_W - 8;
    int player2ScoreRow = this->boardStartRow + BOARD_H;
    int player2ScoreCol = this->boardStartCol + BOARD_W - 8;

    mvprintw(titleRow, titleCol, "PONG");

    mvprintw(player1Row, player1Col, "Player 1");
    mvprintw(player1ScoreRow, player1ScoreCol, "Score: 0");
    mvprintw(player2Row, player2Col, "Player 2");
    mvprintw(player2ScoreRow, player2ScoreCol, "Score: 0");
    
    refresh();
}

void GameInterface::key(){
    WINDOW *key1 = newwin(KEY_H, KEY_W, this->key1StartRow, this->key1StartCol);
    WINDOW *key2 = newwin(KEY_H, KEY_W, this->key2StartRow, this->key2StartCol);
    refresh();

    box(key1, 0, 0);
    box(key2, 0 ,0);
    wrefresh(key1);
    wrefresh(key2);

    mvprintw(this->key1StartRow, this->key1StartCol + (KEY_W - 12) / 2, "Player 1 Keys");
    mvprintw(this->key1StartRow + 1, this->key1StartCol + 1, "W:");
    mvprintw(this->key1StartRow + 1, this->key1StartCol + KEY_W - 6, "Up");
    mvprintw(this->key1StartRow + 2, this->key1StartCol + 1, "S:");
    mvprintw(this->key1StartRow + 2, this->key1StartCol + KEY_W - 6, "Down");
    mvprintw(this->key1StartRow + 3, this->key1StartCol + 1, "Spacebar:");
    mvprintw(this->key1StartRow + 3, this->key1StartCol + KEY_W - 6, "Pause");
    refresh();
    mvprintw(this->key2StartRow, this->key2StartCol + (KEY_W - 12) / 2, "Player 2 Keys");
    mvprintw(this->key2StartRow + 1, this->key2StartCol + 1, "UP Arrow:");
    mvprintw(this->key2StartRow + 1, this->key2StartCol + KEY_W - 6, "Up");
    mvprintw(this->key2StartRow + 2, this->key2StartCol + 1, "DOWN Arrow:");
    mvprintw(this->key2StartRow + 2, this->key2StartCol + KEY_W - 6, "Down");
    mvprintw(this->key2StartRow + 3, this->key2StartCol + 1, "Enter:");
    mvprintw(this->key2StartRow + 3, this->key2StartCol + KEY_W - 6, "Pause");
    refresh();
}   

void GameInterface::player(Player &p1, Player &p2){
    COORD coord;

    for (int i = 0; i < p1.getLen(); i++){
        coord = p1.getBarPiece(i);
        mvaddch(coord.X, coord.Y, '|');
    }

    for (int i = 0; i < p2.getLen(); i++){
        coord = p2.getBarPiece(i);
        mvaddch(coord.X, coord.Y, '|');
    }

    refresh();
}

int GameInterface::getBoardStartRow(){
    return this->boardStartRow;
}

int GameInterface::getBoardStartCol(){
    return this->boardStartCol;
}