/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "./../include/IGame.hpp"
#include <iostream>

class Pacman: public IGame {
    public:
        Pacman();
        ~Pacman();

        virtual void handleEvent(std::string &name) override;
        virtual void handleUpdate(int elapsedTime) override;
        virtual void handleRender(IGraphicRenderer &renderer) override;
        virtual std::map<std::string, std::string> getGameData() override;
        virtual void setGameData(std::map<std::string, std::string> &data) override;
    protected:
    private:
};

#endif /* !PACMAN_HPP_ */