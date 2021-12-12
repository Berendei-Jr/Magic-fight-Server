#ifndef OBJECT_H
#define OBJECT_H
#include "actions.h"
#include <SFML/Graphics.hpp>

class hexagon;

class Action_class
{
public:
    virtual void TickAction()=0;
    Action_class();
    Action_class(int SpeedTime);
protected:
    int SpeedTime;
};



class object
{
public:
    int type = 0;
    hexagon* position;
    object(hexagon* position);
    sf::Sprite sprite;

    virtual int get_type();
    virtual void destroy();
    virtual ~object();

protected:

private:

};

class hero:public object
{

public:
    hero(hexagon* position, sf::Texture &textr, ActionsList SkillNames[4], int number);

    int type=1;
    int health = 100;
    int number;
    int max_mana = 100;
    int cur_mana;

    void make_action(int n_act, int direction);
    int get_type();
    void destroy();
    void add_mana(int mana);
    void get_damage(int damage);
    ~hero();
private:
    action* skills[4];
    void swich_action(ActionsList SkillNames[4]);

};



class projectile: public object, public Action_class
{
public:
    int type = 2;
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
