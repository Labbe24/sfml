#ifndef SPRITE_BUTTON_H
#define SPRITE_BUTTON_H

#include <SFML/Graphics.hpp>
#include <functional>

class SpriteButton
{
public:
    SpriteButton(sf::String imagePath);
    void draw(sf::RenderWindow &window);
    void handleEvent(sf::Event event, sf::RenderWindow &window);
    void onClick(std::function<void()> callback);
    void setColor(sf::Color color);
    void setHoverColor(sf::Color color);
    void setPosition(float x, float y);
    float getWidth() const;

private:
    sf::Sprite sprite_;
    sf::Texture texture_;
    std::function<void()> click_;
    sf::Color color_;
    sf::Color hoverColor_;
};

#endif
