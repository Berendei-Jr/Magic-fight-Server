#ifndef ACTIONS_H
#define ACTIONS_H

enum ActionsList {
    Step,
    Fireball,
    Leap,
    Wizard,
    Smoke
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
    int mana_costs;
};

class make_leap: public action
{
public:
    make_leap(hero* owner);
    void DoIt(int direction);
private:
    int mana_costs;
};

class make_fireball: public action
{
public:
    make_fireball(hero* owner);
    void DoIt(int direction);
private:
    int mana_costs;
};

class passive_action: public action
{
public:
    passive_action(hero* owner);

    void DoIt(int direction);
protected:
    int mana_costs=0;
};

class class_wizard: public passive_action
{
public:
    class_wizard(hero* owner);
    void DoIt(int direction);
};

class potion: public action
{
public:
    potion (hero* owner, int amount);
    void DoIt(int direction);
protected:
    int amount;
    int mana_costs=0;
};

class smoke_grenade: public potion
{
public:
    smoke_grenade(hero* owner, int amount);
    void DoIt(int diretion);
};

#endif // ACTIONS_H
