#ifndef ACTIONS_H
#define ACTIONS_H

enum ActionsList {
    Step,
    Fireball,
    Leap,
    Wizard
};
class hero;

class action
{
public:
    action(hero* owner);
    int mana_costs;
    hero* owner;
    virtual void DoIt(int direction)=0;
    virtual ~action()=default;
};

class make_step: public action
{
public:
    make_step(hero* owner);
    void DoIt(int direction);
private:
    int mana_costs = 10;
};

class make_leap: public action
{
public:
    make_leap(hero* owner);
    void DoIt(int direction);
private:
    int mana_costs = 30;
};

class make_fireball: public action
{
public:
    make_fireball(hero* owner);
    void DoIt(int direction);
private:
    int mana_costs = 50;
};

class passive_action: public action
{
public:
    passive_action(hero* owner);

    void DoIt(int direction);
    int mana_costs=0;
};

class class_wizard: public passive_action
{
public:
    class_wizard(hero* owner);
    void DoIt(int direction);
};

#endif // ACTIONS_H
