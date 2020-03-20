/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "./../include/IGame.hpp"
#include <vector>
#include <iostream>

extern "C" IGame *entry();

class Nibbler: public IGame {
    public:
        Nibbler();
        ~Nibbler();

        enum moveDir {RIGHT, LEFT, UP, DOWN};
        virtual void handleEvent(std::string &name) override;
        virtual void handleUpdate(int elapsedTime) override;
        virtual void handleRender(IGraphicRenderer &renderer) override;
        virtual std::map<std::string, std::string> getGameData() override;
        virtual void setGameData(std::map<std::string, std::string> &data) override;
    protected:
    private:
        // GameData
        std::map<std::string, std::string> _data;
        std::size_t _pixelSize;
        // Snake var
        std::vector<Rect>_snake;
        std::size_t _speed;
        std::size_t _score;
        moveDir _dir;
        Rect _food;
        // Snake fct
        void addCase();
        std::size_t _elapsedTime;
};

#endif /* !NIBBLER_HPP_ */