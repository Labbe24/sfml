#include "chessboardcell.h"
#include <iostream>

ChessBoardCell::ChessBoardCell()
{
}

ChessBoardCell::ChessBoardCell(sf::RenderWindow &window, sf::Color color)
    : m_Window(&window), m_Color(color)
{
    m_Reactangle.setSize(sf::Vector2f(100.f, 100.f));
    m_Reactangle.setFillColor(color);
}

void ChessBoardCell::draw()
{
    m_Window->draw(m_Reactangle);
}

void ChessBoardCell::handleEvent(const sf::Event &event)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*m_Window);

    if (event.type == sf::Event::MouseButtonPressed && m_Reactangle.getGlobalBounds().contains(mousePos.x, mousePos.y))
    {
        m_Reactangle.setFillColor(sf::Color::Red);
        m_IsSelected = true;
    }
    else if (event.type == sf::Event::MouseButtonPressed && !m_Reactangle.getGlobalBounds().contains(mousePos.x, mousePos.y))
    {
        m_IsSelected = false;
    }
    else
    {
        m_Reactangle.setFillColor(m_Color);
    }
}

void ChessBoardCell::setPosition(const float x, const float y)
{
    m_Reactangle.setPosition(x, y);
}

sf::Vector2i ChessBoardCell::getPosition() const
{
    sf::Vector2i pos;
    pos.x = m_Reactangle.getPosition().x;
    pos.y = m_Reactangle.getPosition().y;
    return pos;
}

bool ChessBoardCell::contains(const sf::Vector2i position) const
{
    return m_Reactangle.getGlobalBounds().contains(position.x, position.y);
}

void ChessBoardCell::setAvailable(const bool available)
{
    m_IsAvailable = available;
}

bool ChessBoardCell::isAvailable() const
{
    return m_IsAvailable;
}

bool ChessBoardCell::isSelected() const
{
    return m_IsSelected;
}