/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFML
*/

#include "IGraphicSFML.hpp"

IGraphicSFML::IGraphicSFML()
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
}

void IGraphicSFML::clearScreen()
{
}

void IGraphicSFML::drawRect(Rect rect)
{
    (void)rect;
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
    return true;
}

IEventIterator &IGraphicSFML::handleEvents()
{
}