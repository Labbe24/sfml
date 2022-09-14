#include "button.hpp"

Button::Button(sf::Font &font, sf::String label)
{
    text_.setFont(font);
    text_.setString(label);
    color_ = sf::Color::Black;
    hoverColor_ = sf::Color::White;

    text_.setFillColor(color_);
    isActive_ = false;
}

void Button::draw(sf::RenderWindow &window)
{
    if (isActive_)
    {
        text_.setFillColor(sf::Color::Yellow);
    }
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
            // isActive_ = true;
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

void Button::setActive(const bool active)
{
    isActive_ = active;
}

float Button::getWidth() const
{
    return text_.getGlobalBounds().width;
}

float Button::getHeigth() const
{
    return text_.getGlobalBounds().height;
}