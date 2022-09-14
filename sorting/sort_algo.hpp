#ifndef SORT_ALGO_H
#define SORT_ALGO_H

#include <SFML/Graphics.hpp>

class SortAlgo
{
public:
    SortAlgo();
    ~SortAlgo();
    virtual void sort(std::vector<sf::RectangleShape> &lines, sf::RenderWindow &window) = 0;

private:
};

#endif