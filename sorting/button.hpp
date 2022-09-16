#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <functional>
#include "gui_component.hpp"

class Button : public GuiComponent
{
public:
    Button(sf::Font &font, sf::String label);
    void draw(sf::RenderWindow *window);
    void handleEvent(sf::Event *event, sf::RenderWindow *window);
    void onClick(std::function<void()> callback);
    void setPosition(float x, float y);
    void setColor(sf::Color color);
    void setHoverColor(sf::Color color);
    void setActive(const bool active);

    float getWidth() const;
    float getHeigth() const;

private:
    sf::Text m_text;
    std::function<void()> m_click;
    sf::Color m_color;
    sf::Color m_hoverColor;
    bool m_isActive;
};

#endif