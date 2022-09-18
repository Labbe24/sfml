#include <iostream>
#include "chesspiece.h"

ChessPiece::ChessPiece(sf::RenderWindow &window, const char *imagePath)
    : m_Window(&window)
{
    sf::Texture texture;
    if (texture.loadFromFile(imagePath))
    {
        texture.setSmooth(true);
        m_Texture = texture;
        m_Sprite.setTexture(m_Texture);
    }
}

ChessPiece::ChessPiece(const ChessPiece &other)
{
    m_Window = other.m_Window;
    m_Texture = other.m_Texture;
    m_Sprite = other.m_Sprite;
}

ChessPiece::~ChessPiece()
{
    // delete m_Texture;
}

void ChessPiece::draw()
{
    m_Window->draw(m_Sprite);
}

void ChessPiece::handleEvent(const sf::Event &event)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*m_Window);

    if (event.type == sf::Event::MouseButtonPressed && m_Sprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
    {
        m_MousePressed = true;
    }
    else if (m_MousePressed && event.type == sf::Event::MouseButtonReleased)
    {
        m_MousePressed = false;
        sf::Vector2i toPos = m_ToCell->getPosition();
        setPosition(toPos.x + 20.f, toPos.y + 20.f);
        m_ToCell->setAvailable(false);
    }

    if (m_MousePressed)
    {
        setPosition(mousePos.x - 20.f, mousePos.y - 20.f);
    }
}

void ChessPiece::setToCell(ChessBoardCell &toCell)
{
    m_ToCell = &toCell;
}

void ChessPiece::setPosition(const float x, const float y)
{
    m_Sprite.setPosition(x, y);
}