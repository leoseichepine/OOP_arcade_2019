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
        // Snake var
        std::vector<Rect>_snake;
        Rect _food;
        std::size_t _elapsedTime;
        int _pixelSize;
        int _speed;
        std::size_t _score;
        moveDir _dir;
        // Snake fct
        void addCase();
        void move();
        void createFood();
        void handleCollision();
        std::size_t generateRand(std::size_t max, std::size_t n);
        bool isValidFoodPos(Vector2f pos);
};

#endif /* !NIBBLER_HPP_ */