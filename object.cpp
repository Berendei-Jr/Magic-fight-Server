#include "object.h"
#include "board.h"
//#include "actions.h"
object::object(hexagon* position)
{
    this->position=position;
    position->hex_objects.push_back(this);
}

hero::hero(hexagon* position, ActionsList SkillName):object(position)
{
    this->icon='0';
    this->health=100;
    switch (SkillName)
    {
    case Step:
        this->skill=new step(this);
        break;
    }
}

hero::~hero(){}

void hero::destroy(){
    this->position->hex_objects.remove(this);
    this->~hero();
}
