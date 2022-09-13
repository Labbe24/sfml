#ifndef SLIDER_H
#define SLIDER_H

#include <SFML/Graphics.hpp>

class Slider
{
public:
    Slider(const int min, const int max);
    void draw(sf::RenderWindow &window);
    void handleEvent(sf::Event event, sf::RenderWindow &window);
    void update(sf::RenderWindow &window);
    void setPosition(const float x, const float y);
    void setMax(const int max);
    void setMin(const int min);
    void setColor(const sf::Color color);
    void setHoverColor(const sf::Color hoverColor);
    float getWidth() const;
    int getValue() const;

private:
    int value_;
    int max_;
    int min_;
    void setValue(int value);
    sf::RectangleShape rectangle_;
    sf::CircleShape circle_;
    sf::Color color_;
    sf::Color hoverColor_;
    bool isMouseLeftPressed_ = false;
};

#endif