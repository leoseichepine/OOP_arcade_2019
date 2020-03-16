/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <string>
#include <array>
#include "IGraphic.hpp"
#include "IGame.hpp"
#include "SoLoader.hpp"

#define libPath "./lib/"
#define gamePath "./game/"

class Core {
    public:
        explicit Core(int ac, char **av);
        ~Core();

        void useGraphic(const std::string &filename);
        void useGame(const std::string &filename);
        void run();
    private:
        // SoLoader<IGame>_game;
        // SoLoader<IGraphic>_graphic;
        std::array<std::string, 3>_graphLibs;
        std::array<std::string, 2>_gameLibs;
};

#endif /* !CORE_HPP_ */