#ifndef OBJECT_H
#define OBJECT_H
#include "actions.h"
class hexagon;

class object
{
public:
    char* type;
    char icon;
    hexagon* position;

    object(hexagon* position);
    virtual void destroy()=0;

protected:

private:

};

class hero:public object
{

public:
    hero(hexagon* position, ActionsList SkillName);
    int health;
    action* skill;
    //void move(int direction);
    void destroy();
    ~hero();
private:

};

class projectile: public object
{
public:
    projectile(hexagon* position, int damage, int SpeedTime, int Creator);
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
    effect(hexagon* position);;
    ~effect();
};

class spell: public object
{
public:
    spell(hexagon* position);
    effect* effects;
    void destroy();
    ~spell();
};
#endif // OBJECT_H
