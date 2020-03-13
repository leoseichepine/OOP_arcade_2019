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

void Nibbler::handleEvent(std::string &name)
{
}

void Nibbler::handleUpdate(int elapsedTime)
{
}

void Nibbler::handleRender(IGraphicRenderer &renderer)
{
}

std::map<std::string, std::string> Nibbler::getGameData()
{
}

void Nibbler::setGameData(std::map<std::string, std::string> &data)
{
}