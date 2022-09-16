#include <iostream>
#include "slider.hpp"

Slider::Slider(const int min, const int max)
{
    m_rectangle.setSize(sf::Vector2f(300, 5));
    m_rectangle.setPosition(400, 35);

    m_circle.setRadius(15);
    m_circle.setPosition(400, 23);

    m_min = min;
    m_max = max;
    m_value = min;
}

Slider::~Slider()
{
    delete m_text;
}

void Slider::draw(sf::RenderWindow *window)
{
    if (m_text != nullptr)
    {
        int newSpeed = getValue();
        std::string sliderValue = std::to_string(newSpeed);
        m_text->setString(sliderValue);
        window->draw(*m_text);
    }
    window->draw(m_rectangle);
    window->draw(m_circle);
}

void Slider::handleEvent(sf::Event *event, sf::RenderWindow *window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

    if (event->type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (m_circle.getGlobalBounds().contains(mousePos.x, mousePos.y))
        {
            m_circle.setFillColor(m_hoverColor);
            m_isMouseLeftPressed = true;
        }
    }
    else if (event->type == sf::Event::MouseButtonReleased && !sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        m_circle.setFillColor(m_color);
        m_isMouseLeftPressed = false;
    }
    if (m_isMouseLeftPressed)
    {
        if (m_rectangle.getGlobalBounds().contains(mousePos.x, m_rectangle.getPosition().y))
        {
            m_circle.setPosition(mousePos.x - m_circle.getRadius(), m_circle.getPosition().y);
            setValue(mousePos.x);
        }
    }
}

void Slider::update(sf::RenderWindow *window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

    if (m_isMouseLeftPressed)
    {
        if (m_rectangle.getGlobalBounds().contains(mousePos.x, m_rectangle.getPosition().y))
        {
            m_circle.setPosition(mousePos.x - m_circle.getRadius(), m_circle.getPosition().y);
            setValue(mousePos.x);
        }
    }
}

void Slider::setPosition(const float x, const float y)
{
    m_rectangle.setPosition(x, y + 12);
    m_circle.setPosition(x, y);
}

void Slider::setMax(const int max)
{
    m_max = max;
}

void Slider::setMin(const int min)
{
    m_min = min;
}

void Slider::setColor(const sf::Color color)
{
    m_rectangle.setFillColor(color);
    m_circle.setFillColor(color);
    m_color = color;
}

void Slider::setHoverColor(const sf::Color hoverColor)
{
    m_hoverColor = hoverColor;
}

void Slider::setText(sf::Text *text)
{
    m_text = text;
}

float Slider::getWidth() const
{
    return m_rectangle.getGlobalBounds().width;
}

int Slider::getValue() const
{
    return m_value;
}

void Slider::setValue(const unsigned int value)
{
    float lowerBound = m_rectangle.getPosition().x;
    float upperBound = m_rectangle.getSize().x;
    float v = value - lowerBound;
    float newValue = (v / upperBound) * m_max;

    if (newValue < m_min)
    {
        newValue = m_min;
    }

    m_value = newValue;
}
