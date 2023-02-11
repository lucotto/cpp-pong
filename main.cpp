#include "gameinterface.h"
#include "player.h"

int main(){
    initscr();
    noecho();
    curs_set(0);
    cbreak();

    GameInterface gameInterface;
    Player player1(gameInterface, 'w', 's');
    Player player2(gameInterface, 'i', 'k');

    gameInterface.board();
    gameInterface.text();
    gameInterface.key();

    while (true){
        gameInterface.player(player1, player2);
        player1.move();
        player2.move();
    }

    getch();
    endwin();
    return 0;
}