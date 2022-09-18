#ifndef CHESSBOARDCELL_H
#define CHESSBOARDCELL_H

#include <SFML/Graphics.hpp>

class ChessBoardCell
{
public:
    ChessBoardCell();
    ChessBoardCell(sf::RenderWindow &window, sf::Color color);
    void draw();
    void handleEvent(const sf::Event &event);
    void setPosition(const float x, const float y);
    sf::Vector2i getPosition() const;
    bool contains(const sf::Vector2i position) const;
    void setAvailable(const bool available);
    bool isAvailable() const;
    bool isSelected() const;

private:
    sf::RenderWindow *m_Window = nullptr;
    sf::RectangleShape m_Reactangle;
    sf::Color m_Color;
    bool m_IsAvailable = true;
    bool m_IsSelected = false;
};

#endif