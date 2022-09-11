#include <iostream>
#include "slider.hpp"

Slider::Slider()
{
    rectangle_.setSize(sf::Vector2f(300, 5));
    // rectangle_.setOutlineColor(sf::Color::Red);
    // rectangle_.setOutlineThickness(5);
    rectangle_.setPosition(400, 35);

    circle_.setRadius(15);
    // circle_.setOutlineColor(sf::Color::Red);
    // circle_.setOutlineThickness(5);
    circle_.setPosition(400, 23);

    value_ = 420;
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
            circle_.setFillColor(sf::Color::Green);
            isMouseLeftPressed_ = true;
        }
    }
    else if (event.type == sf::Event::MouseButtonReleased && !sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        circle_.setFillColor(sf::Color::White);
        isMouseLeftPressed_ = false;
    }
}

void Slider::update(sf::RenderWindow &window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    if (isMouseLeftPressed_)
    {
        if (rectangle_.getGlobalBounds().contains(mousePos.x - circle_.getRadius(), rectangle_.getPosition().y))
        {
            circle_.setPosition(mousePos.x - circle_.getRadius(), circle_.getPosition().y);
            setValue(mousePos.x - circle_.getRadius());
        }
    }
}

int Slider::getValue() const
{
    return value_;
}

void Slider::setValue(int value)
{
    // set value_ between 20 and 100
    float lowerBound = rectangle_.getPosition().x;
    float upperBound = rectangle_.getSize().x;
    float v = value - lowerBound;
    float newValue = (v / upperBound) * 200;

    if (newValue < 20)
    {
        newValue = 20;
    }

    value_ = newValue;
}
