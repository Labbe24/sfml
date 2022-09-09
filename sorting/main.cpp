#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <random>
#include <algorithm>
#include <iostream>
#include "bubble_sort.hpp"

const int NUM = 20;
const int WIDTH = 200;
const int WIN_WIDTH = 1000;
const int WIN_HEIGHT = 650;
const int X_MARGIN = 5;

int main()
{
    std::random_device rd;
    sf::Color white = sf::Color::White;
    auto rng = std::default_random_engine{rd()};
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Sorting visualizer");
    BubbleSort bubble_sort = BubbleSort();
    std::vector<sf::RectangleShape> lines;
    const float height_multiplier = WIN_HEIGHT / NUM;

    for (int i = 0; i < NUM; i++)
    {
        sf::RectangleShape line(sf::Vector2f(WIDTH / NUM * 2, i * height_multiplier));
        line.rotate(180);
        line.setPosition(i * WIDTH / NUM * X_MARGIN, WIN_HEIGHT);
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
                // SHUFFLE
                if (event.key.code == sf::Keyboard::Space)
                {
                    std::shuffle(std::begin(lines), std::end(lines), rng);
                    for (int i = 0; i < NUM; i++)
                    {
                        lines[i].setFillColor(white);
                        lines[i].setPosition(i * WIDTH / NUM * X_MARGIN, WIN_HEIGHT);
                    }
                }
                // SORT
                else if (event.key.code == sf::Keyboard::Enter)
                {
                    bubble_sort.sort(lines, window);
                }
            }

            // NUMBER INPUT
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode > 47 && event.text.unicode < 59)
                {
                    sf::String input = event.text.unicode;
                    std::cout << input.toAnsiString() << std::endl;
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