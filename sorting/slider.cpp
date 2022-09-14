#include <iostream>
#include "slider.hpp"

Slider::Slider(const int min, const int max)
{
    rectangle_.setSize(sf::Vector2f(300, 5));
    rectangle_.setPosition(400, 35);

    circle_.setRadius(15);
    circle_.setPosition(400, 23);

    min_ = min;
    max_ = max;
    value_ = min;
}

void Slider::draw(sf::RenderWindow &window)
{
    window.draw(rectangle_);
    window.draw(circle_);
}

void Slider::handleEvent(sf::Event event, sf::RenderWindow &window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (circle_.getGlobalBounds().contains(mousePos.x, mousePos.y))
        {
            circle_.setFillColor(hoverColor_);
            isMouseLeftPressed_ = true;
        }
    }
    else if (event.type == sf::Event::MouseButtonReleased && !sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        circle_.setFillColor(color_);
        isMouseLeftPressed_ = false;
    }
}

void Slider::update(sf::RenderWindow &window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    if (isMouseLeftPressed_)
    {
        if (rectangle_.getGlobalBounds().contains(mousePos.x, rectangle_.getPosition().y))
        {
            circle_.setPosition(mousePos.x - circle_.getRadius(), circle_.getPosition().y);
            setValue(mousePos.x);
        }
    }
}

void Slider::setPosition(const float x, const float y)
{
    rectangle_.setPosition(x, y + 12);
    circle_.setPosition(x, y);
}

void Slider::setMax(const int max)
{
    max_ = max;
}

void Slider::setMin(const int min)
{
    min_ = min;
}

void Slider::setColor(const sf::Color color)
{
    rectangle_.setFillColor(color);
    color_ = color;
}

void Slider::setHoverColor(const sf::Color hoverColor)
{
    hoverColor_ = hoverColor;
}

float Slider::getWidth() const
{
    return rectangle_.getGlobalBounds().width;
}

int Slider::getValue() const
{
    return value_;
}

void Slider::setValue(int value)
{
    float lowerBound = rectangle_.getPosition().x;
    float upperBound = rectangle_.getSize().x;
    float v = value - lowerBound;
    float newValue = (v / upperBound) * max_;

    if (newValue < min_)
    {
        newValue = min_;
    }

    value_ = newValue;
}
