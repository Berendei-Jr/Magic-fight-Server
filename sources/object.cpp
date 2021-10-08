#include "object.h"
#include "board.h"
object::object(hexagon* position)
{
    this->position=position;
    position->AddObject(this);
}
object::~object(){}

hero::hero(hexagon* position, sf::Texture &textr, ActionsList SkillNames[4], int number):object(position)
{
    this->type="hero";
    this->icon='0';
    this->health=100;
    this->number=number;
    this->sprite= sf::Sprite(textr);
    for(int i = 0; i<4; i++){
        switch (SkillNames[i])
        {
        case Step:
            this->skills[i]=new make_step(this);
            break;
        case Fireball:
            this->skills[i]=new make_fireball(this);
            break;
        }
    }

}

projectile::projectile(hexagon* position, int Creator):object(position){
    this->position=position;
    this->Creator=Creator;
}

void projectile::destroy(){}
projectile::~projectile(){}


hero::~hero(){}

void hero::destroy(){
    this->position->DelObject(this);
    this->~hero();
}
