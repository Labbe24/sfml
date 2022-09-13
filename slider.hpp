#ifndef SLIDER_H
#define SLIDER_H

#include <SFML/Graphics.hpp>

class Slider
{
public:
    Slider();
    void draw(sf::RenderWindow &window);
    void handleEvent(sf::Event event, sf::RenderWindow &window);
    void update(sf::RenderWindow &window);
    int getValue() const;

private:
    int value_;
    void setValue(int value);
    sf::RectangleShape rectangle_;
    sf::CircleShape circle_;
    bool isMouseLeftPressed_ = false;
};

#endif