#include <SFML/Graphics.hpp>
#include "chesspiece.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Chess Game");
    window.setVerticalSyncEnabled(true);

    // activate the window
    window.setActive(true);

    // create game objects
    ChessPiece queen(window, "assets/Chess_qdt60.png");

    // run the main loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                // end the program
                window.close();
            }
            else if (event.type == sf::Event::Resized)
            {
                // adjust the viewport when the window is resized
                // window(0, 0, event.size.width, event.size.height);
            }
        }

        window.clear(sf::Color::White);
        // draw ...
        queen.draw();
        window.display();
    }

    return 0;
}