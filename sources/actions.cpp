#include "../include/actions.h"
#include "../include/object.h"
#include "../include/board.h"
#include "../include/projectiles.h"
action::action(hero* owner){
    this->owner=owner;
}

make_step::make_step(hero* owner):action(owner){
    this->mana_costs=10;
}

void make_step::DoIt(int direction)
{
    if (this->owner->cur_mana<this->mana_costs) return;
    hexagon* destination = owner->position->NextHex(direction);
    if (destination!=nullptr){
        this->owner->cur_mana-=this->mana_costs;
        this->owner->position->owner->ChangeHash();
        this->owner->position->hex_objects.remove(owner);
        this->owner->position=destination;
        destination->hex_objects.push_back(owner);
    }
}

make_fireball::make_fireball(hero* owner):action(owner){
    this->mana_costs=50;
}

void make_fireball::DoIt(int direction)
{
    if (this->owner->cur_mana<this->mana_costs) return;
    this->owner->cur_mana-=this->mana_costs;
    this->owner->position->owner->ChangeHash();
    new fireball(this->owner->position->NextHex(direction), this->owner->number, direction);
}
