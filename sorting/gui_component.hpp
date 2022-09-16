#ifndef GUI_COMPONENT_H
#define GUI_COMPONENT_H

#include <SFML/Graphics.hpp>

class GuiComponent
{
public:
    GuiComponent();
    ~GuiComponent();
    virtual void draw(sf::RenderWindow *window);
    virtual void handleEvent(sf::Event *event, sf::RenderWindow *window);

private:
};

#endif