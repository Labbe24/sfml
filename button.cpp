#include "button.hpp"

Button::Button(sf::Font &font, sf::String label, float x, float y)
{
    text_.setFont(font);
    text_.setString(label);
    text_.setPosition(x, y);
    color_ = sf::Color::Black;
    hoverColor_ = sf::Color::White;
}

void Button::draw(sf::RenderWindow &window)
{
    window.draw(text_);
}

void Button::onClick(std::function<void()> callback)
{
    click_ = callback;
}

void Button::handleEvent(sf::Event event, sf::RenderWindow &window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    if (text_.getGlobalBounds().contains(mousePos.x, mousePos.y))
    {
        text_.setFillColor(hoverColor_);
        if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            click_();
            text_.setFillColor(color_);
        }
    }
    else
    {
        text_.setFillColor(color_);
    }
}

void Button::setColor(sf::Color color)
{
    color_ = color;
}

void Button::setHoverColor(sf::Color color)
{
    hoverColor_ = color;
}