#include "actions.h"
#include "object.h"
#include "board.h"
#include "projectiles.h"
action::action(hero* owner){
    this->owner=owner;
}

make_step::make_step(hero* owner):action(owner){}

void make_step::DoIt(int direction)
{
    hexagon* destination = owner->position->NextHex(direction);
    if (destination!=nullptr){
        this->owner->position->owner->ChangeHash();
        this->owner->position->hex_objects.remove(owner);
        this->owner->position=destination;
        destination->hex_objects.push_back(owner);
    }
}

make_fireball::make_fireball(hero* owner):action(owner){}

void make_fireball::DoIt(int direction)
{
    sf::Texture *fireball_texture = new sf::Texture;
    fireball_texture->loadFromFile("img/fireball.png");
    this->owner->position->owner->ChangeHash();
    new fireball(this->owner->position->NextHex(direction), this->owner->number, direction);
}
