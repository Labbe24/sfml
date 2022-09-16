#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <random>
#include <algorithm>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include "bubble_sort.hpp"
#include "merge_sort.hpp"
#include "button.hpp"
#include "slider.hpp"
#include "sprite_button.hpp"
#include "gui_component.hpp"

std::mutex g_window_mutex;
std::condition_variable g_window_cv;

const int WIDTH = 200;
const int WIN_WIDTH = 1600;
const int WIN_HEIGHT = 800;
BubbleSort bubbleSort;
MergeSort mergeSort;
SortAlgo *algo = &bubbleSort;

int g_num = 20;
int g_speed = 20;

bool g_open_main = false;
bool g_open_config = true;

std::vector<sf::RectangleShape> g_lines;

sf::Event event;
std::queue<sf::Event> g_events;

std::vector<GuiComponent *> g_main_guis;
std::vector<GuiComponent *> g_config_guis;

// CREATE LINES
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

// THREADS
void renderMainView(sf::RenderWindow *window)
{
    window->setActive(true);

    while (window->isOpen())
    {
        std::unique_lock<std::mutex> lock(g_window_mutex);
        g_window_cv.wait(lock, []
                         { return g_open_main; });

        while (window->pollEvent(event))
        {
            for (auto g : g_main_guis)
            {
                g->handleEvent(&event, window);
                Slider *slider = dynamic_cast<Slider *>(g);
                if (slider != nullptr)
                {
                    const unsigned int newNum = slider->getValue();
                    if (newNum != g_num)
                    {
                        g_num = newNum;
                        g_lines = createLines(newNum);
                    }
                }
            }

            if (event.type == sf::Event::Closed)
            {
                window->close();
            }
        }
        window->clear();
        for (auto it = std::begin(g_lines); it != std::end(g_lines); it++)
        {
            window->draw(*it);
        }
        for (auto g : g_main_guis)
        {
            g->draw(window);
        }
        window->display();

        lock.unlock();
        g_window_cv.notify_one();
    }
}

