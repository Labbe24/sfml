#include <iostream>
#include "chesspiece.h"

ChessPiece::ChessPiece(sf::RenderWindow &window, const char *imagePath)
    : m_Window(&window)
{
    m_Texture = new sf::Texture();
    if (m_Texture->loadFromFile(imagePath))
    {
        m_Texture->setSmooth(true);
        m_Sprite.setTexture(*m_Texture);
    }
}

ChessPiece::~ChessPiece()
{
    delete m_Texture;
}

void ChessPiece::draw()
{
    m_Window->draw(m_Sprite);
}

void ChessPiece::setPosition(const float x, const float y)
{
    m_Sprite.setPosition(x, y);
}