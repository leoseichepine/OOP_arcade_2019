/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#include "./../include/Core.hpp"

Core::Core(int ac, char **av)
{
    _graphLibs = readLib(GRAPHIC_PATH);
    _gameLibs = readLib(GAME_PATH);
    // for (auto it = _graphLibs.begin(); it != _graphLibs.end(); ++it)
    //     std::cout << it->c_str() << std::endl;

    if (ac != 2)
        throw std::exception();
}

Core::~Core()
{
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