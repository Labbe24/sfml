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
const int WIN_WIDTH = 1600;
const int WIN_HEIGHT = 800;

bool isMainWindow = true;
bool isConfigWindow = false;

// CALLBACK FUNCTIONS
void backToMainBtnOnClick()
{
    isConfigWindow = false;
    isMainWindow = true;
}

void configBtnClick()
{
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
    int speed = 20;

    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Sorting visualizer");
    BubbleSort bubble_sort;
    bubble_sort.setSpeed(50);
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

    // MAIN VIEW
    // BACK BUTTON
    Button backToMenuBtn(font, "Config");
    backToMenuBtn.setPosition(40, 20);
    backToMenuBtn.onClick(configBtnClick);
    backToMenuBtn.setColor(sf::Color::White);
    backToMenuBtn.setHoverColor(sf::Color::Red);

    // START BUTTON
    Button startBtn(font, "Start");
    startBtn.setPosition(140, 20);
    startBtn.onClick(startSortingClick);
    startBtn.setColor(sf::Color::White);
    startBtn.setHoverColor(sf::Color::Green);

    // SHUFFLE BUTTON
    Button shuffleBtn(font, "Shuffle");
    shuffleBtn.setPosition(240, 20);
    shuffleBtn.onClick(startShuffleClick);
    shuffleBtn.setColor(sf::Color::White);
    shuffleBtn.setHoverColor(sf::Color::Yellow);

    // NUMBER TEXT
    sf::String input;
    sf::Text numInput;
    numInput.setFont(font);
    numInput.setPosition(WIN_WIDTH - 80, 20);
    numInput.setString(std::to_string(num));

    // NUMBER SLIDER
    Slider slider(20, 200);
    slider.setColor(sf::Color::White);
    slider.setHoverColor(sf::Color::Green);

    // CONFIG VIEW
    // CONFIG TITLE
    sf::Text configTitle("Configuration", font);
    configTitle.setPosition(WIN_WIDTH / 2 - (configTitle.getGlobalBounds().width / 2), 20);
    configTitle.setFillColor(sf::Color::Black);

    Button back(font, "Back");
    back.setPosition(40, 20);
    back.onClick(backToMainBtnOnClick);
    back.setColor(sf::Color::Black);
    back.setHoverColor(sf::Color::Red);

    // SPEED LABEL
    sf::Text speedInputLabel("Speed:", font);
    speedInputLabel.setPosition(WIN_WIDTH / 2 - (speedInputLabel.getGlobalBounds().width / 2 + 100), 100);
    speedInputLabel.setFillColor(sf::Color::Black);

    // SPEED TEXT
    sf::String speedStr(std::to_string(speed) + "%");
    sf::Text speedText;
    speedText.setFont(font);
    speedText.setString(speedStr);
    speedText.setPosition(WIN_WIDTH / 2 - (speedText.getGlobalBounds().width / 2), 100);
    speedText.setFillColor(sf::Color::Black);

    // SPEED SLIDER
    Slider speedSlider(0, 100);
    speedSlider.setPosition(WIN_WIDTH / 2 - (speedSlider.getWidth() / 2), 180);
    speedSlider.setColor(sf::Color::Black);
    speedSlider.setHoverColor(sf::Color::Green);

    // SELECT SORTING METHOD LABEL
    sf::Text sortingInputLabel("Sorting:", font);
    sortingInputLabel.setPosition(WIN_WIDTH / 2 - (sortingInputLabel.getGlobalBounds().width / 2 + 100), 260);
    sortingInputLabel.setFillColor(sf::Color::Black);

    // SELECT SORTING METHOD BUTTONS
    Button bubbleSort(font, "Bubble");
    bubbleSort.setPosition(WIN_WIDTH / 2 - (bubbleSort.getWidth() / 2), 340);
    bubbleSort.onClick([&]() {});
    bubbleSort.setHoverColor(sf::Color::Green);

    Button mergeSort(font, "Merge");
    mergeSort.setPosition(WIN_WIDTH / 2 - (mergeSort.getWidth() / 2), 400);
    mergeSort.onClick([&]() {});
    mergeSort.setHoverColor(sf::Color::Green);

    Button quickSort(font, "Quick");
    quickSort.setPosition(WIN_WIDTH / 2 - (quickSort.getWidth() / 2), 460);
    quickSort.onClick([&]() {});
    quickSort.setHoverColor(sf::Color::Green);

    // CREATE LINES
    lines = createLines(num);

    while (window.isOpen())
    {
        // NEWEST EVENT
        sf::Event event;

        // MAIN VIEW
        if (isMainWindow)
        {
            while (window.pollEvent(event))
            {
                // EVENT HANDLERS
                shuffleBtn.handleEvent(event, window);
                startBtn.handleEvent(event, window);
                backToMenuBtn.handleEvent(event, window);
                slider.handleEvent(event, window);

                if (event.type == sf::Event::Closed)
                    window.close();
            }

            // UPDATE SLIDER AND CREATE NEW LINES
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
        // CONFIG VIEW
        else if (isConfigWindow)
        {
            while (window.pollEvent(event))
            {
                // EVENT HANDLERS
                back.handleEvent(event, window);
                bubbleSort.handleEvent(event, window);
                mergeSort.handleEvent(event, window);
                quickSort.handleEvent(event, window);
                speedSlider.handleEvent(event, window);
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            // UPDATE SLIDER
            speedSlider.update(window);
            int newSpeed = speedSlider.getValue();
            bubble_sort.setSpeed(newSpeed);
            std::string sliderValue = std::to_string(newSpeed);
            speedText.setString(sliderValue + "%");

            // DRAW
            window.clear(sf::Color::White);
            window.draw(configTitle);
            window.draw(speedInputLabel);
            window.draw(speedText);
            window.draw(sortingInputLabel);
            back.draw(window);
            bubbleSort.draw(window);
            mergeSort.draw(window);
            quickSort.draw(window);
            speedSlider.draw(window);
            window.display();
        }
    }

    return 0;
}