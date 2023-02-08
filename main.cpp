#include "interface.h"

int main(){
    Interface interface;

    initscr();
    noecho();
    curs_set(0);
    cbreak();

    interface.board();
    interface.text();

    getch();
    endwin();
    return 0;
}