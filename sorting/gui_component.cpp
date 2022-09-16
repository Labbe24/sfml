#include "gui_component.hpp"
#include <iostream>

GuiComponent::GuiComponent() {}
GuiComponent::~GuiComponent() {}

void GuiComponent::draw(sf::RenderWindow *window)
{
    std::cout << "GuiComponent draw()" << std::endl;
}

void GuiComponent::handleEvent(sf::Event *event, sf::RenderWindow *window)
{
    std::cout << "GuiComponent handæeEvent()" << std::endl;
}