#ifndef OBJECT_H
#define OBJECT_H
#include "actions.h"
#include <SFML/Graphics.hpp>

class hexagon;

class Action_class
{
public:
    virtual void TickAction()=0;
    int SpeedTime;
};

class mana_creator
{
private:

    int mana_count;
public:
    mana_creator();
    void TickAction();
};

class object
{
public:
    std::string type;
    hexagon* position;
    object(hexagon* position);
    sf::Sprite sprite;

    virtual void destroy()=0;
    virtual ~object();

protected:

private:

};

class hero:public object
{

public:
    hero(hexagon* position, sf::Texture &textr, ActionsList SkillNames[4], int number);
    int health;
    action* skills[4];
    int number;
    int max_mana;
    int cur_mana;

    void destroy();
    ~hero();
private:

};

class projectile: public object, public Action_class
{
public:
    projectile(hexagon* position, int Creator);
    std::string name;
    int damage;
    int SpeedTime;
    int Creator;


    virtual void destroy()=0;
    virtual ~projectile();

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
