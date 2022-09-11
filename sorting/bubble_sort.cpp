#include "bubble_sort.hpp"
#include <iostream>

void BubbleSort::sort(std::vector<sf::RectangleShape> &v, sf::RenderWindow &window)
{
    const int win_width = window.getSize().x;
    const int win_height = window.getSize().y;
    const int count = v.size();
    const float width = (float)win_width / (float)count;

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            v[j].setFillColor(sf::Color::Red);
            if (v[j].getSize().y > v[j + 1].getSize().y)
            {
                std::swap(v[j], v[j + 1]);
                v[j].setPosition((j + 1) * width, win_height);
                v[j + 1].setPosition((j + 2) * width, win_height);
            }

            if (j == count - i - 2)
            {
                v[j + 1].setFillColor(sf::Color::Green);
            }

            window.clear();
            for (int d = 0; d < count; d++)
            {
                window.draw(v[d]);
            }
            window.display();
            sf::sleep(sf::milliseconds(5.0f));
            v[j].setFillColor(sf::Color::White);
        }
    }
}
