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
    #include <ctime>
    #include <chrono>

    #define GRAPHIC_PATH "./lib/"
    #define GAME_PATH "./games/"

    class Core {
        public:
            explicit Core(const std::string &);
            ~Core();

            void useGraphic(const std::string &filename);
            void useGame(const std::string &filename);
            void run();
        private:
            SoLoader<IGraphic>_graphic;
            SoLoader<IGame>_game;
            std::vector<std::string>_graphLibs;
            std::vector<std::string>_gameLibs;
            std::map<std::string, std::string> _gameData;

            std::vector<std::string> readLib(const std::string &path);
            int isValidLib(std::vector<std::string>, const std::string &);
    };
#endif /* !CORE_HPP_ */