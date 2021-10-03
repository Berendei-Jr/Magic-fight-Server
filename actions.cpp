#include "actions.h"
#include "object.h"
#include "board.h"
action::action(hero* owner){
    this->owner=owner;
}

step::step(hero* owner):action(owner){}

void step::DoIt(int direction)
{
    this->owner->position->hex_objects.remove(owner);
    this->owner->position=owner->position->NextHex(direction);
    this->owner->position->hex_objects.push_back(owner);
}
