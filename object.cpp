#include "object.h"
#include "board.h"

void object::move(int direction){
    this->position->hex_objects.remove(this);
    this->position=this->position->NextHex(direction);
    this->position->hex_objects.push_back(this);
}
