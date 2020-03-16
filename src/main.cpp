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
    try {
        Core arcade(ac, av);
    } catch (std::exception()) {
        return 84;
    }
    return 0;
}