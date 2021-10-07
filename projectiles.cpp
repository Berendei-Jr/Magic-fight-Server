#include "projectiles.h"
#include "EventQueue.h"
#include "board.h"

void fireball::TickAction(){
    this->position->owner->GetHash();
    this->position->hex_objects.remove(this);
    this->position=this->position->NextHex(this->direction);
    this->position->hex_objects.push_back(this);
}

fireball::fireball(hexagon* position, int Creator, int direction):projectile(position, Creator){
    this->name="fireball";
    this->damage=10;
    this->SpeedTime=100;
    this->Creator=Creator;
    Event* ev=new Event(this);
    this->direction=direction;this->position->owner->event_queue.push(*ev);
}

void fireball::destroy(){}
