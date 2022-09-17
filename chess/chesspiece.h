#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <SFML/Graphics.hpp>

class ChessPiece
{
public:
    ChessPiece(sf::RenderWindow &window, const char *imagePath);
    ~ChessPiece();
    void draw();
    void setPosition(const float x, const float y);

private:
    sf::RenderWindow *m_Window;
    sf::Sprite m_Sprite;
    sf::Texture *m_Texture;
};

#endif