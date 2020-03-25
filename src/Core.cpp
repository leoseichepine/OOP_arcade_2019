/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#include "Core.hpp"

Core::Core(const std::string &path): _graphic(path), _game("./games/lib_arcade_nibbler.so")
{
    _graphLibs = readLib(GRAPHIC_PATH);
    _gameLibs = readLib(GAME_PATH);

    if (!isValidLib(_graphLibs, path))
        throw std::exception();
}

Core::~Core()
{
}

void Core::useGraphic(const std::string &filename)
{
    _graphic = SoLoader<IGraphic>(filename);
}

void Core::useGame(const std::string &filename)
{
    _game = SoLoader<IGame>(filename);
}

void Core::run()
{
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();


    while (_graphic->isOperational()) {
        auto delta = std::chrono::system_clock::now() - start;
        start = std::chrono::system_clock::now();
        _graphic->clearScreen();
        std::string ev(_graphic->handleEvent());
        _game->handleEvent(ev);
        _game->handleRender(*_graphic.operator->());
        _game->handleUpdate(std::chrono::duration_cast<std::chrono::milliseconds>(delta).count());
        _gameData = _game->getGameData();
        _graphic->drawScreen();
    }
}

int Core::isValidLib(std::vector<std::string> libs, const std::string &path)
{
    std::string newPath = path.substr(path.find_last_of('/') + 1);

    for (auto it = libs.begin(); it != libs.end(); ++it) {
        std::string tmp = it->c_str();
        if (newPath == tmp)
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