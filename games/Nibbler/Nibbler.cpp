/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

Nibbler::Nibbler()
{
    std::cout << "Nibbler ctor" << std::endl;
}

Nibbler::~Nibbler()
{
    std::cout << "Nibbler dtor" << std::endl;
}

extern "C" IGame *entry()
{
    return new Nibbler;
}

void Nibbler::handleEvent(std::string &name)
{
    (void)name;
}

void Nibbler::handleUpdate(int elapsedTime)
{
    (void)elapsedTime;
}

void Nibbler::handleRender(IGraphicRenderer &renderer)
{
    (void)renderer;
}

std::map<std::string, std::string> Nibbler::getGameData()
{
    return {};
}

void Nibbler::setGameData(std::map<std::string, std::string> &data)
{
    (void)data;
}