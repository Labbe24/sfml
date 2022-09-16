#ifndef SLIDER_H
#define SLIDER_H

#include <SFML/Graphics.hpp>
#include "gui_component.hpp"

class Slider : public GuiComponent
{
public:
    Slider(const int min, const int max);
    ~Slider();
    void draw(sf::RenderWindow *window);
    void handleEvent(sf::Event *event, sf::RenderWindow *window);
    void update(sf::RenderWindow *window);
    void setPosition(const float x, const float y);
    void setMax(const int max);
    void setMin(const int min);
    void setColor(const sf::Color color);
    void setHoverColor(const sf::Color hoverColor);
    void setText(sf::Text *text);
    float getWidth() const;
    int getValue() const;

private:
    void setValue(const unsigned int value);
    int m_value;
    int m_max;
    int m_min;
    sf::RectangleShape m_rectangle;
    sf::CircleShape m_circle;
    sf::Color m_color;
    sf::Color m_hoverColor;
    sf::Text *m_text;
    bool m_isMouseLeftPressed = false;
};

#endif