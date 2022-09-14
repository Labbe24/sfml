#include "merge_sort.hpp"
#include <iostream>

void MergeSort::sort(std::vector<sf::RectangleShape> &lines, sf::RenderWindow &window)
{
    const int start = 0;
    const int end = lines.size() - 1;
    mergeSort(lines, start, end, window);
}

void MergeSort::mergeSort(std::vector<sf::RectangleShape> &lines, const int start, const int end, sf::RenderWindow &window)
{
    if (start >= end)
    {
        return;
    }
    const int mid = (start + end) / 2;
    mergeSort(lines, start, mid, window);
    mergeSort(lines, mid + 1, end, window);
    merge(lines, start, mid, end, window);
}

void MergeSort::merge(std::vector<sf::RectangleShape> &lines, const int start, const int mid, const int end, sf::RenderWindow &window)
{
    // DRAWING VARIABLES
    const int win_width = window.getSize().x;
    const int win_height = window.getSize().y;
    const int count = lines.size();
    const float width = (float)win_width / (float)count;

    // COMPUTE SIZE OF SUB-ARRAYS
    const int leftSize = mid - start + 1;
    const int rightSize = end - mid;
    sf::RectangleShape left[leftSize];
    sf::RectangleShape right[rightSize];

    // COPY ELEMENTS INTO SUB-ARRAYS
    for (int i = 0; i < leftSize; i++)
    {
        left[i] = lines[start + i];
    }

    for (int j = 0; j < rightSize; j++)
    {
        right[j] = lines[mid + j + 1];
    }

    int i = 0, j = 0, k = start;

    // MERGE SUB-ARRAYS INTO ARRAY
    while (i < leftSize && j < rightSize)
    {
        if (left[i].getSize().y < right[j].getSize().y)
        {
            lines[k] = left[i];
            lines[k].setPosition(k * width, win_height);
            lines[k].setFillColor(sf::Color::Red);
            i++;
        }
        else if (right[j].getSize().y <= left[i].getSize().y)
        {
            lines[k] = right[j];
            lines[k].setPosition(k * width, win_height);
            lines[k].setFillColor(sf::Color::Red);
            j++;
        }

        // DRAW
        window.clear();
        for (int d = 0; d < count; d++)
        {
            window.draw(lines[d]);
        }
        window.display();
        sf::sleep(sf::milliseconds(100.0f - speed_));
        lines[k].setFillColor(sf::Color::White);

        k++;
    }

    // INSERT REMAINING ELEMENTS
    while (i < leftSize)
    {
        lines[k] = left[i];
        lines[k].setPosition(k * width, win_height);

        // DRAW
        window.clear();
        for (int d = 0; d < count; d++)
        {
            window.draw(lines[d]);
        }
        window.display();
        sf::sleep(sf::milliseconds(100.0f - speed_));
        lines[k].setFillColor(sf::Color::White);

        k++;
        i++;
    }

    while (j < rightSize)
    {
        lines[k] = right[j];
        lines[k].setPosition(k * width, win_height);

        // DRAW
        window.clear();
        for (int d = 0; d < count; d++)
        {
            window.draw(lines[d]);
        }
        window.display();
        sf::sleep(sf::milliseconds(100.0f - speed_));
        lines[k].setFillColor(sf::Color::White);

        k++;
        j++;
    }
}

void MergeSort::setSpeed(const float speed)
{
    speed_ = speed;
}