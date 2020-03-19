/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#include "Core.hpp"

Core::Core(const std::string &path): _graphic(path) //, _game("./games/lib_arcade_nibbler.so")
{
    _graphLibs = readLib(GRAPHIC_PATH);
    _gameLibs = readLib(GAME_PATH);
    // if (!isValidLib(_graphLibs, path)) {
    //     throw std::exception();
    // }
    Rect rect(Vector2f(0,0), Vector2f(20, 20), Color(255, 255, 255, 255));
    Circle cir(Vector2f(30, 40), Vector2f(30, 0), Color(255, 0, 0, 255));
    Text t("SNAKE", Vector2f(200, 200), Vector2f(50, 0), Color(255, 255, 255, 255));
    Sprite spr("./lib/textures/heart.png", Vector2f(300, 20), Vector2f(40, 40));
    while (_graphic->isOperational()) {
        _graphic->handleEvents();
        _graphic->clearScreen();
        _graphic->drawRect(rect);
        _graphic->drawText(t);
        _graphic->drawCircle(cir);
        _graphic->drawSprite(spr);
        _graphic->drawScreen();
    }
}

Core::~Core()
{
}

int Core::isValidLib(std::vector<std::string> libs, const std::string &path)
{
    for (auto it = libs.begin(); it != libs.end(); ++it) {
        std::string tmp = it->c_str();
        if (path == tmp)
            return 1;
    }
    return 0;
}

std::vector<std::string> Core::readLib(const std::string &path) {

    DIR* dirp = opendir(path.c_str());
    struct dirent * dp;
    std::vector<std::string> vec;

    while ((dp = readdir(dirp)) != NULL) {
        std::string tmp = dp->d_name;
        if (tmp.find(".so") != std::string::npos)
            vec.push_back(tmp);
    }
    closedir(dirp);
    return vec;
}