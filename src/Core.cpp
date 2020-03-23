/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#include "Core.hpp"

Core::Core(const std::string &path): _graphic(path), _game("./games/Nibbler/lib_arcade_nibbler.so")
{
    _graphLibs = readLib(GRAPHIC_PATH);
    _gameLibs = readLib(GAME_PATH);
    _clock = std::chrono::system_clock::now();
    // if (!isValidLib(_graphLibs, path)) {
    //     throw std::exception();
    // }
    std::chrono::time_point<std::chrono::system_clock> curr_time;
    std::chrono::time_point<std::chrono::system_clock> last_time = std::chrono::system_clock::now();
    while (_graphic->isOperational()) {
        curr_time = std::chrono::system_clock::now();
        int elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(curr_time - last_time).count();
        _graphic->clearScreen();
        _graphic->handleEvents();
        _game->handleRender(*_graphic.operator->());
        _game->handleUpdate(elapsed);
        _graphic->drawScreen();
        last_time = curr_time;
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