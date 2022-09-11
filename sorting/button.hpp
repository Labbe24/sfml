#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <functional>

class Button
{
public:
    Button(sf::Font &font, sf::String label, float x, float y);
    void draw(sf::RenderWindow &window);
    void handleEvent(sf::Event event, sf::RenderWindow &window);
    void onClick(std::function<void()> callback);
    void setColor(sf::Color color);
    void setHoverColor(sf::Color color);

private:
    sf::Text text_;
    std::function<void()> click_;
    sf::Color color_;
    sf::Color hoverColor_;
};

#endif