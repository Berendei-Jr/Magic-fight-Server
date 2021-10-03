#include "object.h"
#include "board.h"
object::object(hexagon* position, sf::Texture &textr)
{
    this->position=position;
    position->AddObject(this);
    this->sprite = sf::Sprite(textr);
}
object::~object(){}

hero::hero(hexagon* position, sf::Texture &textr, ActionsList SkillNames[4], int number):object(position, textr)
{
    this->type="hero";
    this->icon='0';
    this->health=100;
    this->number=number;
    for(int i = 0; i<4; i++){
        switch (SkillNames[i])
        {
        case Step:
            this->skills[i]=new step(this);
            break;
        case Fireball:
            this->skills[i]=new fireball(this);
            break;
        }
    }

}

projectile::projectile(std::string name, hexagon* position, sf::Texture &textr, int damage, int SpeedTime, int Creator):object(position, textr)
{
    this->name=name;
    this->damage=damage;
    this->SpeedTime=SpeedTime;
    this->Creator=Creator;
}

void projectile::destroy(){}
projectile::~projectile(){}


hero::~hero(){}

void hero::destroy(){
    this->position->DelObject(this);
    this->~hero();
}
