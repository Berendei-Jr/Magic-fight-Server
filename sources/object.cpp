#include "../include/object.h"
#include "../include/board.h"
#include "../include/EventQueue.h"
#include "action_classes.h"
object::object(hexagon* position)
{
    this->position=position;
    position->AddObject(this);
}

int object::get_type(){
    return this->type;
}

void object::destroy(){}

object::~object(){}

void hero::swich_action(ActionsList SkillNames[4]){
    for(int i = 0; i<4; i++){
        switch (SkillNames[i])
        {
        case Step:
            this->skills[i]=new make_step(this);
            break;
        case Fireball:
            this->skills[i]=new make_fireball(this);
            break;
        case Leap:
            this->skills[i]=new make_leap(this);
            break;
        case Wizard:
            this->skills[i]=new class_wizard(this);
            break;
        }
    }
}

int hero::get_type(){
    return this->type;
}

hero::hero(hexagon* position, sf::Texture &textr, ActionsList SkillNames[4], int number):object(position)
{
    this->number=number;
    this->sprite= sf::Sprite(textr);
    this->swich_action(SkillNames);
    this->cur_mana=this->max_mana;
    new mana_creator(&this->position->owner->event_queue, 1, this, 500);
}
void hero::add_mana(int mana){
    this->cur_mana+=mana;
    if (this->cur_mana>this->max_mana){
        this->cur_mana=this->max_mana;
    }
}
void hero::get_damage(int damage){
    this->health-=damage;
    if(this->health<=0){
        this->destroy();
    }
}


Action_class::Action_class(){}
Action_class::Action_class(int SpeedTime){
    this->SpeedTime=SpeedTime;
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
    //this->~hero();
}

