#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <random>
#include <algorithm>
#include <iostream>
#include "bubble_sort.hpp"

const int NUM = 200;
const int SIZE = 200;
const int Y_POSITION = 400;
const int X_MARGIN = 5;

int main()
{
    std::random_device rd;
    sf::Color white = sf::Color::White;
    auto rng = std::default_random_engine{rd()};
    sf::RenderWindow window(sf::VideoMode(1000, Y_POSITION), "Sorting visualizer");
    BubbleSort bubble_sort = BubbleSort();
    std::vector<sf::RectangleShape> lines;

    for (int i = 0; i < NUM; i++)
    {
        sf::RectangleShape line(sf::Vector2f(SIZE / NUM * 2, i * 2));
        line.rotate(180);
        line.setPosition(i * SIZE / NUM * X_MARGIN, Y_POSITION);
        lines.push_back(line);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::EventType::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    std::shuffle(std::begin(lines), std::end(lines), rng);
                    for (int i = 0; i < SIZE; i++)
                    {
                        lines[i].setFillColor(white);
                        lines[i].setPosition(i * SIZE / NUM * X_MARGIN, Y_POSITION);
                    }
                    std::cout << "Shuffled!" << std::endl;
                }
                else if (event.key.code == sf::Keyboard::Enter)
                {
                    bubble_sort.sort(lines, window);
                    std::cout << "Sorted!" << std::endl;
                }
            }
        }

        window.clear();
        for (auto it = std::begin(lines); it != std::end(lines); it++)
        {
            window.draw(*it);
        }

        window.display();
    }

    return 0;
}