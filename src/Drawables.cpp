/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Drawables
*/

#include "Drawables.hpp"

// Vector2f
Vector2f::Vector2f(float pX, float pY): x(pX), y(pY)
{
}

// Color
Color::Color(unsigned char red, unsigned char blue, unsigned char green, unsigned char alpha): red(red), blue(blue), green(green), alpha(alpha)
{
}

Color Color::Red()
{
    return Color(255, 0, 0, 100);
}

Color Color::Blue()
{
    return Color(0, 255, 0, 100);
}

Color Color::Green()
{
    return Color(0, 0, 255, 100);
}

Color Color::Black()
{
    return Color(255, 255, 255, 100);
}

Color Color::White()
{
    return Color(0, 0, 0, 100);
}

Color Color::Transparent()
{
    return Color(0, 0, 0, 0);
}

//APosition
APosition::APosition(const Vector2f &pos): _pos(pos)
{
}

void APosition::setPosition(const Vector2f pos)
{
    _pos = pos;
}

void APosition::setPositionX(float posX)
{
    _pos.x = posX;
}

void APosition::setPositionY(float posY)
{
    _pos.y = posY;
}

void APosition::move(const Vector2f pos)
{
    _pos.x += pos.x;
    _pos.y += pos.y;
}

void APosition::moveX(float movX)
{
    _pos.x += movX;
}

void APosition::moveY(float movY)
{
    _pos.y += movY;
}

Vector2f APosition::getPosition(void) const
{
    return _pos;
}

float APosition::getPositionX(void) const
{
    return _pos.x;
}

float APosition::getPositionY(void) const
{
    return _pos.y;
}

//ASize
ASize::ASize(const Vector2f &size): _size(size)
{
}

void ASize::setSize(const Vector2f &size)
{
    _size = size;
}

void ASize::setSizeX(float sizeX)
{
    _size.x = sizeX;
}

void ASize::setSizeY(float sizeY)
{
    _size.y = sizeY;
}

Vector2f ASize::getSize(void) const
{
    return _size;
}

float ASize::getSizeX(void) const
{
    return _size.x;
}

float ASize::getSizeY(void) const
{
    return _size.y;
}

//AColor
AColor::AColor(const Color &color): _color(color)
{
}

void AColor::setColor(const Color &color)
{
    _color = color;
}

void AColor::setColorRed(unsigned char red)
{
    _color.red = red;
}

void AColor::setColorBlue(unsigned char blue)
{
    _color.blue = blue;
}

void AColor::setColorGreen(unsigned char green)
{
    _color.green = green;
}

void AColor::setColorAlpha(unsigned char alpha)
{
    _color.alpha = alpha;
}

Color AColor::getColor(void) const
{
    return _color;
}

unsigned char AColor::getColorRed(void) const
{
    return _color.red;
}

unsigned char AColor::getColorBlue(void) const
{
    return _color.blue;
}

unsigned char AColor::getColorGreen(void) const
{
    return _color.green;
}

unsigned char AColor::getColorAlpha(void) const
{
    return _color.alpha;
}

//Rect
Rect::Rect(Vector2f pos, Vector2f size, Color color): APosition(pos), ASize(size), AColor(color)
{
}

//Circle
Circle::Circle(Vector2f pos, Vector2f size, Color color): APosition(pos), ASize(size), AColor(color)
{
}

//Text
Text::Text(const std::string &text, Vector2f pos, Vector2f size, Color color): APosition(pos), ASize(size), AColor(color), _text(text)
{
}

const std::string &Text::getText(void) const
{
    return _text;
}

void Text::setText(const std::string &newText)
{
    this->_text = newText;
}

//Sprite
Sprite::Sprite(const std::string &name, Vector2f pos, Vector2f size): APosition(pos), ASize(size), _textureName(name)
{
}

const std::string &Sprite::getTextureName(void) const
{
    return _textureName;
}