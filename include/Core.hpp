/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <string>
#include "IGraphic.hpp"
#include "IGame.hpp"
#include "SoLoader.hpp"
#include <sys/types.h>
#include <dirent.h>
#include <iostream>
#include <vector>

#define GRAPHIC_PATH "./lib/"
#define GAME_PATH "./game/"

class Core {
    public:
        explicit Core(int ac, char **av);
        ~Core();

        void useGraphic(const std::string &filename);
        void useGame(const std::string &filename);
        std::vector<std::string> readLib(const std::string &path);
        void run();
    private:
        // SoLoader<IGame>_game;
        // SoLoader<IGraphic>_graphic;
        std::vector<std::string>_graphLibs;
        std::vector<std::string>_gameLibs;
};

#endif /* !CORE_HPP_ */