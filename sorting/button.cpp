#include "button.hpp"

Button::Button(sf::Font &font, sf::String label)
{
    text_.setFont(font);
    text_.setString(label);
    color_ = sf::Color::Black;
    hoverColor_ = sf::Color::White;

    text_.setFillColor(color_);
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
            if (click_ != NULL)
            {
                click_();
            }
            text_.setFillColor(color_);
        }
    }
    else
    {
        text_.setFillColor(color_);
    }
}

void Button::setPosition(float x, float y)
{
    text_.setPosition(x, y);
}

void Button::setColor(sf::Color color)
{
    color_ = color;
}

void Button::setHoverColor(sf::Color color)
{
    hoverColor_ = color;
}

float Button::getWidth() const
{
    return text_.getGlobalBounds().width;
}

float Button::getHeigth() const
{
    return text_.getGlobalBounds().height;
}