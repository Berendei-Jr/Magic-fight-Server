#include "../include/projectiles.h"
#include "../include/EventQueue.h"
#include "../include/board.h"

void fireball::TickAction(){
    this->position->owner->ChangeHash();
    if(this->position->NextHex(this->direction)!=nullptr){
        this->position->hex_objects.remove(this);
        this->position=this->position->NextHex(this->direction);
        this->position->hex_objects.push_back(this);
        Event* ev=new Event(this, this->SpeedTime);
        this->direction=direction;this->position->owner->event_queue.push(*ev);
    } else {
        this->destroy();
    }
}

fireball::fireball(hexagon* position, int Creator, int direction):projectile(position, Creator){
    this->name="fireball";
    this->Creator=Creator;
    sf::Texture *fireball_texture = new sf::Texture;
    fireball_texture->loadFromFile("/home/supsun/Documents/Magic_fight/img/fireball.png");
    this->sprite=sf::Sprite(*fireball_texture);
    Event* ev=new Event(this, this->SpeedTime);
    this->direction=direction;this->position->owner->event_queue.push(*ev);

}

void fireball::destroy(){
    this->position->DelObject(this);
    delete this;
}
