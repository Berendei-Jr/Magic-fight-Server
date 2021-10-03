#include "actions.h"
#include "object.h"
#include "board.h"
action::action(hero* owner){
    this->owner=owner;
}

step::step(hero* owner):action(owner){}

void step::DoIt(int direction)
{
    hexagon* destination = owner->position->NextHex(direction);
    if (destination!=nullptr){
        this->owner->position->owner->ChangrHash();
        this->owner->position->hex_objects.remove(owner);
        this->owner->position=destination;
        this->owner->position->hex_objects.push_back(owner);
    }
}
