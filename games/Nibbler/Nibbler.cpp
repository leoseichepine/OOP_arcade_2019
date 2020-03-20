/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

Nibbler::Nibbler(): _data({}), _snake({}), _speed(32), _score(0), _elapsedTime(0)
{
    std::cout << "Nibbler ctor" << std::endl;
    _data.insert(std::make_pair<std::string, std::string>("score", std::to_string(_score)));
    addCase();
    addCase();
    _dir = RIGHT;
}

Nibbler::~Nibbler()
{
    std::cout << "Nibbler dtor" << std::endl;
}

extern "C" IGame *entry()
{
    return new Nibbler;
}

void Nibbler::addCase()
{
    Rect newRect;
    newRect.setSize(Vector2f(_pixelSize, _pixelSize));
    newRect.setColor(Color(255, 0, 0, 255));

    if (_snake.empty()) {
        newRect.setPosition(Vector2f(_pixelSize, 0));
    } else {
        newRect.setPosition(Vector2f(_snake[_snake.size() - 1].getPositionX() - newRect.getSizeX(),
        _snake[_snake.size() - 1].getPositionY()));
    }
    _snake.push_back(newRect);
}

void Nibbler::handleEvent(std::string &name)
{
    std::cout << "Handling event : " + name << std::endl;
}

void Nibbler::handleUpdate(int elapsedTime)
{
    if (elapsedTime + _elapsedTime >= 1000){
        std::cout << "elapsedTime : " << elapsedTime << "s" << std::endl;
        _elapsedTime = 0;
    } else
        _elapsedTime += elapsedTime;
}

void Nibbler::handleRender(IGraphicRenderer &renderer)
{
    for (std::size_t i = 0; i < _snake.size(); ++i)
        renderer.drawRect(_snake[i]);
}

std::map<std::string, std::string> Nibbler::getGameData()
{
    return _data;
}

void Nibbler::setGameData(std::map<std::string, std::string> &data)
{
    _data = data;
}