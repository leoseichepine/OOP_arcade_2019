/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "./../include/IGame.hpp"
#include <iostream>

extern "C" IGame *entry();

class Nibbler: public IGame {
    public:
        Nibbler();
        ~Nibbler();

        virtual void handleEvent(std::string &name) override;
        virtual void handleUpdate(int elapsedTime) override;
        virtual void handleRender(IGraphicRenderer &renderer) override;
        virtual std::map<std::string, std::string> getGameData() override;
        virtual void setGameData(std::map<std::string, std::string> &data) override;
    protected:
    private:
};

#endif /* !NIBBLER_HPP_ */