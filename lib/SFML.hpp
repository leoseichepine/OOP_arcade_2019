/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFML
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <iostream>
#include "SFML/Graphics.hpp"
#include "./../include/IGraphic.hpp"

class SFML: public IGraphic {
    public:
        SFML();
        ~SFML();

        virtual void drawScreen() override;
        virtual void clearScreen() override;
        virtual void drawRect(Rect rect) override;
        virtual void drawCircle(Circle circle) override;
        virtual void drawSprite(Sprite sprite) override;
        virtual void drawText(Text text) override;

        virtual bool isOperational() override;
        virtual IEventIterator &handleEvents() override;
    protected:
    private:
        sf::RenderWindow _win;
        sf::Clock _clock;
};

#endif /* !SFML_HPP_ */