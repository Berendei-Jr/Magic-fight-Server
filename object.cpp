#include "object.h"
#include "board.h"
object::object(hexagon* position){
    this->position=position;
    position->hex_objects.push_back(this);
}
hero::hero(hexagon* position):object(position){
    this->icon='0';
    this->health=100;
}
void hero::move(int direction){
    this->position->hex_objects.remove(this);
    this->position=this->position->NextHex(direction);
    this->position->hex_objects.push_back(this);
}
hero::~hero(){}
void hero::destroy(){
    this->position->hex_objects.remove(this);
    this->~hero();
}
