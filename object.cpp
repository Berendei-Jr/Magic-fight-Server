#include "object.h"
#include "board.h"
//#include "actions.h"
object::object(hexagon* position)
{
    this->position=position;
    position->AddObject(this);
}

hero::hero(hexagon* position, ActionsList SkillName, int number):object(position)
{
    this->type="hero";
    this->icon='0';
    this->health=100;
    this->numder;
    switch (SkillName)
    {
    case Step:
        this->skill=new step(this);
        break;
    }
}

hero::~hero(){}

void hero::destroy(){
    this->position->DelObject(this);
    this->~hero();
}
