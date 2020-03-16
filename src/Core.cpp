/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#include "./../include/Core.hpp"

Core::Core(const std::string &path): _graphic(path) //, _game("./games/lib_arcade_nibbler.so")
{
    _graphLibs = readLib(GRAPHIC_PATH);
    _gameLibs = readLib(GAME_PATH);
    // if (!isValidLib(_graphLibs, path))
    //     throw std::exception();
    // _graphic = SoLoader<IGraphic>(path);
    // _game = SoLoader<IGame>("");
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