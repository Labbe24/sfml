#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <SFML/Graphics.hpp>

class BubbleSort
{
public:
    void sort(std::vector<sf::RectangleShape> &v, sf::RenderWindow &window);
};

#endif