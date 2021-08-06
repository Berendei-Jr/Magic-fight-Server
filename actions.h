#ifndef ACTIONS_H
#define ACTIONS_H

enum ActionsList {
    Step
};
class hero;

class action
{
public:
    action(hero* owner);
    hero* owner;
    virtual void DoIt(int direction)=0;
    ~action();
};

class step: public action
{
public:
    step(hero* owner);
    void DoIt(int direction);
};
#endif // ACTIONS_H
