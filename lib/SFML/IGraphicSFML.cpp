/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFML
*/

#include "IGraphicSFML.hpp"

IGraphicSFML::IGraphicSFML(): _win(sf::VideoMode(800, 600, 32), std::string("SFML Window"), sf::Style::Close)
{
    std::cout << "IGraphicSFML ctor" << std::endl;
}

IGraphicSFML::~IGraphicSFML()
{
    std::cout << "IGraphicSFML dtor" << std::endl;
}

extern "C" IGraphic *entry()
{
    return new IGraphicSFML;
}

void IGraphicSFML::drawScreen()
{
    _win.display();
}

void IGraphicSFML::clearScreen()
{
    _win.clear();
}

void IGraphicSFML::drawRect(Rect rect)
{
    sf::Vector2f size(rect.getSizeX(), rect.getSizeY());
    sf::Vector2f pos(rect.getPositionX(), rect.getPositionY());
    sf::RectangleShape rec(size);
    rec.setPosition(pos);
    _win.draw(rec);
}

void IGraphicSFML::drawCircle(Circle circle)
{
    (void)circle;
}

void IGraphicSFML::drawSprite(Sprite sprite)
{
    (void)sprite;
}

void IGraphicSFML::drawText(Text text)
{
    (void)text;
}

bool IGraphicSFML::isOperational()
{
    return (_win.isOpen() ? true : false);
}

IEventIterator &IGraphicSFML::handleEvents()
{
    sf::Event e;

    while (_win.pollEvent(e)) {
        if (e.type == sf::Event::Closed
        || (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape))
            _win.close();
    }
}