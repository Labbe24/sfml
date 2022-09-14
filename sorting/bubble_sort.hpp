#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <SFML/Graphics.hpp>
#include "sort_algo.hpp"

class BubbleSort : public SortAlgo
{
public:
    void sort(std::vector<sf::RectangleShape> &v, sf::RenderWindow &window);
    void setSpeed(const float speed);

private:
    float speed_;
};

#endif