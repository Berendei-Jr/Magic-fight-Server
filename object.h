#ifndef OBJECT_H
#define OBJECT_H
#include "actions.h"
#include <SFML/Graphics.hpp>
class hexagon;

class object
{
public:
    char* type;
    char icon;
    hexagon* position;
    sf::Sprite sprite;

    object(hexagon* position, sf::Texture &textr);
    virtual void destroy()=0;

protected:

private:

};

class hero:public object
{

public:
    hero(hexagon* position, sf::Texture &textr, ActionsList SkillName, int number);
    int health;
    action* skill;
    int numder;

    void destroy();
    ~hero();
private:

};

class projectile: public object
{
public:
    projectile(hexagon* position, sf::Texture &textr, int damage, int SpeedTime, int Creator);
    int damage;
    int SpeedTime;
    int Creator;

    void TickAction();
    void destroy();
    ~projectile();

};

class effect
{
public:
    effect(hexagon* position, std::string texture_file);
    ~effect();
};

class spell: public object
{
public:
    spell(hexagon* position, std::string texture_file);
    effect* effects;
    void destroy();
    ~spell();
};
#endif // OBJECT_H
