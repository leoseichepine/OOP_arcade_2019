/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFML
*/

#include "IGraphicSFML.hpp"

IGraphicSFML::IGraphicSFML(): _win(sf::VideoMode(800, 600, 32), std::string("SFML Window"), sf::Style::Close), _clock()
{
    std::cout << "IGraphicSFML ctor" << std::endl;
}

IGraphicSFML::~IGraphicSFML()
{
    std::cout << "IGraphicSFML dtor" << std::endl;
}

extern "C" IGraphic *entry()
{
    return new IGraphicSFML;
}

void IGraphicSFML::drawScreen()
{
    _win.display();
}

void IGraphicSFML::clearScreen()
{
    _win.clear();
}

void IGraphicSFML::drawRect(Rect rect)
{
    sf::Vector2f size(rect.getSizeX(), rect.getSizeY());
    sf::Vector2f pos(rect.getPositionX(), rect.getPositionY());
    sf::Color color(rect.getColorRed(), rect.getColorGreen(), rect.getColorBlue(), rect.getColorAlpha());
    sf::RectangleShape rec(size);

    rec.setPosition(pos);
    rec.setFillColor(color);
    _win.draw(rec);
}

void IGraphicSFML::drawCircle(Circle circle)
{
    sf::Vector2f pos(circle.getPositionX(), circle.getPositionY());
    sf::Color color(circle.getColorRed(), circle.getColorGreen(), circle.getColorBlue(), circle.getColorAlpha());
    sf::CircleShape cir(circle.getSizeX()); // On mettra toujours le radius dans X

    cir.setPosition(pos);
    cir.setFillColor(color);
    _win.draw(cir);
}

void IGraphicSFML::drawSprite(Sprite sprite)
{
    sf::Texture texture;
    texture.loadFromFile(sprite.getTextureName());
    sf::Sprite spr(texture);
    sf::Vector2f pos(sprite.getPositionX(), sprite.getPositionY());

    spr.setPosition(pos);
    _win.draw(spr);
}

void IGraphicSFML::drawText(Text text)
{
    sf::Font font;
    font.loadFromFile("./lib/fonts/font.ttf");
    unsigned int charSize = text.getSizeX(); // On mettra toujours la font size dans X
    sf::Vector2f pos(text.getPositionX(), text.getPositionY());
    sf::Color color(text.getColorRed(), text.getColorGreen(), text.getColorBlue(), text.getColorAlpha());

    sf::Text textDraw(text.getText(), font, charSize);
    textDraw.setFillColor(color);
    textDraw.setPosition(pos);
    _win.draw(textDraw);
}

bool IGraphicSFML::isOperational()
{
    return (_win.isOpen() ? true : false);
}

std::string IGraphicSFML::handleEvent()
{
    sf::Event e;

    while (_win.pollEvent(e)) {
        if (e.type == sf::Event::Closed
        || (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Delete))
            _win.close();
        if (e.type == sf::Event::KeyPressed) {
            if (e.key.code == sf::Keyboard::E)
                return "next_game";
            if (e.key.code == sf::Keyboard::C)
                return "prev_game";
            if (e.key.code == sf::Keyboard::A)
                return "next_graphic";
            if (e.key.code == sf::Keyboard::W)
                return "prev_graphic";
            if (e.key.code == sf::Keyboard::Escape)
                return "menu";
            if (e.key.code == sf::Keyboard::R)
                return "restart";
            if (e.key.code == sf::Keyboard::Return)
                return "enter";
            if (e.key.code == sf::Keyboard::BackSpace)
                return "space";
            if (e.key.code == sf::Keyboard::Left || e.key.code == sf::Keyboard::Q)
                return "left";
            if (e.key.code == sf::Keyboard::Right || e.key.code == sf::Keyboard::D)
                return "right";
            if (e.key.code == sf::Keyboard::Up || e.key.code == sf::Keyboard::Z)
                return "up";
            if (e.key.code == sf::Keyboard::Down || e.key.code == sf::Keyboard::S)
                return "down";
        }
    }
    return "";
}