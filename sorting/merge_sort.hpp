#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <SFML/Graphics.hpp>

class MergeSort
{
public:
    void sort(std::vector<sf::RectangleShape> &lines, const int start, const int end, sf::RenderWindow &window);
    void setSpeed(const float speed);

private:
    void merge(std::vector<sf::RectangleShape> &lines, const int start, const int mid, const int end, sf::RenderWindow &window);
    float speed_;
};

#endif