/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pacman
*/

#include "Pacman.hpp"

Pacman::Pacman()
{
    std::cout << "Pacman ctor" << std::endl;
}

Pacman::~Pacman()
{
    std::cout << "Pacman dtor" << std::endl;
}

void Pacman::handleEvent(std::string &name)
{
}

void Pacman::handleUpdate(int elapsedTime)
{
}

void Pacman::handleRender(IGraphicRenderer &renderer)
{
}

std::map<std::string, std::string> Pacman::getGameData()
{
}

void Pacman::setGameData(std::map<std::string, std::string> &data)
{
}