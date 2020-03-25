/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

Nibbler::Nibbler(): _data({}), _snake({}), _speed(1), _score(0), _elapsedTime(0), _pixelSize(32)
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

void Nibbler::move()
{
    _elapsedTime = 0;
    if (_snake.size() > 1) {
        for (std::size_t i = _snake.size() - 1; i > 0; --i)
            _snake[i].setPosition(Vector2f(_snake[i - 1].getPositionX(), _snake[i - 1].getPositionY()));
    }
    if (_dir == RIGHT) {
        std::cout << "RIGHT" << std::endl;
        _snake[0].move(Vector2f(_speed * _pixelSize, 0));
    } else if (_dir == LEFT) {
        std::cout << "LEFT" << std::endl;
        _snake[0].move(Vector2f(-_speed * _pixelSize, 0));
    } else if (_dir == UP) {
        std::cout << "UP" << std::endl;
        _snake[0].move(Vector2f(0, -_speed * _pixelSize));
    } else if (_dir == DOWN) {
        std::cout << "DOWN" << std::endl;
        _snake[0].move(Vector2f(0, _speed * _pixelSize));
    }
}

void Nibbler::handleUpdate(int elapsedTime)
{
    _elapsedTime += elapsedTime;
    if (_elapsedTime >= 250)
        move();
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