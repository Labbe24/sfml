#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <random>
#include <algorithm>
#include <iostream>
#include "bubble_sort.hpp"
#include "button.hpp"
#include "slider.hpp"

const int WIDTH = 200;
const int WIN_WIDTH = 1000;
const int WIN_HEIGHT = 650;
const int X_MARGIN = 5;
bool isMenuWindow = true;

// CALLBACK FUNCTIONS
void startBtnOnClick()
{
    isMenuWindow = false;
}

void backToMenuBtnOnClick()
{
    isMenuWindow = true;
}

std::vector<sf::RectangleShape> createLines(int count)
{
    std::vector<sf::RectangleShape> lines;
    const float heightMultiplier = WIN_HEIGHT / count - 5;
    const float height = ((float)WIN_HEIGHT - 70) / (float)count;
    const float width = (float)WIN_WIDTH / (float)count;

    for (int i = 1; i < count + 1; i++)
    {
        sf::RectangleShape line(sf::Vector2f(width, i * height));
        line.rotate(180);
        line.setPosition(i * width, WIN_HEIGHT);
        lines.push_back(line);
    }
    return lines;
}

void shuffleLines(std::vector<sf::RectangleShape> &lines)
{
    std::random_device rd;
    auto rng = std::default_random_engine{rd()};
    std::shuffle(std::begin(lines), std::end(lines), rng);
    int count = lines.size();
    const float width = (float)WIN_WIDTH / (float)count;

    for (int i = 0; i < count; i++)
    {
        lines[i].setFillColor(sf::Color::White);
        lines[i].setPosition(i * width, WIN_HEIGHT);
    }
}

int main()
{
    int num = 420;

    std::random_device rd;
    sf::Color white = sf::Color::White;
    sf::Color blue = sf::Color::Blue;

    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Sorting visualizer");

    auto rng = std::default_random_engine{rd()};
    BubbleSort bubble_sort = BubbleSort();
    std::vector<sf::RectangleShape> lines;
    const float heightMultiplier = WIN_HEIGHT / num - 5;

    sf::Font font;
    if (!font.loadFromFile("peach_days.ttf"))
        return EXIT_FAILURE;

    // SLIDER
    Slider slider;

    // NUM INPUT
    sf::String input;
    sf::Text numInput;
    numInput.setFont(font);
    numInput.setPosition(WIN_WIDTH - 80, 20);
    numInput.setString(std::to_string(num));

    // MENU TITLE
    sf::Text menuTitle("Sorting visulizer", font);
    menuTitle.setPosition(WIN_WIDTH / 2 - 120, 20);
    menuTitle.setFillColor(sf::Color::Black);

    // MENU BUTTONS
    Button menuStartBtn(font, "Start", 460, 100);
    menuStartBtn.onClick(startBtnOnClick);
    menuStartBtn.setHoverColor(sf::Color::Green);

    Button backToMenuBtn(font, "Back", 40, 20);
    backToMenuBtn.onClick(backToMenuBtnOnClick);
    backToMenuBtn.setColor(sf::Color::White);
    backToMenuBtn.setHoverColor(sf::Color::Red);

    lines = createLines(num);

    while (window.isOpen())
    {
        sf::Event event;
        if (!isMenuWindow)
        {
            while (window.pollEvent(event))
            {
                backToMenuBtn.handleEvent(event, window);
                slider.handleEvent(event, window);

                if (event.type == sf::Event::Closed)
                    window.close();

                if (event.type == sf::Event::EventType::KeyPressed)
                {
                    // SHUFFLE
                    if (event.key.code == sf::Keyboard::Space)
                    {
                        shuffleLines(lines);
                    }
                    // SORT
                    else if (event.key.code == sf::Keyboard::Enter)
                    {
                        bubble_sort.sort(lines, window);
                    }
                    else if (event.key.code == sf::Keyboard::Escape)
                    {
                        isMenuWindow = true;
                    }
                    else if (event.key.code == sf::Keyboard::BackSpace)
                    {
                        if (input.getSize() > 0)
                        {
                            input.erase(input.getSize() - 1, 1);
                            numInput.setString(input);
                        }
                    }
                }

                // NUMBER INPUT
                // if (event.type == sf::Event::TextEntered)
                // {
                //     if (event.text.unicode > 47 && event.text.unicode < 59)
                //     {
                //         if (input.getSize() < 3)
                //         {
                //             input += event.text.unicode;
                //             // NUM = stoi(input.toAnsiString());
                //             numInput.setString(input);
                //         }
                //     }
                // }
            }

            slider.update(window);
            int newNum = slider.getValue();
            if (newNum != num)
            {
                num = newNum;
                std::string sliderValue = std::to_string(newNum);
                numInput.setString(sliderValue);
                lines = createLines(num);
            }

            window.clear();
            for (auto it = std::begin(lines); it != std::end(lines); it++)
            {
                window.draw(*it);
            }
            window.draw(numInput);
            slider.draw(window);
            backToMenuBtn.draw(window);
            window.display();
        }
        else if (isMenuWindow)
        {
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                menuStartBtn.handleEvent(event, window);
            }
            window.clear(sf::Color::White);
            window.draw(menuTitle);
            menuStartBtn.draw(window);
            window.display();
        }
    }

    return 0;
}