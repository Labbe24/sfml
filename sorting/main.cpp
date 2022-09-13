#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <random>
#include <algorithm>
#include <iostream>
#include "bubble_sort.hpp"
#include "button.hpp"
#include "slider.hpp"
#include "sprite_button.hpp"

const int WIDTH = 200;
const int WIN_WIDTH = 1000;
const int WIN_HEIGHT = 650;
const int X_MARGIN = 5;

bool isMainWindow = false;
bool isMenuWindow = true;
bool isConfigWindow = false;

// CALLBACK FUNCTIONS
void startBtnOnClick()
{
    isMenuWindow = false;
    isConfigWindow = false;
    isMainWindow = true;
}

void backToMenuBtnOnClick()
{
    isMenuWindow = true;
    isConfigWindow = false;
    isMainWindow = false;
}

void configBtnClick()
{
    isMenuWindow = false;
    isConfigWindow = true;
    isMainWindow = false;
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

// END

int main()
{
    int num = 20;
    int speedPercentage = 20;
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Sorting visualizer");
    BubbleSort bubble_sort;
    std::vector<sf::RectangleShape> lines;

    auto startSortingClick = [&]()
    {
        bubble_sort.sort(lines, window);
    };

    auto startShuffleClick = [&]()
    {
        shuffleLines(lines);
    };

    sf::Font font;
    if (!font.loadFromFile("peach_days.ttf"))
    {
        return EXIT_FAILURE;
    }

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
    menuTitle.setPosition(WIN_WIDTH / 2 - (menuTitle.getGlobalBounds().width / 2), 20);
    menuTitle.setFillColor(sf::Color::Black);

    // MENU BUTTONS
    Button menuStartBtn(font, "Start");
    menuStartBtn.setPosition(WIN_WIDTH / 2 - (menuStartBtn.getWidth() / 2), 100);
    menuStartBtn.onClick(startBtnOnClick);
    menuStartBtn.setHoverColor(sf::Color::Green);

    Button configBtn(font, "Config");
    configBtn.setPosition(WIN_WIDTH / 2 - (configBtn.getWidth() / 2), 180);
    configBtn.onClick(configBtnClick);
    configBtn.setHoverColor(sf::Color::Green);

    // MAIN BUTTONS
    Button backToMenuBtn(font, "Back");
    backToMenuBtn.setPosition(40, 20);
    backToMenuBtn.onClick(backToMenuBtnOnClick);
    backToMenuBtn.setColor(sf::Color::White);
    backToMenuBtn.setHoverColor(sf::Color::Red);

    Button startBtn(font, "Start");
    startBtn.setPosition(140, 20);
    startBtn.onClick(startSortingClick);
    startBtn.setColor(sf::Color::White);
    startBtn.setHoverColor(sf::Color::Green);

    Button shuffleBtn(font, "Shuffle");
    shuffleBtn.setPosition(240, 20);
    shuffleBtn.onClick(startShuffleClick);
    shuffleBtn.setColor(sf::Color::White);
    shuffleBtn.setHoverColor(sf::Color::Yellow);

    // CONFIG TITLE
    sf::Text configTitle("Configuration", font);
    configTitle.setPosition(WIN_WIDTH / 2 - (configTitle.getGlobalBounds().width / 2), 20);
    configTitle.setFillColor(sf::Color::Black);

    // CONFIG INPUT
    sf::Text speedInputLabel("Speed:", font);
    speedInputLabel.setPosition(WIN_WIDTH / 2 - (speedInputLabel.getGlobalBounds().width / 2 + 100), 100);
    speedInputLabel.setFillColor(sf::Color::Black);

    sf::String speedInputStr(std::to_string(speedPercentage) + "%");
    sf::Text speedInput;
    speedInput.setFont(font);
    speedInput.setString(speedInputStr);
    speedInput.setPosition(WIN_WIDTH / 2 - (speedInput.getGlobalBounds().width / 2), 100);
    speedInput.setFillColor(sf::Color::Black);

    auto increaseSpeed = [&]()
    {
        if (speedPercentage < 100)
        {
            speedPercentage++;
            sf::String newSpeed(std::to_string(speedPercentage) + "%");
            speedInput.setString(newSpeed);
        }
    };

    auto decreaseSpeed = [&]()
    {
        if (speedPercentage > 0)
        {
            speedPercentage--;
            sf::String newSpeed(std::to_string(speedPercentage) + "%");
            speedInput.setString(newSpeed);
        }
    };

    SpriteButton arrowUpBtn("arrow_up.png");
    arrowUpBtn.onClick(increaseSpeed);
    arrowUpBtn.setHoverColor(sf::Color(0, 255, 0, 128));
    arrowUpBtn.setPosition(WIN_WIDTH / 2 - (arrowUpBtn.getWidth() / 2 - 70), 80);

    SpriteButton arrowDownBtn("arrow_down.png");
    arrowDownBtn.onClick(decreaseSpeed);
    arrowDownBtn.setHoverColor(sf::Color(0, 255, 0, 128));
    arrowDownBtn.setPosition(WIN_WIDTH / 2 - (arrowDownBtn.getWidth() / 2 - 70), 120);

    sf::Text sortingInputLabel("Sorting:", font);
    sortingInputLabel.setPosition(WIN_WIDTH / 2 - (sortingInputLabel.getGlobalBounds().width / 2 + 100), 180);
    sortingInputLabel.setFillColor(sf::Color::Black);

    // CREATE LINES
    lines = createLines(num);

    while (window.isOpen())
    {
        sf::Event event;
        // MAIN VIEW
        if (isMainWindow)
        {
            backToMenuBtn.setColor(sf::Color::White);
            while (window.pollEvent(event))
            {
                shuffleBtn.handleEvent(event, window);
                startBtn.handleEvent(event, window);
                backToMenuBtn.handleEvent(event, window);
                slider.handleEvent(event, window);

                if (event.type == sf::Event::Closed)
                    window.close();

                if (event.type == sf::Event::EventType::KeyPressed)
                {
                    // if (event.key.code == sf::Keyboard::BackSpace)
                    // {
                    //     if (input.getSize() > 0)
                    //     {
                    //         input.erase(input.getSize() - 1, 1);
                    //         numInput.setString(input);
                    //     }
                    // }
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

            // DRAW
            window.clear();
            for (auto it = std::begin(lines); it != std::end(lines); it++)
            {
                window.draw(*it);
            }
            window.draw(numInput);
            slider.draw(window);
            shuffleBtn.draw(window);
            startBtn.draw(window);
            backToMenuBtn.draw(window);
            window.display();
        }
        // MENU VIEW
        else if (isMenuWindow)
        {
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                menuStartBtn.handleEvent(event, window);
                configBtn.handleEvent(event, window);
            }
            // DRAW
            window.clear(sf::Color::White);
            window.draw(menuTitle);
            menuStartBtn.draw(window);
            configBtn.draw(window);
            window.display();
        }
        // CONFIG VIEW
        else if (isConfigWindow)
        {
            backToMenuBtn.setColor(sf::Color::Black);
            while (window.pollEvent(event))
            {
                backToMenuBtn.handleEvent(event, window);
                arrowUpBtn.handleEvent(event, window);
                arrowDownBtn.handleEvent(event, window);
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            // DRAW
            window.clear(sf::Color::White);
            window.draw(configTitle);
            window.draw(speedInputLabel);
            window.draw(speedInput);
            window.draw(sortingInputLabel);
            arrowUpBtn.draw(window);
            arrowDownBtn.draw(window);
            backToMenuBtn.draw(window);
            window.display();
        }
    }

    return 0;
}