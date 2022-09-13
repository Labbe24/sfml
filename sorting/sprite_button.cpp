#include "sprite_button.hpp"
#include <iostream>

SpriteButton::SpriteButton(sf::String imagePath)
{
    sf::Texture texture;
    if (texture.loadFromFile(imagePath))
    {
        texture.setSmooth(true);
        texture_ = texture;
        sf::Sprite sprite;
        sprite.setTexture(texture_);
        sprite_ = sprite;
    }
}

void SpriteButton::draw(sf::RenderWindow &window)
{
    window.draw(sprite_);
}

void SpriteButton::onClick(std::function<void()> callback)
{
    click_ = callback;
}

void SpriteButton::handleEvent(sf::Event event, sf::RenderWindow &window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    if (sprite_.getGlobalBounds().contains(mousePos.x, mousePos.y))
    {
        sprite_.setColor(hoverColor_);
        if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (click_ != NULL)
            {
                click_();
            }
            sprite_.setColor(color_);
        }
    }
    else
    {
        sprite_.setColor(color_);
    }
}

void SpriteButton::setPosition(float x, float y)
{
    sprite_.setPosition(x, y);
}

void SpriteButton::setColor(sf::Color color)
{
    color_ = color;
}

void SpriteButton::setHoverColor(sf::Color color)
{
    hoverColor_ = color;
}

float SpriteButton::getWidth() const
{
    return sprite_.getGlobalBounds().width;
}