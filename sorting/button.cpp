#include "button.hpp"
#include <iostream>

Button::Button(sf::Font &font, sf::String label)
{
    m_text.setFont(font);
    m_text.setString(label);
    m_color = sf::Color::Black;
    m_hoverColor = sf::Color::White;

    m_text.setFillColor(m_color);
    m_isActive = false;
}

void Button::draw(sf::RenderWindow *window)
{
    if (m_isActive)
    {
        m_text.setFillColor(sf::Color::Yellow);
    }
    window->draw(m_text);
}

void Button::onClick(std::function<void()> callback)
{
    m_click = callback;
}

void Button::handleEvent(sf::Event *event, sf::RenderWindow *window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

    if (m_text.getGlobalBounds().contains(mousePos.x, mousePos.y))
    {
        m_text.setFillColor(m_hoverColor);
        if (event->type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (m_click != NULL)
            {
                m_click();
            }
            m_text.setFillColor(m_color);
        }
    }
    else
    {
        m_text.setFillColor(m_color);
    }
}

void Button::setPosition(float x, float y)
{
    m_text.setPosition(x, y);
}

void Button::setColor(sf::Color color)
{
    m_color = color;
    m_text.setFillColor(m_color);
}

void Button::setHoverColor(sf::Color color)
{
    m_hoverColor = color;
}

void Button::setActive(const bool active)
{
    m_isActive = active;
}

float Button::getWidth() const
{
    return m_text.getGlobalBounds().width;
}

float Button::getHeigth() const
{
    return m_text.getGlobalBounds().height;
}