void renderConfigView(sf::RenderWindow *window)
{
    sf::Font font;
    if (!font.loadFromFile("peach_days.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;
    }
    // CONFIG VIEW
    // TITLE
    sf::Text configTitle("Configuration", font);
    configTitle.setPosition(WIN_WIDTH / 2 - (configTitle.getGlobalBounds().width / 2), 20);
    configTitle.setFillColor(sf::Color::Black);

    // SPEED LABEL
    sf::Text speedInputLabel("Speed:", font);
    speedInputLabel.setPosition(WIN_WIDTH / 2 - (speedInputLabel.getGlobalBounds().width / 2 + 100), 100);
    speedInputLabel.setFillColor(sf::Color::Black);

    // SELECT SORTING METHOD LABEL
    sf::Text sortingInputLabel("Sorting:", font);
    sortingInputLabel.setPosition(WIN_WIDTH / 2 - (sortingInputLabel.getGlobalBounds().width / 2 + 100), 260);
    sortingInputLabel.setFillColor(sf::Color::Black);

    window->setActive(true);

    while (window->isOpen())
    {
        std::unique_lock<std::mutex> lock(g_window_mutex);
        g_window_cv.wait(lock, []
                         { return g_open_config; });

        while (window->pollEvent(event))
        {
            for (auto g : g_config_guis)
            {
                g->handleEvent(&event, window);
                Slider *slider = dynamic_cast<Slider *>(g);
                if (slider != nullptr)
                {
                    const unsigned int newSpeed = slider->getValue();
                    bubbleSort.setSpeed(newSpeed);
                    mergeSort.setSpeed(newSpeed);
                }
            }

            if (event.type == sf::Event::Closed)
            {
                window->close();
            }
        }

        window->clear(sf::Color::White);

        for (auto g : g_config_guis)
        {
            g->draw(window);
        }

        window->draw(configTitle);
        window->draw(speedInputLabel);
        window->draw(sortingInputLabel);
        window->display();

        lock.unlock();
        g_window_cv.notify_one();
    }
}

// CALLBACK FUNCTIONS
void backToMainBtnOnClick()
{
    g_open_config = false;
    g_open_main = true;
}

void configBtnClick()
{
    g_open_main = false;
    g_open_config = true;
}

void shuffleLines(std::vector<sf::RectangleShape> &lines)
{
    std::random_device rd;
    auto rng = std::default_random_engine{rd()};
    std::shuffle(std::begin(lines), std::end(lines), rng);
    int count = lines.size();
    const float width = (float)WIN_WIDTH / (float)count;

    for (int i = 1; i < count + 1; i++)
    {
        lines[i - 1].setFillColor(sf::Color::White);
        lines[i - 1].setPosition(i * width, WIN_HEIGHT);
    }
}

// END

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Sorting visualizer");

    bubbleSort.setSpeed(50);
    mergeSort.setSpeed(50);

    auto startSortingClick = [&]()
    {
        algo->sort(g_lines, window);

        for (auto it = g_lines.begin(); it != g_lines.end(); it++)
        {
            it->setFillColor(sf::Color::Green);
            sf::sleep(sf::milliseconds(10.0f));
            window.draw(*it);
            window.display();
        }
    };

    auto startShuffleClick = [&]()
    {
        shuffleLines(g_lines);
    };

    sf::Font font;
    if (!font.loadFromFile("peach_days.ttf"))
    {
        return EXIT_FAILURE;
    }

    // MAIN VIEW
    // CONFIG BUTTON
    Button configBtn(font, "Config");
    configBtn.setPosition(40, 20);
    configBtn.onClick(configBtnClick);
    configBtn.setColor(sf::Color::White);
    configBtn.setHoverColor(sf::Color::Red);

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
    numInput.setString(std::to_string(g_num));

    // NUMBER SLIDER
    Slider slider(20, 200);
    slider.setColor(sf::Color::White);
    slider.setHoverColor(sf::Color::Green);
    slider.setText(&numInput);

    g_main_guis.push_back(&slider);
    g_main_guis.push_back(&shuffleBtn);
    g_main_guis.push_back(&startBtn);
    g_main_guis.push_back(&configBtn);

    // CONFIG VIEW
    // SPEED TEXT
    sf::String speedStr(std::to_string(g_speed) + "%");
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
    speedSlider.setText(&speedText);

    // BACK BUTTON
    Button back(font, "Back");
    back.setPosition(40, 20);
    back.onClick(backToMainBtnOnClick);
    back.setColor(sf::Color::Black);
    back.setHoverColor(sf::Color::Red);

    // SELECT SORTING METHOD BUTTONS
    Button bubbleSortBtn(font, "Bubble");
    bubbleSortBtn.setPosition(WIN_WIDTH / 2 - (bubbleSortBtn.getWidth() / 2), 340);
    bubbleSortBtn.setHoverColor(sf::Color::Green);

    Button mergeSortBtn(font, "Merge");
    mergeSortBtn.setPosition(WIN_WIDTH / 2 - (mergeSortBtn.getWidth() / 2), 400);
    mergeSortBtn.setHoverColor(sf::Color::Green);

    Button quickSortBtn(font, "Quick");
    quickSortBtn.setPosition(WIN_WIDTH / 2 - (quickSortBtn.getWidth() / 2), 460);
    quickSortBtn.setHoverColor(sf::Color::Green);

    bubbleSortBtn.onClick([&]
                          { bubbleSortBtn.setActive(true);
                          quickSortBtn.setActive(false);
                          mergeSortBtn.setActive(false); 
                          algo = &bubbleSort; });
    quickSortBtn.onClick([&]
                         { quickSortBtn.setActive(true);
                            bubbleSortBtn.setActive(false);
                            mergeSortBtn.setActive(false); });
    mergeSortBtn.onClick([&]
                         { mergeSortBtn.setActive(true);
                            quickSortBtn.setActive(false);
                            bubbleSortBtn.setActive(false);
                            algo = &mergeSort; });

    g_config_guis.push_back(&speedSlider);
    g_config_guis.push_back(&back);
    g_config_guis.push_back(&bubbleSortBtn);
    g_config_guis.push_back(&mergeSortBtn);
    g_config_guis.push_back(&quickSortBtn);

    // CREATE LINES
    g_lines = createLines(g_num);

    // THREADS
    window.setActive(false);
    sf::Thread configViewThread(&renderConfigView, &window);
    sf::Thread mainViewThread(&renderMainView, &window);
    configViewThread.launch();
    mainViewThread.launch();

    configViewThread.wait();
    mainViewThread.wait();
    return 0;
}