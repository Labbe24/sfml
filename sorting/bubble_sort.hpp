#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <SFML/Graphics.hpp>
#include "configuration.hpp"

class BubbleSort
{
public:
    BubbleSort(Configuration config);
    void sort(std::vector<sf::RectangleShape> &v, sf::RenderWindow &window);

private:
    Configuration config_;
};

#endif