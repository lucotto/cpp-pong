#include "player.h"

Player::Player(GameInterface &gameInterface, char upKey, char downKey)
    : gameinterface(gameInterface){
    COORD piece;
    short rowOffset = gameInterface.getBoardStartRow() + 6;
    short colOffset = gameInterface.getBoardStartCol();
    upKey == 'w' ? colOffset += 4 : colOffset += 55;

    this->len = 3;
    this->vel = 1;
    this->upKey = upKey;
    this->downKey = downKey;
    
    for (int i = 0; i < this->len; i++){
        piece = {(short)(rowOffset+i), colOffset};
        this->bar.push_back(piece);
    }
}

void Player::move(){
    if (getch() == this->upKey){
        for (int i = 0; i < this->bar.size(); i++){
            this->bar[i].X--;
        }
    }
    else if (getch() == this->downKey){
        for (int i = 0; i < this->bar.size(); i++){
            this->bar[i].X++;
        }
    }
}

COORD Player::getBarPiece(int num){
    auto it = this->bar.begin() + num;

    return {it->X, it->Y};
}