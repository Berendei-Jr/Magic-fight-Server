#include "../include/projectiles.h"
#include "../include/EventQueue.h"
#include "../include/board.h"
#include <iostream>
#include <fstream>

void fireball::TickAction(){
    this->position->owner->ChangeHash();
    if(this->position->NextHex(this->direction)!=nullptr){
        this->position->hex_objects.remove(this);
        this->position=this->position->NextHex(this->direction);
        this->position->hex_objects.push_back(this);
        bool k = 0;
        auto it = this->position->hex_objects.begin();
        while (it != this->position->hex_objects.end() && k==0){
            if (  (*it)->get_type()==1){
                hero* tmp = dynamic_cast<hero*>(*it);
                tmp->get_damage(this->damage);
                k=1;
            }
            it++;
        }
        if (k==0){
            Event* ev=new Event(this, this->SpeedTime);
            this->direction=direction;this->position->owner->event_queue.push(*ev);
        } else {
            this->destroy();
        }
    } else {
        this->destroy();
    }
}

fireball::fireball(hexagon* position, int Creator, int direction):projectile(position, Creator){
    std::ifstream in("/opt/Magic_fight/configs/fireball.cfg");
    in >> this->damage;
    in >> this->SpeedTime;
    in.close();
    this->name="fireball";
    this->Creator=Creator;
    sf::Texture *fireball_texture = new sf::Texture;
    fireball_texture->loadFromFile("img/fireball.png");
    this->sprite=sf::Sprite(*fireball_texture);
    Event* ev=new Event(this, this->SpeedTime);
    this->direction=direction;this->position->owner->event_queue.push(*ev);

}

void fireball::destroy(){
    this->position->DelObject(this);
    delete this;
}
