#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <random>
#include <algorithm>
#include <iostream>

const int SIZE = 200;

int shuffle(int i)
{
    return std::rand() % i;
}

bool compare(sf::RectangleShape first, sf::RectangleShape second)
{
    return first.getSize().y < second.getSize().y;
}

void sort()
{
}

int main()
{
    std::random_device rd;
    auto rng = std::default_random_engine{rd()};
    sf::RenderWindow window(sf::VideoMode(SIZE * 5, 400), "Sorting visualizer");
    std::vector<sf::RectangleShape> lines;

    for (int i = 0; i < SIZE; i++)
    {
        sf::RectangleShape line(sf::Vector2f(2, i * 2));
        line.rotate(180);
        line.setPosition(i * 5, 400);
        lines.push_back(line);
    }

    std::shuffle(std::begin(lines), std::end(lines), rng);
    for (int i = 0; i < SIZE; i++)
    {
        lines[i].setPosition(i * 5, 400);
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
                        lines[i].setPosition(i * 5, 400);
                    }
                    std::cout << "Shuffle!" << std::endl;
                }
                else if (event.key.code == sf::Keyboard::Enter)
                {
                    std::sort(lines.begin(), lines.end(), compare);
                    for (int i = 0; i < SIZE; i++)
                    {
                        lines[i].setPosition(i * 5, 400);
                    }
                    std::cout << "Sort!" << std::endl;
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