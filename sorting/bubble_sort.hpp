#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <SFML/Graphics.hpp>
#include "configuration.hpp"

class BubbleSort
{
public:
    void sort(std::vector<sf::RectangleShape> &v, sf::RenderWindow &window);
    void setSpeed(const float speed);

private:
    float speed_;
};

#endif