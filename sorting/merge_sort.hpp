#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <SFML/Graphics.hpp>
#include "sort_algo.hpp"

class MergeSort : public SortAlgo
{
public:
    void sort(std::vector<sf::RectangleShape> &lines, sf::RenderWindow &window);
    void setSpeed(const float speed);

private:
    void mergeSort(std::vector<sf::RectangleShape> &lines, const int start, const int end, sf::RenderWindow &window);
    void merge(std::vector<sf::RectangleShape> &lines, const int start, const int mid, const int end, sf::RenderWindow &window);
    float speed_;
};

#endif