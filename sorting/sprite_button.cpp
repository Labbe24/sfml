#include "sprite_button.hpp"
#include <iostream>

SpriteButton::SpriteButton(sf::String imagePath)
{
    sf::Texture texture;
    if (texture.loadFromFile(imagePath))
    {
        texture.setSmooth(true);
        m_texture = texture;
        sf::Sprite sprite;
        sprite.setTexture(m_texture);
        m_sprite = sprite;
    }
}

void SpriteButton::draw(sf::RenderWindow &window)
{
    window.draw(m_sprite);
}

void SpriteButton::onClick(std::function<void()> callback)
{
    m_click = callback;
}

void SpriteButton::handleEvent(sf::Event event, sf::RenderWindow &window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    if (m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
    {
        m_sprite.setColor(m_hoverColor);
        if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (m_click != NULL)
            {
                m_click();
            }
            m_sprite.setColor(m_color);
        }
    }
    else
    {
        m_sprite.setColor(m_color);
    }
}

void SpriteButton::setPosition(float x, float y)
{
    m_sprite.setPosition(x, y);
}

void SpriteButton::setColor(sf::Color color)
{
    m_color = color;
}

void SpriteButton::setHoverColor(sf::Color color)
{
    m_hoverColor = color;
}

float SpriteButton::getWidth() const
{
    return m_sprite.getGlobalBounds().width;
}