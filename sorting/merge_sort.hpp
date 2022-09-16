#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <SFML/Graphics.hpp>
#include "sort_algo.hpp"
#include "button.hpp"

class MergeSort : public SortAlgo
{
public:
    MergeSort();
    ~MergeSort();
    void sort(std::vector<sf::RectangleShape> &lines, sf::RenderWindow &window);
    void setSpeed(const float speed);

private:
    void mergeSort(std::vector<sf::RectangleShape> &lines, const int start, const int end, sf::RenderWindow &window);
    void merge(std::vector<sf::RectangleShape> &lines, const int start, const int mid, const int end, sf::RenderWindow &window);
    float m_speed;
    Button *m_cancleBtn;
};

#endif