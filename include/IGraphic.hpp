/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGraphic
*/

#ifndef IGRAPHIC_HPP_
#define IGRAPHIC_HPP_

#include "Drawables.hpp"

class IGraphicRenderer
{
    public:
        IGraphicRenderer() = default;
        virtual void drawScreen() = 0;
        virtual void clearScreen() = 0;
        virtual void drawRect(Rect rect) = 0;
        virtual void drawCircle(Circle circle) = 0;
        virtual void drawSprite(Sprite sprite) = 0;
        virtual void drawText(Text text) = 0;

        IGraphicRenderer(const IGraphicRenderer &) = delete;
        IGraphicRenderer &operator=(const IGraphicRenderer &) = delete;
};

class IGraphic: public IGraphicRenderer {
    public:
        IGraphic() = default;
        virtual ~IGraphic(){};

        virtual bool isOperational() = 0;
        virtual std::string handleEvent() = 0;
};

#endif /* !IGRAPHIC_HPP_ */