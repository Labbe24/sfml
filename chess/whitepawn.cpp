#ifndef WHITEPAWN_H
#define WHITEPAWN_H

#include "chesspiece.h"
#include <iostream>

class WhitePawn : public ChessPiece
{
public:
    WhitePawn(sf::RenderWindow &window, const char *imagePath, const float x, const float y)
        : ChessPiece(window, imagePath, x, y)
    {
    }

    bool validMove(const ChessBoardCell chessCell)
    {
        sf::Vector2i currentPos = this->getToCell().getPosition();
        sf::Vector2i toPos = chessCell.getPosition();

        if (currentPos.y - 100 == toPos.y && currentPos.x == toPos.x)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

private:
};

#endif