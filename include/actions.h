#ifndef ACTIONS_H
#define ACTIONS_H

enum ActionsList {
    Step,
    Fireball
};
class hero;

class action
{
public:
    action(hero* owner);
    int mana_costs;
    hero* owner;
    virtual void DoIt(int direction)=0;
    ~action();
};

class make_step: public action
{
public:
    make_step(hero* owner);
    void DoIt(int direction);
private:
    int mana_costs = 10;
};

class make_fireball: public action
{
public:
    make_fireball(hero* owner);
    void DoIt(int direction);
private:
    int mana_costs = 50;
};
#endif // ACTIONS_H
