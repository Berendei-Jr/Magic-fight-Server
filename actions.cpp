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
        this->owner->position->owner->ChangeHash();
        this->owner->position->hex_objects.remove(owner);
        this->owner->position=destination;
        this->owner->position->hex_objects.push_back(owner);
    }
}

fireball::fireball(hero* owner):action(owner){}

void fireball::DoIt(int direction)
{
    sf::Texture *fireball_texture = new sf::Texture;
    fireball_texture->loadFromFile("img/fireball.png");
    this->owner->position->owner->ChangeHash();
    new projectile("Fireball", this->owner->position, *fireball_texture, 10, 100, this->owner->number);

}
