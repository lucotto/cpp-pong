#include "interface.h"

int main(){
    initscr();
    noecho();
    curs_set(0);
    cbreak();

    Interface interface;

    interface.board();
    interface.text();
    interface.key();

    getch();
    endwin();
    return 0;
}