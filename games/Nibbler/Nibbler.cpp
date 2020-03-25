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
    createFood();
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

void Nibbler::handleEvent(std::string &name)
{
    if (name == "left" && _dir != RIGHT)
        _dir = LEFT;
    else if (name == "right" && _dir != LEFT)
        _dir = RIGHT;
    else if (name == "down" && _dir != UP)
        _dir = DOWN;
    else if (name == "up" && _dir != DOWN)
        _dir = UP;
}

void Nibbler::handleUpdate(int elapsedTime)
{
    _elapsedTime += elapsedTime;
    if (_elapsedTime >= 16)
        move();
}

void Nibbler::handleRender(IGraphicRenderer &renderer)
{
    for (std::size_t i = 0; i < _snake.size(); ++i)
        renderer.drawRect(_snake[i]);
    renderer.drawRect(_food);
}

std::map<std::string, std::string> Nibbler::getGameData()
{
    return _data;
}

void Nibbler::setGameData(std::map<std::string, std::string> &data)
{
    _data = data;
}

void Nibbler::addCase()
{
    Rect newRect;
    newRect.setSize(Vector2f(_pixelSize, _pixelSize));
    newRect.setColor(Color(255, 0, 0, 255));

    if (_snake.empty()) {
        newRect.setPosition(Vector2f(_pixelSize, 0));
    } else {
        newRect.setPosition(Vector2f(_snake[_snake.size() - 1].getPositionX(),
        _snake[_snake.size() - 1].getPositionY())); // A Revoir
    }
    _snake.push_back(newRect);
}

void Nibbler::handleCollision()
{
    if (_snake[0].getPositionX() == _food.getPositionX() && _snake[0].getPositionY() == _food.getPositionY()) {
        addCase();
        createFood();
    } else if (_snake[0].getPositionX() < 0 || _snake[0].getPositionX() + _snake[0].getSizeX() > 800
    || _snake[0].getPositionY() < 0 || _snake[0].getPositionY() + _snake[0].getSizeY() > 600)
        _data.insert(std::make_pair<std::string, std::string>("lost", "1"));
}

void Nibbler::move()
{
    _elapsedTime = 0;
    if (_snake.size() > 1) {
        for (std::size_t i = _snake.size() - 1; i > 0; --i)
            _snake[i].setPosition(Vector2f(_snake[i - 1].getPositionX(), _snake[i - 1].getPositionY()));
    }
    if (_dir == RIGHT)
        _snake[0].move(Vector2f(_speed * _pixelSize, 0));
    else if (_dir == LEFT)
        _snake[0].move(Vector2f(-_speed * _pixelSize, 0));
    else if (_dir == UP)
        _snake[0].move(Vector2f(0, -_speed * _pixelSize));
    else if (_dir == DOWN)
        _snake[0].move(Vector2f(0, _speed * _pixelSize));
    handleCollision();
}

bool Nibbler::isValidFoodPos(Vector2f pos)
{
    for (auto it = _snake.begin(); it != _snake.end(); ++it)
        if (it->getPositionX() == pos.x && it->getPositionY() == pos.y)
            return false;
    return true;
}

std::size_t Nibbler::generateRand(std::size_t max, std::size_t n)
{
    std::size_t r = rand() % max;

    while (r % n != 0)
        r = rand() % max;
    return r;
}

void Nibbler::createFood()
{
    std::size_t randX = generateRand(800, 32); // Récupérer la taille de la window en dur c moche
    std::size_t randY = generateRand(600, 32);
    Vector2f pos(randX, randY);

    while (!isValidFoodPos(pos)) {
        randX = generateRand(800, _pixelSize);
        randY = generateRand(600, _pixelSize);
        pos.x = randX;
        pos.y = randY;
    }
    _food.setColor(Color(0, 0, 255, 100));
    _food.setSize(Vector2f(_pixelSize, _pixelSize));
    _food.setPosition(Vector2f(randX, randY));
}