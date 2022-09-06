#include "bubble_sort.hpp"
#include <iostream>

void BubbleSort::sort(std::vector<sf::RectangleShape> &v, sf::RenderWindow &window)
{
    const int SIZE = 200;
    const int X_MARGIN = 5;
    int n = v.size();
    sf::Color red = sf::Color::Red;
    sf::Color white = sf::Color::White;
    sf::Color green = sf::Color::Green;

    for (int i = 0; i < n - 1; i++)
    {

        for (int j = 0; j < n - i - 1; j++)
        {
            v[j].setFillColor(red);
            if (v[j].getSize().y > v[j + 1].getSize().y)
            {
                std::swap(v[j], v[j + 1]);
                v[j].setPosition(j * SIZE / n * X_MARGIN, 400);
                v[j + 1].setPosition((j + 1) * SIZE / n * X_MARGIN, 400);
            }

            if (j == n - i - 2)
            {
                v[j + 1].setFillColor(green);
            }

            window.clear();
            for (int d = 0; d < n; d++)
            {
                window.draw(v[d]);
            }
            window.display();
            sf::sleep(sf::milliseconds(5.0f));
            v[j].setFillColor(white);
        }
    }
}
