#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <SFML/Graphics.hpp>
#include "chessboardcell.h"

class ChessPiece
{
public:
    ChessPiece(sf::RenderWindow &window, const char *imagePath);
    ChessPiece(const ChessPiece &other);
    ~ChessPiece();
    void draw();
    void handleEvent(const sf::Event &event);
    void setToCell(ChessBoardCell &toCell);
    void setPosition(const float x, const float y);

private:
    sf::RenderWindow *m_Window;
    sf::Sprite m_Sprite;
    sf::Texture m_Texture;
    ChessBoardCell *m_ToCell;
    bool m_MousePressed = false;
};

#endif