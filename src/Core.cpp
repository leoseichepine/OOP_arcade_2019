/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#include "./../include/Core.hpp"

Core::Core(int ac, char **av)
{
    _graphLibs = {"lib_arcade_sfml.so", "lib_arcade_ncurses.so", "lib_arcade_libcaca.so"};
    _gameLibs = {"lib_arcade_nibbler.so", "lib_arcade_pacman.so"};

    if (ac != 2)
        throw std::exception();
}

Core::~Core()
{
}