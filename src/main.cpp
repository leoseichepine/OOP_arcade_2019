/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include "./../include/Core.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Invalid number of arguments" << std::endl;
        return (84);
    }
    std::string path = av[1];
    try {
        Core arcade(path);
    } catch (std::exception()) {
        return 84;
    }
    return 0;
}